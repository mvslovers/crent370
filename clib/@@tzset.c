/* @@TZSET.C */
#include <stdlib.h>
#include <stddef.h>
#include "clibcrt.h"

int
__tzset(int tzoffset)
{
    int     err     = 1;
    CLIBCRT *crt    = __crtget();

    if (crt) {
#if 0 /* we'll let the application do this rounding/truncation as needed */
        /* There are a few places in the world that have :30 or :15 minute
        ** based time zone offsets, so the best we can do is align to
        ** the 15 minute boundary and hope for the best.
        */

        /* round the time zone offset to 15 minute (900 second) boundary */
        tzoffset = tzoffset / 900;
        tzoffset = tzoffset * 900;
#endif
        crt->crttzoff = tzoffset;
        err = 0;
    }

    return err;
}
