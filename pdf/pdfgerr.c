#define PDF_PRIVATE
#include "clibpdfi.h"

__asm__("\n&FUNC    SETC 'pdf_get_err'");
const char *pdf_get_err(PDF *pdf, int *errval)
{
    if (!pdf)
        return NULL;

    if (pdf->errstr[0] == '\0')
        return NULL;

    if (errval)
        *errval = pdf->errval;

    return pdf->errstr;
}
