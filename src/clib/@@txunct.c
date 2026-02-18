/* @@TXUNCT.C */
#include "svc99.h"
#include "clibary.h"

int
__txunct(TXT99 ***txt99, const char *count)
{
    int     err     = 1;
    int     len     = count ? atoi(count) : 0;
    char    *p;
    TXT99   *tu;

    if (len > 0) {
        p = (char*)&len;

        tu = NewTXT99(DALUNCNT,1,1,&p[3]);
        if (!tu) goto quit;

        err = arrayadd(txt99, tu);
    }

quit:
    return err;
}
