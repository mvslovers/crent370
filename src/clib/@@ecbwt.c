/* @@ECBWT.C - ecb_wait()
*/
#include <clibecb.h>

__asm__("\n&FUNC    SETC 'ecb_wait'");
int
ecb_wait(ECB *ecb)
{
    __asm__("WAIT\tECB=(%0)" : : "r"(ecb) : "1", "14", "15");

    return 0;
}
