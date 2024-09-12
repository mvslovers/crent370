/* @@UATASK.C */
#include "clibcrt.h"
#include "clibauth.h"
#include "clibstae.h"

static void authorize(void);
static void unauthorize(void);

int
__uatask(void)
{
    CLIBCRT *crt    = __crtget();
    int     rc      = 0;

    if (!crt) goto quit;

    if (!(crt->crtauth & CRTAUTH_ON)) goto quit;

    try(unauthorize,0);
    crt->crtauth &= 0xFF - CRTAUTH_ON;

quit:
    return rc;
}

__asm__("\n&FUNC    SETC 'unauthorize'");
static void unauthorize(void)
{
    __asm__(
        "SR\t0,0\n\t"
        "SR\t1,1\n\t"
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
