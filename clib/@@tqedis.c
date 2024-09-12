#include <clibtmr.h>

__asm__("\n&FUNC    SETC 'tqe_disable'");
int tqe_disable(TQEID id)
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
            /* set the disabled flag */
            tqe->flags |= TQE_FLAG_DISABLED;

            /* success */
            rc = 0;
            break;
        }
    }
    if (lockrc==0) unlock(tmr, 0);

    return rc;
}
