#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include "clibvsam.h"
#include "clibwto.h"

int
main(int argc, char **argv)
{
    int         rc      = 0;
    VSFILE      *vs     = 0;
    unsigned    lrecl   = 0;
    unsigned    cinv    = 0;
    unsigned    n       = 0;
    char        *buf    = 0;

#if 0
    rc = vsopen("VSAMESDS", VSTYPE_ESDS, VSACCESS_SEQ, VSMODE_OUT, &vs);
#else
    rc = vsopen("VSAMESDS", VSTYPE_ESDS, VSACCESS_ADR, VSMODE_UPD, &vs);
#endif
    wtof("vsopen() rc=%d", rc);
    wtof("vsopen() handle=%08X", vs);
    if (!vs) goto quit;

    wtodumpf(vs, sizeof(VSFILE), "VSFILE");

    lrecl   = vslrecl(vs);
    cinv    = vscinv(vs);

    wtof("LRECL %u", lrecl);
    wtof("CINV  %u", cinv);

#if 1
    buf = calloc(1,lrecl);
    if (!buf) goto quit;

    n = 3*lrecl;
#if 0
    vssteq(vs, buf, lrecl, &n, 4);
    wtof("vssteq() rc=%d", rc);
#else
    rc = vsread(vs, buf, lrecl, &n, 4);
    wtof("vsread() rc=%d", rc);
#endif
    memset(buf, '*', lrecl);
    rc = vsupdate(vs, buf, lrecl);
    wtof("vsupdate() rc=%d", rc);
    vsclear(vs);

    for(n=0;n<lrecl;n++) {
        buf[n] = (char)n;
    }

    while(!vserror(vs)) {
        rc = vswrite(vs, buf, lrecl, 0, 4);
        if (rc) {
            wtof("main rc=%d", rc);
            break;
        }
#if 1
        n = vstell(vs);
        wtof("RBA   %08X %u", n, n);
#endif
    }
#endif

    wtodumpf(vs, sizeof(VSFILE), "VSFILE");

quit:
    if (buf)    free(buf);
    if (vs)     vsclose(vs);
    return rc;
}
