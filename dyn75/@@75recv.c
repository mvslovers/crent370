/* @@75RECV.C
** Receive data from a socket
*/
#include "__75.h"
#include "socket.h"
#include "errno.h"

/* recv() */
__asm__("\n&FUNC    SETC 'recv'");
extern int
recv(int ss, void *buf, int len, int flags)
{
    int     rc;
    PL75    pl;

    for(;;) {
        __asm__("XC\t0(64,%0),0(%0)     clear __75 parameter list"
            : : "r" (&pl));
        pl.r6   = (unsigned) buf;
        pl.r7   = (unsigned) 11;    /* function code for recv() */
        pl.r8   = (unsigned) ss;
        pl.r9   = (unsigned) len;

        __75(&pl);

        rc = (int) pl.r4;
        if (rc!=-2) break;

        /* we need to wait */
        __asm__("STIMER WAIT,BINTVL==F'8'   0.08 seconds" : : : "0", "1");
    }

    if (rc==-1) {
        pl.r1   = (unsigned) 0;
        pl.r7   = (unsigned) 2;     /* function code for get error */
        __75(&pl);
#if 0
        __75vect->error = (int) pl.r4;
        errno = __75vect->error;
#else
        errno = (int) pl.r4;
#endif
    }

    return rc;
}
