#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_name_tree_limits'");
PDFNAMETREE *pdf_add_name_tree_limits(PDF *pdf, PDFNAMETREE *pdfnametree, const char *namelow, const char *namehigh)
{
    if (pdfnametree) {
        if (namelow)    pdfnametree->namelow = strdup(namelow);
        if (namehigh)   pdfnametree->namehigh = strdup(namehigh);
    }

    return pdfnametree;
}
