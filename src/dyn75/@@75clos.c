/* @@75CLOS.C
** Close socket
*/
#include "__75.h"
#include "socket.h"
#include "clibsock.h"

/* closesocket() */
__asm__("\n&FUNC    SETC 'closesocket'");
extern int
closesocket(int ss)
{
    int     rc  = 0;
    PL75    pl;

#if 0
    memset(&pl, 0, sizeof(pl));
#else
    __asm__("XC\t0(64,%0),0(%0)     clear __75 parameter list" : : "r" (&pl));
#endif

    pl.r7   = (unsigned) 12;        /* function code for closesocket() */
    pl.r8   = (unsigned) ss;        /* socket */

    __75(&pl);

    __sodel(ss);

    return rc;
}
