/* @@TXNEW.C */
#include "svc99.h"
#include "clibary.h"

int
__txnew(TXT99 ***txt99, const char *unused)
{
    int     err     = 1;
    TXT99   *tu;

    tu = NewTXT99(DALSTATS,1,1,"\x04");     /* DISP=NEW */
    if (!tu) goto quit;

    if (arrayadd(txt99, tu)) goto quit;

    err = 0;

quit:
    return err;
}
