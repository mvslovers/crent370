#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_new_num_pair'");
PDFNUMPAIR *pdf_new_num_pair(PDF *pdf, int value, void *obj)
{
    PDFNUMPAIR *pdfnumpair = calloc(1, sizeof(PDFNUMPAIR));

    if (pdfnumpair) {
        PDFOBJ *pdfobj = (PDFOBJ *)pdfnumpair;

        pdfobj->type = OBJNUMPAIR;

        pdfnumpair->value = value;
        pdfnumpair->pdfobj = obj;

        arrayadd(&pdf->objects, pdfnumpair);
    }

    return pdfnumpair;
}
