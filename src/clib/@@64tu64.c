#include <stdio.h>
#include <assert.h>
#include "clib64.h"

__asm__("\n&FUNC    SETC '__64_to_u64'");
uint64_t __64_to_u64(__64* n)
{
	uint64_t ret = 0;

	if (n) {
		ret = n->u64;
	}

	return ret;
}

