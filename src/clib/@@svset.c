#include <clibssvt.h>
#include <clibos.h>
#include <errno.h>

__asm__("\n&FUNC    SETC 'ssvt_set'");
int ssvt_set(SSVT *ssvt, unsigned index, void *func)
{
    int             restore     = 0;
    unsigned char   prevkey;

    if (!ssvt)          return EPERM;

    /* index number must be 1 through 256 inclusive */
    if (!index)         return EPERM;
    if (index > 256)    return EPERM;

    /* make index relative to zero */
    index--;

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

    /* update the SSVT function address */
    ssvt->ssvtfrtn[index] = func;       /* set function address */

    if (restore) {
        /* reset PSW key to callers key */
        __asm__("LR\t2,%0               get prev psw key\n\t"
                "SPKA\t0(2)             save in psw" : : "r"(prevkey) : "2");
    }
}
