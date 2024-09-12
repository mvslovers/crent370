#include <stdio.h>
#include "clib64.h"

__asm__("\n&FUNC    SETC '__64_from_u32'");
void __64_from_u32(__64* n, uint32_t i)
{
	if (n) {
		n->u32[0] = 0;
		n->u32[1] = i;
	}
}

