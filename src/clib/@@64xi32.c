#include <stdio.h>
#include <string.h>
#include <clib64.h>

__asm__("\n&FUNC    SETC '__64_xor_i32'");
void __64_xor_i32(__64* a, int32_t b, __64* c)
{
	__64	tmp;

	if (a && c) {
		__64_from_i32(&tmp, b);

#if 1	/* gccmvs can XOR 64 bit values */
		c->u64 = a->u64 ^ tmp.u64;
#else
		__64_xor(a, &tmp, c);
#endif
	}
}

