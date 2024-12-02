#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_graphic_line_to'");
PDFSTREAM *pdf_graphic_line_to(PDF *pdf, PDFSTREAM *pdfstream, unsigned x, unsigned y)
{
    if (pdfstream) {
        pdf_add_streamf(pdf, pdfstream, "%u %u l", x, y);
        if (pdf->options & PDF_OPTION_DEBUG) pdf_add_streamf(pdf, pdfstream, " %% line to");
        pdf_add_streamf(pdf, pdfstream, "\r\n");
    }

    return pdfstream;
}
