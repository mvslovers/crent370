#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include "clibvsam.h"

int
__vsmdfy(VSFILE *vs, void *rec, int reclen, void *key, int keylen)
{
    unsigned    pl[16]  = {0};

    /* common for all VSAM cluster types, record and reclen */
    __asm__("\n"
    "\tMODCB RPL=(%0),RECLEN=(%1),                                     X\n"
    "\t\tAREALEN=(%1),AREA=(%2),MF=(G,(%3))"
            : : "r"(&vs->rpl), "r"(reclen), "r"(rec), "r"(pl)
            : "1", "14", "15" );

    if (!key) goto quit;

    if (vs->type==VSTYPE_RRDS || vs->type==VSTYPE_ESDS) {
        /* set relative record key */
        __asm__("MODCB RPL=(%0),ARG=(%1),MF=(G,(%2))"
                : : "r"(&vs->rpl), "r"(key), "r"(pl)
                : "1", "14", "15" );
    }
    else if (vs->type==VSTYPE_KSDS) {
        /* set keyed sequential key */
        __asm__("MODCB RPL=(%0),ARG=(%1),KEYLEN=(%2),MF=(G,(%3))"
                : : "r"(&vs->rpl), "r"(key), "r"(keylen), "r"(pl)
                : "1", "14", "15" );
    }

quit:
    return 0;
}
