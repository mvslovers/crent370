#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_get_dstr'");
static DSTR *pdf_get_dstr(PDF *pdf, PDFSTREAM *pdfstream)
{
    unsigned count = arraycount(&pdfstream->dstrs);
    DSTR *dstr = arrayget(&pdfstream->dstrs, count);
#define DSTR_CHUNK  256

    if (!dstr || dstr->len == dstr->size) {
        /* Allocate new DSTR structure */
        dstr = calloc(1, sizeof(DSTR) + DSTR_CHUNK);
        if (dstr) {
            dstr->stream = ((char *)dstr) + sizeof(DSTR);
            dstr->size   = DSTR_CHUNK;
            arrayadd(&pdfstream->dstrs, dstr);
        }
    }
    else if (dstr->len > dstr->size || dstr->len < 0) {
        wtof("_p2core->pdf_get_dstr() error, dstr->len > dstr->size or dstr->len < 0");
        wtof("_p2core->pdf_get_dstr() error, %d > %d or %d < 0", dstr->len, dstr->size, dstr->len);
        asm("DC\tH'0' DIE DIE DIE");
    }

    return dstr;
}

__asm__("\n&FUNC    SETC 'pdf_add_dstr'");
static void pdf_add_dstr(PDF *pdf, PDFSTREAM *pdfstream, int len, const char *stream)
{
    if (len > 0) {
        pdfstream->len += len;
        while(len > 0) {
            DSTR *dstr = pdf_get_dstr(pdf, pdfstream);
            int move = len;
            int avail = dstr->size - dstr->len;

            if (move > avail) {
                move = avail;
            }

            memcpy(&dstr->stream[dstr->len], stream, move);
            stream += move;
            dstr->len += move;
            len -= move;
        }
    }
}

#if 1
__asm__("\n&FUNC    SETC 'chop'");
static double chop(double t)
{
    return (double)(((int) (t * 1000)) / 1000.0);
}
#else
#define chop(t) ((double)(((int) (t * 1000)) / 1000.0))
#endif
__asm__("\n&FUNC    SETC 'pdf_calc_arc'");
static double *pdf_calc_arc(double r, double a, double f[8])
{
    double t;

    a = (double)((3.141593 / 180.0) * a);

    t = (double)((r * (4.0/3.0) * (1 - cos(a)) ) / sin(a));

    f[6] = (double)(r * cos( 2 * a ));
    f[7] = (double)(r * sin( 2 * a ));
    f[4] = chop( (double)(f[6] + t * sin( 2 * a )) );
    f[5] = chop( (double)(f[7] - t * cos( 2 * a )) );
    f[6] = chop( f[6] );
    f[7] = chop( f[7] );
    f[2] = chop( r );
    f[3] = chop( t );
    f[0] = r;
    f[1] = 0;

    return &f[0];
}

static struct pdf_private pdfprivate = {
    pdf_get_dstr,
    pdf_add_dstr,
    pdf_calc_arc,
};

struct pdf_private *_p2core = &pdfprivate;
