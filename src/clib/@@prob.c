
#include <clibos.h>
#include <clibauth.h>
#include <errno.h>

__asm__("\n&FUNC    SETC '__prob'");
int __prob(unsigned char pswkey, unsigned char *savekey)
{
    int     rc  = 0;

    if (!__isauth()) return EPERM;    /* operation not permitted  */

    /* are we already in supervisor mode? */
    if (__issup()) {
        /* yes */
        if (savekey) {
            /* get current PSW key */
            __asm__("IPK\t0\n\tSTC\t2,0(,%0)" : : "r"(savekey) : "2");
        }

        /* are we to set a new PSW key? */
        if (pswkey != PSWKEYNONE) {
            /* yes, set new PSW key */
            /* we'll allow for PSW key in low nibble value and shift if needed */
            if (pswkey < 0x10) pswkey = pswkey << 4;    /* put key value in next higher nibble */

            /* set new PSW key */
            __asm__("IC\t2,0(,%0)\n\tSPKA\t0(2)" : : "r"(&pswkey) : "2");
        }

        /* switch to problem mode */
        __asm__("MODESET\tMODE=PROB\n\tST\t15,0(,%0)" : : "r"(&rc) : "1", "14", "15");
        goto quit;
    }

    /* we're already in problem mode, so nothing we can do */
    if (savekey) *savekey = PSWKEYNONE; /* we can't extract the PSW key while in problem mode */

quit:
    return rc;
}
