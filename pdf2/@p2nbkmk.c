#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_new_bookmark'");
PDFOUTLINE *pdf_new_bookmark(PDF *pdf, PDFOUTLINE *parent, const char *title, const char *color, PDFPAGE *pdfpage, unsigned x, unsigned y)
{
    PDFDEST *pdfdest = pdf_new_dest(pdf, pdfpage, x, y);

    return pdf_new_bookmark_dest(pdf, parent, title, color, pdfdest);
}
