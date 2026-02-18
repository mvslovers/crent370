#include <stdio.h>
#include "clib64.h"

__asm__("\n&FUNC    SETC '__64_from_i32'");
void __64_from_i32(__64* n, int32_t i)
{
	if (n) {
		n->u32[0] = 0;
		n->u32[1] = 0;
		if (i < 0) {
			__64_sub_u32(n, (uint32_t)(-i), n);	/* make i positive value */
		}
		else {
			n->u32[1] = (uint32_t)i;
		}
	}
}

