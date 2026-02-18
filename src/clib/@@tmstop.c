#include <clibtmr.h>

__asm__("\n&FUNC    SETC 'tmr_stop'");
int tmr_stop(void)
{
    TMR         *tmr    = tmr_get();
    int         lockrc;
    int         i;

    /* initialize the timer handle if needed */
    tmr_init();

    /* if we have a timer thread that is running, quiesce it */
    lockrc = lock(tmr, 0);
    if (tmr->task && (tmr->flags & TMR_FLAG_RUNNING)) {
        wtof("%s QUIESCE posted", __func__);
        tmr->flags |= TMR_FLAG_QUIESCE;
        ecb_post(&tmr->wakeup, 0);
    }
    if (lockrc==0) unlock(tmr, 0);

    /* if we have a timer thread that is quiesced, shut it down */
    lockrc = lock(tmr, 0);
    if (tmr->task && (tmr->flags & TMR_FLAG_RUNNING)) {
        wtof("%s SHUTDOWN posted", __func__);
        tmr->flags |= TMR_FLAG_SHUTDOWN;
        ecb_post(&tmr->wakeup, 0);
    }
    if (lockrc==0) unlock(tmr, 0);

    /* if we have a timer thread that is shut down, delete it */
    lockrc = lock(tmr, 0);
    if (tmr->task && (tmr->flags & TMR_FLAG_SHUTDOWN)) {
        wtof("%s thread DELETE", __func__);
        cthread_delete(&tmr->task);
        tmr->task = NULL;
    }
    if (lockrc==0) unlock(tmr, 0);

    /* if we have a timer thread that has not shut down, detach it */
    lockrc = lock(tmr, 0);
    if (tmr->task && !(tmr->flags & TMR_FLAG_SHUTDOWN)) {
        wtof("%s thread DETACH", __func__);
        cthread_detach(tmr->task);
        tmr->task = NULL;
    }
    if (lockrc==0) unlock(tmr, 0);

quit:
    return 0;
}
