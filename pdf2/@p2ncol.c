#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_new_color'");
PDFCOLOR *pdf_new_color(PDF *pdf, const char *name, const char *abbrev, unsigned rgb)
{
    PDFCOLOR *pdfcolor = calloc(1, sizeof(PDFCOLOR));

    if (pdfcolor) {
        PDFOBJ *pdfobj = (PDFOBJ *)pdfcolor;

        pdfobj->type = OBJCOLOR;

        if (name)   pdfcolor->name = strdup(name);
        if (abbrev) pdfcolor->abbrev = strdup(abbrev);

        pdfcolor->rgb = rgb;

        arrayadd(&pdf->objects, pdfcolor);
        arrayadd(&pdf->colors, pdfcolor);
    }

    return pdfcolor;
}
