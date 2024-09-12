#include <clibecb.h>
#include <clibwto.h>

__asm__("\n&FUNC    SETC 'ecb_post'");
int
ecb_post(ECB *ecb, unsigned postcode)
{
#if 0
    unsigned    *psa    = 0;                            /* low core == PSA      */
    unsigned    *tcb    = (unsigned*)psa[0x21c/4];      /* TCB      == PSATOLD  */

    wtof("%s(%08X,%08X) TCB(%08X)", __func__, ecb, postcode, tcb);
    if (ecb) {
        wtof("%s *ecb = %08X", __func__, *ecb);
        if ((unsigned)*ecb & 0x80000000) {
            wtodumpf((void*) ((unsigned)*ecb & 0x00FFFFFF), 32, "PRB");
        }
    }
    else {
        wtof("%s NULL ECB pointer", __func__);
        wto_traceback(NULL);
    }
#endif
    __asm__("POST  (%0),(%1)" : : "r"(ecb), "r"(postcode) : "1", "14", "15");

    return 0;
}
