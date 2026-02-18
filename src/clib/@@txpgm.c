/* @@TXPGM.C */
#include "svc99.h"
#include "clibary.h"

int
__txpgm(TXT99 ***txt99, const char *pgm)
{
    int     err     = 1;
    int     len     = pgm ? strlen(pgm) : 0;
    TXT99   *tu;

    if (len >=1 && len <= 8) {
        tu = NewTXT99(DALSPGNM,1,len,pgm);
        if (!tu) goto quit;

        err = arrayadd(txt99, tu);
    }

quit:
    return err;
}
