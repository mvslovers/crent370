/* @@TXDIR.C */
#include "svc99.h"
#include "clibary.h"

int
__txdir(TXT99 ***txt99, const char *pds_dir)
{
    int     err     = 1;
    int     len     = pds_dir ? atoi(pds_dir) : 0;
    char    *p;
    TXT99   *tu;

    if (len) {
        p = (char*)&len;

        tu = NewTXT99(DALDIR,1,3, &p[1]);
        if (!tu) goto quit;

        err = arrayadd(txt99, tu);
    }

quit:
    return err;
}
