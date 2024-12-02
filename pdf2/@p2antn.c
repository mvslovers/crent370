#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_name_tree_names'");
PDFNAMETREE *pdf_add_name_tree_names(PDF *pdf, PDFNAMETREE *pdfnametree, const char *name, void *obj)
{
    if (pdfnametree) {
        pdf_add_name_tree_pair(pdf, pdfnametree, pdf_new_str_obj_pair(pdf, name, obj));
    }

    return pdfnametree;
}
