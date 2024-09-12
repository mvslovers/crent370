#include <stdio.h>
#include <string.h>
#include <clib64.h>

__asm__("\n&FUNC    SETC '__64_dec'");
void __64_dec(__64* n)
{

	if (n) {
#if 0	/* gccmvs can't decrement 64 bit values */
		n->u64--;
#else
		__64_DTYPE 	tmp; /* copy of n */
		__64_DTYPE 	res;
		int i;

		for (i = __64_ARRAY_SIZE - 1; i >= 0; i--) {
			tmp = n->array[i];
			res = tmp - 1;
			n->array[i] = res;

			if (!(res > tmp)) {
				/* no borrow needed, we're done */
				break;
			}
		}
#endif
	}
}

