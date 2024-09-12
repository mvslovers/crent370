#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include "clibvsam.h"

int
__vsupdt(VSFILE *vs, void *rec, int reclen)
{
    unsigned        pl[16]  = {0};
    volatile int    rc      = 0;

    __asm__("\n"
    "\tMODCB RPL=(%0),RECLEN=(%1),                                     X\n"
    "\t\tAREALEN=(%1),AREA=(%2),MF=(G,(%3))"
            : : "r"(&vs->rpl), "r"(reclen), "r"(rec), "r"(pl)
            : "1", "14", "15");

    __asm__("LA\t2,PUTDONE\n\t"
            "PUT\tRPL=(%0)\n"
   "PUTDONE\tDS\t0H\n\t"
            "ST\t15,%1"
        : : "r"(&vs->rpl), "m"(rc) : "1", "2", "14", "15");

quit:
    return rc;
}
