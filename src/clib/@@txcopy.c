/* @@TXCOPY.C */
#include "svc99.h"
#include "clibary.h"

int
__txcopy(TXT99 ***txt99, const char *copies)
{
    int     err     = 1;
    int     len     = copies ? atoi(copies) : 0;
    char    *p;
    TXT99   *tu;

    if (len >= 1 && len <= 255) {
        p = (char*)&len;

        tu = NewTXT99(DALCOPYS,1,1,&p[3]);
        if (!tu) goto quit;

        err = arrayadd(txt99, tu);
    }

quit:
    return err;
}
