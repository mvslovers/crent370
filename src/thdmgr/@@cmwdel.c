/* @@CMWDEL.C - cthread_worker_del()
*/
#include "clibthdi.h"

#if 0
static void
dumpwork(CTHDMGR *mgr)
{
    unsigned    count   = arraycount(&mgr->worker);
    unsigned    n;

    for(n=0; n < count; n++) {
        wtof("worker#%u = %08X", n+1, mgr->worker[n]);
    }
}
#endif

__asm__("\n&FUNC    SETC 'cthread_worker_del'");
int
cthread_worker_del(CTHDWORK **work)
{
    int         rc      = 0;
    int         locked;
    CTHDMGR     *mgr;
    CTHDTASK    *task;
    CTHDQUE     *queue;
    unsigned    ecb;
    unsigned    count;
    unsigned    n;

    if (!work) goto quit;
    if (!*work) goto quit;

    mgr = (*work)->mgr;
    if (mgr) {
        locked  = lock(mgr,0);
        count   = arraycount(&mgr->worker);

        for(n=0; n < count; n++) {
            if (!mgr->worker[n]) continue;

            if (mgr->worker[n] == *work) {
#if 0
                wtof("worker count %u, about to delete worker %u",
                    count, n+1);
                dumpwork(mgr);
#endif
                arraydel(&mgr->worker, n+1);
#if 0
                count = arraycount(&mgr->worker);
                wtof("worker count now %u", count);
                dumpwork(mgr);
#endif
                break;
            }
        }
        if (locked==0) {
            unlock(mgr,0);
        }
    }

    ecb = (*work)->wait;
    if (ecb & 0x80000000) {
        cthread_worker_shutdown(*work);
    }

    task = (*work)->task;
    if (task) {
        cthread_delete(&task);
        (*work)->task = 0;
    }

    queue = (*work)->queue;
    if (queue) {
        /* delete the orphaned queue item */
        cthread_queue_del(&queue);
        (*work)->queue = 0;
    }

    free(*work);
    *work = 0;

quit:
    return rc;
}
