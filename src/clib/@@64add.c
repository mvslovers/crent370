#include <stdio.h>
#include <string.h>
#include <clib64.h>

__asm__("\n&FUNC    SETC '__64_add'");
void __64_add(__64* a, __64* b, __64* c)
{
	__64_DTYPE_TMP 	tmp;
	int 			carry = 0;
	int 			i;

	if (a && b && c) {
		for (i = __64_ARRAY_SIZE - 1; i >=0 ; i--) {
			tmp = (__64_DTYPE_TMP)a->array[i] + b->array[i] + carry;
			carry = (tmp > __64_MAX_VAL);
			c->array[i] = (tmp & __64_MAX_VAL);
		}
	}
}

