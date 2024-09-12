/* @@CS.C - compare and swap
*/
#include "clibos.h"

unsigned __cs(void *mem, unsigned new_value)
{
    unsigned  old_value = 0;

    if (!mem) goto quit;

    __asm__("\n"
"AGAIN    DS    0H\n"
"         L     0,0(,%1)    get current value\n"
"         L     1,0(,%2)    get new value\n"
"         CS    0,1,0(%1)   save new value in memory\n"
"         BNZ   AGAIN       changed, try again\n"
"         ST    0,%0        return value"
        : "=m"(old_value) : "r"(mem), "r"(new_value));

quit:
    return old_value;
}
