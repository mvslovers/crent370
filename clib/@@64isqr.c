#include <stdio.h>
#include <string.h>
#include <clib64.h>

__asm__("\n&FUNC    SETC '__64_isqrt'");
void __64_isqrt(__64 *a, __64* b)
{
	__64 low, high, mid, tmp;

	if (a && b) {
		__64_init(&low);
		__64_assign(&high, a);
		__64_rshift(&high, &mid, 1);
		__64_inc(&mid);

		while (__64_cmp(&high, &low) > 0) {
			__64_mul(&mid, &mid, &tmp);
			if (__64_cmp(&tmp, a) > 0) {
				__64_assign(&high, &mid);
				__64_dec(&high);
			}
			else {
				__64_assign(&low, &mid);
			}

			__64_sub(&high,&low,&mid);
			__64_rshift_one_bit(&mid);
			__64_add(&low,&mid,&mid);
			__64_inc(&mid);
		}
		
		__64_assign(b,&low);
	}
}

