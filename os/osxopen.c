/* OSXOPEN.C - open DD for EXCP access */
#include <ctype.h>
#include <stdlib.h>
#include "osio.h"
#include "clibstae.h"

static void opendcb(DCB *dcb, int typej, int *rc);

int
osxopen(DCB *dcb, int typej)
{
    int         rc;
    JFCB        jfcb = {0};

    /* use try() in case of abend */
    try(opendcb, dcb, typej, &rc);

    /* make sure the dataset was opened */
    if (!(dcb->dcboflg & DCBOFOPN)) {
        rc = 8;    /* dataset not open */
    }

    if (rc) {
        goto quit;
    }

    /* DCB's for EXCP access do not fill in the BSAM/QSAM related fields
    ** so we'll use RDJFCB to get those field values and populate the
    ** remaining DCB fields that we might find useful.
    */

    /* get dataset information */
    rdjfcb(dcb, &jfcb);

    dcb->dcbblksi = jfcb.jfcblksi;
    dcb->dcblrecl = jfcb.jfclrecl;

quit:
    return rc;
}

__asm__("\n&FUNC    SETC 'opendcb'");
static void
opendcb(DCB *dcb, int typej, int *rc)
{
    unsigned    plist   = 0x84000000 | (unsigned)dcb;   /* UPDATE access */

    if (!typej) {
        /* normal OPEN for a single dataset */
        __asm__("LR    1,%1\n\tSVC   19         OPEN\n\tST\t15,0(,%0)"
            : : "r"(rc), "r"(&plist) : "1", "14", "15");
    }
    else {
        /* OPEN type J for a single dataset */
        __asm__("LR    1,%1\n\tSVC   22         OPENJ\n\tST\t15,0(,%0)"
            : : "r"(rc), "r"(&plist) : "1", "14", "15");
    }

    return;
}
