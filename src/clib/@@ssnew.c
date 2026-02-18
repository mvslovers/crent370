#include <clibssct.h>
#include <clibos.h>
#include <clibstr.h>

__asm__("\n&FUNC    SETC 'ssct_new'");
SSCT *ssct_new(const char *name, SSVT *ssvt, void *suse)
{
    int             restore = 0;
    SSCT            *ssct;
    unsigned char   prevkey;

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

    /* allocate SSCT in subpool 241, key 0 */
    ssct = getmain(sizeof(SSCT), 241);
    if (ssct) {
        /* note: our getmain clears allocated storage, so no need to clear it again */

        memcpy(ssct->ssctid, SSCT_EYE, sizeof(ssct->ssctid));
        if (name) strcpyp(ssct->ssctsnam, sizeof(ssct->ssctsnam), (void*)name, ' ');
        ssct->ssctssvt  = ssvt;
        ssct->ssctsuse  = suse;
    }

    if (restore) {
        /* reset PSW key to callers key */
        __asm__("LR\t2,%0               get prev psw key\n\t"
                "SPKA\t0(2)             save in psw" : : "r"(prevkey) : "2");
    }

    return ssct;
}

