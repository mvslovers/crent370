/* @@GTIN.C */
#include <stdio.h>
#include "clibcrt.h"

FILE **__gtin(void)
{
    CLIBGRT *grt    = __grtget();

    return((FILE**)&grt->grtin);
}
