#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <time64.h>
#include "__time64.h"

__asm__("\n&FUNC    SETC 'ctime64'");
char *ctime64( const time64_t* time ) {
    return asctime64(localtime64(time));
}

