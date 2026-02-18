/* @@CTWAIT.C - cthread_wait()
*/
#include "clibthrd.h"

#if 0
#define WTODEBUG    /* define for wtof() debug messages */
#endif

__asm__("\n&FUNC    SETC 'cthread_wait'");
int
cthread_wait(unsigned *ecb)
{
    int         rc      = 0;
#ifdef WTODEBUG
    wtof("cthdwait(%08X) ecb=%08X before WAIT", ecb, *ecb);
#endif
    if (!ecb) goto quit;

    __asm__("WAIT\tECB=(%0)" : : "r"(ecb) : "1", "14", "15");
#ifdef WTODEBUG
    wtof("cthdwait(%08X) ecb=%08X after WAIT", ecb, *ecb);
#endif

#if 1
    __asm__("\n"
"AGAIN    DS    0H\n"
"         L     0,0(,%1)    get ecb value\n"
"         LA    1,0         new ecb value\n"
"         CS    0,1,0(%1)   save new value in ecb\n"
"         BNZ   AGAIN       ecb changed, try again\n"
"         N     0,=X'3FFFFFFF'\n"
"         ST    0,%0        return ecb value"
        : "=m"(rc) : "r"(ecb));
#else
    rc = (int)(*ecb & 0x3FFFFFFF);
    *ecb = 0;
#endif

quit:
#ifdef WTODEBUG
    wtof("cthdwait(%08X) ecb=%08X, rc=%d", ecb, *ecb, rc);
#endif
    return rc;
}
