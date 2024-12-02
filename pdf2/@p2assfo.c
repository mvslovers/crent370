#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_stream_select_font'");
PDFSTREAM *pdf_add_stream_select_font(PDF *pdf, PDFSTREAM *pdfstream, const char *name, unsigned points)
{
    return pdf_add_streamf(pdf, pdfstream, "%s %u Tf ", name, points);
}
