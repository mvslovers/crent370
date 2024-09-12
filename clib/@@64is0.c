#include <stdio.h>
#include <string.h>
#include <clib64.h>

__asm__("\n&FUNC    SETC '__64_is_zero'");
int __64_is_zero(__64* n)
{
	if (n) {
#if 1	/* gccmvs can test 64 bit values */
		if (n->u64) return 0;
#else
		int i;

		for (i = 0; i < __64_ARRAY_SIZE; ++i) {
			if (n->array[i]) {
				return 0;
			}
		}
#endif
	}

	return 1;
}

