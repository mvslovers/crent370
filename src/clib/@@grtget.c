/* @@GRTGET.C */
#define CLIB_C
#include "clib.h"

CLIBGRT *
__grtget(void)
{
    CLIBCRT     *crt    = __crtget();
    CLIBGRT     *grt    = crt ? crt->crtgrt : 0;

    return grt;
}
