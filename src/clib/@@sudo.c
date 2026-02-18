#include <clibos.h>

__asm__("\n&FUNC    SETC 'super_do'");
int super_do(void *func, ...)
{
    int         rc;
    void        *r1 = (void*)(&func)+4;
    int         sup;

    /* are we already in supervisor mode? */
    sup = __issup();
    if (!sup) {
        /* no, switch to supervisor mode */
        __asm__("MODESET\tMODE=SUP\n\tLR\t%0,15" : "=r"(rc) : : "1", "14", "15");
        if (rc) goto quit;  /* not likely, but just in case */
    }

    /* call the function in supervisor state */
    __asm__(
    "LR\t15,%1          => function to call \n\t"
    "LR\t1,%2           => parameter list\n\t"
    "BALR\t14,15         call function\n\t"
    "LR\t%0,15          save return code"
    : "=r" (rc)
    : "r" (func), "r" (r1)
    : "0", "1", "14", "15");

    if (!sup) {
        /* return caller to problem state */
        __asm__("MODESET\tMODE=PROB" : : : "1", "14", "15");
    }

quit:
    return rc;
}
