#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <time64.h>

__asm__("\n&FUNC    SETC 'time64'");
time64_t time64(time64_t *timer)
{
    time64_t tt;

    tt.u64 = clock64();

    __64_div_u32(&tt, CLOCKS_PER_SEC, &tt);	/* scale to seconds */

	if (timer) *timer = tt;

    return tt;
}

