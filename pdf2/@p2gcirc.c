#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

/* example pdf_graphic_circle(pdf, pdfstream, 100, 100, 20, "B")  at 100,100 draw a 20 point radius circle, fill and stroke */
/* example pdf_graphic_circle(pdf, pdfstream, 100, 100, 20, "S")  at 100,100 draw a 20 point radius circle, stroke only */

__asm__("\n&FUNC    SETC 'pdf_graphic_circle'");
PDFSTREAM *pdf_graphic_circle(PDF *pdf, PDFSTREAM *pdfstream, unsigned x, unsigned y, unsigned r, const char *stroke)
{
    if (pdfstream) {
        double c[8];
        double *ci = pdf_calc_arc(r, 90.0, c);

        /* Top half of circle */
        pdf_add_streamf(pdf, pdfstream, "%g %g m %g %g %g %g %g %g c %s ",
            x+ci[0], y+ci[1], x+ci[2], y+ci[3], x+ci[4], y+ci[5], x+ci[6], y+ci[7], stroke);

        /* Bottom half of circle */
        pdf_add_streamf(pdf, pdfstream, "%g %g m %g %g %g %g %g %g c %s",
            x-ci[0], y-ci[1], x-ci[2], y-ci[3], x-ci[4], y-ci[5], x-ci[6], y-ci[7], stroke);

        if (pdf->options & PDF_OPTION_DEBUG) pdf_add_streamf(pdf, pdfstream, " %% circle");
        pdf_add_streamf(pdf, pdfstream, "\r\n");
    }

    return pdfstream;
}
