#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_page_annots'");
PDFPAGE *pdf_add_page_annots(PDF *pdf, PDFPAGE *pdfpage, void *obj)
{
    if (pdfpage) {
        if (obj) {
            arrayadd(&pdfpage->annots, obj);
        }
    }

    return pdfpage;
}
