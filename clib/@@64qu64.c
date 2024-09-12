#include <stdio.h>
#include <string.h>
#include <clib64.h>

__asm__("\n&FUNC    SETC '__64_mod_u64'");
void __64_mod_u64(__64* a, uint64_t b, __64* c)
{
	__64	tmp;

	if (a && c) {
		__64_from_u64(&tmp, b);
		__64_mod(a, &tmp, c);
	}
}

