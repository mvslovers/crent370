#include <stdio.h>
#include <string.h>
#include <clib64.h>

__asm__("\n&FUNC    SETC '__64_cmp'");
int __64_cmp(__64* a, __64* b)
{
	int		i;

	if (a && b) {
#if 1	/* gccmvs can compare 64 bit values */
		__asm__("DS\t0H\tif (a->u64 > b->u64) return __64_LARGER;");
		if (a->u64 > b->u64) return __64_LARGER;
		__asm__("DS\t0H\tif (a->u64 < b->u64) return __64_SMALLER;");
		if (a->u64 < b->u64) return __64_SMALLER;
#else
		for(i=0; i < __64_ARRAY_SIZE; i++) {
			if (a->array[i] > b->array[i]) {
				return __64_LARGER;
			}
			else if (a->array[i] < b->array[i]) {
				return __64_SMALLER;
			}
		}
#endif
	}

	__asm__("DS\t0H\treturn __64_EQUAL;");
	return __64_EQUAL;
}
#if 0
int __64_cmp(__64* a, __64* b)
{
	if (a && b) {
		int i = __64_ARRAY_SIZE;

		do {
			i -= 1; /* Decrement first, to start with last array element */

			if (a->array[i] > b->array[i]) {
				return __64_LARGER;
			}
			else if (a->array[i] < b->array[i]) {
				return __64_SMALLER;
			}
		}  while (i != 0);
	}

	return __64_EQUAL;
}
#endif

