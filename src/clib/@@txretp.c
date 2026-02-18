/* @@TXRETP.C */
#include "svc99.h"
#include "clibary.h"

int
__txretp(TXT99 ***txt99, const char *days)
{
    int     err     = 1;
    int     len     = days ? atoi(days) : 0;
    char    *p;
    TXT99   *tu;

    if (len >= 1 && len <= 93000) {
        p = (char *)&len;

        tu = NewTXT99(DALRETPD,1,3,&p[1]);
        if (!tu) goto quit;

        err = arrayadd(txt99, tu);
    }

quit:
    return err;
}
