#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_boundaries_crop'");
void pdf_boundaries_crop(PDF *pdf)
{
    pdf->cropl  = pdf->pagel;
    pdf->cropr  = pdf->pager;

    if (pdf->flags & PDF_OPTION_HAS_HOLES) {
        pdf->cropl += pdf->holesize * 2;
        pdf->cropr += pdf->holesize * 2;
    }

    pdf->cropt  = pdf->paget;
    pdf->cropb  = pdf->pageb;
    pdf->cropw  = pdf->cropr - pdf->cropl;
    pdf->croph  = pdf->cropt - pdf->cropb;

    pdf_boundaries_text(pdf);
}
