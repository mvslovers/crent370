/* @@AUTASK.C - set APF authorization for task */
#include "clibcrt.h"
#include "clibauth.h"
#include "clibstae.h"

static void authorize(void);

__asm__("\n&FUNC    SETC '__autask'");
int
__autask(void)
{
    CLIBCRT *crt    = __crtget();
    volatile int rc = 0;

    /* check for APF authorization */
    __asm__("TESTAUTH\tFCTN=1\n\tST\t15,%0" : "=m" (rc));
    /* wtof("%s TESTAUTH #1 rc=%d", __func__, rc); */
    if (rc==0) goto quit;

    /* get APF authorization */
    try(authorize,0);

    __asm__("TESTAUTH\tFCTN=1\n\tST\t15,%0" : "=m" (rc));
    /* wtof("%s TESTAUTH #2 rc=%d", __func__, rc); */
    if (rc!=0) goto quit;

    if (crt) {
        /* remember that we now running APF authorized */
        crt->crtauth |= CRTAUTH_ON;
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
