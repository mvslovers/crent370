#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_boundaries_text'");
void pdf_boundaries_text(PDF *pdf)
{
    pdf->textl  = pdf->cropl + pdf->lmargin;
    pdf->textr  = pdf->cropr - pdf->rmargin;
    pdf->textt  = pdf->cropt - pdf->tmargin;
    pdf->textb  = pdf->cropb + pdf->bmargin;
    pdf->textw  = pdf->textr - pdf->textl;
    pdf->texth  = pdf->textt - pdf->textb;

    pdf_boundaries_leading(pdf);
}
