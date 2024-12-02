#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_tell'");
int pdf_tell(PDF *pdf)
{
    int     rc = 0;

    if (pdf->flags & PDF_FLAG_NO_OUTPUT) {
        return 0;
    }

    if (pdf->tell) {
        rc = pdf->tell(pdf->udata);
    }

    return rc;
}
