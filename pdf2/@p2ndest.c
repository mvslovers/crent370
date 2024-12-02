#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_new_dest'");
PDFDEST *pdf_new_dest(PDF *pdf, PDFPAGE *pdfpage, int left, int top)
{
    PDFDEST *pdfdest = calloc(1, sizeof(PDFDEST));

    if (pdfdest) {
        PDFOBJ *pdfobj = (PDFOBJ *)pdfdest;

        pdfobj->type = OBJDEST;

        pdfdest->page = pdfpage;
        pdfdest->left = left;
        pdfdest->top  = top;

        arrayadd(&pdf->objects, pdfdest);
    }

    return pdfdest;
}
