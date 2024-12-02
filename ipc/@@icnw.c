#include "ipci.h"

static int ipc_subtask(void *arg1, void *arg2);
static int ipc_accept(IPC *ipc);
static int ipc_close_channels(IPC *ipc);
static int ipc_fd_set(IPC *ipc, fd_set *read, fd_set *write, fd_set *excp);
static unsigned ipc_send_queue_count(IPC *ipc);
static void close_stale_port(int port);
static int ipc_send_channel_messages(IPCC *ipcc);
static int ipc_read_channel_messages(IPCC *ipcc);
static int ipc_proc_message(IPCC *ipcc, IPCM *ipcm);

/* Create an IPC handle 
 * port     port number to listen on for IPC request, 0 == TCPIP will assign port
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 * Creates an IPC subtask for sending and receiving messages.
*/
IPC *ipc_new(unsigned short port)
{
    IPC                 *ipc        = calloc(1, sizeof(IPC));
    int                 sock;
    struct sockaddr_in  serv_addr;
    int                 salen = sizeof(serv_addr);
    int                 rc;
    int                 error;
    int                 i;

    if (!ipc) goto quit;    /* Out of memory */
    
    strcpy(ipc->eye, IPC_EYE);
    ipc->sock = -1;

    /* create listener socket */
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        /* failed */
        wtof("IPC0028E socket() failed, rc=%d, error=%d", sock, errno);
        goto quit;
    }

    /* bind socket to IP address and port */
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family        = AF_INET;
    serv_addr.sin_addr.s_addr   = 0x7F000001;   /* 127.0.0.1 */ 
    serv_addr.sin_port          = htons(port);

    rc = bind(sock, &serv_addr, sizeof(serv_addr));
    if (rc < 0) {
        error = errno;
        wtof("IPC0030E bind() failed for IPC port, rc=%d, error=%d", rc, errno);
        if (error==EADDRINUSE) for (i=0; i < 10; i++) {
            wtof("IPC0030I EADDRINUSE, waiting for TCPIP to release IPC port=%d", port);
            sleep(10);
            rc = bind(sock, &serv_addr, sizeof(serv_addr));
            if (rc >= 0) break;
            error = errno;
        }
        if (rc < 0) {
            wtof("IPC0030E bind() failed for IPC port, rc=%d, error=%d", rc, errno);
            closesocket(sock);
            close_stale_port(port);
            goto failed;
        }
    }

    /* get the port from the socket */
    getsockname(sock, (struct sockaddr*)&serv_addr, &salen);
    wtof("%s: port=%u sin_port=%u", __func__, port, serv_addr.sin_port);
    port = serv_addr.sin_port;

    /* listen for connection */
    rc = listen(sock, 10);
    if (rc < 0) {
        wtof("IPC0031E listen() failed, rc=%d, error=%d", rc, errno);
        closesocket(sock);
        goto failed;
    }

    /* success */
    ipc->sock = sock;
    ipc->port = port;
    wtof("IPC0032I Listening for IPC request on port %d", ipc->port);

    /* create the subtask for this IPC instance */
    ipc->task = cthread_create_ex(ipc_subtask, ipc, NULL, 32*1024);
    if (!ipc->task) {
        wtof("%s: ctread_create_ex() failed for IPC subtask", __func__);
        goto failed;
    }
    
quit:
    return ipc;

failed:
    ipc_free(&ipc);
    goto quit;
}

