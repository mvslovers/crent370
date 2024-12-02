#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_stream_stroking_color'");
PDFSTREAM *pdf_add_stream_stroking_color(PDF *pdf, PDFSTREAM *pdfstream, const char *color)
{
    char        color_buf[256];
    const char *color_spec = pdf_color_spec(pdf->colors, color, color_buf);

    if (color_spec) {
        return pdf_add_streamf(pdf, pdfstream, "%s RG ", color_spec);
    }

    return NULL;
}
