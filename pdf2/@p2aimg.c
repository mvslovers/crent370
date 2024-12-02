#define PDF_PRIVATE
#include "../pdf2/pdfi.h"
#include <clibgrt.h>

__asm__("\n&FUNC    SETC 'pdf_add_image'");
PDFIMAGE *pdf_add_image(PDF *pdf, PDFIMAGE *pdfimage, const unsigned char *data, int len)
{
    if (pdfimage && len > 0) {
        DSTR *dstr = pdfimage->dstr;

        if (dstr) {
            int avail = dstr->size - dstr->len;
            if (avail >= 0 && avail < len) {
                len = avail;
            }

            memcpy(&dstr->stream[dstr->len], data, len);
            dstr->len += len;
        }
    }

    return pdfimage;
}
