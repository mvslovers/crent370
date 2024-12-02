#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_stream'");
PDFSTREAM *pdf_add_stream(PDF *pdf, PDFSTREAM *pdfstream, int len, const char *stream)
{
    if (pdfstream) {
        pdf_add_dstr(pdf, pdfstream, len, stream);
    }

    return pdfstream;
}
