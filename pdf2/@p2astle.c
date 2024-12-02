#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_stream_text_leading'");
PDFSTREAM *pdf_add_stream_text_leading(PDF *pdf, PDFSTREAM *pdfstream, unsigned leading)
{
    return pdf_add_streamf(pdf, pdfstream, "%u TL ", leading);
}
