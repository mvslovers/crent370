#define PDF_PRIVATE
#include "clibpdfi.h"

__asm__("\n&FUNC    SETC 'pdf_width'");
int pdf_width(PDF *pdf)
{
    return pdf->width;
}
