#include <stdio.h>
#include <string.h>
#include <clib64.h>

__asm__("\n&FUNC    SETC '__64_rshift'");
void __64_rshift(__64* a, __64* b, int nbits)
{
	const int nbits_pr_word = (__64_WORD_SIZE * 8);
	int nwords = nbits / nbits_pr_word;

	if (a && b && (nbits>=0)) {
		__64_assign(b, a);

		/* Handle shift in multiples of word-size */
		if (nwords != 0) {
			/* wtof("%s: nbits=%d, nbits_pr_word=%d, nwords=%d", __func__, nbits, nbits_pr_word, nwords); */
			__64_rshift_word(b, nwords);
			nbits -= (nwords * nbits_pr_word);
		}

		if (nbits != 0) {
			int i;
			
			for (i = (__64_ARRAY_SIZE - 1); i > 0; i--) {
				b->array[i] = (b->array[i] >> nbits) | (b->array[i - 1] << ((8 * __64_WORD_SIZE) - nbits));
			}
			b->array[0] >>= nbits;
		}
	}
}

