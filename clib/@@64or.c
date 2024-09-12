#include <stdio.h>
#include <string.h>
#include <clib64.h>

__asm__("\n&FUNC    SETC '__64_or'");
void __64_or(__64* a, __64* b, __64* c)
{
	if (a && b && c) {
#if 1
		c->u64 = a->u64 | b->u64;
#else
		int i;

		for (i = 0; i < __64_ARRAY_SIZE; ++i) {
			c->array[i] = (a->array[i] | b->array[i]);
		}
#endif
	}
}

