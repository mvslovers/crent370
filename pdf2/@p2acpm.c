#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_cat_page_mode'");
PDFCAT *pdf_add_cat_page_mode(PDF *pdf, PDFCAT *pdfcat, const char *mode)
{
    if (pdfcat) {
        if (mode) {
            pdfcat->pagemode = strdup(mode);
        }
    }

    return pdfcat;
}
