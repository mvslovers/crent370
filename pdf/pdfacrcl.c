#define PDF_PRIVATE
#include "clibpdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_circle'");
int pdf_add_circle(PDF *pdf, PDFO *page, int xr, int yr, int radius, int width,
                   unsigned colour, unsigned fill_colour)
{
    return pdf_add_ellipse(pdf, page, xr, yr, radius, radius, width, colour,
                           fill_colour);
}
