#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mvssupa.h>
#include "clibvsam.h"

int jesirput(VSFILE *vsfile, const char *rec)
{
    int      rc     = -1;

    if (rec == NULL || rec[0] == 0 || strlen(rec) > 80) goto quit;
   
    vsfile->flags |= VSFILE_FLAG_WRITE;
    
    strcpyp(vsfile->rpl.rplarea, 80, (void *)rec, ' ');

    __asm__("PUT RPL=(%0)\n\t"
            "ST  15,%1"
        : : "r"(&vsfile->rpl), "m"(rc) : "1", "14", "15");
    
quit:
    return rc;
}

