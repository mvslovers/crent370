#include <clibssvt.h>
#include <clibos.h>
#include <errno.h>

__asm__("\n&FUNC    SETC 'ssvt_funcmap'");
int ssvt_funcmap(SSVT *ssvt, unsigned index, unsigned funcnum)
{
    int             restore     = 0;
    unsigned char   prevkey;

    if (!ssvt)          return EPERM;

    /* index number must be 0 through 256 inclusive (0 disables the function) */
    if (index > 256)                return EPERM;

    /* funcnum number must be 1 through 256 inclusive */
    if (!funcnum)                   return EPERM;
    if (funcnum > 256)              return EPERM;

    /* make funcnum relative to zero */
    funcnum--;

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

    /* update the SSVT index of the function address */
    ssvt->ssvtfcod[funcnum] = index;    /* set index of function address or 0 */

    if (restore) {
        /* reset PSW key to callers key */
        __asm__("LR\t2,%0               get prev psw key\n\t"
                "SPKA\t0(2)             save in psw" : : "r"(prevkey) : "2");
    }
}
