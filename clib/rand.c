/* RAND.C */
#define STDLIB_C
#include <stdlib.h>
#include <stddef.h>
#include "clibcrt.h"

__PDPCLIB_API__ int rand(void)
{
    int ret;
    CLIBCRT *crt = __crtget();

    if (crt) {
        crt->crtseed = crt->crtseed * 1103515245UL + 12345;
        ret = (int)(((crt->crtseed) >> 16) & 0x8fff);
    }

    return (ret);
}
