/* @@TXFORM.C */
#include "svc99.h"
#include "clibary.h"

int
__txform(TXT99 ***txt99, const char *form)
{
    int     err     = 1;
    int     len     = form ? strlen(form) : 0;
    TXT99   *tu;

    if (len >= 1 && len <= 4) {
        tu = NewTXT99(DALSFMNO,1,len,form);
        if (!tu) goto quit;

        err = arrayadd(txt99, tu);
    }

quit:
    return err;
}
