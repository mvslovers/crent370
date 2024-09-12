#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include "clibvsam.h"

unsigned
__vscinv(VSFILE *vs)
{
    unsigned    cinv    = 0;
    unsigned    pl[16]  = {0};

    /* get LRECL of data component */
    __asm__("SHOWCB ACB=(%0),FIELDS=CINV,AREA=(%1),LENGTH=4,MF=(G,(%2))"
        : : "r"(&vs->acb), "r"(&cinv), "r"(pl));

quit:
    return cinv;
}
