#include <stdio.h>
#include <string.h>
#include <clib64.h>

__asm__("\n&FUNC    SETC '__64_xor'");
void __64_xor(__64* a, __64* b, __64* c)
{
	if (a && b && c) {
#if 1	/* gccmvs can XOR 64 bit values */
		c->u64 = a->u64 ^ b->u64;
#else
		int i;

		for (i = 0; i < __64_ARRAY_SIZE; ++i) {
			c->array[i] = (a->array[i] ^ b->array[i]);
		}
#endif
	}
}

