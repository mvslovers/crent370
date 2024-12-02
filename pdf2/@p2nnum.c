#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_new_num'");
PDFNUM *pdf_new_num(PDF *pdf, double value)
{
    PDFNUM *pdfnum = calloc(1, sizeof(PDFNUM));

    if (pdfnum) {
        PDFOBJ *pdfobj = (PDFOBJ *)pdfnum;

        pdfobj->type = OBJNUM;

        pdfnum->value = value;

        arrayadd(&pdf->objects, pdfnum);
    }

    return pdfnum;
}
