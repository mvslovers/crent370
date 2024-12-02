#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_stream_key_val'");
PDFSTREAM *pdf_add_stream_key_val(PDF *pdf, PDFSTREAM *pdfstream, const char *key_val)
{
    if (pdfstream) {
        if (key_val) {
            char *str = strdup(key_val);

            if (str) {
                pdf_translate(str, pdf->ebc2asc);
                arrayadd(&pdfstream->keyvals, str);
            }
        }
    }

    return pdfstream;
}
