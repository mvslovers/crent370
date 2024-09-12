#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include "clibvsam.h"

static int restore(VSFILE *vs);

int
__vswrit(VSFILE *vs, void *rec, int reclen, void *key, int keylen)
{
    unsigned        pl[16]  = {0};
    volatile int    rc      = 0;

    /* modify common RPL parameters */
    __vsmdfy(vs, rec, reclen, key, keylen);

    vs->flags   |= VSFILE_FLAG_WRITE;

    if (vs->mode==VSMODE_UPD) {
        /* turn off UPD for record insertion */
        __asm__("MODCB RPL=(%0),OPTCD=(NUP),MF=(G,(%1))"
            : : "r"(&vs->rpl), "r"(pl) : "1", "14", "15");
        /* SYNAD exit will call our restore function on error */
        vs->vsreset = restore;
    }

    /* get record from VSAM dataset */
    __asm__("LA\t2,PUTDONE\n\t"
            "PUT\tRPL=(%0)\n"
   "PUTDONE\tDS\t0H\n\t"
            "ST\t15,%1"
        : : "r"(&vs->rpl), "m"(rc) : "1", "2", "14", "15");

    if (vs->mode==VSMODE_UPD && vs->vsreset) {
        /* restore UPD in RPL */
        restore(vs);
    }

quit:
    return rc;
}

static int
restore(VSFILE *vs)
{
    unsigned    pl[16]  = {0};

    __asm__("MODCB RPL=(%0),OPTCD=(UPD),MF=(G,(%1))"
        : : "r"(&vs->rpl), "r"(pl) : "1", "14", "15");

    vs->vsreset = 0;

    return 0;
}
