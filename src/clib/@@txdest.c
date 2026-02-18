/* @@TXDEST.C */
#include "svc99.h"
#include "clibary.h"

int
__txdest(TXT99 ***txt99, const char *dest)
{
    int     err     = 1;
    int     len;
    TXT99   *tu;
    char    *p;
    char    *user;
    char    *node;
    char    buf[40];

    if (!dest) goto quit;

    if (strchr(dest, '.')) {
        /* "node.user" */
        len = strlen(dest);
        if (len >= sizeof(buf)) goto quit;

        memcpy(buf, dest, len);
        buf[len] = 0;

        p = strchr(buf, '.');
        if (!p) goto quit;  /* shouldn't happen, but just in case */

        node = buf;
        *p++ = 0;
        user = p;

        len = strlen(user);
        tu = NewTXT99(DALUSRID,1,len,user);     /* User */
        if (!tu) goto quit;
        if (arrayadd(txt99, tu)) goto quit;

        len = strlen(node);
        tu = NewTXT99(DALSUSER,1,len,node);     /* Node */
        if (!tu) goto quit;
        if (arrayadd(txt99, tu)) goto quit;
    }
    else {
        /* destination */
        len = strlen(dest);
        tu = NewTXT99(DALSUSER,1,len,dest);     /* destination */
        if (!tu) goto quit;
        if (arrayadd(txt99, tu)) goto quit;
    }

    err = 0;

quit:
    return err;
}
