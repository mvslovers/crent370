#include <clibtmr.h>

__asm__("\n&FUNC    SETC 'tqe_enable'");
int tqe_enable(TQEID id)
{
    int         rc      = ENOENT;   /* default, not found */
    TMR         *tmr    = tmr_get();
    unsigned    count;
    unsigned    n;
    int         lockrc;

    tmr_init();

    lockrc = lock(tmr, 0);
    count = array_count(&tmr->tqe);
    for(n=0; n < count; n++) {
        TQE *tqe = tmr->tqe[n];

        if (!tqe) continue;
        if (tqe->id == id) {
            /* reset the disabled flag */
            tqe->flags &= ~TQE_FLAG_DISABLED;

            if (tqe->bintvl) {
                /* reset the TQE expires value */
                tqe->expires = tmr_secs(NULL) + ((TMRSEC)tqe->bintvl / 100.0);

                /* wakeup the timer thread */
                ecb_post(&tmr->wakeup, 0);
            }

            /* success */
            rc = 0;
            break;
        }
    }
    if (lockrc==0) unlock(tmr, 0);

    return rc;
}
