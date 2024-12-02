#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_tell_default'");
int pdf_tell_default(void *udata)
{
    FILE    *fp = (FILE*)udata;
    int     rc;

    rc = ftell(fp);

    return rc;
}
