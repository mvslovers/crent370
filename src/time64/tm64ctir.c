#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <time64.h>
#include "__time64.h"

__asm__("\n&FUNC    SETC 'ctime64_r'");
char *ctime64_r( const time64_t* time, char* result ) 
{
    struct tm date;

    if (result) {
	    localtime64_r( time, &date );

		result = asctime64_r( &date, result );
	}

	return result;
}

