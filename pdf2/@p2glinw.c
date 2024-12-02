#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_graphic_line_width'");
PDFSTREAM *pdf_graphic_line_width(PDF *pdf, PDFSTREAM *pdfstream, unsigned width)
{
    if (pdfstream) {
        pdf_add_streamf(pdf, pdfstream, "%u w", width);
        if (pdf->options & PDF_OPTION_DEBUG) pdf_add_streamf(pdf, pdfstream, " %% line width");
        pdf_add_streamf(pdf, pdfstream, "\r\n");
    }

    return pdfstream;
}
