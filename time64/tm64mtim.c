#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <time64.h>

mtime64_t mtime64(mtime64_t *mtimer)
{
    mtime64_t tt;

    tt.u64 = mclock64();

	if (mtimer) *mtimer = tt;

    return tt;
}

