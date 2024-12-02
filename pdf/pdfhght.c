#define PDF_PRIVATE
#include "clibpdfi.h"

__asm__("\n&FUNC    SETC 'pdf_height'");
int pdf_height(PDF *pdf)
{
    return pdf->height;
}
