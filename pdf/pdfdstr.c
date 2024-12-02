#define PDF_PRIVATE
#include "clibpdfi.h"

__asm__("\n&FUNC    SETC 'pdf_destroy'");
void pdf_destroy(PDF *pdf)
{
    unsigned i;
    unsigned count;

    if (pdf) {
        if (pdf->objects) {
            count = arraycount(&pdf->objects);
            for (i = 0; i < count; i++) {
                pdf_object_destroy(pdf->objects[i]);
            }
            arrayfree(&pdf->objects);
        }
        free(pdf);
    }
}

