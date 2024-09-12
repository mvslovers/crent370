/* @@TXUCS.C */
#include "svc99.h"
#include "clibary.h"

int
__txucs(TXT99 ***txt99, const char *name)
{
    int     err     = 1;
    int     len     = name ? strlen(name) : 0;
    TXT99   *tu     = 0;

    if (len) {
        if (strcmp(name, "FOLD")==0) {
            tu = NewTXT99(DALUFOLD,0,0,0);
        }
        else if (strcmp(name, "VERIFY")==0) {
            tu = NewTXT99(DALUVRFY,0,0,0);
        }
        else {
            tu = NewTXT99(DALUCS,1,len,name);
        }
        if (!tu) goto quit;

        err = arrayadd(txt99, tu);
    }

quit:
    return err;
}
