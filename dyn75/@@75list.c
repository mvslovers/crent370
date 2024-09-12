/* @@75LIST.C
** listen()
*/
#include "__75.h"
#include "socket.h"
#include "errno.h"

/* listen() */
__asm__("\n&FUNC    SETC 'listen'");
extern int
listen(int ss, int backlog)
{
    int     rc;
    PL75    pl;

#if 0
    memset(&pl, 0, sizeof(pl));
#else
    __asm__("XC\t0(64,%0),0(%0)     clear __75 parameter list" : : "r" (&pl));
#endif

    pl.r7   = (unsigned) 8;         /* function code for listen() */
    pl.r8   = (unsigned) ss;        /* socket */
    pl.r9   = (unsigned) backlog;

    __75(&pl);

    rc      = (int)pl.r4;           /* success? */
    if (rc==0) goto quit;           /* yes, we're done */

    /* get error code */
    pl.r1   = (unsigned) 0;
    pl.r7   = (unsigned) 2;         /* function code for get error */

    __75(&pl);
#if 0
    __75vect->error = (int)pl.r4;   /* save error code */
    errno = __75vect->error;
#else
    errno = (int) pl.r4;
#endif
quit:
    return rc;
}
