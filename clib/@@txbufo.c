/* @@TXBUFO.C */
#include "svc99.h"
#include "clibary.h"

int
__txbufo(TXT99 ***txt99, const char *offset)
{
    int     err     = 1;
    int     len     = offset ? atoi(offset) : 0;
    char    *p;
    TXT99   *tu;

    if (!len && offset) {
        if (strcmp(offset, "L")==0) {
            /* The block prefix is four bytes long
            ** and contains the block length (L)
            */
            len = 0x80;
        }
    }

    if ((len >= 0 && len <= 99) || (len == 0x80)) {
        p = (char*)&len;

        tu = NewTXT99(DALBUFOF,1,1,&p[3]);
        if (!tu) goto quit;

        err = arrayadd(txt99, tu);
    }

quit:
    return err;
}
