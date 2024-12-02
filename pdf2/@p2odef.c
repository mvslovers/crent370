#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_out_default'");
int pdf_out_default(void *udata, int len, const char *data)
{
    FILE    *fp = (FILE*)udata;
    int     rc;

    if (!len) return 0; /* nothing to output, always success */

    if (!(fp->flags & _FILE_FLAG_WRITE)) {
        wtof("pdf_out_default() file not opened for output");
        return -1;
    }

    if (!(fp->flags & _FILE_FLAG_BINARY)) {
        wtof("pdf_out_default() file not opened in binary mode");
        return -1;
    }

    rc = fwrite(data, 1, len, fp);

    return (len - rc);    /* should be zero for success */
}
