#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_new_name'");
PDFNAME *pdf_new_name(PDF *pdf, const char *name)
{
    PDFNAME *pdfname = calloc(1, sizeof(PDFNAME));

    if (pdfname) {
        PDFOBJ *pdfobj = (PDFOBJ *)pdfname;

        pdfobj->type    = OBJNAME;

        if (name) pdfname->name = strdup(name);

        arrayadd(&pdf->objects, pdfname);
    }

    return pdfname;
}
