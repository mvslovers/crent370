#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_num_tree_limits'");
PDFNUMTREE *pdf_add_num_tree_limits(PDF *pdf, PDFNUMTREE *pdfnumtree, int low, int high)
{
    if (pdfnumtree) {
        pdfnumtree->intlow = (void *) pdf_new_int(pdf, low);
        pdfnumtree->inthigh = (void *) pdf_new_int(pdf, high);
    }

    return pdfnumtree;
}
