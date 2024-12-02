#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_name_tree_pair'");
PDFNAMETREE *pdf_add_name_tree_pair(PDF *pdf, PDFNAMETREE *pdfnametree, PDFSTROBJPAIR *strobjpair)
{
    if (pdfnametree) {
        if (strobjpair)     arrayadd(&pdfnametree->strobjpair, strobjpair);
    }

    return pdfnametree;
}
