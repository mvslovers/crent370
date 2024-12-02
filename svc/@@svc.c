#include <clibsvc.h>
#include <clibwto.h>
#include <clibstae.h>

void __svc(SVCREGS *svcregs)
{
    int         rc;
    unsigned    r15     = 0;
    unsigned    r0      = 0;
    unsigned    r1      = 0;

#if 0   /* note: using wtodumpf() adds abot 16K of code */
    wtodumpf(svcregs, sizeof(SVCREGS), "%s SVCREGS", __func__);
#endif

    /* give control to svcmain() to perform the request */
    rc = svcmain(svcregs, &r15, &r0, &r1);

    /* return values back to caller */
    svcregs->r15    = r15;
    svcregs->r0     = r0;
    svcregs->r1     = r1;
}
#if 0
__asm__("CVT LIST=YES,DSECT=YES");
#endif
