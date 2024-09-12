/* @@75IOCT.C
** ioctl for socket
*/
#include "__75.h"
#include "socket.h"
#include "errno.h"

/* ioctlsocket() */
__asm__("\n&FUNC    SETC 'ioctlsocket'");
extern int
ioctlsocket(int ss, int cmd, void *argp)
{
    int     rc;
    PL75    pl;

#if 0
    memset(&pl, 0, sizeof(pl));
#else
    __asm__("XC\t0(64,%0),0(%0)     clear __75 parameter list" : : "r" (&pl));
#endif

    pl.r7   = (unsigned) 15;        /* function code for ioctlsocket() */
    pl.r7   = (unsigned) pl.r7 BOR (ss << 16);  /* socket in high half */
    pl.r8   = (unsigned) cmd;       /* command code */
    pl.r9   = (unsigned) argp;      /* args pointer */

    __75(&pl);

    if (cmd==FIONBIO) {
        /* FIONBIO can't produce an error */
        goto success;
    }

    rc = (int) pl.r4;
    if (rc==-1) {
        /* get error */
        pl.r1   = (unsigned) 0;
        pl.r7   = (unsigned) 2;     /* function code for get error */
        pl.r8   = (unsigned) ss;    /* socket */

        __75(&pl);
#if 0
        __75vect->error = (int) pl.r4;
        errno = __75vect->error;
#else
        errno = (int) pl.r4;
#endif
        goto quit;
    }

success:
    /* success, return result */
    if (argp) {
        *(unsigned*)argp = pl.r4;
    }
    rc = 0;

quit:
    return rc;
}
