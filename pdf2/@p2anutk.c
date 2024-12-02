#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_num_tree_kids'");
PDFNUMTREE *pdf_add_num_tree_kids(Pdf *ptPdf, PdfNumTree *ptPdfNumTree, void *ptPdfObj)
{
    if (pdfnumtree) {
        if (obj) arrayadd(&pdfnumtree->kids, obj);
    }

    return pdfnumtree;
}
