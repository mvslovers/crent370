#include <stdio.h>
#include <string.h>
#include <clib64.h>

__asm__("\n&FUNC    SETC '__64_cmp_u32'");
int __64_cmp_u32(__64* a, uint32_t b)
{
	__64	tmp;

	__64_from_u32(&tmp, b);

	return __64_cmp(a, &tmp);
}

