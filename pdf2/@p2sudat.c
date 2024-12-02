#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_set_user_data'");
int pdf_set_user_data(PDF *pdf, void *udata)
{
    int     rc;

    pdf->udata = udata;

    return 0;
}

