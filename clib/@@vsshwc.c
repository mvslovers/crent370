#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include "clibvsam.h"

int
__vsshwc(ACB *acb, const char *name, char *buf, int buflen)
{
    int         rc      = 0;
    SHWOUT      *out    = 0;
    SHWPL       pl      = {0};
    char        tmp[44];

    out             = (SHWOUT*)buf;
    out->shwlen1    = (unsigned short)buflen;

    strcpyp(tmp, sizeof(tmp), name, ' ');

    __asm__("SHOWCAT ACB=(%0),AREA=(%1),NAME=(%2),MF=(B,(%3))"
        : : "r"(acb), "r"(buf), "r"(tmp), "r"(&pl) : "1", "14", "15");

    __asm__("SHOWCAT MF=(E,(%0))\n\t"
            "ST\t15,%1" : : "r"(&pl), "m"(rc) : "1", "14", "15");

    return rc;
}
