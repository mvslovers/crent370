/* @@CPPOIN.C - Point JES Checkpoint Dataset */
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "clibwto.h"
#include "osdcb.h"
#include "osjfcb.h"
#include "clibcp.h"     /* JES Checkpoint prototypes and functions            */

int __cppoin(HASPCP *cp, unsigned TTRz)
{
    int     rc      = -1;

    if (cp) {
        DCB     *dcb    = cp->dcb;

        if (dcb->dcboflgs & DCBOFOPN) {
            __asm("POINT\t(%0),(%1)" : : "r"(dcb), "r"(&TTRz));
            rc = 0;
        }
    }

    return rc;
}
