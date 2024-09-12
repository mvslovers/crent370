/* @@CPCLOS.C - Close JES Checkpoint Dataset */
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "clibwto.h"
#include <mvssupa.h>
#include "svc99.h"
#include "clibary.h"
#include "osdcb.h"
#include "osjfcb.h"
#include "clibcp.h"     /* JES Checkpoint prototypes and functions            */

static int deallocate_checkpoint(HASPCP *fp);

int __cpclos(HASPCP *cp)
{
    if (cp) {
        DCB     *dcb    = cp->dcb;
        unsigned plist  = 0x80000000;

        if (dcb->dcboflgs & DCBOFOPN) {
            __asm("CLOSE\t((%0)),MF=(E,(%1))" : : "r"(dcb), "r"(&plist));
        }

        deallocate_checkpoint(cp);

        if (cp->buf) free(cp->buf);
        free(cp);
    }

    return 0;
}

__asm__("\n&FUNC    SETC 'deallocate_checkpoint'");
static int deallocate_checkpoint(HASPCP *fp)
{
    int         err     = 1;
    unsigned    count   = 0;
    TXT99       **txt99 = NULL;
    RB99        rb99    = {0};

    /* this DDNAME */
    err = __txddn(&txt99, fp->ddname);
    if (err) goto quit;

    count = arraycount(&txt99);
    if (!count) goto quit;

    /* Set high order bit to mark end of list */
    count--;
    txt99[count]    = (TXT99*)((unsigned)txt99[count] | 0x80000000);

    /* construct the request block for dynamic allocation */
    rb99.len        = sizeof(RB99);
    rb99.request    = S99VRBUN;
    rb99.flag1      = S99NOCNV;
    rb99.txtptr     = txt99;

    /* SVC 99 */
    err = __svc99(&rb99);

quit:
    if (txt99) FreeTXT99Array(&txt99);

    return err;
}
