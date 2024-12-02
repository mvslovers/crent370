#include "../pdfprt/pdfprt.h"

__asm__("\n&FUNC    SETC 'pdfprt_tell'");
int pdfprt_tell(void *udata)
{
    PDFPRT *pdfprt = udata;

    if (pdfprt->tell) {
        /* use the callers provided tell() function */
        return pdfprt->tell(pdfprt->udata);
    }

    /* otherwise we return the bytes we've sent out via pdfprt_out() */
    return pdfprt->outcount;
}
