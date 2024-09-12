/* @@TXLREC.C */
#include "svc99.h"
#include "clibary.h"

int
__txlrec(TXT99 ***txt99, const char *lrecl)
{
    int     err     = 1;
    int     len     = lrecl ? atoi(lrecl) : 0;
    char    *p;
    TXT99   *tu;

    if (lrecl) {
        p = (char*)&len;

        if (strchr(lrecl, 'X')) {
            /* Variable length spanned records greater than 32,756 */
            len = 0x8000;
        }
        else if (strchr(lrecl, 'K')) {
            len *= 1024;
            if (len > 32760) len = 32760;
        }
        else {
            if (len > 32760) len = 32760;
        }

        tu = NewTXT99(DALLRECL,1,2,&p[2]);
        if (!tu) goto quit;

        err = arrayadd(txt99, tu);
    }

quit:
    return err;
}
