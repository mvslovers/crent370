/* @@GTOUT.C */
#include <stdio.h>
#include "clibcrt.h"

FILE **
__gtout(void)
{
    CLIBGRT *grt    = __grtget();

    return((FILE**)&grt->grtout);
}
