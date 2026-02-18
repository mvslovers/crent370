/* @@TXVSEQ.C */
#include "svc99.h"
#include "clibary.h"

int
__txvseq(TXT99 ***txt99, const char *sequence)
{
    int     err     = 1;
    int     len     = sequence ? atoi(sequence) : 0;
    char    *p;
    TXT99   *tu;

    if (len >= 1 && len <= 255) {
        p = (char *)&len;

        tu = NewTXT99(DALVLSEQ,1,2,&p[2]);
        if (!tu) goto quit;

        err = arrayadd(txt99, tu);
    }

quit:
    return err;
}
