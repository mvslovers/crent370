/* @@TXUNIT.C */
#include "svc99.h"
#include "clibary.h"

int
__txunit(TXT99 ***txt99, const char *unit)
{
    int     err     = 1;
    int     len     = unit ? strlen(unit) : 0;
    TXT99   *tu;

    if (len) {
        tu = NewTXT99(DALUNIT,1,len,unit);
        if (!tu) goto quit;

        err = arrayadd(txt99, tu);
    }

quit:
    return err;
}
