#include <clibtmr.h>

__asm__("\n&FUNC    SETC 'tqe_get'");
TQE *tqe_get(TQEID id)
{
    TMR         *tmr    = tmr_get();
    TQE         *tqe    = NULL;
    unsigned    count;
    unsigned    n;
    int         lockrc;

    tmr_init();

    lockrc = lock(tmr, 0);
    count = array_count(&tmr->tqe);
    for(n=0; n < count; n++) {
        TQE *t = tmr->tqe[n];

        if (!t) continue;
        if (t->id == id) {
            tqe = t;
            break;
        }
    }
    if (lockrc==0) unlock(tmr, 0);

    return tqe;
}
