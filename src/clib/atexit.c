/* ATEXIT.C */
#include <stdlib.h>
#include <stddef.h>
#include "cliblock.h"
#include "clibcrt.h"
#include "clibary.h"

__PDPCLIB_API__ int atexit(void (*func)(void))
{
    CLIBGRT *grt        = __grtget();

    if (func) {
        lock(&grt->grtexit,0);
        arrayadd(&grt->grtexit, func);
        arrayadd(&grt->grtexita, 0);
        unlock(&grt->grtexit,0);
    }

    return 0;
}
