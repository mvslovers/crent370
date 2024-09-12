#include <stdio.h>
#include <string.h>
#include <clib64.h>

__asm__("\n&FUNC    SETC '__64_lshift_one_bit'");
void __64_lshift_one_bit(__64* a)
{
	if (a) {
#if 1	/* gccmvs uses SLDA for unsigned 64 bit value, so we'll use 32 bit shifts instead */
		a->u32[0] = a->u32[0] << 1 | a->u32[1] >> 31;
		a->u32[1] <<= 1;
#else
		int i;

		for (i = 0; i < (__64_ARRAY_SIZE-1); i++) {
			a->array[i] = (a->array[i] << 1) | (a->array[i + 1] >> ((8 * __64_WORD_SIZE) - 1));
		}
		a->array[__64_ARRAY_SIZE-1] <<= 1;
#endif
	}
}

