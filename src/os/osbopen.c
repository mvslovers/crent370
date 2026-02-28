/* OSBOPEN.C - open DCB for "read", "write" or "update" access mode */
#include "osio.h"
#include "clibstae.h"

static void opendcb(DCB *dcb, int typej, int *rc);

int
osbopen(DCB *dcb, int typej, const char *mode)
{
    int         rc      = -1;

#if 0
    wtof("osbopen dcb=%08X, typej=%d, mode=%s",
        dcb, typej, mode ? mode : "(null)");
#endif
    if (!dcb) goto quit;

    if (mode) {
        /* reset DCB MACRF options */
        switch (mode[0]) {
        case 'r':   /* read access */
        case 'R':
        case 'i':   /* input access */
        case 'I':
            dcb->dcbmacr1 = DCBMRRD;
            dcb->dcbmacr2 = 0;
            break;
        case 'w':   /* write access */
        case 'W':
        case 'o':   /* output access */
        case 'O':
            dcb->dcbmacr1 = 0;
            dcb->dcbmacr2 = DCBMRWRT;
            break;
        case 'l':   /* load access */
        case 'L':
            dcb->dcbmacr1 = 0;
            dcb->dcbmacr2 = DCBMRWRT + DCBMRLDM; /* MACRF=(WL) */
            break;
        case 'u':   /* update access */
        case 'U':
            dcb->dcbmacr1 = DCBMRRD;
            dcb->dcbmacr2 = DCBMRWRT;
            break;
        }
    }

    /* use try() in case of abend */
    rc = try(opendcb, dcb, typej, &rc);
    if (rc) goto quit;

    /* make sure the dataset was opened */
    if (!(dcb->dcboflg & DCBOFOPN)) {
        rc = 8;    /* dataset not open */
    }

quit:
    return rc;
}

__asm__("\n&FUNC    SETC 'opendcb'");
static void
opendcb(DCB *dcb, int typej, int *rc)
{
    unsigned    plist   = 0x80000000 | (unsigned)dcb;

    if (dcb->dcbmacr2 & DCBMRWRT) {
        /* write enabled */
        if (dcb->dcbmacr1 & DCBMRRD) {
            /* and read enabled */
            plist |= 0x04000000;    /* UPDATE access */
        }
        else {
            /* write only */
            plist |= 0x0F000000;    /* OUTPUT access */
        }
    }

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

__asm("OPEN ((2),OUTPUT)");
