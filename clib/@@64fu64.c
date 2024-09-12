#include <stdio.h>
#include "clib64.h"

__asm__("\n&FUNC    SETC '__64_from_u64'");
void __64_from_u64(__64* n, uint64_t u64)
{
	if (n) {
		n->u64 = u64;
	}
	/* wtof("%s: n=%08X, u64=%016llX, n->u64=%016llX (%llu)", __func__, n, u64, *n, *n); */
}


