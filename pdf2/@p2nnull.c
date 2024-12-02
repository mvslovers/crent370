#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_new_null'");
PDFNULL *pdf_new_null(PDF *pdf)
{
    PDFNULL *pdfnull = calloc(1, sizeof(PDFNULL));

    if (pdfnull) {
        PDFOBJ *pdfobj  = (PDFOBJ *)pdfnull;

        pdfobj->type    = OBJNULL;

        arrayadd(&pdf->objects, pdfnull);
    }

    return pdfnull;
}
