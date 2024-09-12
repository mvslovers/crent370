#include <clibssvt.h>
#include <clibos.h>

__asm__("\n&FUNC    SETC 'ssvt_new'");
SSVT * ssvt_new(unsigned funcmax)
{
    int             restore = 0;
    SSVT            *ssvt;
    unsigned        size;
    unsigned char   prevkey;

    /* sanity check */
    if (funcmax > 256) return (SSVT*)0;

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

    /* calulate size of SSVT we need to allocate */
    size = sizeof(SSVT) + (funcmax * 4);

    /* allocate SSVT in subpool 241, key 0 */
    ssvt = getmain(size, 241);
    if (ssvt) {
        /* note: our getmain clears allocated storage, so no need to clear it again */

        /* set the maximum number of functions we support */
        ssvt->ssvtfnum  = funcmax;
    }

    if (restore) {
        /* reset PSW key to callers key */
        __asm__("LR\t2,%0               get prev psw key\n\t"
                "SPKA\t0(2)             save in psw" : : "r"(prevkey) : "2");
    }

    return ssvt;
}
