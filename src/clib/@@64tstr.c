#include <stdio.h>
#include <string.h>
#include "clib64.h"

__asm__("\n&FUNC    SETC '__64_to_string'");
void __64_to_string(__64* n, char* str, int nbytes)
{
	int			x	= 0;
	int			i	= 0;
	unsigned	u;
	char		work[50] = "0";
	__64		base;
	__64		tmp;
	__64		rem;

	__64_from_i32(&base, 10);

	if (n && str) {
		__64_copy(n, &tmp);

		while((!__64_is_zero(&tmp)) && (x < nbytes)) {
			__64_divmod(&tmp, &base, &tmp, &rem);
            u  = rem.array[__64_ARRAY_SIZE-1];
            work[x++] = (char) ("0123456789"[u]);
		}

		if (x==0) {
			if (i < nbytes) str[i++] = '0';
		}
		else {
			for(x--; (x >= 0) && (i < nbytes); x--, i++) {
				str[i] = work[x];
        	}
		}
		if (i < nbytes) str[i] = 0;
	}
}

