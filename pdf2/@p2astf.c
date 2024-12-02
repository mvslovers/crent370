#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_stream_textf'");
PDFSTREAM *pdf_add_stream_textf(PDF *pdf, PDFSTREAM *pdfstream, const char *fmt, ... )
{
    char    buf[1024];
    va_list list;

    va_start(list, fmt);
    vnsprintf(buf, sizeof(buf)-1, fmt, list);
    va_end(list);

    buf[sizeof(buf)-1] = 0;
    return pdf_add_stream_text(pdf, pdfstream, buf);
}
