#define PDF_PRIVATE
#include "clibpdfi.h"

__asm__("\n&FUNC    SETC 'pdf_create'");
PDF *pdf_create(int width, int height, PDFI *info)
{
    PDF     *pdf;
    PDFO    *obj;

    pdf = calloc(1, sizeof(*pdf));
    pdf->width = width;
    pdf->height = height;
#if 0
    /* We don't want to use ID 0 */
    pdf_add_object(pdf, OBJ_none);
#endif
    /* Create the 'info' object */
    obj = pdf_add_object(pdf, OBJ_info);
    if (!obj) {
        pdf_destroy(pdf);
        return NULL;
    }

    obj->info = calloc(sizeof(*obj->info), 1);
    if (!obj->info) {
        pdf_destroy(pdf);
        return NULL;
    }

    if (info) {
        *obj->info = *info;
        obj->info->creator[sizeof(obj->info->creator) - 1] = '\0';
        obj->info->producer[sizeof(obj->info->producer) - 1] = '\0';
        obj->info->title[sizeof(obj->info->title) - 1] = '\0';
        obj->info->author[sizeof(obj->info->author) - 1] = '\0';
        obj->info->subject[sizeof(obj->info->subject) - 1] = '\0';
        obj->info->date[sizeof(obj->info->date) - 1] = '\0';
    }

    /* FIXME: Should be quoting PDF strings? */
    if (!obj->info->date[0]) {
        time_t now = time(NULL);
        struct tm tm;
        struct tm *tmp;

        tmp = localtime(&now);
        tm = *tmp;

        strftime(obj->info->date, sizeof(obj->info->date), "%Y%m%d%H%M%SZ", &tm);
    }
    if (!obj->info->creator[0])
        snprintf(obj->info->creator, sizeof(obj->info->creator), "clibpdf");
    if (!obj->info->producer[0])
        snprintf(obj->info->producer, sizeof(obj->info->producer), "clibpdf");
    if (!obj->info->title[0])
        snprintf(obj->info->title, sizeof(obj->info->title), "clibpdf");
    if (!obj->info->author[0])
        snprintf(obj->info->author, sizeof(obj->info->author), "clibpdf");
    if (!obj->info->subject[0])
        snprintf(obj->info->subject, sizeof(obj->info->subject), "clibpdf");

    pdf_add_object(pdf, OBJ_pages);
    pdf_add_object(pdf, OBJ_catalog);

    pdf_set_font(pdf, "Times-Roman");

    return pdf;
}
