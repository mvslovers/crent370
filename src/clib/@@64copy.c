#include <stdio.h>
#include <string.h>
#include <clib64.h>

__asm__("\n&FUNC    SETC '__64_copy'");
void __64_copy(__64 *src, __64* dst)
{
	if (src && dst) {
#if 1	/* gccmvs can copy 64 bit values */
		dst->u64 = src->u64;
#else
		int i;

		for (i = 0; i < __64_ARRAY_SIZE; ++i) {
			dst->array[i] = src->array[i];
		}
#endif
	}
}

