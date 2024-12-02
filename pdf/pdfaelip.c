#define PDF_PRIVATE
#include "clibpdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_ellipse'");
int pdf_add_ellipse(PDF *pdf, PDFO *page, int xr,
                    int yr, int xradius, int yradius, int width,
                    unsigned colour, unsigned fill_colour)
{
    int ret;
    DSTR str = {0,0,0,{0}};

    float rx = xradius * 1.0f;
    float ry = yradius * 1.0f;
    float lx, ly;
    float x = xr * 1.0f;
    float y = yr * 1.0f;

    lx = (4.0f / 3.0f) * (M_SQRT2 - 1) * rx;
    ly = (4.0f / 3.0f) * (M_SQRT2 - 1) * ry;

    if (!PDF_IS_TRANSPARENT(fill_colour)) {
        dstr_append(&str, "BT ", 3);
        dstr_printf(&str, "/DeviceRGB CS\r\n");
        dstr_printf(&str, "%g %g %g rg\r\n", PDF_RGB_R(fill_colour),
                    PDF_RGB_G(fill_colour), PDF_RGB_B(fill_colour));
        dstr_append(&str, "ET\r\n", 4);
    }

    dstr_append(&str, "BT ", 3);

    /* stroke color */
    dstr_printf(&str, "/DeviceRGB CS\r\n");
    dstr_printf(&str, "%g %g %g RG\r\n", PDF_RGB_R(colour), PDF_RGB_G(colour),
                PDF_RGB_B(colour));

    dstr_printf(&str, "%d w ", width);

    dstr_printf(&str, "%.2f %.2f m ", (x + rx), (y));

    dstr_printf(&str, "%.2f %.2f %.2f %.2f %.2f %.2f c ", (x + rx), (y - ly),
                (x + lx), (y - ry), x, (y - ry));

    dstr_printf(&str, "%.2f %.2f %.2f %.2f %.2f %.2f c ", (x - lx), (y - ry),
                (x - rx), (y - ly), (x - rx), y);

    dstr_printf(&str, "%.2f %.2f %.2f %.2f %.2f %.2f c ", (x - rx), (y + ly),
                (x - lx), (y + ry), x, (y + ry));

    dstr_printf(&str, "%.2f %.2f %.2f %.2f %.2f %.2f c ", (x + lx), (y + ry),
                (x + rx), (y + ly), (x + rx), y);

    if (PDF_IS_TRANSPARENT(fill_colour))
        dstr_printf(&str, "%s", "S ");
    else
        dstr_printf(&str, "%s", "B ");

    dstr_append(&str, "ET", 2);

    ret = pdf_add_stream(pdf, page, dstr_data(&str));
    dstr_free(&str);

    return ret;
}
