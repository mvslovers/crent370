/* OSDREAD.C - read one block from BDAM dataset by relative block number */
#include "osio.h"

int
osdread(DECB *decb, DCB *dcb, void *buf, int length, unsigned block)
{
    int     rc = 0;
    char    *rec = (char*)&block;

    if (length > 0) {
        dcb->dcbblksi = (unsigned short)length;
    }
    else {
        length = (int) dcb->dcbblksi;
    }

    __asm__("\n"
"         READ (%1),DI,(%2),(%3),(%4),0,(%5),MF=E\n"
"         LR    %0,15"
        : "=r"(rc) : "r"(decb), "r"(dcb), "r"(buf), "r"(length), "r"(rec+1)
        : "0", "1", "14", "15");

quit:
    return rc;
}
