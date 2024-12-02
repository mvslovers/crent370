#define PDF_PRIVATE
#include "clibpdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_text'");
int pdf_add_text(PDF *pdf, PDFO *page, const char *text, int size, int xoff, int yoff, unsigned colour)
{
    return pdf_add_text_spacing(pdf, page, text, size, xoff, yoff, colour, 0);
}
