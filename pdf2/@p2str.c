#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_string'");
char *pdf_string(PDF *pdf, const char *str)
{
    char    *p = NULL;
    char    buf[2048];

    if (str) {
        int len = strlen(pdf_escape(str, buf));
        p = calloc(1, len + 3);
        if (p) {
            p[0] = '(';
            memcpy(&p[1],buf,len);
            p[len+1] = ')';
            p[len+2] = 0;
        }
    }

    return p;
}
