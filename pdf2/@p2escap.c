#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_escape'");
char *pdf_escape(const char *in, char *out)
{
    char  *p = out;

    while(*in) {
        if (*in=='(' || *in==')' || *in=='\\') {
            *p++ = '\\';
        }
        *p++ = *in++;
    }
    *p = 0;

    return out;
}
