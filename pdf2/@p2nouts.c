#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_new_outlines'");
PDFOUTLINES *pdf_new_outlines(PDF *pdf)
{
    PDFOUTLINES *pdfoutlines = calloc(1, sizeof(PDFOUTLINES));

    if (pdfoutlines) {
        PDFOBJ *pdfobj = (PDFOBJ *)pdfoutlines;

        pdfobj->type = OBJOUTLINES;
        pdfobj->index = ++pdf->current_index;

        pdf->outlines = pdfoutlines;

        arrayadd(&pdf->objects, pdfoutlines);
        arrayadd(&pdf->offsets, (void*)0);

        if (pdf->catalog) {
            pdf->catalog->outlines = pdfoutlines;
        }
    }

    return pdfoutlines;
}
