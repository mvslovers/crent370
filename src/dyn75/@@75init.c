/* @@75INIT.C
** Initialize API
*/
#include "__75.h"
#include "socket.h"
#include "clibsock.h"
#include "cliblock.h"
#include "clibary.h"
#include "clibgrt.h"

__asm__("\n&FUNC    SETC '@@75init'");
extern int
__75init(void)
{
    CLIBGRT *grt    = __grtget();
    PL75    pl;

    lock(&grt->grtsock, 0);
    if (!grt->grtsock) {
        grt->grtsock = arraynew(FD_SETSIZE);
    }
    unlock(&grt->grtsock, 0);

#if 0
    memset(&pl, 0, sizeof(pl));
#else
    __asm__("XC\t0(64,%0),0(%0)     clear __75 parameter list" : : "r" (&pl));
#endif

    pl.r7   = (unsigned) 1;

    __75(&pl);

    lock(&grt->grtsock, 0);
    grt->grtflag1 |= GRTFLAG1_SOCKINIT;
    unlock(&grt->grtsock, 0);

    return pl.r15;
}
