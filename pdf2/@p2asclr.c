#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_stream_color'");
PDFSTREAM *pdf_add_stream_color(PDF *pdf, PDFSTREAM *pdfstream, const char *color)
{
    if (pdfstream) {
        if (color) {
            char  temp[40];
            const char *p = pdf_color_spec(pdf->colors, color, temp);

            if (p) color = temp;

            if (pdf->options & PDF_OPTION_DEBUG) pdf_add_streamf(pdf, pdfstream, "\r\n%% crop area color\r\n");

            pdf_add_streamf(pdf, pdfstream, "q %s rg %u %u %u %u re f Q\r\n",
                color, pdf->cropl, pdf->cropb, pdf->cropw, pdf->croph);
        }
    }

    return pdfstream;
}
