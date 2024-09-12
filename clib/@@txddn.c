/* @@TXDDN.C */
#include "svc99.h"
#include "clibary.h"

int
__txddn(TXT99 ***txt99, const char *ddname)
{
    int     err     = 1;
    int     len;
    TXT99   *tu;

    if (ddname) {
        len = strlen(ddname);

        tu = NewTXT99(DALDDNAM,1,len,ddname);
        if (!tu) goto quit;

        err = arrayadd(txt99, tu);
    }

quit:
    return err;
}
