/* @@UDEC.C - decrement unsigned value via compare and swap
*/
#include "clibos.h"

unsigned __udec(void *mem)
{
    unsigned  old_value = 0;

    if (!mem) goto quit;

    __asm__("\n"
"AGAIN    DS    0H\n"
"         L     0,0(,%1)    get current value\n"
"         LR    1,0         copy for new value\n"
"         C     1,=F'0'     min value?\n"
"         BNE   DECIT       no, decrement\n"
"         L     1,=F'-1'    reset to max value\n"
"         B     SWAPIT\n"
"DECIT    DS    0H\n"
"         SL    1,=F'1'     decrement new value\n"
"SWAPIT   DS    0H\n"
"         CS    0,1,0(%1)   save new value in memory\n"
"         BNZ   AGAIN       changed, try again\n"
"         ST    0,%0        return value"
        : "=m"(old_value) : "r"(mem));

quit:
    return old_value;
}
