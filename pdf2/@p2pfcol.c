#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_find_color'");
PDFCOLOR *pdf_find_color(PDFCOLOR **pdfcolors, const char *name)
{
    unsigned n, count = arraycount(&pdfcolors);

    for(n=0; n < count; n++) {
        PDFCOLOR *pdfcolor = pdfcolors[n];

        if (!pdfcolor) continue;
        if (pdfcolor->name) {
            if (pdf_case_cmp(name, pdfcolor->name)==0) return pdfcolor;
        }
        if (pdfcolor->abbrev) {
            if (pdf_case_cmp(name, pdfcolor->abbrev)==0) return pdfcolor;
        }
    }

    return NULL;
}
