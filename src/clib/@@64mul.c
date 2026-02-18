#include <stdio.h>
#include <string.h>
#include <clib64.h>

__asm__("\n&FUNC    SETC '__64_mul'");
#if 1
void __64_mul(__64* a, __64* b, __64* c)
{
	__64	row;
	__64	tmp;
	__64	result;
	__64_DTYPE_TMP intermediate;
	int 	i, j, k, x;

	if (a && b && c) {
		__64_init(&result);

		for (i = __64_ARRAY_SIZE - 1; i >= 0; i--) {
			__64_init(&row);

			for (j = __64_ARRAY_SIZE - 1; j >= 0; j--) {
				k = i + j;
				if (k > (__64_ARRAY_SIZE-2)) {
					intermediate = ((__64_DTYPE_TMP)a->array[i] * (__64_DTYPE_TMP)b->array[j]);

					if (intermediate) {
						x = ((__64_ARRAY_SIZE - 1) * 2) - k;
						if (x < 0 || x > __64_ARRAY_SIZE -1) {
							wtof("%s: *** x=%d is out of range ***", __func__, x);
							wtodumpf(a, sizeof(__64), "%s: a", __func__);
							wtodumpf(b, sizeof(__64), "%s: b", __func__);
							wtof("%s: i=%d, j=%d, k=%d, 0x%04X * 0x%04X intermediate=%u", 
								__func__, i, j, k, a->array[i], b->array[j], intermediate);
						}

						__64_from_u32(&tmp, intermediate);
						/* wtodumpf(&tmp, sizeof(__64), "%s: tmp", __func__); */

						__64_lshift_word(&tmp, x);
						/* wtodumpf(&tmp, sizeof(__64), "%s: tmp after lshift word %d", __func__, x); */

						__64_add(&tmp, &row, &row);
						/* wtodumpf(&row, sizeof(__64), "%s: row after add tmp", __func__); */
					}
				}
			}
			__64_add(&result, &row, &result);
			/* wtodumpf(&result, sizeof(__64), "%s: result", __func__); */
		}
		__64_copy(&result, c);
		/* wtodumpf(c, sizeof(__64), "%s: c", __func__); */
	}
}
#endif
#if 0
void __64_mul(__64* a, __64* b, __64* c)
{
	__64	row;
	__64	tmp;
	int 	i, j;

	if (a && b && c) {
		__64_init(c);

		for (i = 0; i < __64_ARRAY_SIZE; ++i) {
			__64_init(&row);

			for (j = 0; j < __64_ARRAY_SIZE; ++j) {
				if (i + j < __64_ARRAY_SIZE) {
					__64_DTYPE_TMP intermediate = ((__64_DTYPE_TMP)a->array[i] * (__64_DTYPE_TMP)b->array[j]);

					__64_from_int(&tmp, intermediate);
					__64_lshift_word(&tmp, i + j);
					__64_add(&tmp, &row, &row);
				}
			}
			__64_add(c, &row, c);
		}
	}
}
#endif

