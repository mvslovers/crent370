#include <clibtmr.h>

__asm__("\n&FUNC    SETC 'tmr_func_every'");
TQEID tmr_func_every(int (*func)(void *, TQE*), void *udata, unsigned bintvl)
{
    TMR         *tmr    = tmr_get();
    TQE         *tqe    = NULL;
    TQEID       id      = 0;
    int         lockrc;

    tmr_start();

    tqe = tqe_new(NULL, func, udata, bintvl, TQE_FLAG_KEEP + TQE_FLAG_RESET);
    if (tqe) {
        id = tqe->id;

        lockrc = lock(tmr, 0);
        array_add(&tmr->tqe, tqe);
        ecb_post(&tmr->wakeup, 0);
        if (lockrc==0) unlock(tmr, 0);
    }

    return id;
}


