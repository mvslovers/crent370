#include <clibtmr.h>

__asm__("\n&FUNC    SETC 'tqe_new'");
TQE *
tqe_new(ECB *ecb, int (*func)(void*, TQE*), void *udata, unsigned bintvl, char flags)
{
    unsigned    *psa    = (unsigned *)0;
    unsigned    *tcb    = (unsigned*)psa[0x21c/4];  /* TCB      == PSATOLD  */
    unsigned    *ascb   = (unsigned *)psa[0x224/4]; /* ascb     == PSAAOLD  */
    unsigned    asid    = ((ascb[0x24/4]) >> 16);
    TQE         *tqe    = calloc(1, sizeof(TQE));

    if (tqe) {
        strcpy(tqe->eye, TQE_EYE);
        tqe->flags      = flags;
        tqe->asid       = asid;
        tqe->tcb        = tcb;
        tqe->expires    = tmr_secs(NULL) + ((TMRSEC)bintvl / 100.0);
        tqe->bintvl     = bintvl;
        tqe->ecb        = ecb;
        tqe->func       = func;
        tqe->udata      = udata;
        tqe->id         = tmr_id();
        /* wtof("%s TQE(%08X) TQEID(%u) BINTVL(%u) EXPIRES(%.6f)", __func__, tqe, tqe->id, bintvl, tqe->expires); */
    }

    return tqe;
}
