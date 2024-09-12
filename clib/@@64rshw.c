#include <stdio.h>
#include <string.h>
#include <clib64.h>

__asm__("\n&FUNC    SETC '__64_rshift_word'");
void __64_rshift_word(__64* a, int nwords)
{
	int i;
	int	j;
	int	shift = nwords;

	if (a && (nwords >=0)) {
		if (shift < 0) shift = 0;
		if (shift > __64_ARRAY_SIZE) shift = __64_ARRAY_SIZE;	/* range 0 through 4 */
		if (shift != nwords) wtof("%s: *** shift corrected from %d to %d ***", __func__, nwords, shift);

		/* if shift is 0 then do nothing */
		for (i=0; i < shift; i++) {
			for(j= (__64_ARRAY_SIZE - 1); j > 0; j--) {
				a->array[j] = a->array[j-1];
			}
			a->array[j] = 0;
		}
	}
}

