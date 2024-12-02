#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_new_bool'");
PDFBOOL *pdf_new_bool(PDF *pdf, int value)
{
    PDFBOOL *pdfbool = calloc(1, sizeof(PDFBOOL));

    if (pdfbool) {
        PDFOBJ *pdfobj = (PDFOBJ *)pdfbool;

        pdfobj->type    = OBJBOOL;

        pdfbool->value  = value;

        arrayadd(&pdf->objects, pdfbool);
    }

    return pdfbool;
}
