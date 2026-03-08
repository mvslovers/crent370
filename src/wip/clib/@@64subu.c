#include <stdio.h>
#include <string.h>
#include <clib64.h>

__asm__("\n&FUNC    SETC '__64_sub_ull'");
void __64_sub_ull(__64* a, uint64_t b, __64* c)
{
	__64	tmp;

	if (a && c) {
		__64_from_ull(&tmp, b);
		__64_sub(a, &tmp, c);
	}
}

