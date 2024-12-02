#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_set_default_page'");
int pdf_set_default_page(PDF *pdf, int width, int height)
{
    int     rc;

    pdf->width = width;
    pdf->height = height;

    return 0;
}


