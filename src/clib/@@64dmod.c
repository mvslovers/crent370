#include <stdio.h>
#include <string.h>
#include <clib64.h>

__asm__("\n&FUNC    SETC '__64_divmod'");
void __64_divmod(__64* a, __64* b, __64* c, __64* d)
{
	/*
    Puts a%b in d
    and a/b in c

    mod(a,b) = a - ((a / b) * b)

    example:
      mod(8, 3) = 8 - ((8 / 3) * 3) = 2
	*/
	if (a && b && c && d) {
		__64 tmp;
		__64 tmpc;

		/* tmpc = (a / b) */
		__64_div(a, b, &tmpc);

		/* tmp = (tmpc * b) */
		__64_mul(&tmpc, b, &tmp);

		/* d = a - tmp */
		__64_sub(a, &tmp, d);

		/* c = tmpc */
		__64_copy(&tmpc, c);
	}
}

