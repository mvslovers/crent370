#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_graphic_stroke'");
PDFSTREAM *pdf_graphic_stroke(PDF *pdf, PDFSTREAM *pdfstream)
{
    if (pdfstream) {
        pdf_add_streamf(pdf, pdfstream, "S");
        if (pdf->options & PDF_OPTION_DEBUG) pdf_add_streamf(pdf, pdfstream, " %% stroke");
        pdf_add_streamf(pdf, pdfstream, "\r\n");
    }

    return pdfstream;
}
