/* @@TXBUFN.C */
#include "svc99.h"
#include "clibary.h"

int
__txbufn(TXT99 ***txt99, const char *bufno)
{
    int     err     = 1;
    int     len     = bufno ? atoi(bufno) : 0;
    char    *p;
    TXT99   *tu;

    if (len > 255) len = 255;
    if (len > 0) {
        p = (char *)&len;

        tu = NewTXT99(DALBUFNO,1,1,&p[3]);
        if (!tu) goto quit;

        err = arrayadd(txt99, tu);
    }

quit:
    return err;
}
