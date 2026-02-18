#include <stdio.h>
#include <string.h>
#include <clib64.h>

#define binary "01"
#define digits "0123456789"
#define hexstr "0123456789abcdef"

__asm__("\n&FUNC    SETC '__64_from_string'");
void __64_from_string(__64* n, char* str)
{
	__64		base;
	__64_DTYPE 	tmp;
	int			c;
	char		*p;
	char		*table;

	/* skip any leading space */
	while(*str==' ') str++;

	if (memcmp(str, "0x", 2)==0) {
		table = hexstr;
		__64_from_i32(&base, 16);
		str+=2;
	}
	else if (memcmp(str, "0b", 2)==0) {
		table = binary;
		__64_from_i32(&base, 2);
		str++;
	}
	else {
		table = digits;
		__64_from_i32(&base, 10);
	}

	if (n) {
		__64_init(n);

		for(;*str;str++) {
			c = tolower(*str);
			p = strchr(table, c);
			if (!p) break;
			tmp = (__64_DTYPE) (p - table);
			__64_mul(n, &base, n);
			n->array[__64_ARRAY_SIZE-1] += tmp;
		}
	}
}

