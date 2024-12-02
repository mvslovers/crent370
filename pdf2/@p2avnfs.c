#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_viewpref_non_full_screen_page_mode'");
PDFVIEWPREF *pdf_add_viewpref_non_full_screen_page_mode(PDF *pdf, PDFVIEWPREF *pdfviewpref, const char *mode)
{
    if (pdfviewpref) {
        if (mode) {
            pdfviewpref->nonfullscreenpagemode = strdup(mode);
        }
    }

    return pdfviewpref;
}
