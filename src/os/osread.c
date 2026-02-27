/* OSREAD.C - read from dataset */
#include "osio.h"

void
osread(DECB *decb, DCB *dcb, void *buf, int length)
{
    __asm__("\n"
"         READ  (%0),SF,(%1),(%2),(%3),MF=E"
        : : "r"(decb), "r"(dcb), "r"(buf), "r"(length)
        : "0", "1", "14", "15");

quit:
    return;
}
