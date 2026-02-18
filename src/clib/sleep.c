#include <clibecb.h>

int
sleep(unsigned seconds)
{
#if 0
    /* 1 BINTVL == .01 seconds */
    int         t       = seconds * 100;  /* convert to hundreths of a second */
#else
    unsigned    timeout_ecb = 0;
#endif
#if 0
    unsigned    *psa    = 0;                            /* low core == PSA      */
    unsigned    *tcb    = (unsigned*)psa[0x21c/4];      /* TCB      == PSATOLD  */

    wtof("%s(%u) TCB(%06X) SLEEPING", __func__, seconds, tcb);
#endif

    if (seconds > 0) {
#if 0
        __asm__("STIMER WAIT,BINTVL=(%0)"
                : : "r"(&t): "0", "1", "14", "15");
#else
        ecb_timed_wait(&timeout_ecb, seconds * 100, 0);
#endif
    }
#if 0
    wtof("%s(%u) TCB(%06X) AWAKE", __func__, seconds, tcb);
#endif
    return 0;
}
