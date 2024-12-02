#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_graphic_fill_color'");
PDFSTREAM *pdf_graphic_fill_color(PDF *pdf, PDFSTREAM *pdfstream, const char *color)
{
    if (pdfstream) {
        if (color) {
            char  buf[40];
            const char *p = pdf_color_spec(pdf->colors, color, buf);
            if (p) color = buf;

            pdf_add_streamf(pdf, pdfstream, "%s rg", color);
            if (pdf->options & PDF_OPTION_DEBUG) pdf_add_streamf(pdf, pdfstream, " %% fill color");
            pdf_add_streamf(pdf, pdfstream, "\r\n");
        }
    }

    return pdfstream;
}

