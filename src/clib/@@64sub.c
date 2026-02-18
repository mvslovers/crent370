#include <stdio.h>
#include <string.h>
#include <clib64.h>

__asm__("\n&FUNC    SETC '__64_sub'");
void __64_sub(__64* a, __64* b, __64* c)
{
	__64_DTYPE_TMP res;
	__64_DTYPE_TMP tmp1;
	__64_DTYPE_TMP tmp2;
	int borrow = 0;
  	int i;

	if (a && b && c) {
		for (i = __64_ARRAY_SIZE-1; i >= 0; i--) {
			tmp1 = (__64_DTYPE_TMP)a->array[i] + (__64_MAX_VAL + 1); /* + number_base */
			tmp2 = (__64_DTYPE_TMP)b->array[i] + borrow;
			res = (tmp1 - tmp2);
			/* "modulo number_base" == "% (number_base - 1)" if number_base is 2^N */
			c->array[i] = (__64_DTYPE)(res & __64_MAX_VAL); 
			borrow = (res <= __64_MAX_VAL);
		}
	}
}

