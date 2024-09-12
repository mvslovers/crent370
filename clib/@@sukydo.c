#include <clibos.h>

__asm__("\n&FUNC    SETC 'super_key_do'");
int super_key_do(unsigned char pswkey, void *func, ...)
{
    int             rc;
    void            *r1 = (void*)(&func)+4;
    int             sup;
    unsigned char   prevkey;

    /* are we already in supervisor mode? */
    sup = __issup();
    if (!sup) {
        /* no, switch to supervisor mode */
        __asm__("MODESET\tMODE=SUP      switch to supervisor state\n\t"
                "LR\t%0,15              save return code" : "=r"(rc) : : "1", "14", "15");
        if (rc) goto quit;  /* not likely, but just in case */
    }

    /* save current PSW key */
    __asm__("IPK\t0             get psw key in R2\n\t"
            "STC\t2,0(,%0)      save psw key" : : "r"(&prevkey) : "2");

    /* are we to set a new PSW key? */
    if (pswkey != PSWKEYNONE) {
        /* yes, set new PSW key */
        /* we'll allow for PSW key in low nibble value and shift if needed */
        if (pswkey < 0x10) pswkey = pswkey << 4;    /* put key value in next higher nibble */

        /* set new PSW key */
        __asm__("IC\t2,0(,%0)           get new psw key\n\t"
                "SPKA\t0(2)             save in psw" : : "r"(&pswkey) : "2");
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

    /* reset PSW key to callers key */
    __asm__("IC\t2,0(,%0)           get prev psw key\n\t"
            "SPKA\t0(2)             save in psw" : : "r"(&prevkey) : "2");

    if (!sup) {
        /* return caller to problem state */
        __asm__("MODESET\tMODE=PROB     switch to problem state" : : : "1", "14", "15");
    }

quit:
    return rc;
}

