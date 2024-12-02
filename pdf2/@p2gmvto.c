#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_graphic_move_to'");
PDFSTREAM *pdf_graphic_move_to(PDF *pdf, PDFSTREAM *pdfstream, unsigned x, unsigned y)
{
    if (pdfstream) {
        pdf_add_streamf(pdf, pdfstream, "%u %u m", x, y);
        if (pdf->options & PDF_OPTION_DEBUG) pdf_add_streamf(pdf, pdfstream, " %% move to");
        pdf_add_streamf(pdf, pdfstream, "\r\n");
    }

    return pdfstream;
}
