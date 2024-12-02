#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_num_tree_nums'");
PDFNUMTREE *pdf_add_num_tree_nums(PDF *pdf, PDFNUMTREE *pdfnumtree, int value, void *obj)
{
    if (pdfnumtree) {
        pdf_add_num_tree_pair(pdf, pdfnumtree, pdf_new_num_pair(pdf, value, obj));
    }

    return pdfnumtree;
}
