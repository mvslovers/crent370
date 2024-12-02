/* @@75RECV.C
** Receive data from a socket
*/
#include "__75.h"
#include "socket.h"
#include "errno.h"

/* recv() */
__asm__("\n&FUNC    SETC 'recv'");
extern int
recv(int ss, void *vbuf, int len, int flags)
{
    int     rc;
    int     chunk;
    char    *buf;
    int     read;
    PL75    pl;

    /* sanity check the parms */
    if (ss < 0 || !vbuf) {
        rc = -1;
        errno = EPERM;
        goto quit;
    }
 
    for(read = 0; read < len; read += rc) {
        buf = ((char *)vbuf) + read;

        /* we have to limit the recv() length to no more than
         * 4096 bytes due to a limitation of the dyn75 interface
         * and the Hercules emulator.
         * If we don't do this then the buf is overwritten from
         * the start after 4096 bytes are received.
         */
        chunk = len - read;
        if (chunk > 4096) chunk = 4096;
        
        __asm__("XC\t0(64,%0),0(%0)     clear __75 parameter list"
            : : "r" (&pl));
        pl.r6   = (unsigned) buf;
        pl.r7   = (unsigned) 11;    /* function code for recv() */
        pl.r8   = (unsigned) ss;    /* socket number            */
        pl.r9   = (unsigned) chunk; /* from 1 to 4096 bytes     */

        __75(&pl);

        rc = (int) pl.r4;
        if (rc==-2) {
            /* special case, we have to wait for some reason??? */
            __asm__("STIMER WAIT,BINTVL==F'8'   0.08 seconds" : : : "0", "1");
            rc = 0;
            continue;
        }

        if (rc <= 0) break;
    }
    
    if (rc==-1) {
        /* set the errno value for this error */
        pl.r1   = (unsigned) 0;
        pl.r7   = (unsigned) 2;     /* function code for get error */
        __75(&pl);
        errno = (int) pl.r4;
    }

    /* if we read some data, return the length we read */
    if (read) rc = read;

quit:
    return rc;
}
