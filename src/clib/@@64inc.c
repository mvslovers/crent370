#include <stdio.h>
#include <string.h>
#include <clib64.h>

__asm__("\n&FUNC    SETC '__64_inc'");
void __64_inc(__64* n)
{
	__64_DTYPE 		res;
	__64_DTYPE_TMP 	tmp; /* copy of n */
	int i;

	if (n) {
		for (i = __64_ARRAY_SIZE - 1; i >= 0; i--) {
			tmp = n->array[i];
			res = tmp + 1;
			n->array[i] = res;

			if (res > tmp) {
				/* no overflow occured, we're done */
				break;
			}
		}
	}
}

