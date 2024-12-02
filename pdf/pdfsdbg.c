#define PDF_PRIVATE
#include "clibpdfi.h"

__asm__("\n&FUNC    SETC 'pdf_set_debug'");
int pdf_set_debug(PDF *pdf, int on)
{
    if (on) {
        pdf->flags |= PDF_DEBUG;
    }
    else {
        pdf->flags &= ~PDF_DEBUG;
    }

    return 0;
}
