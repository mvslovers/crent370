#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_stream_text_matrix'");
PDFSTREAM *pdf_add_stream_text_matrix(PDF *pdf, PDFSTREAM *pdfstream, unsigned leftmargin, unsigned topmargin)
{
    return pdf_add_streamf(pdf, pdfstream, "1 0 0 1 %u %u Tm ", leftmargin, topmargin);
}
