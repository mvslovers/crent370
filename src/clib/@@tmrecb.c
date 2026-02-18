#include <clibtmr.h>

__asm__("\n&FUNC    SETC 'tmr_ecb'");
TQEID tmr_ecb(ECB *ecb, unsigned bintvl)
{
    TMR         *tmr    = tmr_get();
    TQE         *tqe    = NULL;
    TQEID       id      = 0;
    int         lockrc;

    tmr_start();

    tqe = tqe_new(ecb, NULL, NULL, bintvl, 0);
    if (tqe) {
        id = tqe->id;

        lockrc = lock(tmr, 0);
        array_add(&tmr->tqe, tqe);
        ecb_post(&tmr->wakeup, 0);
        if (lockrc==0) unlock(tmr, 0);
    }

    return id;
}
