/* @@CIBSET.C */
#include "clibcib.h"

int
__cibset(unsigned count)
{
    int     rc      = 0;
    COM     *com    = __gtcom();

    if (count) {
        __asm__("QEDIT ORIGIN=(%1),CIBCTR=(%2)\n\tLR\t%0,15"
            : "=r" (rc) : "r" (&com->comcibpt), "r" (count));
    }

quit:
    return rc;
}
