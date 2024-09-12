/* @@TXKEYL.C */
#include "svc99.h"
#include "clibary.h"

int
__txkeyl(TXT99 ***txt99, const char *length)
{
    int     err     = 1;
    int     len     = length ? atoi(length) : 0;
    char    *p;
    TXT99   *tu;

    if (len >= 0 && len <= 255) {
        p = (char*)&len;
        tu = NewTXT99(DALKYLEN,1,1,&p[3]);
        if (!tu) goto quit;

        err= arrayadd(txt99, tu);
    }

quit:
    return err;
}