static int 
ipc_subtask(void *arg1, void *arg2)
{
    IPC         *ipc        = (IPC *)arg1;
    int         rc;
    timeval     wait;
    int         maxsock;
    unsigned    count;
    unsigned    n;
    fd_set      read;
    unsigned    *ecblist[2];
    struct sockaddr_in addr;
    struct sockaddr_in *a = (struct sockaddr_in *)&addr;

    if (!ipc) {
        wtof("%s: No IPC handle", __func__);
        return 8;
    }

    lock(ipc, LOCK_EXC);

    ipc->flag |= IPC_FLAG_ACTIVE;   /* indicate subtask is active */

    if (ipc->sock < 0) {
        wtof("%s: No IPC listener socket", __func__);
        goto quit;
    }

    /* build ECB list, last entry must have high order bit on */
    ecblist[0] = (unsigned*)((unsigned)&ipc->ecb | 0x80000000);
    
    wtof("%s: IPC Subtask Listening on socket %d port %u", __func__, ipc->sock, ipc->port);

    unlock(ipc, LOCK_EXC);

    /* IPC processing loop */
    while(1) {
        lock(ipc, LOCK_EXC);

        ipc->sock = IPC_STATE_ACTIVE;

        /* Immediate shutdown requested? */
        if (ipc->flag & IPC_FLAG_SHUTDOWN) break;

        /* close channels that are IPCC_STATE_CLOSE */
        ipc_close_channels(ipc);

        /* build fd_set for select() */
        maxsock = ipc_fd_set(ipc, &read, NULL, NULL);
        if (!maxsock) {
            /* No sockets are open */
            if (ipc->flag & IPC_FLAG_QUIESCE) break;

            wtof("IPC0050E maxsock==0, something is wrong!");
            goto quit;
        }

        /* set the wait interval */
        wait.tv_sec     = 0;
        wait.tv_usec    = 0;

        /* Any messages waiting to be sent */
        count = ipc_send_queue_count(ipc);
        if (count==0) {
            /* No messages waiting to be sent */
            /* if we're quiesced then break out of loop */
            if (ipc->flag & IPC_FLAG_QUIESCE) break;

            /* wait just a little bit */
            wait.tv_sec = 10;
        }

        /* Note: we don't want to hold the lock while select 
         * is running so that other task can queue or process 
         * messages as needed.
        */
        ipc->state = IPC_STATE_WAIT;
        unlock(ipc, LOCK_EXC);

        /* wait for something to do */
        rc = selectex(maxsock, &read, NULL, NULL, &wait, ecblist);
        if (rc<0) {
            wtof("IPC0051E selectex() failed, rc=%d, error=%d", rc, errno);
            goto quit;
        }

        /* Note: In logic below we lock and unlock around each
         * processing loop so as to minimize the exclusion of
         * other task that may want to create or process messages,
        */
        lock(ipc, LOCK_EXC);
        ipc->state = IPC_STATE_ACTIVE;

        /* Immediate shutdown requested? */
        if (ipc->flag & IPC_FLAG_SHUTDOWN) break;

        /* Check and reset IPC ECB */
        if (ipc->ecb) {
            wtof("%s: Got IPC ECB 0x%08X", __func__, ipc->ecb);
            ipc->ecb = 0;
        }

        if (!(ipc->flag & IPC_FLAG_QUIESCE)) {
            /* not quiesce, check for new connections */
            if (FD_ISSET(ipc->sock, &read)) {
                /* new client wants to connect */
                ipc->state = IPC_STATE_ACCEPT;

                ipc_accept(ipc);

                ipc->state = IPC_STATE_IDLE;
            }
        } /* if (FD_ISSET(ipc->sock, &read)) */
        unlock(ipc, LOCK_EXC);

        lock(ipc, LOCK_EXC);

        /* Immediate shutdown requested? */
        if (ipc->flag & IPC_FLAG_SHUTDOWN) break;

        ipc->state = IPC_STATE_SEND;

        /* send channel message */
        count = array_count(&ipc->ipcc);
        for(n=0; n < count; n++) {
            IPCC *ipcc = ipc->ipcc[n];
            
            if (!ipcc) continue;

            if (array_count(&ipcc->outq)) {
                /* send channel queued messages */
                ipc_send_channel_messages(ipcc);
            }
        }

        ipc->state = IPC_STATE_ACTIVE;
        unlock(ipc, LOCK_EXC);

        lock(ipc, LOCK_EXC);

        /* Immediate shutdown requested? */
        if (ipc->flag & IPC_FLAG_SHUTDOWN) break;

        if (!(ipc->flag & IPC_FLAG_QUIESCE)) {
            /* read channel message */
            ipc->state = IPC_STATE_READ;

            count = array_count(&ipc->ipcc);
            for(n=0; n < count; n++) {
                IPCC *ipcc = ipc->ipcc[n];
            
                if (!ipcc) continue;

                if (FD_ISSET(ipcc->sock, &read)) {
                    /* get channel messages */
                    ipc_read_channel_messages(ipcc);
                }
            }
            ipc->state = IPC_STATE_ACTIVE;
        }

        unlock(ipc, LOCK_EXC);
    }

quit:
    lock(ipc, LOCK_EXC);
    ipc->state = IPC_STATE_IDLE;    /* IPC is IDLE               */
    ipc->flag &= ~IPC_FLAG_ACTIVE;  /* indicate subtask inactive */
    ipc->flag |= IPC_FLAG_SHUTDOWN; /* indicate subtask shutdown */

    /* close the listener socket */
    if (ipc->sock >= 0) {
        wtof("%s: Closing IPC listener socket %d port %u", __func__, ipc->sock, ipc->port);
        closesocket(ipc->sock);
        ipc->sock = -1;
    }
    unlock(ipc, LOCK_EXC);
    return 0;
}

