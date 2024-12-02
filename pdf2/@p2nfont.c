#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_new_font'");
PDFFONT *pdf_new_font(PDF *pdf, const char *subtype, const char *basefont, const char *encoding, const char *alias, const char *abbrev)
{
    PDFFONT *pdffont = calloc(1, sizeof(PDFFONT));

    if (pdffont) {
        PDFOBJ *pdfobj = (PDFOBJ *)pdffont;

        pdffont->type = OBJFONT;
        pdfobj->index = ++pdf->current_index;

        if (subtype) {
            pdffont->subtype = strdup(subtype);
        }
        if (basefont) {
            pdffont->basefont = strdup(basefont);
        }
        if (encoding) {
            pdffont->encoding = strdup(encoding);
        }
        if (alias) {
            pdffont->alias = strdup(alias);
        }
        if (abbrev) {
            pdffont->abbrev = strdup(abbrev);
        }

        arrayadd(&pdf->objects, pdffont);
        arrayadd(&pdf->offsets, (void*)0);
        arrayadd(&pdf->pdffonts, pdffont);
    }

    return pdffont;
}
