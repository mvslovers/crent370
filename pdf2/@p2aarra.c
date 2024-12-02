#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_array'");
PDFARRAY *pdf_add_array(PDF *pdf, PDFARRAY *pdfarray, void *pdfobj)
{
    if (pdfarray) {
        arrayadd(&pdfarray->objects, pdfobj);
    }

    return pdfarray;
}
