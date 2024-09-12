/* @@CPREAD.C - Read JES Checkpoint Dataset */
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "clibwto.h"
#include "osdcb.h"
#include "osjfcb.h"
#include "clibcp.h"     /* JES Checkpoint prototypes and functions            */

int __cpread(HASPCP *cp, void *buf4k)
{
    int         rc      = -1;

    if (cp) {
        DCB         *dcb    = cp->dcb;
        unsigned    decb[4] = {0};

        if (dcb->dcboflgs & DCBOFOPN) {
            __asm("READ  (%0),SF,(%1),(%2),4096,MF=E READ FIRST RECORD\n\t"
                  "CHECK (%0)" : : "r"(decb), "r"(dcb), "r"(buf4k));
            rc = 0;
        }
    }

    return rc;
}

