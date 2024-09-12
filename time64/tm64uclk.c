#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <time64.h>

__asm__("\n&FUNC    SETC 'uclock64'");
uclock64_t uclock64(void)
{
	uclock64_t	clock;

__asm__("LA\t2,%0\tget address of 8 byte work area\n\t"
       	"STCK\t0(2)\tstore clock into work area\n\t"
		: "=m" (clock) : : "2");

    /* make Jan 1 1900 (STCK) relative to Jan 1 1970 (unix epoch) */
    clock -=  0x7D91048BCA000000ULL;  /* STCK value for Jan 1 1970 */

    /* convert to microseconds (bits 0-51==number of microseconds) */
    clock >>= 12; /* convert to microseconds (1 us = .000001 sec) */

	return clock;
}

