/* @@75SNAM.C
** getsockname()
*/
#include "__75.h"
#include "socket.h"
#include "errno.h"
#include "clibsock.h"

/* getsockname() */
__asm__("\n&FUNC    SETC 'getsockname'");
extern int
getsockname(int ss, struct sockaddr *addr, int *addrlen)
{
    CLIBSOCK    *s  = 0;
    int         rc  = 0;
    PL75        pl;

    if (addr) {
        /* do we have this socket in our cache? */
        if (__sofind(ss,&s)) {
            /* yes, do we have socket name? */
            if (s && memcmp(s->name, "\x00\x00\x00\x00", 4)!= 0) {
                /* yes, return cached name */
                int len = addrlen ? *addrlen : sizeof(*addr);
                if (len > sizeof(s->name)) len = sizeof(s->name);
                memcpy(addr, s->name, len);
                goto quit;
            }
        }
    }

#if 0
    memset(&pl, 0, sizeof(pl));
#else
    __asm__("XC\t0(64,%0),0(%0)     clear __75 parameter list" : : "r" (&pl));
#endif

    pl.r6   = (unsigned) addr;      /* sockaddr pointer */
    pl.r7   = (unsigned) 16;        /* function code for getsockname() */
    pl.r8   = (unsigned) ss;        /* socket */

    __75(&pl);

    rc = (int) pl.r4;
    if (rc!=-1) goto quit;

    pl.r1   = (unsigned) 0;
    pl.r7   = (unsigned) 2;         /* function code for get error */
    __75(&pl);
#if 0
    __75vect->error = (int) pl.r4;  /* save error code */
    errno = __75vect->error;
#else
    errno = (int)pl.r4;
#endif

quit:
    if (addrlen) *addrlen = sizeof(struct sockaddr);
    return rc;
}
