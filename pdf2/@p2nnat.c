#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_new_name_tree'");
PDFNAMETREE *pdf_new_name_tree(PDF *pdf)
{
    PDFNAMETREE *pdfnametree = calloc(1, sizeof(PDFNAMETREE));

    if (pdfnametree) {
        PDFOBJ *pdfobj = (PDFOBJ *)pdfnametree;

        pdfobj->type = OBJNAMETREE;
        pdfobj->index = ++pdf->current_index;

        arrayadd(&pdf->objects, pdfnametree);
        arrayadd(&pdf->offsets, (void*)0);
    }

    return pdfnametree;
}
