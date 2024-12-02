#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_resource_proc_set'");
PDFRESOURCE *pdf_add_resource_proc_set(PDF *pdf, PDFRESOURCE *pdfresource, const char *name)
{
    if (pdfresource) {
        if (name) {
            arrayadd(&pdfresource->procset, strdup(name));
        }
    }

    return pdfresource;
}
