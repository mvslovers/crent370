#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_set_tell'");
int pdf_set_tell(PDF *pdf, int (*tell)(void *udata))
{
    int     rc;

    pdf->tell = tell;

    return 0;
}

