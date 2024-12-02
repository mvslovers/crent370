#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_num_tree_pair'");
PDFNUMTREE *pdf_add_num_tree_pair(PDF *pdf, PDFNUMTREE *pdfnumtree, PDFNUMPAIR *pdfnumpair)
{
    if (pdfnumtree) {
        if (pdfnumpair) arrayadd(&pdfnumtree->pdfnumpair, pdfnumpair);
    }

    return pdfnumtree;
}
