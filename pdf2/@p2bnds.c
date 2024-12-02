#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_boundaries'");
void pdf_boundaries(PDF *pdf)
{
    pdf_boundaries_page(pdf);
}
