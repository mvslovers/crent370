#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_resource_name_xobj'");
PDFRESOURCE *pdf_add_resource_name_xobj(PDF *pdf, PDFRESOURCE *pdfresource, const char *name, void *xobj)
{
    if (pdfresource) {
        PDFNAMEOBJPAIR *pdfnameobjpair = pdf_new_name_obj_pair(pdf, name, xobj);

        if (pdfnameobjpair) {
            arrayadd(&pdfresource->nameobjpairxobj, pdfnameobjpair);
        }
    }

    return pdfresource;
}
