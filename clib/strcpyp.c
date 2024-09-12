/* STRCPYP.C */
#include "clibstr.h"

char *
strcpyp(char *target, int tlen, void *source, int pad )
{
    char    *t      = target;
    int     slen    = source ? strlen(source) : 0;

    if (slen > tlen) slen = tlen;

    if (slen > 0) {
        memcpy(t, source, slen);
        t      += slen;
        tlen   -= slen;
    }

    if (tlen > 0) {
        memset(t, pad, tlen);
    }

    return target;
}
