#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_stream_fdecode'");
PDFSTREAM *pdf_add_stream_fdecode(PDF *pdf, PDFSTREAM *pdfstream, void *obj)
{
    if (pdfstream) {
        if (obj) {
            arrayadd(&pdfstream->objfdecodes, obj);
        }
    }

    return pdfstream;
}
