#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_graphic_dash_line'");
PDFSTREAM *pdf_graphic_dash_line(PDF *pdf, PDFSTREAM *pdfstream, unsigned on, unsigned off, unsigned phase)
{
    if (pdfstream) {
        pdf_add_streamf(pdf, pdfstream, "[%u %u] %u d", on, off, phase);
        if (pdf->options & PDF_OPTION_DEBUG) pdf_add_streamf(pdf, pdfstream, " %% dash line");
        pdf_add_streamf(pdf, pdfstream, "\r\n");
    }

    return pdfstream;
}
