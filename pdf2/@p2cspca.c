#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_color_spec_array'");
const char *pdf_color_spec_array(PDFCOLOR **pdfcolors, const char *name, char *buf)
{
   sprintf(buf, "[%s]", PdfColorSpec(pdfcolors, name));

   return buf;
}
