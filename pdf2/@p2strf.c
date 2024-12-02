#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_stringf'");
char *pdf_stringf(PDF *pdf, const char *fmt, ...)
{
    char    buf[1024];
    va_list list;

    va_start(list, fmt);
    vsnprintf(buf, sizeof(buf)-1, fmt, list);
    va_end(list);

    buf[sizeof(buf)-1] = 0;
    return pdf_string(pdf, buf);
}
