#include <stdio.h>
#include <assert.h>
#include "clib64.h"

__asm__("\n&FUNC    SETC '__64_to_u32'");
uint32_t __64_to_u32(__64* n)
{
	uint32_t ret = 0;

	if (n) {
		ret = n->u32[1];
	}

	return ret;
}

