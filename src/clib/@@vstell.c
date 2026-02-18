#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include "clibvsam.h"

unsigned
__vstell(VSFILE *vs)
{
    unsigned    rba     = 0;
    unsigned    pl[16]  = {0};

    /* get RBA of record just read */
    __asm__("SHOWCB RPL=(%0),FIELDS=RBA,AREA=(%1),LENGTH=4,MF=(G,(%2))"
        : : "r"(&vs->rpl), "r"(&rba), "r"(pl));

quit:
    return rba;
}
