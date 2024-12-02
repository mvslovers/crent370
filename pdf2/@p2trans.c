#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_translate'");
unsigned char *pdf_translate(unsigned char *str, const unsigned char *tab)
{
    unsigned char  *p = str;

    if (tab) {
        while(*p) {
            *p = tab[*p];
            p++;
        }
    }
    else {
        while(*p) {
            *p = toupper(*p);
            p++;
        }
    }

    return str;
}
