#include "ipci.h"

void ipc_free_message(IPCM **pipcm)
{
    IPCM        *ipcm;
    IPCC        *ipcc;
    unsigned    n, count;
    int         lockrc;
    
    if (!pipcm) goto quit;
    
    ipcm = *pipcm;
    if (!ipcm) goto quit;

    ipcc = ipcm->ipcc;
    if (ipcc) {
        lockrc = lock(ipcc, LOCK_EXC);

        /* remove message from channel input queue */
        count = array_count(&ipcc->inq);
        for(n=count; n > 0; n--) {
            IPCM *m = array_get(&ipcc->inq, n);
            
            if (!m) continue;
            if (m==ipcm) {
                array_del(&ipcc->inq, n);
                break;
            }
        }
        
        /* remove message from channel output queue */
        count = array_count(&ipcc->outq);
        for(n=count; n > 0; n--) {
            IPCM *m = array_get(&ipcc->outq, n);
            
            if (!m) continue;
            if (m==ipcm) {
                array_del(&ipcc->outq, n);
                break;
            }
        }

        if (lockrc==0) unlock(ipcc, LOCK_EXC);
    }

    /* do we have a message header+buffer */
    if (ipcm->ipch) {
        /* yes, free it */
        free(ipcm->ipch);
        ipcm->ipch = NULL;
    }

    /* free the message handle */
    free(ipcm);
    *pipcm = NULL;

quit:
    return;
}
