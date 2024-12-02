#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_graphic_save'");
PDFSTREAM *pdf_graphic_save(PDF *pdf, PDFSTREAM *pdfstream)
{
    if (pdfstream) {
        pdf_add_streamf(pdf, pdfstream, "q");
        if (pdf->options & PDF_OPTION_DEBUG) pdf_add_streamf(pdf, pdfstream, " %% save graphic state");
        pdf_add_streamf(pdf, pdfstream, "\r\n");
    }

    return pdfstream;
}
