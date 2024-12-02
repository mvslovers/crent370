#define PDF_PRIVATE
#include "clibpdfi.h"

__asm__("\n&FUNC    SETC 'pdf_get_font_text_width'");
int pdf_get_font_text_width(PDF *pdf, const char *font_name, const char *text, int size)
{
    const unsigned short *widths = find_font_widths(font_name);
    int err;

    if (!widths)
        return pdf_set_err(pdf, -EINVAL,
                           "Unable to determine width for font '%s'",
                           font_name);

    err = pdf_text_pixel_width(text, -1, size, widths);
    if (err < 0)
        return pdf_set_err(pdf, err, "Unable to determine text width");

    return err;
}
