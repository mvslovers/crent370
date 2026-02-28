/* OSBCLOSE.C - close DCB with options or free of DCB
** options can be NULL, "reread", "leave", "rewind", "free", "disp".
** type_t is for close,type=t and should be 0 for normal close.
*/
#include <stdlib.h>
#include <string.h>
#include "osio.h"

void
osbclose(DCB *dcb, const char *option, int freedcb, int type_t)
{
    unsigned    plist;

    if (!dcb) goto quit;

    plist = 0x80000000 | (unsigned)dcb;     /* default opt=disp */

    if (option) {
        /* we don't check for "disp" since that's our default */
        if (strcmp(option, "reread")==0) {
            plist |= 0x90000000;
        }
        else if (strcmp(option, "free")==0) {
            plist |= 0xA0000000;
        }
        else if (strcmp(option, "leave")==0) {
            plist |= 0xB0000000;
        }
        else if (strcmp(option, "rewind")==0) {
            plist |= 0xC0000000;
        }
    }

    if (type_t) {
        __asm__("LR    1,%0\n\tSVC   23         TCLOSE"
            : : "r"(&plist) : "1", "14", "15");
        /* close,type=t leave the DCB open, so we're done */
        goto quit;
    }

    /* normal close */
    __asm__("LR    1,%0\n\tSVC   20         CLOSE"
        : : "r"(&plist) : "1", "14", "15");
#if 0
    /* release buffer pool (if any) */
    __asm__("FREEPOOL ((%0))" : : "r"(dcb) : "1", "14", "15");
#endif
    /* if we have any private DCB storage we need to free it now */
    if (dcb->dcbpriv) {
        free(dcb->dcbpriv);
        dcb->dcbpriv = (void*)0;
    }

    /* if caller is done with DCB area we'll free it now */
    if (freedcb) {
        free(dcb);
    }

quit:
    return;
}
