#include "../pdfprt/pdfprt.h"

__asm__("\n&FUNC    SETC 'pdfprt_out'");
int pdfprt_out(void *udata, int len, const char *data)
{
    PDFPRT  *pdfprt = udata;    /* our handle */
    int     rc;

    pdfprt->outcount += len;    /* remember number of bytes written */

    if (pdfprt->out) {
        /* call user provided output routine */
        rc = pdfprt->out(pdfprt->udata, len, data);
    }
    else {
        /* use the default pdf writer routine */
        rc = pdf_out_default(NULL, len, data);
    }

    return rc;
}
