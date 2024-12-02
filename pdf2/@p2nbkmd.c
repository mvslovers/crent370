#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_new_bookmark_dest'");
PDFOUTLINE *pdf_new_bookmark_dest(PDF *pdf, PDFOUTLINE *parent, const char *title, const char *color, PDFDEST *pdfdest)
{
    PDFOUTLINE  *pdfoutline;
    char        buf[256];

    if (!pdf) return NULL;

    if (!parent) {
        /* Make parent the root object */
        if (!pdf->outlines) pdf_new_outlines(pdf);
        parent = (PDFOUTLINE *)pdf->outlines;
    }

    pdfoutline = pdf_new_outline(pdf);

    if (pdfoutline) {
        PDFOUTLINE *sibling = (PDFOUTLINE *)parent->last;

        /* Chain siblings together */
        if (sibling) {
            sibling->next = (PDFOBJ *)pdfoutline;
            pdfoutline->prev = (PDFOBJ *)sibling;
        }

        /* Chain the parent "bookmark" to this "bookmark" */
        if (!parent->first) {
            parent->first = (PDFOBJ *)pdfoutline;
        }
        parent->last = (PDFOBJ *)pdfoutline;
        parent->count++;

        /* Chain this "bookmark" to it's parent */
        pdfoutline->parent = (PDFOBJ *)parent;

        /* Set title for bookmark */
        if (title) {
            if (*title=='(') {
                pdfoutline->title = strdup(title);
            }
            else {
                pdf_escape(title, buf);
                pdfoutline->title = calloc(1,strlen(buf)+3);
                sprintf(pdfoutline->title, "(%s)", buf);
            }
        }

        /* Set color for bookmark */
        if (color) {
            pdf_color_spec_array(pdf->colors, color, buf);
            color = buf;
        }
        pdfoutline->color = strdup(color);

        /* Add our destination */
        pdfoutline->dest = (PDFOBJ *)pdfdest;
    }

    return pdfoutline;
}
