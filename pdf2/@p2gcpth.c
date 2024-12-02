#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_graphic_close_path'");
PDFSTREAM *pdf_graphic_close_path(PDF *pdf, PDFSTREAM *pdfstream)
{
    if (pdfstream) {
        pdf_add_streamf(pdf, pdfstream, "h");
        if (pdf->options & PDF_OPTION_DEBUG) pdf_add_streamf(pdf, pdfstream, " %% close path");
        pdf_add_streamf(pdf, pdfstream, "\r\n");
    }

    return pdfstream;
}
