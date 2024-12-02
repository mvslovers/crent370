#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_stream_file_include'");
PDFSTREAM *pdf_add_stream_file_include(PDF *pdf, PDFSTREAM *pdfstream, const char *file)
{
    if (pdfstream) {
        if (file) {
            FILE *fp = fopen(file, "r");

            if (!fp) {
                wtof("Unable to open file \"%s\" in pdf_add_stream_file_include() function\n", file);
                goto quit;
            }

            pdf_add_streamf(pdf, pdfstream, "q\r\n");   /* save graphic state */

            while(!feof(fp)) {
                char  buf[1024];
                char  *p = fgets(buf, sizeof(buf)-1, fp);

                if (p) {
                    strtok(buf, "\r\n");    /* strip out any line terminators */
                    pdf_add_streamf(pdf, pdfstream, "%s\r\n", buf);
                }
            }

            pdf_add_streamf(pdf, pdfstream, "Q\r\n");   /* restore graphic state */
            fclose(fp);
        }
    }

quit:
    return pdfstream;
}