static int
ipc_accept(IPC *ipc)
{
    IPCC                *ipcc;
    int                 len;
    int                 sock;
    struct sockaddr_in  addr;
    struct sockaddr_in  *a = (struct sockaddr_in *)&addr;

    len = sizeof(addr);
    sock = accept(ipc->sock, &addr, &len);
    if (sock<0) {
        wtof("IPC0052E accept() failed, rc=%d, error=%d", sock, errno);
        goto quit;
    }

    /* we've accepted a connection */
    wtof("%s: new connection on socket=%d", __func__, sock);

    /* set non-blocking I/O */
    len = 1;    
    if (ioctlsocket(sock, FIONBIO, &len)) {
        wtof("IPC0053E Unable to set non-blocking I/O for socket %d", sock);
    }

    /* allocate a new IPCC handle */
    ipcc = calloc(1, sizeof(IPCC));
    if (!ipcc) {
        wtof("IPC0999E Out of memory!");
        closesocket(sock);
        goto quit;
    }

    /* Initialize IPCC handle */
    strcpy(ipcc->eye, IPCC_EYE);
    ipcc->ipc  = ipc;               /* IPC handle               */
    ipcc->sock = sock;              /* Channel socket number    */
    ipcc->addr = a->sin_addr.s_addr;/* Channel IPV4 address     */
    ipcc->port = a->sin_port;       /* Channel port number      */
    ipcc->flag = IPCC_FLAG_ACCEPT;  /* Created by accept()      */
    ipcc->state = IPCC_STATE_IDLE;  /* Not doing anything yet   */
    time64(&ipcc->lastused);        /* update last used time    */

    /* Remember this channel */
    array_add(&ipc->ipcc, ipcc);

quit:
    return 0;
}


static int
ipc_close_channels(IPC *ipc)
{
    int         rc      = 0;
    unsigned    count;
    unsigned    n;
    IPCC        *ipcc;

    /* look for any channels that need to be closed */
    count = array_count(&ipc->ipcc);
    for(n=0; n < count; n++) {
        ipcc = ipc->ipcc[n];
        if (!ipcc) continue;           /* no client handle? */

        if (ipcc->state==IPCC_STATE_CLOSE) {
            /* we close a single channel at a time,
            ** other channels will be closed on next pass.
            */
            wtof("%s: closing channel(%u) socket(%d)\n", n+1, ipcc->sock);
            ipc_free_channel(&ipcc);
            rc = 1;
            break;
        }
    }

quit:
    return rc;
}

static int
ipc_fd_set(IPC *ipc, fd_set *read, fd_set *write, fd_set *excp)
{
    int         maxsock = 0;
    unsigned    count   = array_count(&ipc->ipcc);
    unsigned    n;
    IPCC        *ipcc;

    if (read && ipc->sock >= 0) {
        memset(read, 0, sizeof(fd_set));
    }

    if (write) {
        memset(write, 0, sizeof(fd_set));
    }

    if (excp) {
        memset(excp, 0, sizeof(fd_set));
    }

    if (!(ipc->flag & IPC_FLAG_QUIESCE)) {
        /* Not queisce */
        if (read && ipc->sock >= 0) {
            FD_SET(ipc->sock, read);
            if (ipc->sock > maxsock) maxsock = ipc->sock;
        }
    }

    for(n=0; n < count; n++) {
        ipcc = ipc->ipcc[n];
        if (!ipcc) continue;           /* no channel handle? */

        if (ipcc->sock < 0) continue;   /* no socket? */

        if (ipcc->sock > maxsock) maxsock = ipcc->sock;
        if (read)   FD_SET(ipcc->sock, read);
        if (write)  FD_SET(ipcc->sock, write);
        if (excp)   FD_SET(ipcc->sock, excp);
    }

quit:
    if (maxsock) maxsock++;
    return maxsock;
}

static unsigned 
ipc_send_queue_count(IPC *ipc)
{
    unsigned    queued  = 0;
    unsigned    count, n;
    
    count = array_count(&ipc->ipcc);
    for(n=0; n < count; n++) {
        IPCC *ipcc = ipc->ipcc[n];
        
        if (!ipcc) continue;
        queued += array_count(ipcc->outq);
    }

    return queued;
}

