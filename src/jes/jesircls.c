
#include <stdio.h>
#include <mvssupa.h>
#include "clibvsam.h"

int jesircls(VSFILE *vsfile)
{
    int rc = 0;

    /* call ENDREQ macro */
    __asm__("ENDREQ RPL=(%0)\n\t"
            "ST  15,%1\n"
        : : "r"(&vsfile->rpl), "m"(rc) : "1", "14", "15");

    vsclose(vsfile);

quit:
    return rc;
    
}

