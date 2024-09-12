/* @@CMWWAT.C - cthread_worker_wait()
*/
#include "clibthdi.h"

__asm__("\n&FUNC    SETC 'cthread_worker_wait'");
int
cthread_worker_wait(CTHDWORK *work, char **data)
{
    int         rc      = -1;
    CTHDMGR     *mgr;
#if 0
    wtof("cthmwwat enter");
#endif
    if (!work) goto quit;

    if (data) *data = 0;

    /* release any previous work queue item */
    cthread_queue_del(&work->queue);

    /* set worker state to waiting for work */
    work->state     = CTHDWORK_STATE_WAITING;
    work->wait_time = time64(NULL);

    /* tell the manager we're waiting for work */
    mgr = work->mgr;
    rc = cthread_post(&mgr->wait, CTHDMGR_POST_WAIT);

    /* wait for manager to give us some work */
#if 0
    wtof("cthmwwat waiting, TASK=%08X, TCB=%08X, ECB=%08X", work->task, work->task->tcb, work->wait);
#endif
    rc = cthread_wait(&work->wait);
#if 0
    wtof("cthmwwat running, TASK=%08X, TCB=%08X, ECB=%08X, RC=%d", work->task, work->task->tcb, work->wait, rc);
#endif

    /* set worker state */
    if (rc == CTHDWORK_POST_SHUTDOWN) {
        work->state = CTHDWORK_STATE_SHUTDOWN;
    }
    else {
        work->state = CTHDWORK_STATE_RUNNING;
    }

    if (data && work->queue) {
        /* give data to caller */
        *data = work->queue->data;
    }

quit:
#if 0
    wtof("cthmwwat exit, rc=%d", rc);
#endif
    return rc;
}
