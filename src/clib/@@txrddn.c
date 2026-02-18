/* @@TXRDDN.C */
#include "svc99.h"
#include "clibary.h"

int
__txrddn(TXT99 ***txt99, const char *unused)
{
    int     err     = 1;
    int     len;
    TXT99   *tu;

    tu = NewTXT99(DALRTDDN,1,8,0);
    if (!tu) goto quit;

    err = arrayadd(txt99, tu);

quit:
    return err;
}
