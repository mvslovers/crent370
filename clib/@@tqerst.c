#include <clibtmr.h>

__asm__("\n&FUNC    SETC 'tqe_reset'");
int tqe_reset(TQEID id, unsigned bintvl)
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
            /* success */
            rc = 0;

            /* set the bintvl value */
            tqe->bintvl     = bintvl;

            if (tqe->flags & TQE_FLAG_DISABLED) break;

            if (tqe->bintvl) {
                /* set the TQE expires value */
                tqe->expires = tmr_secs(NULL) + ((TMRSEC)tqe->bintvl / 100.0);

                /* wakeup the timer thread */
                ecb_post(&tmr->wakeup, 0);
            }
            break;
        }
    }
    if (lockrc==0) unlock(tmr, 0);

    return rc;
}

