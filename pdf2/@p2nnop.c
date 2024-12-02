#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_new_name_obj_pair'");
PDFNAMEOBJPAIR *pdf_new_name_obj_pair(PDF *pdf, const char *name, void *obj)
{
    PDFNAMEOBJPAIR *pdfnameobjpair = calloc(1, sizeof(PDFNAMEOBJPAIR));

    if (pdfnameobjpair) {
        PDFOBJ *pdfobj = (PDFOBJ *)pdfnameobjpair;

        pdfobj->type = OBJNAMEOBJPAIR;

        if (name) pdfnameobjpair->name = strdup(name);

        if (obj)  pdfnameobjpair->pdfobj = obj;

        arrayadd(&pdf->objects, pdfnameobjpair);
    }

    return pdfnameobjpair;
}
