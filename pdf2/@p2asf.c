#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_streamf'");
PDFSTREAM *pdf_add_streamf(PDF *pdf, PDFSTREAM *pdfstream, const char *fmt, ...)
{
    char    buf[1024];
    va_list list;
    int     len;

    va_start(list, fmt);
    len = vsnprintf(buf, sizeof(buf)-1, fmt, list);
    va_end(list);

    if (len > sizeof(buf)-1) len = sizeof(buf)-1;
    buf[len] = 0;

    pdf_translate(buf, pdf->ebc2asc);   /* translate to ASCII */

    return pdf_add_stream(pdf, pdfstream, len, buf);
}
