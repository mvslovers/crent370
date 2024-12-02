#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_name_tree_kids'");
PDFNAMETREE *pdf_add_name_tree_kids(PDF *pdf, PDFNAMETREE *pdfnametree, void *obj)
{
    if (pdfnametree) {
        if (obj)    arrayadd(&pdfnametree->kids, obj);
    }

    return pdfnametree;
}
