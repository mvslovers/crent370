/* @@TXFCB.C */
#include "svc99.h"
#include "clibary.h"

int
__txfcb(TXT99 ***txt99, const char *fcb)
{
    int     err     = 1;
    int     len     = fcb ? strlen(fcb) : 0;
    TXT99   *tu;

    if (len > 0) {
        tu = 0;
        if (strcmp(fcb, "ALIGN")==0) {
            tu = NewTXT99(DALFCBAV,1,1,"\x08");
        }
        else if (strcmp(fcb, "VERIFY")==0) {
            tu = NewTXT99(DALFCBAV,1,1,"\x04");
        }
        else {
            tu = NewTXT99(DALFCBIM,1,len,fcb);
        }

        if (!tu) goto quit;

        err = arrayadd(txt99, tu);
    }

quit:
    return err;
}
