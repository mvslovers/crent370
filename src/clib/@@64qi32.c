#include <stdio.h>
#include <string.h>
#include <clib64.h>

__asm__("\n&FUNC    SETC '__64_mod_i32'");
void __64_mod_i32(__64* a, int32_t b, __64* c)
{
	__64	tmp;

	if (a && c) {
		__64_from_i32(&tmp, b);
		__64_mod(a, &tmp, c);
	}
}

