#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_new_stream'");
PDFSTREAM *pdf_new_stream(PDF *pdf)
{
    PDFSTREAM *pdfstream = calloc(1, sizeof(PDFSTREAM));

    if (pdfstream) {
        PDFOBJ *pdfobj = (PDFOBJ *)pdfstream;

        pdfobj->type = OBJSTREAM;
        pdfobj->index = ++pdf->current_index;

        arrayadd(&pdf->objects, pdfstream);
    }

    return pdfstream;
}
