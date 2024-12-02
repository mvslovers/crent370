#include "ipci.h"

/* ipc_connect_addr_port() - create new chanel to addr, port */
IPCC *
ipc_connect_addr_port(IPC *ipc, unsigned addr, unsigned short port)
{
    IPCC        *ipcc   = NULL;
    int         rc      = 0;
	int		 	sock	= -1;
    struct sockaddr_in  sockaddr_in = {0};
    int			len = sizeof(sockaddr_in);
    int         lockrc;

    /* Sanity check address and port values */
    if (addr > 0xDFFFFFFF) { 
        /* 223.255.255.255 class D or higher */
        unsigned char *c = (unsigned char *)&addr;
        wtof("%s: Invalid address: 0x%08X %u.%u.%u.%u", 
            __func__, addr, c[0], c[1], c[2], c[3]);
        goto quit;
    }

    if (!port) {
        wtof("%s: Invalid port number: %u", __func__, port);
        goto quit;
    }

    if (!addr) {
        /* default to localhost 127.0.0.1 */
        addr = 0x7F000001;
    }

    if (ipc) {
        /* do we already have a channel for this address and port? */
        ipcc = ipc_get_addr_port(ipc, addr, port);
        if (ipcc) {
            /* is this channel operationsal? */
            if (ipcc->sock < 0) {
                /* socket is closed */
                ipc_free_channel(&ipcc);
                ipcc = NULL;
            }
            else if (ipcc->flag & IPCC_FLAG_ERROR) {
                /* broken channel */
                ipc_free_channel(&ipcc);
                ipcc = NULL;
            }

            if (ipcc) {
                /* Don't create new channel, use this one */
                goto quit;
            }
        }   /* if (ipcc) */
    }   /* if (ipc) */
    
    /* Let's allocate a new IPCC handle */
    ipcc = calloc(1, sizeof(IPCC));
    if (!ipcc) {
        wtof("%s: Out of memory", __func__);
        goto quit;
    }

    /* Initialize IPCC handle */
    strcpy(ipcc->eye, IPCC_EYE);
    ipcc->sock = -1;
   
    /* Connect if we can */
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0) {
		wtof("%s: Unable to create socket.", __func__);
		goto failed;
	}
	
	sockaddr_in.sin_family 		= AF_INET;
	sockaddr_in.sin_port   		= htons(port);
	sockaddr_in.sin_addr.s_addr = htonl(addr);

	rc = connect(sock, &sockaddr_in, len);
	if (rc < 0) {
        unsigned char *c = (unsigned char *)&addr;
		int error = errno;
		wtof("%s: Connect failed for %u.%u.%u.%u port %u %s", 
			__func__, c[0], c[1], c[2], c[3], port, strerror(error));
		closesocket(sock);
		goto failed;
	}

    /* Success */
    ipcc->ipc  = ipc;               /* IPC handle or NULL       */
    ipcc->sock = sock;              /* Channel socket number    */
    ipcc->addr = addr;              /* Channel IPV4 address     */
    ipcc->port = port;              /* Channel port number      */
    ipcc->flag = IPCC_FLAG_CONNECT; /* Created by connect()     */
    ipcc->state = IPCC_STATE_IDLE;  /* Not doing anything yet   */
    time64(&ipcc->lastused);        /* update last used time    */

    if (ipc) {
        /* Remember this channel */
        lockrc = lock(ipc, LOCK_EXC);
        array_add(&ipc->ipcc, ipcc);
        if (lockrc==0) unlock(ipc, LOCK_EXC);
    }
    
quit:
    return ipcc;

failed:
    if (ipcc) {
        free(ipcc);
        ipcc = NULL;
    }
    goto quit;
}
