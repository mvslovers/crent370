/* @@CMWSHU.C - cthread_worker_shutdown()
*/
#include "clibthdi.h"

__asm__("\n&FUNC    SETC 'cthread_worker_shutdown'");
int
cthread_worker_shutdown(CTHDWORK *work)
{
    int         rc      = 0;
    int         i;
    CTHDTASK    *task;

    if (!work) goto quit;
#if 0
    wtof("__cmwshu() shutdown of worker thread %08X, task %08X starting", work, work->task);
#endif

    /* if the worker has already stopped then we're done */
    task = work->task;
    if (task) {
        if (task->termecb & 0x40000000) {
            /* subtask has terminated */
            if (task->tcb) cthread_detach(task);
            goto quit;
        }
    }

#if 0
    wtof("__cmwshu() posting work wait ecb %08X", work->wait);
#endif
    /* post the worker thread for shutdown */
    cthread_post(&work->wait, CTHDWORK_POST_SHUTDOWN);
#if 0
    wtof("__cmwshu() posted work wait ecb %08X", work->wait);
#endif

    if (task && task->tcb) {
        /* we have a subtask */
#if 0
        wtof("__cmwshu() shutdown of task %08X starting", task);
#endif
        for(i=0; i < 50; i++) {
            if (task->termecb & 0x40000000) {
                /* subtask has terminated */
                if (task->tcb) cthread_detach(task);
                goto quit;
            }
#if 0
            wtof("__cmwshu() shutdown waiting for task %08X termination", task);
#endif
#if 0
            wtof("__cmwshu() posting work wait ecb %08X", work->wait);
#endif
            cthread_post(&work->wait, CTHDWORK_POST_SHUTDOWN);
#if 0
            wtof("__cmwshu() posted work wait ecb %08X", work->wait);
#endif
            __asm__("STIMER WAIT,BINTVL==F'10'   0.10 seconds");
        }
        /* unable to shutdown subtask, abend the subtask */
#if 0
        wtof("__cmwshu() detaching task %08X to force termination", task);
#endif
        if (task->tcb) cthread_detach(task);
    }

quit:
    return rc;
}
