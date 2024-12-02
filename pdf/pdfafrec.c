#define PDF_PRIVATE
#include "clibpdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_filled_rectangle'");
int pdf_add_filled_rectangle(PDF *pdf, PDFO *page, int x, int y, int width, int height,
                             int border_width, unsigned colour)
{
    int ret;
    DSTR str = {0,0,0,{0}};

    dstr_append(&str, "BT ", 3);
    dstr_printf(&str, "%g %g %g rg ", PDF_RGB_R(colour), PDF_RGB_G(colour),
                PDF_RGB_B(colour));
    dstr_printf(&str, "%d w ", border_width);
    dstr_printf(&str, "%d %d %d %d re f ", x, y, width, height);
    dstr_append(&str, "ET", 2);

    ret = pdf_add_stream(pdf, page, dstr_data(&str));
    dstr_free(&str);

    return ret;
}
