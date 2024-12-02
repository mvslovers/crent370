#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_new_bookmark_page'");
PDFOUTLINE *pdf_new_bookmark_page(PDF *pdf, PDFOUTLINE *parent, const char *title, const char *color, PDFPAGE *pdfpage)
{
    PDFDEST *pdfdest = pdf_new_dest(pdf, pdfpage, pdf->pagel, pdf->paget);

    return pdf_new_bookmark_dest(pdf, parent, title, color, pdfdest);
}
