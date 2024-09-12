/* @@TXVOLS.C */
#include "svc99.h"
#include "clibary.h"

int
__txvols(TXT99 ***txt99, const char *vols)
{
    int     err     = 1;
    int     len     = vols ? strlen(vols) : 0;
    char    **tmp   = NULL;
    char    *buf    = calloc(1, len + 1);
    char    *p;
    TXT99   *tu;

    if (!len) goto quit;
    if (!buf) goto quit;

    memcpy(buf, vols, len);
    for(p=strtok(buf," ,"); p; p=strtok(NULL," ,")) {
        arrayadd(&tmp, p);
    }

    if (tmp) {
        /* array of volsers */
        len = (int) arraycount(&tmp);
        tu = NewTXT99a(DALVLSER,len,tmp);
        if (!tu) goto quit;

        err = arrayadd(txt99, tu);
    }

quit:
    if (tmp)    arrayfree(&tmp);
    if (buf)    free(buf);

    return err;
}
