/* @@75SELX.C
** select ready socket(s) and wait for ECB post.
**
** __75() selectex() sub codes (r8):
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
#include "clibary.h"

/* selectex() */
__asm__("\n&FUNC    SETC 'selectex'");
extern int
selectex(int maxsock, fd_set *r, fd_set *w, fd_set *e, timeval * t,
    unsigned **ecblist)
{
    unsigned    wait    = 0;
    unsigned    count   = 0;
    unsigned    n;
    unsigned    *ecb;
    int         rc;
    int         bytes;
    PL75        pl;

    __asm__("XC\t0(64,%0),0(%0)     clear __75 parameter list" : : "r" (&pl));

    /* maxsock *should* be highest sockets plus 1, so min is 2
    ** since the DYN75 code starts socket assignment with 1.
    */
    if (maxsock < 2) {
        rc = 0;
        goto quit;
    }

    if (ecblist) {
        count = arraycount(&ecblist);
    }

    pl.r7   = (unsigned) ((maxsock-1) << 16) BOR 17;
    pl.r8   = (unsigned) 0; /* subcode 0 - initialize for select() */
    pl.r9   = (unsigned) maxsock;

    __75(&pl);

    /* calculate number of bytes we need for fd_set of maxsize */
    bytes = (((maxsock+31)/32)*4);
    if (r) {
        pl.r1   = (unsigned) bytes;
        pl.r5   = (unsigned) r;
        pl.r8   = (unsigned) 1; /* subcode 1 - set read */
        __75(&pl);
    }

    if (w) {
        pl.r1   = (unsigned) bytes;
        pl.r5   = (unsigned) w;
        pl.r8   = (unsigned) 2; /* subcode 2 - set write */
        __75(&pl);
    }

    if (e) {
        pl.r1   = (unsigned) bytes;
        pl.r5   = (unsigned) e;
        pl.r8   = (unsigned) 3; /* subcode 3 - set exception */
        __75(&pl);
    }

    if (t) {
        /* calculate number of 0.08 seconds we need to wait */
        wait    = (unsigned) (t->tv_sec << 5);      /* times 32 */
        wait    = (unsigned) ((wait << 1) + wait);  /* times 64 + */
        wait    = (unsigned) (wait >> 3);           /* # of .08 sec waits */
        if (t->tv_usec) {
            if (t->tv_usec > 64) {
                wait   = (unsigned) (wait + (t->tv_usec >> 6));
            }
            else {
                wait++;    /* insure at least one .08 sec wait */
            }
        }
    }

    for(;;) {
        /* this is basically a spin loop with a slight delay of
        ** 0.08 seconds for each poll to see if we have a ready
        ** socket from any of the fd_set's.
        */
        pl.r1   = (unsigned) 0;
        pl.r8   = (unsigned) 4;     /* sub code 4 *** select ***/
        __75(&pl);

        rc = (int)pl.r4;
        if (rc!=-2) break;  /* no wait */

        /* no ready socket, we need to wait */
        pl.r4   = (unsigned) 0; /* assume timeout or ECB posted */

        /* do we have a timeval? */
        if (t) {
            /* has the timeval expired? */
            if (wait==0) break;     /* no more time, return 0 */
            wait--;                 /* decrement remainting count */
        }

        /* do we have an ECB list or array? */
        if (ecblist) {
            if (count) {
                /* array, was an ECB posted? */
                for(n=0; n < count; n++) {
                    ecb = ecblist[n];

                    if (!ecb) continue;     /* skip NULL pointers */

                    /* was this ECB posted? */
                    if ((*ecb) & 0x40000000) goto check;    /* yes */
                }
            }
            else {
                /* list, was an ECB posted? */
                for(n=0; ecblist[n]; n++) {
                    ecb = ecblist[n];

                    /* check for NULL end of ECB list */
                    if ((unsigned)ecb == 0x80000000) break;

                    /* was this ECB posted? */
                    if ((*ecb) & 0x40000000) goto check;    /* yes */

                    /* check for end of ECB list */
                    if ((unsigned)ecb & 0x80000000) break;
                }
            }
        }

        /* we need to wait 0.08 seconds */
        __asm__("STIMER WAIT,BINTVL==F'8'   0.08 seconds" : : : "0", "1");
    }

check:
    rc = (int) pl.r4;       /* get return code */
    if (rc==-1) {
        /* get error */
        pl.r1   = (unsigned) 0;
        pl.r8   = (unsigned) (pl.r7 >> 16); /* get socket */
        pl.r7   = (unsigned) 2;
        __75(&pl);
#if 0
        __75vect->error = (int) pl.r4;
        errno = __75vect->error;
#else
        errno = (int) pl.r4;
#endif
    }

    if (r) {
        pl.r1   = (unsigned) 0;
        pl.r6   = (unsigned) r;
        pl.r8   = (unsigned) 5; /* sub code 5 - get read */
        __75(&pl);
    }

    if (w) {
        pl.r1   = (unsigned) 0;
        pl.r6   = (unsigned) w;
        pl.r8   = (unsigned) 6; /* sub code 6 - get write */
        __75(&pl);
    }

    if (e) {
        pl.r1   = (unsigned) 0;
        pl.r6   = (unsigned) e;
        pl.r8   = (unsigned) 7; /* sub code 7 - get exception */
        __75(&pl);
    }

    pl.r8   = (unsigned) 8; /* sub code 8 - clean up */
    __75(&pl);

quit:
    return rc;
}
