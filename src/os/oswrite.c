/* OSWRITE.C - write to dataset */
#include "osio.h"

int
oswrite(DECB *decb, DCB *dcb, void *buf, int length)
{
    int     rc = 0;
#if 0
    wtof("oswrite decb=%08X, dcb=%08X, buf=%08X, length=%d",
        decb, dcb, buf, length);
#endif

    if (length > 0) {
        dcb->dcbblksi = (unsigned short)length;
    }
    else {
        length = (int) dcb->dcbblksi;
    }

    __asm__("\n"
"         WRITE (%1),SF,(%2),(%3),(%4),MF=E\n"
"         LR    %0,15"
        : "=r"(rc) : "r"(decb), "r"(dcb), "r"(buf), "r"(length)
        : "0", "1", "14", "15");

quit:
    return rc;
}
