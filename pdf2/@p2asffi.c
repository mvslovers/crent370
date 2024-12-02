#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_stream_ffilter'");
PDFSTREAM *pdf_add_stream_ffilter(PDF *pdf, PDFSTREAM *pdfstream, void *obj)
{
    if (pdfstream) {
        if (obj) {
            arrayadd(&pdfstream->objffilters, obj);
        }
    }

    return pdfstream;
}
