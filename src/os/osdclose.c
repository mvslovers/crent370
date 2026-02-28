/* OSDCLOSE.C - close DCB with options or free of DCB
*/
#include <stdlib.h>
#include <string.h>
#include "osio.h"

void
osdclose(DCB *dcb, int freedcb)
{
    unsigned    plist;

    if (!dcb) goto quit;

    plist = 0x80000000 | (unsigned)dcb;     /* default opt=disp */

    /* normal close */
    __asm__("LR    1,%0\n\tSVC   20         CLOSE"
        : : "r"(&plist) : "1", "14", "15");

    /* if caller is done with DCB area we'll free it now */
    if (freedcb) {
        free(dcb);
    }

quit:
    return;
}
