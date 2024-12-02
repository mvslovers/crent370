#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_viewpref_direction'");
PDFVIEWPREF *pdf_add_viewpref_direction(PDF *pdf, PDFVIEWPREF *pdfviewpref, const char *mode)
{
    if (pdfviewpref) {
        if (mode) {
            pdfviewpref->direction = strdup(mode);
        }
    }

    return pdfviewpref;
}
