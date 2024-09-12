/* @@UASTEP.C */
#include "clibcrt.h"
#include "clibauth.h"

int
__uastep(void)
{
    CLIBCRT         *crt    = __crtget();
    volatile int    rc      = 0;

    /* check for APF authorization */
    __asm__("TESTAUTH\tFCTN=1\n\tST\t15,%0" : "=m" (rc));
    if (rc!=0) goto quit;

    if (crt) {
        if (!(crt->crtauth & CRTAUTH_STEPLIB)) goto quit;
    }

    /* we're APF authorized, reset the STEPLIB DEB authorization */
    __asm__("\n"
"         MODESET KEY=ZERO,MODE=SUP\n"
"         ICM   1,15,PSATOLD-PSA(0) Get our TCB address\n"
"         ICM   1,15,TCBJLB-TCB(1)  Get STEPLIB DCB\n"
"         LA    1,0(,1)             Purify DCB address\n"
"         LTR   14,1                Save DCB address\n"
"         BZ    QUITOFF             No STEPLIB\n"
"         USING IHADCB,1            DECLARE IT\n"
"         L     1,DCBDEBAD          LOAD DEB FOR STEPLIB\n"
"         N     1,=X'00FFFFFF'      FIX HIGH BYTE\n"
"         USING DEBBASIC,1\n"
"RESETAPF DS    0H\n"
"         NI    DEBFLGS1,X'FF'-DEBAPFIN   TURN OFF APF LIBRARY BIT\n"
#if 0
"         L     1,DEBDEBAD          Get next DEB address\n"
"         LA    1,0(,1)             Purify DEB address\n"
"         L     15,DEBDCBAD         Get DCB for this next DEB\n"
"         LA    15,0(,15)           Purify address\n"
"         CR    14,15               Same DCB as our STEPLIB?\n"
"         BE    RESETAPF            Yes, reset the APF bit in this DEB\n"
#endif
"         DROP  1\n"
"QUITOFF  DS    0H\n"
"         MODESET KEY=NZERO,MODE=PROB" : : : "0", "1", "14", "15");

    if (crt) {
        crt->crtauth &= 0xFF - CRTAUTH_STEPLIB;
    }

quit:
    return rc;
}

__asm__("PRINT NOGEN");
__asm__("IHAPSA ,            MAP LOW STORAGE");
__asm__("CVT DSECT=YES");
__asm__("IKJTCB DSECT=YES");
__asm__("DCBD DSORG=PO,DEVD=DA");
__asm__("IEZDEB");
__asm__("PRINT GEN");
__asm__("CSECT");
