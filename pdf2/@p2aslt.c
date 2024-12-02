#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_stream_line_to'");
PDFSTREAM *pdf_add_stream_line_to(PDF *pdf, PDFSTREAM *pdfstream, unsigned x, unsigned y)
{
    return pdf_add_streamf(pdf, pdfstream, "%u %u l ", x, y);
}
