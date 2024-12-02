#define PDF_PRIVATE
#include "clibpdfi.h"

__asm__("\n&FUNC    SETC 'pdf_page_set_size'");
int pdf_page_set_size(PDF *pdf, PDFO *page, int width, int height)
{
    if (!page)
        page = pdf_find_last_object(pdf, OBJ_page);

    if (!page || page->type != OBJ_page)
        return pdf_set_err(pdf, -EINVAL, "Invalid PDF page");

    page->page.width = width;
    page->page.height = height;
    return 0;
}
