#include <iefsscs.h>
#include <iefssso.h>
#include <clibstr.h>
#include <clibjes2.h>
#include "clibstae.h"               /* C runtime recovery routines  */
#include <hasppso.h>                /* Process sysout control block */

static void authorize(void);
static int makeauth(const char *id);

int main(int argc, char **argv)
{
    int         rc;
    SSSO        ssso = {0};

    rc = makeauth(argv[0]);
    if (rc) goto quit;

    rc = jesxwrtr(&ssso, "G", NULL, NULL);
    switch (rc) {
        case SSSORTOK:              /*  0   dataset selected                */
            /* allocate selected SYSOUT dataset and process it */
            break;
        case SSSOEODS:              /*  4   no more datasets                */
            /* sleep a bit then try again */
            break;
#if 0
        case SSSONJOB:              /*  8   JOB NOT FOUND                   */
        case SSSOINVA:              /* 12   INVALID SEARCH ARGUMENTS        */
        case SSSOUNAV:              /* 16   UNABLE TO PROCESS NOW           */
        case SSSODUPJ:              /* 20   DUPLICATE JOBNAMES              */
        case SSSOINVJ:              /* 24   INVALID JOBNAME/JOBID COMBO     */
        case SSSOIDST:              /* 28   INVALID DESTINATION SPECIFIED   */
        case -1:                    /* -1   bad/missing required parms      */
#endif
        default:
            wtof("%s unexpected return code from jesxwrtr rc=%d", rc);
            goto quit;
    }

quit:
    jesxdone(&ssso);
    return rc;
}

__asm__("\n&FUNC    SETC 'makeauth'");
static int
makeauth(const char *id)
{
    int     rc      = 0;
    int     steplib = 0;

    if (!id) id = "TESTWRTR";

    /* check for APF authorization */
    __asm__("TESTAUTH\tFCTN=1\n\tST\t15,0(,%0)" : : "r"(&rc));
    if (rc==0) {
        wtof("XWRTR010I %s is APF authorized", id);
    }
    else {
        /* get APF authorization */
        try(authorize,0);
        __asm__("TESTAUTH\tFCTN=1\n\tST\t15,0(,%0)" : : "r"(&rc));
        if (rc==0) {
            wtof("XWRTR011I %s was APF authorized via SVC 244", id);
        }
        else {
            wtof("XWRTR012E %s unable to dynamically obtain APF authorization, rc=%d",
                id, rc);
            rc = -1;
            goto quit;
        }
    }

    __asm__("\n"
"         MODESET KEY=ZERO,MODE=SUP\n"
"         ICM   1,15,PSATOLD-PSA(0) Get our TCB address\n"
"         ICM   1,15,TCBJLB-TCB(1)  Get STEPLIB DCB\n"
"         BZ    APFQUIT             No STEPLIB\n"
"         USING IHADCB,1            DECLARE IT\n"
"         L     1,DCBDEBAD          LOAD DEB FOR STEPLIB\n"
"         N     1,=X'00FFFFFF'      FIX HIGH BYTE\n"
"         USING DEBBASIC,1\n"
"         OI    DEBFLGS1,DEBAPFIN   TURN ON APF LIBRARY BIT\n"
"         DROP  1\n"
"APFQUIT  DS    0H\n"
"         ST    1,0(,%0)\n"
"         MODESET KEY=NZERO,MODE=PROB" : : "r"(&steplib));

    if (steplib) {
        wtof("XWRTR013I STEPLIB is now APF authorized");
    }

quit:
    return rc;
}

__asm__("\n&FUNC    SETC 'authorize'");
static void authorize(void)
{
    __asm__(
        "SR\t0,0\n\t"
        "LA\t1,1\n\t"
        "SVC\t244"
    );
}

__asm__("PRINT NOGEN");
__asm__("IHAPSA ,            MAP LOW STORAGE");
__asm__("CVT DSECT=YES");
__asm__("IKJTCB DSECT=YES");
__asm__("DCBD DSORG=PO,DEVD=DA");
__asm__("IEZDEB");
__asm__("PRINT GEN");
__asm__("CSECT");

