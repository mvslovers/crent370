#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_new_resource'");
PDFRESOURCE *pdf_new_resource(PDF *pdf)
{
    PDFRESOURCE *pdfresource = calloc(1, sizeof(PDFRESOURCE));

    if (pdfresource) {
        PDFOBJ *pdfobj = (PDFOBJ *)pdfresource;

        pdfobj->type = OBJRESOURCE;

        arrayadd(&pdf->objects, pdfresource);
    }

    return pdfresource;
}
