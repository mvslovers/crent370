#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_graphic_solid_line'");
PDFSTREAM *pdf_graphic_solid_line(PDF *pdf, PDFSTREAM *pdfstream)
{
    if (pdfstream) {
        pdf_add_streamf(pdf, pdfstream, "[] 0 d");
        if (pdf->options & PDF_OPTION_DEBUG) pdf_add_streamf(pdf, pdfstream, " %% solid line");
        pdf_add_streamf(pdf, pdfstream, "\r\n");
    }

    return pdfstream;
}
