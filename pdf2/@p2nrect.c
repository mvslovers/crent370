#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_new_rect'");
PDFRECT *pdf_new_rect(PDF *pdf, int bx, int by, int tx, int ty)
{
    PDFRECT *pdfrect = calloc(1, sizeof(PDFRECT));

    if (pdfrect) {
        PDFOBJ *pdfobj = (PDFOBJ *)pdfrect;

        pdfobj->type = OBJRECT;

        pdfrect->bx = bx;
        pdfrect->by = by;
        pdfrect->tx = tx;
        pdfrect->ty = ty;

        arrayadd(&pdf->objects, pdfrect);
    }

    return pdfrect;
}
