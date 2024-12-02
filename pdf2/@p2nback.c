#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_new_background'");
PDFSTREAM *pdf_new_background(PDF *pdf)
{
    PDFSTREAM *pdfstream = pdf_new_stream(pdf);

    if (pdfstream) {
        if (pdf->options & PDF_OPTION_DEBUG) pdf_add_streamf(pdf, pdfstream, "\r\n%% Background stream\r\n");
    }

    return pdfstream;
}
