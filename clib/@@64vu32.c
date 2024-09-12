#include <stdio.h>
#include <string.h>
#include <clib64.h>

__asm__("\n&FUNC    SETC '__64_divmod_u32'");
void __64_divmod_u32(__64* a, uint32_t b, __64* c, __64* d)
{
	__64	tmp;

	if (a && c && d) {
		__64_from_u32(&tmp, b);
		__64_divmod(a, &tmp, c, d);
	}
}

