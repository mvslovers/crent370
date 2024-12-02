#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_new_str_obj_pair'");
PDFSTROBJPAIR *pdf_new_str_obj_pair(PDF *pdf, const char *str, void *obj)
{
    PDFSTROBJPAIR *pdfstrobjpair = calloc(1, sizeof(PDFSTROBJPAIR));

    if (pdfstrobjpair) {
        PDFOBJ *pdfobj  = (PDFOBJ *)pdfstrobjpair;

        pdfobj->type    = OBJSTROBJPAIR;

        if (str) pdfstrobjpair->str = strdup(str);

        if (obj) pdfstrobjpair->pdfobj = obj;

        arrayadd(&pdf->objects, pdfstrobjpair);
    }

    return pdfstrobjpair;
}
