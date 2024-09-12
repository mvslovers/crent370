#include <clibtmr.h>

__asm__("\n&FUNC    SETC 'tqe_purge'");
int tqe_purge(TQEID id)
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
            /* remove TQE from TMR handle */
            array_del(&tmr->tqe, n+1);

            /* release TQE storage */
            free(tqe);

            /* success */
            rc = 0;
            break;
        }
    }
    if (lockrc==0) unlock(tmr, 0);

    return rc;
}
