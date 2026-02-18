#include <stdio.h>
#include <assert.h>
#include "clib64.h"

__asm__("\n&FUNC    SETC '__64_to_i32'");
int32_t __64_to_i32(__64* n)
{
	int32_t ret = 0;

	if (n) {
		ret = (int) (n->u32[1] & 0x7FFFFFFF);
	}

	return ret;
}

