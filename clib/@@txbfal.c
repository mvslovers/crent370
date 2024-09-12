/* @@TXBFAL.C */
#include "svc99.h"
#include "clibary.h"

int
__txbfal(TXT99 ***txt99, const char *align)
{
    int     err     = 1;
    int     len     = align ? strlen(align) : 0;
    TXT99   *tu;
    unsigned char type;

    if (len) {
        if (memcmp(align, "FULL", len)==0) {
            type = 0x01;
        }
        else if (memcmp(align, "DOUBLE", len)==0) {
            type = 0x02;
        }
        else {
            goto quit;
        }

        tu = NewTXT99(DALBFALN,1,1,&type);
        if (!tu) goto quit;

        err = arrayadd(txt99, tu);
    }

quit:
    return err;
}
