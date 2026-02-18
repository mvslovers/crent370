/* @@ECBTW.C - ecb_timed_wait()
*/
#include <clibecb.h>

__asm__("\n&FUNC    SETC 'ecb_timed_wait'");
int
ecb_timed_wait(ECB *ecb, unsigned bintvl, unsigned postcode)
{
    ECB     *ecblist[1] = {(void*)((unsigned)ecb | 0x80000000)};

    return ecb_timed_waitlist(ecblist, ecb, bintvl, postcode);
}
