#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_set_out'");
int pdf_set_out(PDF *pdf, int (*out)(void *udata, int len, const char *data))
{
    int     rc;

    pdf->out = out;

    if (pdf->out) {
        /* remove PDF_FLAG_NO_OUTPUT (enable output again) */
        pdf->flags &= ~PDF_FLAG_NO_OUTPUT;
    }
    else {
        /* disable output */
        pdf->flags != PDF_FLAG_NO_OUTPUT;
    }

    return 0;
}
