/* @@TXBKSZ.C */
#include "svc99.h"
#include "clibary.h"

int
__txbksz(TXT99 ***txt99, const char *blksize)
{
    int     err     = 1;
    int     len     = blksize ? atoi(blksize) : 0;
    char    *p;
    TXT99   *tu;

    if (len > 32760) len = 32760;
    if (len > 0) {
        p = (char*)&len;

        tu = NewTXT99(DALBLKSZ,1,2,&p[2]);
        if (!tu) goto quit;

        err = arrayadd(txt99, tu);
    }

quit:
    return err;
}
