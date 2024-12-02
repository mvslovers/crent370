#define PDF_PRIVATE
#include "clibpdfi.h"

static const char *find_word_break(const char *string);

__asm__("\n&FUNC    SETC 'pdf_add_text_wrap'");
int pdf_add_text_wrap(PDF *pdf, PDFO *page,
                      const char *text, int size, int xoff, int yoff,
                      unsigned colour, int wrap_width, int align)
{
    /* Move through the text string, stopping at word boundaries,
     * trying to find the longest text string we can fit in the given width
     */
    const char *start = text;
    const char *last_best = text;
    const char *end = text;
    char line[512];
    const unsigned short *widths;
    int orig_yoff = yoff;

    PDFO *font = pdf_get_object(pdf, pdf->current_font);

    widths = find_font_widths(font->font.name);
    if (!widths)
        return pdf_set_err(pdf, -EINVAL,
                           "Unable to determine width for font '%s'",
                           font->font.name);

    while (start && *start) {
        const char *new_end = find_word_break(end + 1);
        int line_width;
        int output = 0;
        int xoff_align = xoff;

        end = new_end;

        line_width = pdf_text_pixel_width(start, end - start, size, widths);
        if (line_width < 0)
            return pdf_set_err(pdf, line_width,
                               "Unable to determine text width");

        if (line_width >= wrap_width) {
            if (last_best == start) {
                /* There is a single word that is too long for the line */
                int i;
                /* Find the best character to chop it at */
                for (i = end - start - 1; i > 0; i--) {
                    int e = pdf_text_pixel_width(start, i, size, widths);
                    if (e < 0)
                        return pdf_set_err(pdf, e,
                                           "Unable to determine text width");
                    if (e < wrap_width)
                        break;
                }

                end = start + i;
            } else
                end = last_best;
            output = 1;
        }
        if (*end == '\0')
            output = 1;

        if (*end == '\n' || *end == '\r')
            output = 1;

        if (output) {
            int len = end - start;
            double char_spacing = 0;
            if (len >= sizeof(line))
                len = sizeof(line) - 1;
            strncpy(line, start, len);
            line[len] = '\0';

            line_width = pdf_text_pixel_width(start, len, size, widths);
            if (line_width < 0)
                return pdf_set_err(pdf, line_width,
                                   "Unable to determine text width");

            switch (align) {
            case PDF_ALIGN_RIGHT:
                xoff_align += wrap_width - line_width;
                break;
            case PDF_ALIGN_CENTER:
                xoff_align += (wrap_width - line_width) / 2;
                break;
            case PDF_ALIGN_JUSTIFY:
                if ((len - 1) > 0 && *end != '\r' && *end != '\n' &&
                    *end != '\0')
                    char_spacing =
                        ((double)(wrap_width - line_width)) / (len - 2);
                break;
            }

            pdf_add_text_spacing(pdf, page, line, size, xoff_align, yoff,
                                 colour, char_spacing);

            if (*end == ' ')
                end++;

            start = last_best = end;
            yoff -= size;
        } else
            last_best = end;
    }

    return orig_yoff - yoff;
}

__asm__("\n&FUNC    SETC 'find_word_break'");
static const char *find_word_break(const char *string)
{
    /* Skip over the actual word */
    while (string && *string && !isspace(*string))
        string++;

    return string;
}
