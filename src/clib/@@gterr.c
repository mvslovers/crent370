/* @@GTERR.C */
#include <stdio.h>
#include "clibcrt.h"

FILE **
__gterr(void)
{
    CLIBGRT *grt    = __grtget();

    return((FILE**)&grt->grterr);
}
