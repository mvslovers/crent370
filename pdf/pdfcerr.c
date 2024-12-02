#define PDF_PRIVATE
#include "clibpdfi.h"

__asm__("\n&FUNC    SETC 'pdf_clear_err'");
void pdf_clear_err(PDF *pdf)
{
    if (!pdf)
        return;

    pdf->errstr[0] = '\0';
    pdf->errval = 0;
}
