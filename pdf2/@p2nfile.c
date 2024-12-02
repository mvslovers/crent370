#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_new_file'");
PDFFILE *pdf_new_file(PDF *pdf, const char *file)
{
    PDFFILE *pdffile = calloc(1, sizeof(PDFFILE));

    if (pdffile) {
        PDFOBJ *pdfobj = (PDFOBJ *)pdffile;

        pdfobj->type    = OBJFILE;

        if (file) pdffile->file = strdup(file);

        arrayadd(&pdf->objects, pdffile);
    }

    return pdffile;
}
