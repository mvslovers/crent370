#define PDF_PRIVATE
#include "clibpdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_bookmark'");
int pdf_add_bookmark(PDF *pdf, PDFO *page, int parent, const char *name)
{
    PDFO *obj;

    if (!page)
        page = pdf_find_last_object(pdf, OBJ_page);

    if (!page)
        return pdf_set_err(pdf, -EINVAL,
                           "Unable to add bookmark, no pages available");

    if (!pdf_find_first_object(pdf, OBJ_outline))
        if (!pdf_add_object(pdf, OBJ_outline))
            return pdf->errval;

    obj = pdf_add_object(pdf, OBJ_bookmark);
    if (!obj)
        return pdf->errval;

    strncpy(obj->bookmark.name, name, sizeof(obj->bookmark.name));
    obj->bookmark.name[sizeof(obj->bookmark.name) - 1] = '\0';
    obj->bookmark.page = page->index;
    if (parent >= 0) {
        PDFO *parent_obj = pdf_get_object(pdf, parent);
        if (!parent_obj)
            return pdf_set_err(pdf, -EINVAL, "Invalid parent ID %d supplied",
                               parent);
        obj->bookmark.parent = parent_obj->index;
        arrayadd(&parent_obj->bookmark.children, (void *)obj->index);
    }

    return obj->index;
}
