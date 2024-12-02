#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_boundaries_lpp'");
void pdf_boundaries_lpp(PDF *pdf)
{
    pdf->lpp    = pdf->texth / pdf->leading;
}
