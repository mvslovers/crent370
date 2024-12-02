#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_color_spec'");
const char *pdf_color_spec(PDFCOLOR **pdfcolors, const char *name, char *color)
{
    unsigned rgb =  PDF_RGB(0xff, 0xff, 0xff);  /* white */
    PDFCOLOR *pdfcolor = pdf_find_color(pdfcolors, name);

    if (pdfcolor) {
        rgb = pdfcolor->rgb;
    }

    sprintf(color, "%g %g %g", PDF_RGB_R(rgb), PDF_RGB_G(rgb), PDF_RGB_B(rgb));

    return (const char*)color;
}
