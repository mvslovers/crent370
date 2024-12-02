#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_new_array'");
PDFARRAY *pdf_new_array(PDF *pdf)
{
    PDFARRAY *pdfarray = calloc(1, sizeof(PDFARRAY));

    if (pdfarray) {
        PDFOBJ *pdfobj = (PDFOBJ *)pdfarray;

        pdfobj->type    = OBJARRAY;

        arrayadd(&pdf->objects, pdfarray);
    }

    return pdfarray;
}
