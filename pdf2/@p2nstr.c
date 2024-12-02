#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_new_str'");
PDFSTR *pdf_new_str(PDF *pdf, const char *str)
{
    PDFSTR *pdfstr = calloc(1, sizeof(PDFSTR));

    if (pdfstr) {
        PDFOBJ *pdfobj = (PDFOBJ *)pdfstr;

        pdfobj->type = OBJSTR;

        if (str) pdfstr->str = strdup(str);

        arrayadd(&pdf->objects, pdfstr);
    }

    return pdfstr;
}
