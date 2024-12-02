#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_pages_page'");
PDFPAGES *pdf_add_pages_page(PDF *pdf, PDFPAGES *pdfpages, PDFPAGE *pdfpage)
{
    if (pdfpages) {
        if (pdfpage) {
            arrayadd(&pdfpages->pdfpage, pdfpage);
        }
    }

    return pdfpages;
}
