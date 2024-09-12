#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <time64.h>
#include "__time64.h"

__asm__("\n&FUNC    SETC 'uctime64'");
char *uctime64( const utime64_t* utime ) {
	time64_t	time;

	/* convert 64 bit useconds (utime) to 64 bit seconds (time) value */
	__64_div_u32((utime64_t *)utime, 1000000, &time);

    return asctime64(localtime64(&time));
}