static void
close_stale_port(int port)
{
	int					rc;
	int					i;
    int                 addrlen;
    struct sockaddr     addr;
    struct sockaddr_in  serv_addr;

	for(i = 1; i < FD_SETSIZE; i++) {
		addrlen = sizeof(addr);
		rc = getsockname(i, &addr, &addrlen);
		if (rc==0) {
			struct sockaddr_in *in = (struct sockaddr_in*)&addr;
			if (in->sin_port == port) {
				wtof("IPC0027I Closing stale socket %d on port:%u\n", i, in->sin_port);
				closesocket(i);
				sleep(2);	/* give the underlying host a chance to cleanup the socket */
				break;
			}
		}
	}
}

static int 
ipc_send_channel_messages(IPCC *ipcc)
{
    IPCM        *ipcm;
    IPCH        *ipch;
    unsigned    count;
    int         len;
    unsigned    size;
    char        *p;

    lock(ipcc, LOCK_EXC);

    if (ipcc->state == IPCC_STATE_CLOSE) goto quit;

    /* any outgoing messages for the channel? */
    count = array_count(&ipcc->outq);
    if (!count) goto quit;

    ipcc->state = IPCC_STATE_SEND;

    /* get message from top of queue */
    ipcm = array_get(&ipcc->outq, 1);
    if (!ipcm) {
        /* remove NULL from outgoing message queue */
        array_del(&ipcc->outq, 1);
        ipcc->state = IPCC_STATE_IDLE;
        goto quit;
    }
    
    /* Make sure this message has our channel handle */
    if (ipcm->ipcc != ipcc) ipcm->ipcc = ipcc;

    ipch = ipcm->ipch;
    if (!ipch) {
        /* no message header */
        /* free the message (also removes message from channel queue) */
        ipc_free_message(&ipcm);
        ipcc->state = IPCC_STATE_IDLE;
        goto quit;
    }

    /* send the message */
    p = (char*)ipch;
    size = sizeof(IPCH) + ipch->len; 
    while(ipcm->pos < size) {
        len = send(ipcc->sock, &p[ipcm->pos], size - ipcm->pos, 0);
        if (len < 0) {
            /* socket error */
            if (errno == EWOULDBLOCK) {
                ipcc->state = IPCC_STATE_IDLE;
                goto quit;
            }

            /* a real error occured */
            ipcc->flag |= IPCC_FLAG_ERROR;
            ipcc->state = IPCC_STATE_CLOSE;
            goto quit;
        }
        
        if (len == 0) {
            /* our sockets *should* be NON BLOCKING so this shouldn't happen */
            wtof("%s: send() returned 0 len", __func__);
            ipcc->state = IPCC_STATE_IDLE;
            goto quit;
        }

        /* remember how much data we've already sent */
        ipcm->pos += len;
    }

    /* delete message from queue */
    ipc_free_message(&ipcm);    /* also removes the message from the channel queue */
    ipcc->state = IPCC_STATE_IDLE;

quit:
    unlock(ipcc, LOCK_EXC);
    return 0;
}

