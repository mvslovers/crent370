/* @@CMWADD.C - cthread_worker_add()
*/
#include "clibthdi.h"

__asm__("\n&FUNC    SETC 'cthread_worker_add'");
int
cthread_worker_add(CTHDMGR *mgr)
{
    int         rc      = -1;
    int         locked;
    CTHDWORK    *work;

    if (!mgr) goto quit;

    locked = lock(mgr,0);

    if (mgr->state == CTHDMGR_STATE_QUIESCE) goto unlock;
    if (mgr->state == CTHDMGR_STATE_STOPPED) goto unlock;

    work = calloc(1, sizeof(CTHDWORK));
    if (!work) {
        rc = -1;
        goto unlock;
    }

    strcpy(work->eye, CTHDWORK_EYE);
    work->mgr           = mgr;
    work->state         = CTHDWORK_STATE_INIT;
    work->start_time    = time64(NULL);

    arrayadd(&mgr->worker, work);

    work->task = cthread_create_ex(mgr->func, mgr->udata, work, mgr->stacksize);
    if (!work->task) {
        cthread_worker_del(&work);
        goto quit;
    }

    rc = 0;

unlock:
    if (locked==0) {
        unlock(mgr,0);
    }

quit:
    return rc;
}
