#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_boundaries_leading'");
void pdf_boundaries_leading(PDF *pdf)
{
    pdf->leading = 72 / pdf->lpi;

    pdf_boundaries_lpp(pdf);
}
