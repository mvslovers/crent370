#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <time64.h>

__asm__("\n&FUNC    SETC 'utime64'");
utime64_t utime64(utime64_t *utimer)
{
    utime64_t tt;

    tt.u64 = uclock64();

	if (utimer) *utimer = tt;

    return tt;
}

