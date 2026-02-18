/* @@CMQADD.C - cthread_queue_add()
*/
#include "clibthdi.h"

__asm__("\n&FUNC    SETC 'cthread_queue_add'");
int
cthread_queue_add(CTHDMGR *mgr, void *data)
{
    int         rc      = 0;
    int         locked;
    CTHDQUE     *queue;

    if (!mgr) goto quit;

    locked = lock(mgr,0);

    if (mgr->state == CTHDMGR_STATE_QUIESCE) goto unlock;
    if (mgr->state == CTHDMGR_STATE_STOPPED) goto unlock;

    queue = calloc(1, sizeof(CTHDQUE));
    if (!queue) {
        rc = -1;
        goto unlock;
    }

    /* initialize queue record */
    strcpy(queue->eye, CTHDQUE_EYE);
    queue->mgr  = mgr;
    queue->data = data;

    /* add queue item to manager queue */
    arrayadd(&mgr->queue, queue);

    /* wake up the thread manager thread */
    rc = cthread_post(&mgr->wait, CTHDMGR_POST_DATA);

unlock:
    if (locked == 0) {
        unlock(mgr,0);
    }

quit:
    return rc;
}
