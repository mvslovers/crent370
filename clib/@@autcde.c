#include <clib.h>

__asm__("\n&FUNC    SETC 'clib_auth_cde'");
int
clib_auth_cde(CDE *cde)
{
    int     rc = 0;

    if (cde) {
        __asm__("MODESET KEY=ZERO,MODE=SUP\n" : : : "0", "1", "14", "15");
        cde->CDATTR2 |= (CDSYSLIB | CDAUTH);
        __asm__("MODESET KEY=NZERO,MODE=PROB" : : : "0", "1", "14", "15");
    }

    return rc;
}
