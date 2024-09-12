#include <stdio.h>
#include <string.h>
#include <clib64.h>

__asm__("\n&FUNC    SETC '__64_rshift_one_bit'");
void __64_rshift_one_bit(__64* a)
{
	int i;
	__64_DTYPE	tmp;

	if (a) {
		/* wtodumpf(a, sizeof(__64), "%s: before", __func__); */

		for (i = (__64_ARRAY_SIZE - 1); i > 0; i--) {
#if 0
			tmp = a->array[i];
			wtof("%s: a->array[%d] tmp before 0x%04X", __func__, i, tmp);

			tmp = (a->array[i] >> 1) | (a->array[i - 1] << ((8 * __64_WORD_SIZE) - 1));
			wtof("%s: a->array[%d] tmp after 0x%04X", __func__, i, tmp);
#endif
			a->array[i] = (a->array[i] >> 1) | (a->array[i - 1] << ((8 * __64_WORD_SIZE) - 1));
		}
		
		a->array[0] >>= 1;

		/* wtodumpf(a, sizeof(__64), "%s: after", __func__); */
	}
}

#if 0
void __64_rshift_one_bit(__64* a)
{
	int i;
	__64_DTYPE	tmp;

	if (a) {

		for (i = 0; i < (__64_ARRAY_SIZE - 1); ++i) {
			tmp = a->array[i];
			wtof("%s: a->array[%d] tmp before 0x%04X", __func__, i, tmp);

			tmp = (a->array[i] >> 1) | (a->array[i + 1] << ((8 * __64_WORD_SIZE) - 1));
			wtof("%s: a->array[%d] tmp after 0x%04X", __func__, i, tmp);

			a->array[i] = (a->array[i] >> 1) | (a->array[i + 1] << ((8 * __64_WORD_SIZE) - 1));
		}
		
		a->array[__64_ARRAY_SIZE - 1] >>= 1;
	}
}
#endif

