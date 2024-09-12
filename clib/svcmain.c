#include <clibsvc.h>
#include <iharb.h>
#include <clibwto.h>
#include <clibos.h>

/* SVCMAIN() on entry svcregs->r1 has the request code, r15, r0 and r1 parm values are 0 */
/* After return to @@SVC, r15, r0, and r1 values are returned to caller */
int svcmain(SVCREGS *svcregs, unsigned *r15, unsigned *r0, unsigned *r1)
{
    RBBASIC     *rb         = svcregs->rblink;      /* callers request block    */
    char        *p;

    switch(svcregs->r1) {
    case SVCMAIN_SUP:
        /* switch caller to supervisor state */
        *r15 = !(rb->RBOPSWB2 & RBOPSWPS);
        /* R15=0 caller in problem state, otherwise caller already in supervisor state */

        /* remove problem state bit from callers PSW */
        rb->RBOPSWB2 &= ~RBOPSWPS;
        break;

    case SVCMAIN_PROB:
        /* switch caller to problem state */
        *r15 = (rb->RBOPSWB2 & RBOPSWPS);
        /* R15=0 caller in supervisor state, otherwise caller already in problem state */

        /* set problem state bit in callers PSW */
        rb->RBOPSWB2 |= RBOPSWPS;
        break;

    case SVCMAIN_KEY:
        /* return the callers PSW key in R15 */
        *r15 = rb->RBOPSWB2 & 0xF0;

        /* special case, svcregs->r15==0xFF does not change the key */
        /* ... we return the current key in R15 */
        if ((svcregs->r15 & 0xFF) == PSWKEYNONE) break;

        /* if the caller has the key in the lowest bits, shift the key to proper alignment */
        if (svcregs->r15 < 0x10) svcregs->r15 << 4;

        /* remove and replace the callers PSW key value */
        rb->RBOPSWB2 &= 0x0F;                   /* remove   */
        rb->RBOPSWB2 |= (svcregs->r15 & 0xF0);  /* replace  */
        break;

    case SVCMAIN_AUTHON:
        p   = svcregs->jscb;        /* get JSCB address             */
        *r15 = p[0xEC] & 1;         /* R15=0 if not auth, =1 if already auth */
        p[0xEC] |= 1;               /* set JSCBOPTS JSCBAUTH ON     */
        break;

    case SVCMAIN_AUTHOFF:
        p   = svcregs->jscb;        /* get JSCB address             */
        *r15 = !(p[0xEC] & 1);      /* R15=0 if auth, =1 if already not auth */
        p[0xEC] &= 0xFE;            /* set JSCBOPTS JSCBAUTH OFF    */
        break;

    default:
        /* invalid request */
        *r15 = 0xFFFFFFFF;
        break;
    }

    return 0;
}
#if 0
__asm__("IEZJSCB ,");
#endif
