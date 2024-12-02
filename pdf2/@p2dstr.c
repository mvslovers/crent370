#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_date_string'");
char *pdf_date_string(PDF *pdf, const time_t *time)
{
    char  buf[40];
    int   len;

    len = strftime(buf, sizeof(buf), "%Y%m%d%H%M%S", localtime(time));
    if (pdf->gmthours > 0) {
        sprintf(&buf[len], "+%02d'%02d'", pdf->gmthours, pdf->gmtmins);
    }
    else {
        sprintf(&buf[len], "-%02d'%02d'", pdf->gmthours * -1, pdf->gmtmins);
    }

    return pdf_stringf(pdf, "D:%s", buf);
}
