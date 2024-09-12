/* @@CMQDEL.C - cthread_queue_del()
*/
#include "clibthdi.h"

__asm__("\n&FUNC    SETC 'cthread_queue_del'");
int
cthread_queue_del(CTHDQUE **queue)
{
    int         rc      = 0;
    int         locked;
    CTHDMGR     *mgr;
    unsigned    count;
    unsigned    n;

    if (!queue) goto quit;
    if (!*queue) goto quit;

    mgr = (*queue)->mgr;
    if (mgr) {
        locked  = lock(mgr,0);
        count   = arraycount(&mgr->queue);

        for(n=0; n < count; n++) {
            if (!mgr->queue[n]) continue;

            if (mgr->queue[n] == *queue) {
                arraydel(&mgr->queue, n+1);
                break;
            }
        }
        if (locked == 0) {
            unlock(mgr,0);
        }
    }

    free(*queue);
    *queue = 0;

quit:
    return rc;
}
