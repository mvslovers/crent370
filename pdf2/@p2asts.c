#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_stream_text_stroke'");
PDFSTREAM *pdf_stream_add_text_stroke(PDF *pdf, PDFSTREAM *pdfstream, const char *text, const char *stroke)
{
    int     len = 0;
    int     avail;
    char    buf[2048];

    if (pdfstream) {
        if (text) {
            buf[len++] = '(';
            pdf_escape(text, &buf[len]);  /* copy text to buf, escaped characters as needed */
            len += strlen(&buf[len]);

            avail = sizeof(buf) - len - 3;
            if (avail > 2) {
                buf[len++] = ')';
                buf[len] = 0;
                avail = sizeof(buf) - len - 3;
            }

            if (stroke && avail > strlen(stroke)) {
                /* append the stroke to our escaped string */
                len += snprintf(&buf[len], avail, "%s", stroke);
                avail = sizeof(buf) - len - 3;
            }

            if (avail > 3) {
                strcat(&buf[len], "\r\n");
            }
            else {
                buf[len] = 0;
            }

            pdf_translate(buf, pdf->ebc2asc);   /* translate to ASCII */
            pdf_add_dstr(pdf, pdfstream, strlen(buf), buf);
        }
    }

    return pdfstream;
}
