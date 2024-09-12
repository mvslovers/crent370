#include <stdio.h>
#include <string.h>
#include <clib64.h>

/* Initialize __64 structure */
__asm__("\n&FUNC    SETC '__64_init'");
void __64_init(__64* n)
{
#if 1	/* a slightly faster method */
	n->u32[0] = 0; n->u32[1] = 0;	/* memset(n, 0, sizeof(__64)); */
#else
	int i;

	if (n) {
		for (i = 0; i < __64_ARRAY_SIZE; ++i) {
			n->array[i] = 0;
		}
	}
#endif
}

