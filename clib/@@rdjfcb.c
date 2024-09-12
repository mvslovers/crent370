/* @@RDJFCB.C - read job file control block for DCB */
#include "osjfcb.h"

int
__rdjfcb(DCB *dcb, JFCB *jfcb)
{
    int         rc          = -1;
    unsigned    newlist     = 0x87000000 | ((unsigned)jfcb & 0x00FFFFFF);
    unsigned    plist       = 0x80000000;
    unsigned    exlst;

    if (!dcb) goto quit;
    if (!jfcb) goto quit;

    exlst = (unsigned)dcb->dcbexlst;
    dcb->dcbexlst = (void*) ((exlst & 0xFF000000) | (unsigned)&newlist);

    __asm__("RDJFCB ((%1)),MF=(E,(%2))\n"
"         ST     15,%0"
        : "=m"(rc)
        : "r"(dcb), "r"(&plist)
        : "1", "14", "15" );

    dcb->dcbexlst = (void*)exlst;

quit:
    return rc;
}
#if 0
__asm__("\n"
"EX1       RDJFCB (0),MF=L");
#endif
