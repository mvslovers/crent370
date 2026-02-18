/* @@AUSTEP.C - APF authorized the STEPLIB dataset */
#include "clibcrt.h"
#include "clibauth.h"

__asm__("\n&FUNC    SETC '__austep'");
int
__austep(void)
{
    CLIBCRT         *crt    = __crtget();
    volatile int    rc      = 0;
    volatile int    steplib = 0;

    /* check for APF authorization */
    __asm__("TESTAUTH\tFCTN=1\n\tST\t15,%0" : "=m" (rc));
    if (rc!=0) goto quit;

    /* we're APF authorized, fixup the STEPLIB DEB if needed */
    __asm__("\n"
"         MODESET KEY=ZERO,MODE=SUP\n"
"         ICM   1,15,PSATOLD-PSA(0) Get our TCB address\n"
"         ICM   1,15,TCBJLB-TCB(1)  Get STEPLIB DCB\n"
"         LA    1,0(,1)             Purify DCB address\n"
"         ST    1,%0            Save STEPLIB DCB address\n"
"         LTR   14,1                Save DCB address\n"
"         BZ    QUITON              No STEPLIB\n"
"         USING IHADCB,1            DECLARE IT\n"
"         L     1,DCBDEBAD          LOAD DEB FOR STEPLIB\n"
"         N     1,=X'00FFFFFF'      FIX HIGH BYTE\n"
"         USING DEBBASIC,1\n"
"         TM    DEBFLGS1,DEBAPFIN   Is STEPLIB authorized?\n"
"         BNO   SETAPF              No, go set APF bit\n"
"         SR    1,1                 Yes, we're not changing STEPLIB\n"
"         ST    1,%0                No STEPLIB change\n"
"         B     QUITON\n"
"SETAPF   DS    0H\n"
"         OI    DEBFLGS1,DEBAPFIN   TURN ON APF LIBRARY BIT\n"
#if 0
"         L     1,DEBDEBAD          Get next DEB address\n"
"         LA    1,0(,1)             Purify DEB address\n"
"         L     15,DEBDCBAD         Get DCB for this next DEB\n"
"         LA    15,0(,15)           Purify address\n"
"         CR    14,15               Same DCB as our STEPLIB?\n"
"         BE    SETAPF              Yes, set the APF bit in this DEB\n"
#endif
"         DROP  1\n"
"QUITON   DS    0H\n"
"         MODESET KEY=NZERO,MODE=PROB" : "=m"(steplib)
    : : "0", "1", "14", "15");

    if (steplib) {
        if (crt) {
            crt->crtauth |= CRTAUTH_STEPLIB;
        }
#if 0
        wtof("STEPLIB is now APF authorized");
#endif
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
