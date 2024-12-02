#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_stream_filter'");
PDFSTREAM *pdf_add_stream_filter(PDF *pdf, PDFSTREAM *pdfstream, void *obj)
{
    if (pdfstream) {
        if (obj) {
            arrayadd(&pdfstream->objfilters, obj);
        }
    }

    return pdfstream;
}
