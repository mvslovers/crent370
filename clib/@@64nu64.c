#include <stdio.h>
#include <string.h>
#include <clib64.h>

__asm__("\n&FUNC    SETC '__64_and_u64'");
void __64_and_u64(__64* a, uint64_t b, __64* c)
{
	__64	tmp;

	if (a && c) {
		__64_from_u64(&tmp, b);

#if 1	/* gccmvs can AND 64 bit values */
		c->u64 = a->u64 & tmp.u64;
#else
		__64_and(a, &tmp, c);
#endif
	}
}

