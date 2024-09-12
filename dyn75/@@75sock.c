/* @@75SOCK.C
** request socket allocation
*/
#include "__75.h"
#include "socket.h"
#include "errno.h"
#include "clibsock.h"
#include "clibgrt.h"

/* socket() */
__asm__("\n&FUNC    SETC 'socket'");
extern int
socket(int af, int type, int protocol)
{
    CLIBGRT *grt    = __grtget();
    int     socket  = -1;
    PL75    pl;

#if 0
    memset(&pl, 0, sizeof(pl));
#else
    __asm__("XC\t0(64,%0),0(%0)     clear __75 parameter list" : : "r" (&pl));
#endif

    if (!(grt->grtflag1 & GRTFLAG1_SOCKINIT)) {
                                    /* Need a socket before anything else... */
        __75init();                 /* so it's the best place to init.       */
                                    /* The Host PC has it's own trigger too! */
    }

    pl.r8   = (unsigned) af << 16;  /* address family */
    pl.r9   = (unsigned) type;      /* socket type */
    pl.r8   = pl.r8 BOR pl.r9;
    pl.r9   = (unsigned) protocol;  /* protocol */
    pl.r7   = (unsigned) 5;         /* function code */

    __75(&pl);

    socket  = (int) pl.r4;          /* socket or error (-1) */
    if (socket >= 0) {
        /* success */
        __soadd(socket, 0, 0);
        goto quit;
    }

    pl.r1   = (unsigned) 0;
    pl.r7   = (unsigned) 3;         /* function code for get error */

    __75(&pl);
#if 0
    __75vect->error = (int) pl.r4;  /* remember error */
    errno = __75vect->error;
#else
    errno = (int) pl.r4;
#endif
quit:
    return socket;
}
