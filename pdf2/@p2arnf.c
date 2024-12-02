#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_resource_name_font'");
PDFRESOURCE *pdf_add_resource_name_font(PDF *pdf, PDFRESOURCE *pdfresource, const char *name, PDFFONT *pdffont)
{
    if (pdfresource) {
        PDFNAMEOBJPAIR *pdfnameobjpair = pdf_new_name_obj_pair(pdf, name, pdffont);

        if (pdfnameobjpair) {
            arrayadd(&pdfresource->nameobjpairfont, pdfnameobjpair);
        }
    }

    return pdfresource;
}
