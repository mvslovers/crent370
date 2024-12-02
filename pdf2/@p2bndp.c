#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_boundaries_page'");
void pdf_boundaries_page(PDF *pdf)
{
    pdf->pagel  = 0;
    pdf->pager  = pdf->paperw;
    pdf->paget  = pdf->paperh;

    pdf->pageb  = 0;
    pdf->pagew  = pdf->pager - pdf->pagel;
    pdf->pageh  = pdf->paget - pdf->pageb;

    pdf_boundaries_crop(pdf);
}
