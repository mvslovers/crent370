#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_new_int'");
PDFINT *pdf_new_int(PDF *pdf, int value)
{
    PDFINT *pdfint = calloc(1, sizeof(PDFINT));

    if (pdfint) {
        PDFOBJ *pdfobj = (PDFOBJ *)pdfint;

        pdfobj->type    = OBJINT;

        pdfint->value   = value;

        arrayadd(&pdf->objects, pdfint);
    }

    return pdfint;
}
