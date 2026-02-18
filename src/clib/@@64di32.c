#include <stdio.h>
#include <string.h>
#include <clib64.h>

__asm__("\n&FUNC    SETC '__64_div_i32'");
void __64_div_i32(__64* a, int32_t b, __64* c)
{
	__64	tmp;

	if (a && c) {
		__64_from_u32(&tmp, (uint32_t) (b < 0 ? -b : b));
		if (b < 0) {
			__64_mul(a, &tmp, c);
		}
		else {
			__64_div(a, &tmp, c);
		}
	}
}

