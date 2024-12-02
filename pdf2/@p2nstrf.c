#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_new_strf'");
PDFSTR *pdf_new_strf(PDF *pdf, const char *fmt, ...)
{
    char    buf[1024];
    va_list list;

    va_start(list, fmt);
    vsnprintf(buf, sizeof(buf)-1, fmt, list);
    va_end(list);

    buf[sizeof(buf)-1] = 0;
    return pdf_new_str(pdf, buf);
}
