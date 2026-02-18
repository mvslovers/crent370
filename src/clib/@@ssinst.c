#include <clibssct.h>
#include <clibos.h>

__asm__("\n&FUNC    SETC 'ssct_install'");
int ssct_install(SSCT *ssct, const char *after_name)
{
    unsigned        *cvt        = *(unsigned**)16;      /* get CVT pointer from PSA */
    SSCT            *after      = ssct_find(after_name);
    unsigned char   prevkey;

    if (!after) {
        after = ssct_find(0);                           /* get the first subsystem name     */
        while(after->ssctscta) after = after->ssctscta; /* walk the chain until we find the last one */
    }

    /* save current PSW key */
    __asm__("IPK\t0             get psw key in R2\n\t"
            "LR\t%0,2           save psw key in register" : "=r"(prevkey) : : "2");

    if (prevkey != PSWKEY0) {
        /* set PSW key 0 */
        __asm__("SLR\t2,2               PSW key 0 value\n\t"
                "SPKA\t0(2)             save in psw" : : : "2");
    }

    /* insert ssct into subsystem chain */
    ssct->ssctscta      = after->ssctscta;      /* ssct next = after next   */
    after->ssctscta     = ssct;                 /* after next = ssct        */

    if (prevkey != PSWKEY0) {
        /* reset PSW key to callers key */
        __asm__("LR\t2,%0               get prev psw key\n\t"
                "SPKA\t0(2)             save in psw" : : "r"(prevkey) : "2");
    }

    return 0;
}

