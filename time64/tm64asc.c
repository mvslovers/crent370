#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <time64.h>
#include "__time64.h"
#include "mvssupa.h"
#include "clibcrt.h"

__asm__("\n&FUNC    SETC 'asctime64'");
char *asctime64(const struct tm *timeptr)
{
    CLIBCRT *crt = __crtget();
    char    *buf = crt ? crt->crtctime : NULL;

	if (buf) {
		buf = asctime64_r(timeptr, buf);
	}

    return buf;
}

