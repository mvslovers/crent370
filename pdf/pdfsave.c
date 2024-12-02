#define PDF_PRIVATE
#include "clibpdfi.h"

__asm__("\n&FUNC    SETC 'pdf_save'");
int pdf_save(PDF *pdf, const char *filename)
{
    FILE *fp;
    int e;

    if (filename == NULL)
        fp = stdout;
    else if ((fp = fopen(filename, "wb")) == NULL)
        return pdf_set_err(pdf, -errno, "Unable to open '%s': %s", filename,
                           strerror(errno));

    e = pdf_save_file(pdf, fp);

    if (fp != stdout)
        if (fclose(fp) != 0 && e >= 0)
            return pdf_set_err(pdf, -errno, "Unable to close '%s': %s",
                               filename, strerror(errno));

    return e;
}
