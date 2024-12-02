#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_new_cat'");
PDFCAT *pdf_new_cat(PDF *pdf)
{
    PDFCAT *pdfcat = calloc(1, sizeof(PDFCAT));

    if (pdfcat) {
        PDFOBJ *pdfobj = (PDFOBJ *)pdfcat;

        pdfobj->type = OBJCATALOG;
        pdfobj->index = ++pdf->current_index;

        pdf->catalog = pdfcat;

        arrayadd(&pdf->objects, pdfcat);
        arrayadd(&pdf->offsets, (void*)0);
    }

    return pdfcat;
}
