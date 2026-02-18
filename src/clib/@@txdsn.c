/* @@TXDSN.C */
#include "svc99.h"
#include "clibary.h"

int
__txdsn(TXT99 ***txt99, const char *dataset)
{
    int     err     = 1;
    int     len;
    char    *p;
    char    *member;
    char    dsn[80];

    if (dataset) {
        len = strlen(dataset);
        if (len >= sizeof(dsn)) goto quit;

        memcpy(dsn, dataset, len);
        dsn[len]=0;

        member = strchr(dsn, '(');
        if (member) {
            TXT99 *txmem;
            *member = 0;
            member++;
            p = strchr(member,')');
            if (p) *p = 0;
            len = strlen(member);
            txmem = NewTXT99(DALMEMBR,1,len,member);
            wtodumpf(txmem, sizeof(TXT99)+len, "%s: DALMEMBR", __func__);
            err = arrayadd(txt99, txmem);
            if (err) goto quit;
            len = strlen(dsn);
        }
        err = arrayadd(txt99, NewTXT99(DALDSNAM,1,len,dsn));
    }

quit:
    return err;
}
