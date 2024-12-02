#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_stream_end_text'");
PDFSTREAM *pdf_add_stream_end_text(PDF *pdf, PDFSTREAM *pdfstream)
{
    /* we have to use pdf_add_streamf() to get automatic EBCDIC to ASCII conversion */
    return pdf_add_streamf(pdf, pdfstream, "ET\r\n");
}

