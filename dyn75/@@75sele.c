/* @@75SELE.C
** select ready socket(s).
**
** __75() select() sub codes (r8):
**  0 = initialize select, allocates buffers
**  1 = set select read fd_set
**  2 = set select write fd_set
**  3 = set select exception fd_set
**  4 = run select, does not block or obey timeval
**  5 = get select read fd_set
**  6 = get select write fd_set
**  7 = get select exception fd_set
**  8 = terminate select, deallocate buffers
*/
#include "__75.h"
#include "socket.h"
#include "errno.h"

/* select() */
__asm__("\n&FUNC    SETC 'select'");
extern int
select(int maxsock, fd_set *r, fd_set *w, fd_set *e, timeval * t)
{
    /* use the selectex() function with a NULL ECB list/array */
    int     rc = __75selx(maxsock, r, w, e, t, (void*)0);

    return rc;
}
