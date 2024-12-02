#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_new_page'");
PDFPAGE *pdf_new_page(PDF *pdf, int width, int height)
{
    PDFPAGE *pdfpage = calloc(1, sizeof(PDFPAGE));
    PDFRECT *pdfrect = pdf_new_rect(pdf, 0, 0, width, height);

    if (pdfpage) {
        PDFOBJ *pdfobj = (PDFOBJ *)pdfpage;

        pdfobj->type = OBJPAGE;
        pdfobj->index = ++pdf->current_index;
        arrayadd(&pdf->objects, pdfpage);
        arrayadd(&pdf->offsets, (void*)0);

        pdfpage->medixbox = pdfrect;

        pdf->current_page = pdfpage;
        pdf->paperw     = width;    /* points */
        pdf->paperh     = height;   /* points */
        if (width == 612 /* 8.5 in */ && height == 720 /* 11.0 in */) {
            pdf->lpi = 6;
        }
        else {
            pdf->lpi = 8;
        }
        pdf_boundaries(pdf);

        if (pdf->pages) {
            PDFPAGES *pdfpages = (PDFPAGES*)pdf->pages;

            pdfpage->pages = pdfpages;              /* this is the parent for this page */
            arrayadd(&pdfpages->pdfpage, pdfpage);  /* we are one of our parents kids   */
        }
    }

    return pdfpage;
}
