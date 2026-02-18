/* @@TXHOLD.C */
#include "svc99.h"
#include "clibary.h"

int
__txhold(TXT99 ***txt99, const char *unused)
{
    int     err     = 1;
    TXT99   *tu;

    tu = NewTXT99(DALSHOLD,0,0,0);
    if (!tu) goto quit;

    err = arrayadd(txt99, tu);

quit:
    return err;
}
