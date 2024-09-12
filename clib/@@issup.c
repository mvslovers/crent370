#include <clibos.h>
#include <clibauth.h>
#include <errno.h>

__asm__("\n&FUNC    SETC '__issup'");
int __issup(void)
{
    int     rc  = 0;

    /* check for SUPERVISOR mode */
    __asm__("TESTAUTH\tFCTN=0,STATE=YES,KEY=NO,RBLEVEL=1\n\tST\t15,0(,%0)" : : "r"(&rc));
    if (rc==0) {
        return 1;   /* currently in SUPERVISOR mode */
    }

    return 0;   /* not in SUPERVISOR mode */
}
