#include <stdio.h>
#include <string.h>
#include <clib64.h>

__asm__("\n&FUNC    SETC '__64_sub_i32'");
void __64_sub_i32(__64* a, int32_t b, __64* c)
{
	__64	tmp;

	if (a && c) {
		/* make tmp value positive */
		__64_from_u32(&tmp, (uint32_t) (b < 0 ? -b : b));
		if (b < 0) {
			__64_add(a, &tmp, c);
		}
		else {
			__64_sub(a, &tmp, c);
		}
	}
}

