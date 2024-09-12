/* @@ECBWL.C - ecb_waitlist()
*/
#include <clibecb.h>

__asm__("\n&FUNC    SETC 'ecb_waitlist'");
int
ecb_waitlist(ECB **ecblist)
{
    /* wait for ECB post */
    __asm__("WAIT ECBLIST=(%0)" : : "r"(ecblist) : "0", "1", "14", "15");

    return 0;
}
