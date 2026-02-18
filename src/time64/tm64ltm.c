#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <time64.h>
#include "__time64.h"
#include "mvssupa.h"
#include "clibcrt.h"

__asm__("\n&FUNC    SETC 'gmtime64'");
struct tm *localtime64(const time64_t *timer)
{
    CLIBCRT     *crt    = __crtget();
    struct tm   *tms    = (struct tm*)crt->crttms;

	return localtime64_r(timer, tms);
}

