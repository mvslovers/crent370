#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_stream_file'");
PDFSTREAM *pdf_add_stream_file(PDF *pdf, PDFSTREAM *pdfstream, void *obj)
{
    if (pdfstream) {
        if (obj) {
            pdfstream->objfile = obj;
        }
    }

    return pdfstream;
}
