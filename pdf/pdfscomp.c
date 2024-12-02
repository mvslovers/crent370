#define PDF_PRIVATE
#include "clibpdfi.h"

__asm__("\n&FUNC    SETC 'pdf_set_compression'");
int pdf_set_compression(PDF *pdf, int on)
{
    if (on) {
        pdf->flags |= PDF_COMPRESS;
    }
    else {
        pdf->flags &= ~PDF_COMPRESS;
    }

    return 0;
}

