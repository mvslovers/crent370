#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_new_date'");
PDFDATE *pdf_new_date(PDF *pdf, const struct tm *time)
{
    PDFDATE *pdfdate = calloc(1, sizeof(PDFDATE));

    if (pdfdate) {
        PDFOBJ *pdfobj = (PDFOBJ *)pdfdate;

        pdfobj->type    = OBJDATE;

        if (time) pdfdate->time = *time;

        arrayadd(&pdf->objects, pdfdate);
    }

    return pdfdate;
}
