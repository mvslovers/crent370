/* @@TXEXPD.C */
#include "svc99.h"
#include "clibary.h"

int
__txexpd(TXT99 ***txt99, const char *yyddd)
{
    int     err     = 1;
    int     len     = yyddd ? strlen(yyddd) : 0;
    TXT99   *tu;

    if (len==5) {
        tu = NewTXT99(DALEXPDT,1,len,yyddd);
        if (!tu) goto quit;

        err = arrayadd(txt99, tu);
    }

quit:
    return err;
}
