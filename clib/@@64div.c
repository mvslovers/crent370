#include <stdio.h>
#include <string.h>
#include <clib64.h>

__asm__("\n&FUNC    SETC '__64_div'");
void __64_div(__64* a, __64* b, __64* c)
{
	__64	current;
	__64	denom;
	__64	tmp;
	const __64_DTYPE_TMP half_max = 1 + (__64_DTYPE_TMP)(__64_MAX_VAL / 2);
	int 	overflow = 0;

	if (a && b && c) {
		__64_from_i32(&current, 1);               // int current = 1;
		__64_assign(&denom, b);                   // denom = b
		__64_assign(&tmp, a);                     // tmp   = a
#if 0
		wtodumpf(&current, sizeof(__64), "%s: current", __func__);
		wtodumpf(&denom, sizeof(__64), "%s: denom", __func__);
		wtodumpf(&tmp, sizeof(__64), "%s: tmp", __func__);
		wtof("%s: half_max=%u", __func__, half_max);

		wtof("%s: while (__64_cmp(&denom, a) != __64_LARGER) {", __func__);
#endif
		while (__64_cmp(&denom, a) != __64_LARGER) {   // while (denom <= a) {
			if (denom.array[0] >= half_max) {
				overflow = 1;
				break;
			}

			__64_lshift_one_bit(&current);                //   current <<= 1;
			/* wtodumpf(&current, sizeof(__64), "%s: current <<=1", __func__); */

			__64_lshift_one_bit(&denom);                  //   denom <<= 1;
			/* wtodumpf(&denom, sizeof(__64), "%s: denom <<=1", __func__); */
		}
#if 0
		wtof("%s: }", __func__);

		wtof("%s: if (!overflow) { // overflow=%d", __func__, overflow);
#endif
		if (!overflow) {
			__64_rshift_one_bit(&denom);                  // denom >>= 1;
			/* wtodumpf(&denom, sizeof(__64), "%s: denom >>=1", __func__); */
			__64_rshift_one_bit(&current);                // current >>= 1;
			/* wtodumpf(&current, sizeof(__64), "%s: current >>=1", __func__); */
		}
		/* wtof("%s: }", __func__); */

		__64_init(c);                             // int answer = 0;
#if 0
		wtodumpf(c, sizeof(__64), "%s: c", __func__);

		wtof("%s: while (!__64_is_zero(&current)) {", __func__);
#endif
		while (!__64_is_zero(&current)) {         // while (current != 0)
			/* wtof("%s:     if (__64_cmp(&tmp, &denom) != __64_SMALLER) {", __func__); */
			if (__64_cmp(&tmp, &denom) != __64_SMALLER) {  //   if (dividend >= denom)
#if 0
				wtof("%s: __64_sub()", __func__);
				wtodumpf(&tmp, sizeof(__64), "%s: tmp", __func__);
				wtodumpf(&denom, sizeof(__64), "%s: denom", __func__);
#endif
				__64_sub(&tmp, &denom, &tmp);         //     dividend -= denom;
#if 0
				wtodumpf(&tmp, sizeof(__64), "%s: tmp", __func__);

				wtof("%s: __64_or()", __func__);
				wtodumpf(c, sizeof(__64), "%s: c", __func__);
				wtodumpf(&current, sizeof(__64), "%s: current", __func__);
#endif
				__64_or(c, &current, c);              //     answer |= current;
				/* wtodumpf(c, sizeof(__64), "%s: c", __func__); */
			}
			/* wtof("%s:     }", __func__); */

			__64_rshift_one_bit(&current);                //   current >>= 1;
			/* wtodumpf(&current, sizeof(__64), "%s: current >>=1", __func__); */

			__64_rshift_one_bit(&denom);                  //   denom >>= 1;
			/* wtodumpf(&denom, sizeof(__64), "%s: denom >>=1", __func__); */
		}                                           // return answer;
		/* wtof("%s: }", __func__); */
	}
}

