/* @@75SEND.C
** Send data to a socket
*/
#include "__75.h"
#include "socket.h"
#include "errno.h"

/* send() */
__asm__("\n&FUNC    SETC 'send'");
extern int
send(int ss, const void *buf, int len, int flags)
{
    int     rc;
    PL75    pl;

#if 0
    memset(&pl, 0, sizeof(pl));
#else
    __asm__("XC\t0(64,%0),0(%0)     clear __75 parameter list" : : "r" (&pl));
#endif

#if 0
    wtof("__75send(%d,%08X,%d,%d)", ss, buf, len, flags);
    wtof("%-60.60s", buf);
#endif

    pl.r1   = (unsigned) len;
    pl.r5   = (unsigned) buf;
    pl.r7   = (unsigned) 10;        /* function code for send() */
    pl.r8   = (unsigned) ss;

    __75(&pl);

    rc = (int) pl.r4;
#if 0
    wtof("__75send() rc=%d", rc);
#endif
    if (rc!=-1) goto quit;

    pl.r1   = (unsigned) 0;
    pl.r7   = (unsigned) 2;         /* function code for get error */
    __75(&pl);
#if 0
    __75vect->error = (int) pl.r4;
    errno = __75vect->error;
#else
    errno = (int) pl.r4;
#endif
quit:
    return rc;
}
