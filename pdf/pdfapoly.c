#define PDF_PRIVATE
#include "clibpdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_polygon'");
int pdf_add_polygon(PDF *pdf, PDFO *page, int x[], int y[], int count,
                    int border_width, unsigned colour)
{
    int ret;
    int i;
    DSTR str = INIT_DSTR;

    dstr_append(&str, "BT ", 3);
    dstr_printf(&str, "%g %g %g RG ", PDF_RGB_R(colour), PDF_RGB_G(colour),
                PDF_RGB_B(colour));
    dstr_printf(&str, "%d w ", border_width);
    dstr_printf(&str, "%d %d m ", x[0], y[0]);
    for (i = 1; i < count; i++) {
        dstr_printf(&str, "%d %d l ", x[i], y[i]);
    }
    dstr_printf(&str, "h S ");
    dstr_append(&str, "ET", 2);

    ret = pdf_add_stream(pdf, page, dstr_data(&str));
    dstr_free(&str);

    return ret;
}
