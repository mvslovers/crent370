#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include "clibvsam.h"

int
__vsread(VSFILE *vs, void *rec, int reclen, void *key, int keylen)
{
    unsigned    pl[16]  = {0};
    int         rc      = 0;

    if (key && keylen) {
        /* position to desired record */
        __vssteq(vs, rec, reclen, key, keylen);
    }
    else {
        /* modify common RPL parameters */
        __vsmdfy(vs, rec, reclen, key, keylen);
    }

    vs->flags   &= (0xFF - VSFILE_FLAG_WRITE);

    /* get record from VSAM dataset */
    __asm__("LA\t2,GETDONE\n\t"
            "GET\tRPL=(%0)\n"
   "GETDONE\tDS\t0H\n\t"
            "ST\t15,%1"
        : : "r"(&vs->rpl), "m"(rc) : "1", "2", "14", "15");

    if (vs->flags & VSFILE_FLAG_ERROR) {
        /* SYNAD exit has indicated an error */
        errno = EVSERROR;
        reclen = -2;
        goto quit;
    }
    if (vs->flags & VSFILE_FLAG_EOF) {
        /* EODAD exit has indicated end of file */
        reclen = -1;
        goto quit;
    }

    /* get length of record just read */
    __asm__("SHOWCB RPL=(%0),FIELDS=RECLEN,AREA=(%1),LENGTH=4,MF=(G,(%2))"
        : : "r"(&vs->rpl), "r"(&reclen), "r"(pl));

quit:
    return reclen;
}
