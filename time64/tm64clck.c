#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <time64.h>

__asm__("\n&FUNC    SETC 'clock64'");
clock64_t clock64(void)
{
	time64_t	clock;

__asm__("LA\t2,%0\tget address of 8 byte work area\n\t"
       	"STCK\t0(2)\tstore clock into work area\n\t"
		: "=m" (clock.u64) : : "2");

#if 0 /* accurate but slightly slower */

	clock.u64 >>=12;
	__64_sub_u64(&clock, 0x0007D91000000000ULL, &clock);
	__64_div_i32(&clock, 1000000, &clock);
	__64_sub_i32(&clock, 1220, &clock);

#else /* accurate and a little faster */

    /* make Jan 1 1900 (STCK) relative to Jan 1 1970 (unix epoch) */
    clock.u64 -=  0x7D91048BCA000000ULL;  /* STCK value for Jan 1 1970 */

    /* convert to microseconds (bits 0-51==number of microseconds) */
    clock.u64 >>= 12; /* convert to microseconds (1 us = .000001 sec) */

#if 0
    /* calc seconds by discarding the microseconds (divide by 1000000) */
	__64_div_u32(&clock, 1000000, &clock);
#else
    /* convert microseconds to miliseconds (divide by 1000) 
     * Note: 1000000 microseconds == 1 second.
     * 		    1000 miliseconds  == 1 second 
     */
	__64_div_u32(&clock, 1000, &clock);	/* CLOCKS_PER_SECOND is 1000 */
#endif

#endif
	return (clock64_t) clock.u64;
}

#if 0
int main(int argc, char **argv)
{
	unsigned 	work[2] = {0,0};
	time_t		t 		= __getclk(work);
	clock64_t 	t64 	= clock64();

	printf("%s:     t=0x00000000%08X (%d)\n", __func__, t, t);
	printf("%s:   t64=0x%016llX (%lld)\n", __func__, t64, t64);

	return 0;
}
#endif

