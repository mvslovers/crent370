#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_new_pages'");
PDFPAGES *pdf_new_pages(PDF *pdf)
{
    PDFPAGES *pdfpages = calloc(1, sizeof(PDFPAGES));

    if (pdfpages) {
        PDFOBJ *pdfobj = (PDFOBJ *)pdfpages;

        pdfobj->type = OBJPAGES;
        pdfobj->index = ++pdf->current_index;

        pdf->pages = pdfpages;

        arrayadd(&pdf->objects, pdfpages);
        arrayadd(&pdf->offsets, (void*)0);
    }

    return pdfpages;
}
