#include <clibssct.h>
#include <clibos.h>

__asm__("\n&FUNC    SETC 'ssct_free'");
void ssct_free(SSCT *ssct)
{
    int             restore     = 0;
    unsigned char   prevkey;

    if (!ssct) return;

    /* save current PSW key */
    __asm__("IPK\t0             get psw key in R2\n\t"
            "LR\t%0,2           save psw key in register" : "=r"(prevkey) : : "2");

    if (prevkey != PSWKEY0) {
        /* we need to switch to KEY 0 */
        restore = 1;    /* restore the key before we return to caller */

        /* set PSW key 0 */
        __asm__("SLR\t2,2               PSW key 0 value\n\t"
                "SPKA\t0(2)             save in psw" : : : "2");
    }

    /* release the SSCT storage */
    freemain(ssct);

    if (restore) {
        /* reset PSW key to callers key */
        __asm__("LR\t2,%0               get prev psw key\n\t"
                "SPKA\t0(2)             save in psw" : : "r"(prevkey) : "2");
    }
}
