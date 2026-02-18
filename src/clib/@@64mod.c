#include <stdio.h>
#include <string.h>
#include <clib64.h>

__asm__("\n&FUNC    SETC '__64_mod'");
void __64_mod(__64* a, __64* b, __64* c)
{
	/* Take divmod and throw away div part */
	if (a && b && c) {
		__64 tmp;

		__64_divmod(a,b,&tmp,c);
	}
}

