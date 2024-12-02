#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_stream_bar'");
PDFSTREAM *pdf_add_stream_bar(PDF *pdf, PDFSTREAM *pdfstream, unsigned width, const char *color)
{
    if (pdfstream) {
        PDFCOLOR *pdfcolor = pdf_find_color(pdf->colors, color);

        if (pdfcolor) {
            unsigned    rgb     = pdfcolor->rgb;
            int         inc     = (int)(width * 2);
            int         y       = (int)(pdf->textt - inc) - 2;

            if (pdf->options & PDF_OPTION_DEBUG) {
                pdf_add_streamf(pdf, pdfstream, "\r\n%% equal spaced \"%s\" horizontal bars, %.2f inch wide\r\n", color, PDF_POINT_TO_INCH(width));
            }

            for(;y >= pdf->textb; y -= inc) {
                pdf_add_streamf(pdf, pdfstream, "q %g %g %g rg %g %g %g RG %u %d %u %u re B Q\r\n",
                    PDF_RGB_R(rgb),      PDF_RGB_G(rgb),      PDF_RGB_B(rgb),       /* stroke color                     */
                    PDF_RGB_R(rgb) - .1, PDF_RGB_G(rgb) - .1, PDF_RGB_B(rgb) - .1,  /* fill color (a little lighter)    */
                    pdf->textl, y, pdf->textw, width);
            }
        }
    }

    return pdfstream;
}
