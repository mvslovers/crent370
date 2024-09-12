/* @@TXSYSO.C */
#include "svc99.h"
#include "clibary.h"

int
__txsyso(TXT99 ***txt99, const char *out_class)
{
    int     err     = 1;
    TXT99   *tu;

    if (out_class) {
        tu = NewTXT99(DALSYSOU,1,1,out_class);
    }
    else {
        tu = NewTXT99(DALSYSOU,0,0,0);
    }
    if (!tu) goto quit;

    if (arrayadd(txt99, tu)) goto quit;

    err = 0;

quit:
    return err;
}
