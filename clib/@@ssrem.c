#include <clibssct.h>
#include <clibos.h>

__asm__("\n&FUNC    SETC 'ssct_remove'");
int ssct_remove(SSCT *ssct)
{
    unsigned        *cvt        = *(unsigned**)16;      /* get CVT pointer from PSA */
    SSCT            *inst       = ssct_find(0);         /* get first subsystem      */
    int             rc          = 4;                    /* assume not found         */
    unsigned char   prevkey;

    /* save current PSW key */
    __asm__("IPK\t0             get psw key in R2\n\t"
            "LR\t%0,2           save psw key in register" : "=r"(prevkey) : : "2");

    if (prevkey != PSWKEY0) {
        /* set PSW key 0 */
        __asm__("SLR\t2,2               PSW key 0 value\n\t"
                "SPKA\t0(2)             save in psw" : : : "2");
    }

    /* search installed subsystems */
    while(inst) {
        /* is this subsystem 'next' value our subsystem pointer? */
        if (inst->ssctscta == ssct) {
            /* yes, remove ssct from installed next */
            inst->ssctscta = ssct->ssctscta;    /* installed->next = our subsystem->next */
            ssct->ssctscta = (SSCT*)0;          /* our subsystem->next = NULL            */
            rc = 0;                             /* indicate success                      */
            break;
        }
        inst = inst->ssctscta;
    }

    if (prevkey != PSWKEY0) {
        /* reset PSW key to callers key */
        __asm__("LR\t2,%0               get prev psw key\n\t"
                "SPKA\t0(2)             save in psw" : : "r"(prevkey) : "2");
    }

    return rc;
}
