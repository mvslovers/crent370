/* OSDDCB.C - allocate a DCB for BDAM access */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "osio.h"

DCB *
osddcb(const char *ddname)
{
    DCB     *dcb    = (DCB*)0;
    int     i;

    __asm("LA\t0,PROTOLEN\n\t"
          "ST\t0,0(,%0)" : : "r"(&i));

    dcb = calloc(1, i);
    if (!dcb) goto quit;

    __asm__("MVC   0(PROTOLEN,%0),PROTODCB" : : "r"(dcb));

    if (ddname) {
        if (ddname[2]==':') ddname += 3;
        for (i=0; i < 8 && ddname[i]; i++) {
            dcb->dcbddnam[i] = toupper(ddname[i]);
        }
    }

quit:
    return dcb;
}
    __asm__("\n"
"* BDAM DCB Prototype for relative record processing\n"
"PROTODCB DCB   DDNAME=A,DSORG=DA,MACRF=(RIC,WIC),OPTCD=R\n"
"PROTOLEN EQU   *-PROTODCB");
