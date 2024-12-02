#define PDF_PRIVATE
#include "clibpdfi.h"

__asm__("\n&FUNC    SETC 'pdf_set_font'");
int pdf_set_font(PDF *pdf, const char *font)
{
    PDFO    *obj;
    int     last_index = 0;

    /* See if we've used this font before */
    for (obj = pdf_find_first_object(pdf, OBJ_font); obj; obj = pdf_get_object(pdf, obj->next)) {
        if (strcmp(obj->font.name, font) == 0)
            break;
        last_index = obj->font.index;
    }

    /* Create a new font object if we need it */
    if (!obj) {
        obj = pdf_add_object(pdf, OBJ_font);
        if (!obj)
            return pdf->errval;
        strncpy(obj->font.name, font, sizeof(obj->font.name));
        obj->font.name[sizeof(obj->font.name) - 1] = '\0';
        obj->font.index = last_index + 1;
    }

    pdf->current_font = obj->index;

    return 0;
}
