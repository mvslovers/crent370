#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <time64.h>

__asm__("\n&FUNC    SETC 'mclock64'");
mclock64_t mclock64(void)
{
	__64	clock;

__asm__("LA\t2,%0\tget address of 8 byte work area\n\t"
       	"STCK\t0(2)\tstore clock into work area\n\t"
		: "=m" (clock.u64) : : "2");

    /* make Jan 1 1900 (STCK) relative to Jan 1 1970 (unix epoch) */
    clock.u64 -=  0x7D91048BCA000000ULL;  /* STCK value for Jan 1 1970 */

    /* convert to microseconds (bits 0-51==number of microseconds) */
    clock.u64 >>= 12; /* convert to microseconds (1 us = .000001 sec) */

    /* convert the microseconds value (.000001 seconds) 
     * to miliseconds (.001 seconds), divide by 1000 */
	__64_div_u32(&clock, 1000, &clock);

	return (mclock64_t) clock.u64;
}