static int 
ipc_read_channel_messages(IPCC *ipcc)
{
    IPCH        head    = {0};
    IPCM        *ipcm   = NULL;
    IPCH        *ipch   = NULL;
    unsigned    n, count;
    int         len;
    unsigned    size;
    unsigned    pos;
    char        *p;

    lock(ipcc, LOCK_EXC);

    if (ipcc->state == IPCC_STATE_CLOSE) goto quit;

    ipcc->state = IPCC_STATE_RECV;

    /* check for partial message received */
    if (ipcc->in) {
        ipcm = ipcc->in;
        ipcc->in = NULL;
        ipch = ipcm->ipch;
        goto getdata;
    }

    /* read header from channel socket */
    size = sizeof(head);
    p = (char *)&head;
    pos = 0;
    while(pos < size) {
        len = recv(ipcc->sock, &p[pos], size - pos, 0);
        if (len < 0) {
            int error = errno;
            /* socket error */
            if (error == EWOULDBLOCK) {
                ipcc->state = IPCC_STATE_IDLE;
                goto quit;
            }
            
            /* a real error occured */
            wtof("%s: recv() error %d %s", __func__, error, strerror(error));
            goto badchannel;
        }
        /* remember how many bytes we read */
        pos += len;
    }

    /* Make sure we're in sync */
    if (head.sync != IPCH_SYNC) {
        wtof("%s: Invalid sync 0x%02X expecting 0x%02X", __func__, head.sync, IPCH_SYNC);
        goto badchannel;
    }

    if (head.len > 65535) {
        wtof("%s: Message length greater than 65535", __func__);
        goto badchannel;
    }

    /* allocate message handle */
    ipcm = calloc(1, sizeof(IPCM));
    if (!ipcm) {
        wtof("%s: Out of memory", __func__);
        goto badchannel;
    }
    
    strcpy(ipcm->eye, IPCM_EYE);

    /* calulate size of IPCH handle (header + data) */
    size = sizeof(IPCH) + head.len;
    /* allocate message (header+data) */
    ipch = calloc(1, size);
    if (!ipch) {
        wtof("%s: Out of memory", __func__);
        goto badchannel;
    }

    memcpy(ipch, &head, sizeof(IPCH));
    ipcm->ipcc = ipcc;
    ipcm->ipch = ipch;

getdata:
    /* read message data from channel socket */
    size = ipch->len;
    while(ipcm->pos < size) {
        len = recv(ipcc->sock, &ipch->buf[ipcm->pos], size - ipcm->pos, 0);
        if (len < 0) {
            int error = errno;
            /* socket error */
            if (error == EWOULDBLOCK) {
                wtof("%s: EWOULDBLOCK", __func__);
                ipcc->in = ipcm;    /* remember this message for next attempt */
                ipcc->state = IPCC_STATE_IDLE;
                goto quit;
            }
            
            /* a real error occured */
            wtof("%s: recv() error %d %s", __func__, error, strerror(error));
            goto badchannel;
        }
        /* remember how many bytes we read */
        ipcm->pos += len;
    }

    /* Message read, reset message pos */
    ipcm->pos = 0;

    if (ipch->maj == IPCH_MAJ_IPC) {
        /* internal message */
        ipc_proc_message(ipcc, ipcm);
    }
    else {
        /* channel gets posted for all other messages */
        array_add(&ipcc->inq, ipcm);
        cthread_post(&ipcc->ecb, 1);
    }

    /* Update channel and post ecb */
    time64(&ipcc->lastused);
    ipcc->state = IPCC_STATE_IDLE;

    goto quit;

badchannel:
    ipcc->flag |= IPCC_FLAG_ERROR;
    ipcc->state = IPCC_STATE_CLOSE;
    if (ipcm) ipc_free_message(&ipcm);

quit:
    unlock(ipcc, LOCK_EXC);
    return 0;
}

static int 
ipc_proc_message(IPCC *ipcc, IPCM *ipcm)
{
    IPCH        *ipch = ipcm->ipch;
    
    ipcc->state = IPCC_STATE_PROC;

    /* Should never happen, but just in case */
    if (ipch->maj != IPCH_MAJ_IPC) {
        /* Not our message! */
        wtof("%s: Invalid IPC internal message", __func__);
        goto freemsg;
    }

    /* Should never happen, but just in case */
    if (ipcm->pos != 0) {
        /* incomplete message? */
        wtof("%s: Incomplete message", __func__);
        goto freemsg;
    }

    /* Check for REQUEST */
    if (ipch->flag & IPCH_FLAG_REQUEST) {
        /* Turn off the REQUEST flag */
        ipch->flag &= ~IPCH_FLAG_REQUEST;

        switch(ipch->min) {
        case IPCH_MIN_IPC_PING:
            wtof("%s: Received PING request, send REPLY", __func__);
            ipch->flag |= IPCH_FLAG_REPLY;
            array_add(&ipcc->outq, ipcm);
            goto quit;
        default:
            wtof("%s: Received unknown request %u", __func__, ipch->min);
            goto freemsg;
        }
    }

    /* Check for REPLY */
    if (ipch->flag & IPCH_FLAG_REPLY) {
        /* Turn off the REPLY flag */
        ipch->flag &= ~IPCH_FLAG_REPLY;

        switch(ipch->min) {
        case IPCH_MIN_IPC_PING:
            wtof("%s: Received PING reply", __func__);
            goto freemsg;
        default:
            wtof("%s: Received unknown reply %u", __func__, ipch->min);
            goto freemsg;
        }
    }

    /* Check for UNSOL */
    if (ipch->flag & IPCH_FLAG_UNSOL) {
        wtof("%s: Received UNSOL message", __func__);
        wtodumpf(ipch, sizeof(IPCH), "%s: HEAD", __func__);
        if (ipch->len) wtodumpf(ipch->buf, ipch->len, "%s: DATA", __func__);
        goto freemsg;
    }

    /* Anything else is invalid */
    wtof("%s: Invalid message flag 0x%02X", __func__, ipch->flag);

freemsg:
    ipc_free_message(&ipcm);

quit:
    ipcc->state = IPCC_STATE_IDLE;
    return 0;
}
