/* OSXDCB.C - allocate a DCB for EXCP access */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "osio.h"

DCB *
osxdcb(const char *ddname, EXITLIST *exitlist)
{
    DCB     *dcb    = calloc(1, sizeof(DCB));
    int     i;

    if (!dcb) goto quit;

    __asm__("MVC   0(PROTOLEN,%0),PROTODCB" : : "r"(dcb));

    if (ddname) {
        if (ddname[2]==':') ddname += 3;
        for (i=0; i < 8 && ddname[i]; i++) {
            dcb->dcbddnam[i] = toupper(ddname[i]);
        }
    }

    if (exitlist) {
        unsigned *list = calloc(1, sizeof(unsigned)*10);   /* up to 10 exits */

        if (!list) goto quit;

        dcb->dcbpriv  = (void*)list;    /* save address for cleanup */
        dcb->dcbexlst = (void*)list;
        for(i=0; i < 10; i++, exitlist++) {
            list[i] = exitlist->exit_code << 24 |
                ((unsigned)exitlist->exit_addr & 0x00FFFFFF);
            if (exitlist->exit_code & 0x80) break;
        }
        if (i==10) i--;
        list[i] |= 0x80000000;  /* tag end of exit list */
    }

quit:
    return dcb;
}

    __asm__("\n"
"* DCB Prototype\n"
"PROTODCB DCB   DSORG=PS,MACRF=E\n"
"PROTOLEN EQU   *-PROTODCB");

#if 0
#define OFF(a) (unsigned) &(((DCB*)0)->a)

int
main(int argc, char**argv)
{
    wtof("DCBDDNAM  %02X", OFF(dcbddnam));
    wtof("DCBTIOT   %02X", OFF(dcbtiot));
    wtof("DCBGERR   %02X", OFF(dcbgerr));
    wtof("DCBIOBA   %02X", OFF(dcbioba));
    wtof("DCBDIRCT  %02X", OFF(dcbdirct));
    wtof("DCBLRECL  %02X", OFF(dcblrecl));
    wtof("DCBEOB    %02X", OFF(dcbeob));
    wtof("DCB       %02X", sizeof(DCB));
}
#endif
