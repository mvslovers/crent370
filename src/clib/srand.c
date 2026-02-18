/* SRAND.C */
#define STDLIB_C
#include <stdlib.h>
#include <stddef.h>
#include "clibcrt.h"

__PDPCLIB_API__ void srand(unsigned int seed)
{
    CLIBCRT *crt = __crtget();

    if (crt) {
        crt->crtseed = seed;
    }
    return;
}
