#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_out'");
int pdf_out(PDF *pdf, int len, const char *data)
{
    int     rc;

    if (pdf->flags & PDF_FLAG_NO_OUTPUT) {
        return 0;
    }

    if (pdf->out) {
        rc = pdf->out(pdf->udata, len, data);
        if (rc) {
            wtof("pdf_out() rc=%d, output disabled");
            pdf->flags |= PDF_FLAG_NO_OUTPUT;
        }
    }

    return -1;
}
