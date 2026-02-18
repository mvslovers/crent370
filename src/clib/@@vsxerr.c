#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include "clibvsam.h"

/* This is the VSAM common error handler for LERAD and SYNAD errors */
int
__vsxerr(RPL *rpl, int code)
{
    VSFILE          *vs     = (VSFILE*)((char*)rpl - offsetof(VSFILE,rpl));
    unsigned        pl[16]  = {0};
    unsigned char   fdbk[4] = {0};
    int (*reset)(VSFILE *);

    vs->flags   |= VSFILE_FLAG_ERROR;

    __asm__("\n"
    "\tSHOWCB RPL=(%0),                                               X\n"
    "\t\tFIELDS=FDBK,AREA=(%1),LENGTH=4,MF=(G,(%2))"
        : : "r"(rpl), "r"(fdbk), "r"(pl) : "1", "14", "15" );

    vs->rc          = fdbk[1];
    vs->component   = fdbk[2];
    vs->rsn         = fdbk[3];

    if (vs->vsreset) {
        if ((vs->flags & VSFILE_FLAG_STARTGE) ||
            (vs->flags & VSFILE_FLAG_WRITE)) {
            reset = vs->vsreset;
            reset(vs);
        }
    }

    return code;
}
