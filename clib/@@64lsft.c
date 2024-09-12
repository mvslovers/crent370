#include <stdio.h>
#include <string.h>
#include <clib64.h>

__asm__("\n&FUNC    SETC '__64_lshift'");
void __64_lshift(__64* a, __64* b, int nbits)
{
	if (a && b && (nbits>=0)) {
		int i;
		const int nbits_pr_word = (__64_WORD_SIZE * 8);
		int nwords = nbits / nbits_pr_word;

		__64_assign(b, a);

#if 0	/* gccmvs uses SLDA which preserves the sign bit. This is incorrect for our unsigned value. */
		/* gccmvs *should* have used SLDL to perform a shift left double logical. */
		if (nbits>63) {
			/* gccmvs uses SLDA for shift which is limited to 0 throough 63 for the shift value */
			__64_init(b);
		}
		else {
			/* gccmvs uses SLDA which can shift up to 63 bits */
			b->u64 = a->u64 << nbits;
		}
#else	/* slower but correct results */

		/* Handle shift in multiples of word-size */
		if (nwords != 0) {
			__64_lshift_word(b, nwords);
			nbits -= (nwords * nbits_pr_word);
		}

		if (nbits != 0) {
			for (i=0; i < (__64_ARRAY_SIZE - 1); i++) {
				b->array[i] = (b->array[i] << nbits) | (b->array[i + 1] >> ((8 * __64_WORD_SIZE) - nbits));
			}
			b->array[i] <<= nbits;
		}
#endif
	}
}

