#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include "clibvsam.h"

int
__vssteq(VSFILE *vs, void *rec, int reclen, void *key, int keylen)
{
    unsigned        pl[16]  = {0};
    volatile int    rc      = 0;

    /* modify common RPL parameters */
    __vsmdfy(vs, rec, reclen, key, keylen);

    vs->vsreset = 0;

    __asm__("MODCB RPL=(%0),OPTCD=(KEQ),MF=(G,(%1))"
            : : "r"(&vs->rpl), "r"(pl) : "1", "14", "15");

    __asm__("LA\t2,DONE\n\t"
            "POINT\tRPL=(%0)\n"
   "DONE\tDS\t0H\n\t"
            "ST\t15,%1"
        : : "r"(&vs->rpl), "m"(rc) : "1", "2", "14", "15");
#if 0
    __asm__("MODCB RPL=(%0),OPTCD=(KEQ),MF=(G,(%1))"
            : : "r"(&vs->rpl), "r"(pl) : "1", "14", "15");
#endif

quit:
    return rc;
}
