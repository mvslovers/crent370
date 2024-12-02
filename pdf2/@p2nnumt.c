#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_new_num_tree'");
PDFNUMTREE *pdf_new_num_tree(PDF *pdf)
{
    PDFNUMTREE *pdfnumtree = calloc(1, sizeof(PDFNUMTREE));

    if (pdfnumtree) {
        PDFOBJ *pdfobj = (PDFOBJ *)pdfnumtree;

        pdfobj->type = OBJNUMTREE;
        pdfobj->index = ++pdf->current_index;

        arrayadd(&pdf->objects, pdfnumtree);
        arrayadd(&pdf->offsets, (void*)0);
    }

    return pdfnumtree;
}
