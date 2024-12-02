#define PDF_PRIVATE
#include "../pdf2/pdfi.h"
#include <clibgrt.h>

__asm__("\n&FUNC    SETC 'pdf_new_info'");
PDFINFO *pdf_new_info(PDF *pdf, const char *title, const char *subject, const char *author, const char *keywords,
                      const char *creator, const char *producer, const time_t *created)
{
    time_t      now;
    CLIBGRT     *grt     = __grtget();
    const char  **argv   = (const char **)grt->grtptrs;
    PDFINFO     *pdfinfo = calloc(1, sizeof(PDFINFO));

    if (pdfinfo) {
        PDFOBJ *pdfobj = (PDFOBJ *)pdfinfo;

        pdfobj->type = OBJINFO;
        pdfobj->index = ++pdf->current_index;

        if (title)      pdfinfo->title      = pdf_string(pdf, title);
        if (subject)    pdfinfo->subject    = pdf_string(pdf, subject);
        if (author)     pdfinfo->author     = pdf_string(pdf, author);
        if (keywords)   pdfinfo->keywords   = pdf_string(pdf, keywords);
        if (creator)    pdfinfo->creator    = pdf_string(pdf, creator);
        if (producer) {
            pdfinfo->producer = pdf_string(pdf, producer);
        }
        else {
            producer = argv[0];                     /* use program name */
            if (!producer) producer = "PDFINFO";    /* just in case */
            pdfinfo->producer = pdf_string(pdf, producer);
        }

        if (!created) {
            now = time(NULL);
            created = &now;
        }
        pdfinfo->created = pdf_date_string(pdf, created);

        pdf->pdfinfo = pdfinfo;

        arrayadd(&pdf->objects, pdfinfo);
        arrayadd(&pdf->offsets, (void*)0);
    }

    return pdfinfo;
}
