#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_cat_page_layout'");
PDFCAT *pdf_add_cat_page_layout(PDF *pdf, PDFCAT *pdfcat, const char *layout)
{
    if (pdfcat) {
        if (layout) {
            pdfcat->pagelayout = strdup(layout);
        }
    }

    return pdfcat;
}
