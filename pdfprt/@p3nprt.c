#include "../pdfprt/pdfprt.h"

__asm__("\n&FUNC    SETC 'pdfprt_new'");
PDFPRT *pdfprt_new(int (*out)(void *udata, int len, const char *data), int (*tell)(void *udata), void *udata)
{
    PDFPRT  *pdfprt = calloc(1, sizeof(PDFPRT));

    if (!pdfprt) goto quit;

    if (!out) {
        out = pdf_out_default;
        if (!udata) udata = stdout;
        if (!tell)  tell  = (void*)ftell;
    }

    strcpy(pdfprt->eye, PDFPRT_EYE);
    pdfprt->out         = out;
    pdfprt->udata       = udata;
    pdfprt->tell        = tell;

    /* create an instance of PDF handle */
    pdfprt->pdf = pdf_new(pdfprt_out, pdfprt_tell, pdfprt);
    if (!pdfprt->pdf) {
        free(pdfprt);
        pdfprt = NULL;
        goto quit;
    }

quit:
    return pdfprt;
}
