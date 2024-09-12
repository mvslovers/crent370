#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <time64.h>

__asm__("\n&FUNC    SETC '__getclk64'");
uint64_t __getclk64(void)
{
	time64_t	clock;

__asm__("LA\t2,%0\tget address of 8 byte work area\n\t"
       	"STCK\t0(2)\tstore clock into work area\n\t"
		: "=m" (clock.u64) : : "2");

	clock.u64 >>=12;
	__64_sub_ull(&clock, 0x0007D91000000000ULL, &clock);
	__64_div_int(&clock, 1000000, &clock);
	__64_sub_int(&clock, 1220, &clock);

	return clock.u64;
}

#if 0
int main(int argc, char **argv)
{
	unsigned 	work[2] = {0,0};
	time_t		t 		= __getclk(work);
	time64_t 	t64 	= __getclk64();

	printf("%s:     t=0x00000000%08X (%d)\n", __func__, t, t);
	printf("%s:   t64=0x%016llX (%lld)\n", __func__, t64, t64);

	return 0;
}
#endif

