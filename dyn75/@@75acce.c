/* @@75ACCE.C
** Accept socket connection
*/
#include "__75.h"
#include "socket.h"
#include "errno.h"
#include "clibsock.h"

/* accept() */
__asm__("\n&FUNC    SETC 'accept'");
extern int
accept(int ss, struct sockaddr_in *name, int *length)
{
    int     rc;
    PL75    pl;
    struct sockaddr_in temp;

    if (!name) {
        name = &temp;
#if 0
        memset(&temp, 0, sizeof(temp));
#else
        __asm__("XC\t0(16,%0),0(%0)     clear temp sockaddr_in" : : "r"(name));
#endif
    }

#if 0
    memset(&pl, 0, sizeof(pl));
#else
    __asm__("XC\t0(64,%0),0(%0)     clear __75 parameter list" : : "r" (&pl));
#endif

    for(;;) {
        pl.r1   = (unsigned) 0;
        pl.r6   = (unsigned) name;
        pl.r7   = (unsigned) 9;     /* function code for accept() */
        pl.r8   = (unsigned) ss;

        __75(&pl);

        rc = (int) pl.r4;
        if (rc!=-2) break;

        /* we need to wait */
        __asm__("STIMER WAIT,BINTVL==F'8'   0.08 seconds" : : : "0", "1");
    }

    if (rc >= 0) {
        /* success */
        struct sockaddr addr = {0};
        int             addrlen = sizeof(addr);

        /* get the local socket name (address and port) */
        __75snam(rc, &addr, &addrlen);

        /* save new socket, local and remote information */
        __soadd(rc, &addr, name);   /* socket, local, remote */
    }

    if (rc==-1) {
        pl.r1   = (unsigned) 0;
        pl.r7   = (unsigned) 2;     /* get error code */
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
