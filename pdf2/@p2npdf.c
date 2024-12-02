#include "../pdf2/pdfi.h"
extern unsigned char *ebc2asc;

__asm__("\n&FUNC    SETC 'pdf_new'");
PDF *pdf_new(int (*out)(void *udata, int len, const char *data), int (*tell)(void *udata), void *udata)
{
    PDF     *pdf = calloc(1, sizeof(PDF));

    if (!pdf) goto quit;

    if (!out) {
        out = pdf_out_default;
        if (!udata) udata = stdout;
        if (!tell)  tell = (void*)ftell;
    }

    strcpy(pdf->eye, PDF_EYE);
    pdf->out        = out;
    pdf->udata      = udata;
    pdf->tell       = tell;
    pdf->ebc2asc    = ebc2asc;

quit:
    return pdf;
}
