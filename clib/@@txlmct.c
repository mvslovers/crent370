/* @@TXLMCT.C */
#include "svc99.h"
#include "clibary.h"

int
__txlmct(TXT99 ***txt99, const char *limit)
{
    int     err     = 1;
    int     len     = limit ? atoi(limit) : 0;
    char    *p;
    TXT99   *tu;

    if (len > 32760) len = 32760;
    if (len > 0) {
        p = (char*)&len;

        tu = NewTXT99(DALLIMCT,1,3,&p[1]);
        if (!tu) goto quit;

        err = arrayadd(txt99, tu);
    }

quit:
    return err;
}
