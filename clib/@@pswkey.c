#include <clibos.h>
#include <clibauth.h>
#include <errno.h>

__asm__("\n&FUNC    SETC '__pswkey'");
int __pswkey(unsigned char *savekey)
{
    int     rc  = 0;

    if (!__auth()) return EPERM;    /* operation not permitted  */

    if (__issup()) {
        /* get current PSW key */
        __asm__("IPK\t0\n\tSTC\t2,0(,%0)" : : "r"(savekey) : "2");
        goto quit;
    }

    /* switch to supervisor mode */
    __super(PSWKEYNONE, savekey);

    /* switch back to problem mode */
    __prob(PSWKEYNONE, (void*)0);

quit:
    return rc;
}
