#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_new_outline'");
PDFOUTLINE *pdf_new_outline(PDF *pdf)
{
    PDFOUTLINE *pdfoutline = calloc(1, sizeof(PDFOUTLINE));

    if (pdfoutline) {
        PDFOBJ *pdfobj = (PDFOBJ *)pdfoutline;

        pdfobj->type = OBJOUTLINE;
        pdfobj->index = ++pdf->current_index;

        arrayadd(&pdf->objects, pdfoutline);
        arrayadd(&pdf->offsets, (void*)0);
    }

    return pdfoutline;
}
