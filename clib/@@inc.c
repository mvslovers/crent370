/* @@INC.C - increment signed value via compare and swap
*/
#include "clibos.h"

int __inc(void *mem)
{
    int  old_value = 0;

    if (!mem) goto quit;

    __asm__("\n"
"AGAIN    DS    0H\n"
"         L     0,0(,%1)    get current value\n"
"         LR    1,0         copy for new value\n"
"         C     1,=F'2147483647'  max value?\n"
"         BNE   INCIT       no, bump it up\n"
"         SR    1,1         reset to zero\n"
"         B     SWAPIT\n"
"INCIT    DS    0H\n"
"         A     1,=F'1'     increment new value\n"
"SWAPIT   DS    0H\n"
"         CS    0,1,0(%1)   save new value in memory\n"
"         BNZ   AGAIN       changed, try again\n"
"         ST    0,%0        return value"
        : "=m"(old_value) : "r"(mem));

quit:
    return old_value;
}
