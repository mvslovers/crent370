#include <stdio.h>
#include <string.h>
#include <clib64.h>

__asm__("\n&FUNC    SETC '__64_cmp_i32'");
int __64_cmp_i32(__64* a, int32_t b)
{
	__64	tmp;

	__64_from_i32(&tmp, b);

	return __64_cmp(a, &tmp);
}

