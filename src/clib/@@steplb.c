/* @@STEPLB.C - returns DCB address or NULL for STEPLIB DD */
#include "clibos.h"

__asm__("\n&FUNC    SETC '__steplb'");
void *
__steplb(void)
{
    void    *steplib;

    __asm__("\n"
"         ICM   1,15,PSATOLD-PSA(0) Get our TCB address\n"
"         ICM   1,15,TCBJLB-TCB(1)  Get STEPLIB DCB\n"
"         LA    1,0(,1)             Purify DCB address\n"
"         LR    %0,1                Save STEPLIB DCB address"
    : "=r"(steplib) : : "1");

    return steplib;
}

__asm__("PRINT NOGEN");
__asm__("IHAPSA ,            MAP LOW STORAGE");
__asm__("CVT DSECT=YES");
__asm__("IKJTCB DSECT=YES");
__asm__("DCBD DSORG=PO,DEVD=DA");
__asm__("IEZDEB");
__asm__("PRINT GEN");
__asm__("CSECT");

