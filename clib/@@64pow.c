#include <stdio.h>
#include <string.h>
#include <clib64.h>

__asm__("\n&FUNC    SETC '__64_pow'");
void __64_pow(__64* a, __64* b, __64* c)
{
	__64 	tmp;
	__64	bcopy;

	if (a && b && c) {
		__64_init(c);

		if (__64_cmp(b, c) == __64_EQUAL) {
			/* Return 1 when exponent is 0 -- n^0 = 1 */
			__64_inc(c);
		}
		else {
			__64_assign(&bcopy, b);

			/* Copy a -> tmp */
			__64_assign(&tmp, a);

			__64_dec(&bcopy);
 
			/* Begin summing products: */
			while (!__64_is_zero(&bcopy)) {
				/* c = tmp * tmp */
				__64_mul(&tmp, a, c);

				/* Decrement b by one */
				__64_dec(&bcopy);

				__64_assign(&tmp, c);
			}

			/* c = tmp */
			__64_assign(c, &tmp);
  		}
	}
}

