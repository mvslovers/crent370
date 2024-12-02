#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_out_null'");
int pdf_out_null(void *udata, int len, const char *data)
{
    return 0;
}
