/* @@TXSPAC.C */
#include "svc99.h"
#include "clibary.h"

int
__txspac(TXT99 ***txt99, const char *space)
{
    int     err     = 1;
    int     len     = space ? strlen(space) : 0;
    char    *buf    = calloc(1, len + 1);
    char    *p;
    char    *s;
    char    *d;
    TXT99   *tu;

    if (!len) goto quit;
    if (!buf) goto quit;

    /* "pri[,sec]" */
    memcpy(buf, space, len);
    p = strtok(buf, " ,");
    s = strtok(NULL, ",");
    d = strtok(NULL, "");

    /* Primary space */
    len = p ? atoi(p) : 0;
    p = (char*)&len;
    tu = NewTXT99(DALPRIME,1,3,&p[1]);
    if (!tu) goto quit;
    err = arrayadd(txt99, tu);
    if (err) goto quit;

    /* Secondary space */
    err = 1;
    len = s ? atoi(s) : 0;
    s = (char*)&len;
    tu = NewTXT99(DALSECND,1,3,&s[1]);
    if (!tu) goto quit;
    err = arrayadd(txt99, tu);

    /* Directory space */
    len = d ? atoi(d) : 0;
    if (len) {
        err = 1;
        d = (char*)&len;
        tu = NewTXT99(DALDIR,1,3,&d[1]);
        if (!tu) goto quit;
        err = arrayadd(txt99, tu);
    }

quit:
    if (buf)    free(buf);
    return err;
}
