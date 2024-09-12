/* @@TXKEEP.C */
#include "svc99.h"
#include "clibary.h"

int
__txkeep(TXT99 ***txt99, const char *unused)
{
    int     err     = 1;
    TXT99   *tu;

    tu = NewTXT99(DALNDISP,1,1,"\x08");
    if (!tu) goto quit;

    err = arrayadd(txt99, tu);

quit:
    return err;
}
