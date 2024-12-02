#include "ipci.h"

void ipc_free_channel(IPCC **pipcc)
{
    IPCC        *ipcc;
    IPC         *ipc;
    unsigned    n, count;
    int         lockrc;
    
    if (!pipcc) goto quit;

    ipcc = *pipcc;
    if (!ipcc) goto quit;
    
    /* if we have an IPC handle, remove channel from IPC */
    ipc = ipcc->ipc;
    if (ipc) {
        lockrc = lock(ipc, LOCK_EXC);

        /* find channel handle in channel array */
        count = array_count(&ipc->ipcc);
        for(n=count; n > 0; n--) {
            IPCC *i = array_get(&ipc->ipcc, n);

            if (!i) continue;
            if (i==ipcc) {
                /* remove this channel from the array */
                array_del(&ipc->ipcc, n);
                break;
            }
        }
        if (lockrc==0) unlock(ipc, LOCK_EXC);
    }

    lockrc = lock(ipcc, LOCK_EXC);

    /* close socket if open */
    if (ipcc->sock >= 0)    closesocket(ipcc->sock);
    
    /* free channel name */
    if (ipcc->name)         free(ipcc->name);

    /* free array of inbound messages */
    if (ipcc->inq) {
        count = array_count(&ipcc->inq);
        for(n=count; n > 0; n--) {
            IPCM *m = ipcc->inq[n];

            if (!m) continue;
            ipc_free_message(&m);
        }
        array_free(&ipcc->inq);
    }

    /* free array of outbouond messages */
    if (ipcc->outq) {
        count = array_count(&ipcc->outq);
        for(n=count; n > 0; n--) {
            IPCM *m = ipcc->outq[n];

            if (!m) continue;
            ipc_free_message(&m);
        }
        array_free(&ipcc->outq);
    }

    /* free channel handle */
    free(ipcc);
    *pipcc = NULL;

    if (lockrc==0) unlock(ipcc, LOCK_EXC);

quit:
    return;
}
