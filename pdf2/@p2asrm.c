#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_stream_render_mode'");
PDFSTREAM *pdf_add_stream_render_mode(PDF *pdf, PDFSTREAM *pdfstream, unsigned mode)
{
    return pdf_add_streamf(pdf, pdfstream, "%u Tr ", mode);
}
