/* @@TXBUFL.C */
#include "svc99.h"
#include "clibary.h"

int
__txbufl(TXT99 ***txt99, const char *length)
{
    int     err     = 1;
    int     len     = length ? atoi(length) : 0;
    char    *p;
    TXT99   *tu;

    if (len > 32760) len = 32760;
    if (len > 0) {
        p = (char*)&len;

        tu = NewTXT99(DALBUFL,1,2,&p[2]);
        if (!tu) goto quit;

        err = arrayadd(txt99, tu);
    }

quit:
    return err;
}
