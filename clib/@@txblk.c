/* @@TXBLK.C */
#include "svc99.h"
#include "clibary.h"

int
__txblk(TXT99 ***txt99, const char *blocks)
{
    int     err     = 1;
    int     len     = blocks ? atoi(blocks) : 0;
    char    *p;
    TXT99   *tu;

    if (len) {
        p = (char*)&len;

        tu = NewTXT99(DALBLKLN,1,3,&p[1]);
        if (!tu) goto quit;

        err = arrayadd(txt99, tu);
    }

quit:
    return err;
}
