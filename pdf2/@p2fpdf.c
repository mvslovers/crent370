#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_free'");
void pdf_free(PDF **pp)
{
    PDF *pdf = pp ? *pp : (PDF*)0;

    if (pdf) {
        free(pdf);
        *pp = (PDF*)0;
    }
}
