/* MEMCPYP.C */
#include "clibstr.h"

void *
memcpyp(void *target, int tlen, void *source, int slen, int pad)
{
    char    *t = target;

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
