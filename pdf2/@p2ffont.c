#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_find_font'");
PDFFONT *pdf_find_font(PDF *pdf, const char *name)
{
    unsigned n, count = arraycount(&pdf->pdffonts);

    for(n=0; n < count; n++) {
        PDFFONT *pdffont = pdf->pdffonts[n];

        if (!pdffont) continue;

        if (pdffont->basefont && pdf_case_cmp(name, pdffont->basefont)==0) return pdffont;
        if (pdffont->alias    && pdf_case_cmp(name, pdffont->alias   )==0) return pdffont;
        if (pdffont->abbrev   && pdf_case_cmp(name, pdffont->abbrev  )==0) return pdffont;
    }

    return NULL;
}
