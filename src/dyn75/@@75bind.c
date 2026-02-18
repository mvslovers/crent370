/* @@75BIND.C
** request socket bind
*/
#include "__75.h"
#include "socket.h"
#include "errno.h"
#include "time.h"
#include "clibsock.h"
#include "clibwto.h"

/* bind() */
__asm__("\n&FUNC    SETC 'bind'");
extern int
bind(int ss, struct sockaddr_in * name, int length)
{
    int     rc;
    PL75    pl;

    if (name->sin_port==0) {
        /* caller wants system to assign a random port */
        int i;
        time_t now;

        time(&now);
        srand(now & 0X7FFF);
        for(i=0; i < 100; i++) {
            name->sin_port = (unsigned short) (rand() & 0x7FFF) + 10000;
            rc = __75bind(ss, name, length);
            if (rc==0) return rc;
        }
        name->sin_port = 0; /* reset port back to 0 */
    }

#if 0
    memset(&pl, 0, sizeof(pl));
#else
    __asm__("XC\t0(64,%0),0(%0)     clear __75 parameter list" : : "r" (&pl));
#endif

    pl.r7   = (unsigned) ((ss<<16) BOR 6); /* socket in high half */
    pl.r8   = (unsigned) name->sin_addr.s_addr;
    pl.r9   = (unsigned)
        (((name->sin_family << 16) BOR name->sin_port) & 0x00FFFFFF);
    /* wtof("%s r9=%08X, family=%04X, port=%04X", __func__, pl.r9, name->sin_family, name->sin_port); */
    /* wtodumpf(name, sizeof(struct sockaddr_in), "%s sockaddr_in", __func__); */

    /* wtodumpf(&pl, sizeof(pl), "%s regs before", __func__); */

    __75(&pl);

    /* wtodumpf(&pl, sizeof(pl), "%s regs after", __func__); */
    rc      = (int) pl.r4;
    if (rc>=0) {
        /* success */
        __soupd(ss, name, 0);
        goto quit;
    }

    /* failed, get error code */
    pl.r1   = (unsigned) 0;     /* clear */
    pl.r8   = (unsigned) ss;    /* socket */
    pl.r7   = (unsigned) 2;     /* function get error(sock) */

    __75(&pl);
#if 0
    __75vect->error = (int) pl.r4;  /* save error code */
    errno = __75vect->error;
#else
    errno = (int) pl.r4;
#endif
quit:
    return rc;
};
