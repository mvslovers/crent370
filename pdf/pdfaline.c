#define PDF_PRIVATE
#include "clibpdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_line'");
int pdf_add_line(PDF *pdf, PDFO *page, int x1, int y1,
                 int x2, int y2, int width, unsigned colour)
{
    int ret;
    DSTR str = {0,0,0,{0}};

    dstr_append(&str, "BT\r\n", 4);
    dstr_printf(&str, "%d w\r\n", width);
    dstr_printf(&str, "%d %d m\r\n", x1, y1);
    dstr_printf(&str, "/DeviceRGB CS\r\n");
    dstr_printf(&str, "%g %g %g RG\r\n", PDF_RGB_R(colour), PDF_RGB_G(colour),
                PDF_RGB_B(colour));
    dstr_printf(&str, "%d %d l S\r\n", x2, y2);
    dstr_append(&str, "ET", 2);

    ret = pdf_add_stream(pdf, page, dstr_data(&str));
    dstr_free(&str);

    return ret;
}
