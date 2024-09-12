/* @@CMTERM.C - cthread_manager_term()
*/
#include "clibthdi.h"

#if 0
#define WTODEBUG    /* define for wtof() debug messages */
#endif

__asm__("\n&FUNC    SETC 'cthread_manager_term'");
int
cthread_manager_term(CTHDMGR **cthdmgr)
{
    int         rc      = 0;
    int         locked;
    CTHDMGR     *mgr;
    CTHDTASK    *task;
    unsigned    count;
    unsigned    n;

    if (!cthdmgr) goto quit;
    mgr = *cthdmgr;
#ifdef WTODEBUG
    wtof("cthmterm(%08X) enter", mgr);
#endif
    if (!mgr) goto quit;

#ifdef WTODEBUG
    wtof("cthmterm(%08X) requesting lock", mgr);
#endif
    locked = lock(mgr,0);
#ifdef WTODEBUG
    wtof("cthmterm(%08X) have lock, state=%u", mgr, mgr->state);
#endif

    if (mgr->state == CTHDMGR_STATE_RUNNING) {
        /* prevent any new work */
        mgr->state = CTHDMGR_STATE_QUIESCE;
    }

#ifdef WTODEBUG
    wtof("cthmterm(%08X) POST(CTHDMGR_POST_QUIESCE)", mgr);
#endif
    /* wake up the thread manager thread */
    cthread_post(&mgr->wait, CTHDMGR_POST_QUIESCE);
    if (locked==0) {
        unlock(mgr,0);
    }

    __asm__("STIMER WAIT,BINTVL==F'25'   0.25 seconds");
    locked = lock(mgr,0);
    if (mgr->queue) {
        count = arraycount(&mgr->queue);
#ifdef WTODEBUG
        wtof("cthmterm(%08X) queue cleanup, %u items", mgr, count);
#endif
        for(n=count; n > 0; n--) {
            CTHDQUE *queue = arrayget(&mgr->queue, n);

            if (!queue) continue;
            cthread_queue_del(&queue);
        }

        arrayfree(&mgr->queue);
    }

    /* now we stop the manager dispatcher thread */
    task = mgr->task;
#ifdef WTODEBUG
    wtof("cthmterm(%08X) stop thread manager, task(%08X)", mgr, task);
#endif
    if (task) {
        /* we have a subtask */
        if (mgr->state < CTHDMGR_STATE_QUIESCE) {
            mgr->state = CTHDMGR_STATE_QUIESCE;
        }
#ifdef WTODEBUG
        wtof("cthmterm(%08X) POST(CTHDMGR_POST_QUIESCE)", mgr);
#endif
        cthread_post(&mgr->wait, CTHDMGR_POST_QUIESCE);
        if (locked==0) {
            unlock(mgr,0);
        }

        for(n=0; n < 10; n++) {
            if (task->termecb & 0x40000000) {
                /* subtask has terminated */
                break;
            }
            __asm__("STIMER WAIT,BINTVL==F'25'   0.25 seconds");
            if (mgr->state < CTHDMGR_STATE_QUIESCE) {
                mgr->state = CTHDMGR_STATE_QUIESCE;
            }
#ifdef WTODEBUG
            wtof("cthmterm(%08X) POST(CTHDMGR_POST_QUIESCE)", mgr);
#endif
            cthread_post(&mgr->wait, CTHDMGR_POST_QUIESCE);
        }

        __asm__("STIMER WAIT,BINTVL==F'25'   0.25 seconds");
        locked = lock(mgr,0);

#ifdef WTODEBUG
        wtof("cthmterm(%08X) POST(CTHDMGR_POST_SHUTDOWN)", mgr);
#endif
        cthread_post(&mgr->wait, CTHDMGR_POST_SHUTDOWN);
        if (locked==0) {
            unlock(mgr,0);
        }

        __asm__("STIMER WAIT,BINTVL==F'25'   0.25 seconds");
        locked = lock(mgr,0);

#ifdef WTODEBUG
        wtof("cthmterm(%08X) delete task(%08X)", mgr, task);
#endif
        cthread_delete(&task);
        mgr->task = 0;
    }

    if (locked==0) {
        unlock(mgr,0);
    }

#ifdef WTODEBUG
    wtof("cthmterm(%08X) free", mgr);
#endif
    free(mgr);
    *cthdmgr = 0;

quit:
#ifdef WTODEBUG
    wtof("cthmterm exit, rc=%d", rc);
#endif
    return rc;
}
