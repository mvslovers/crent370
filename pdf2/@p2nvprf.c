#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_new_viewpref'");
PDFVIEWPREF *pdf_new_viewpref(PDF *pdf)
{
    PDFVIEWPREF *pdfviewpref = calloc(1, sizeof(PDFVIEWPREF));

    if (pdfviewpref) {
        PDFOBJ *pdfobj = (PDFOBJ *)pdfviewpref;

        pdfobj->type = OBJVIEWPREF;
        pdfobj->index = ++pdf->current_index;

        arrayadd(&pdf->objects, pdfviewpref);
        arrayadd(&pdf->offsets, (void*)0);

        if (pdf->catalog) {
            pdf->catalog->viewpref = pdfviewpref;
        }
    }

    return pdfviewpref;
}
