#include <clibtmr.h>

__asm__("\n&FUNC    SETC 'tmr_start'");
int tmr_start(void)
{
    TMR         *tmr    = tmr_get();
    CTHDTASK    *task   = NULL;
    int         rc      = 0;
    int         lockrc;
    int         running;
    int         i;

    /* initialize the timer handle if needed */
    tmr_init();

    /* if we don't have a timer thread, create one now */
    lockrc = lock(tmr, 0);
    if (!tmr->task) {
        task = cthread_create_ex(tmr_thread, tmr, NULL, 32*1024);
        if (!task) {
            wtof("%s unable to create timer thread", __func__);
            rc = ENOMEM;
        }
        else {
            tmr->task = task;
            if (lockrc==0) unlock(tmr, 0);
            cthread_yield();
            lockrc = 8; /* prevent next unlock since we're already unlocked */
        }
    }
    if (lockrc==0) unlock(tmr, 0);

    if (rc) goto quit;

    if (task) {
        /* we created a new timer task */
        for(i=0; i < 100; i++) {
            lockrc = lock(tmr, 0);
            running = (tmr->flags & TMR_FLAG_RUNNING);
            if (lockrc==0) unlock(tmr, 0);

            if (running) break;

            if ((i & 3) == 3) wtof("%s waiting for timer thread to start", __func__);
            cthread_yield();
        }

        if (i == 100) {
            wtof("%s timer thread failed to start", __func__);
            lockrc = lock(tmr, 0);
            cthread_delete(&tmr->task);
            tmr->flags &= ~TMR_FLAG_RUNNING;
            if (lockrc==0) unlock(tmr, 0);
            rc = ENOMEM;
        }
    }

quit:
    return rc;
}
