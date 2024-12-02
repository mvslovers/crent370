#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_stream_text'");
PDFSTREAM *pdf_add_stream_text(PDF *pdf, PDFSTREAM *pdfstream, const char *text)
{
    return pdf_add_stream_text_stroke(pdf, pdfstream, text, "'");
}
