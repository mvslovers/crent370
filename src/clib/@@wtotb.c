#include <clibwto.h>
#include <clibcrt.h>
#include <clibstae.h>

static void try_traceback(SAVEAREA *sa);

__asm__("\n&FUNC    SETC 'wto_traceback'");
void wto_traceback(SAVEAREA *sa)
{
    try(try_traceback, sa);
}

__asm__("\n&FUNC    SETC 'try_traceback'");
static void try_traceback(SAVEAREA *sa)
{
    CLIBCRT     *crt    = __crtget();
    SAVEAREA    *prev;
    SAVEAREA    *next;
    unsigned    offset;
    unsigned    retto;
    unsigned    frame;
    int         i;
    void        *thisep;
    void        *prevep;
    char        thisname[256];
    char        prevname[256];

    if (!sa) {
        /* caller didn't provide a save area to start at */
        sa = sa_prev(0);    /* this save area has "try_traceback" ep in R15 */
#if 1
        sa = sa_prev(sa);   /* this save area has "call" ep in R15 */
        sa = sa_prev(sa);   /* this save area has "@@@TRY" ep in R15 */
        sa = sa_prev(sa);   /* this save area has "wto_traceback" ep in R15 */
#endif
    }

    wtof("Save area trace back");

    for(i=0, prev = (SAVEAREA*) sa->prev;i < 256 && sa != (SAVEAREA*)crt->crtsave; i++, sa = prev, prev = (SAVEAREA*) sa->prev) {
        next = sa_next(sa);
        prevep = (void*) prev->r15;
        sa_get_epname(prev, prevname);
        thisep = (void*) sa->r15;
        sa_get_epname(sa, thisname);
        frame = (unsigned)next->nab - (unsigned)next;

        retto = (sa->r14 & 0x0FFFFFFF); /* strip out BALR bits in R14 */
        offset = retto - prev->r15;
        wtof("  \"%s\" ep=%06X frame=%u bytes", thisname, thisep, frame);
        wtof("    returns to=%06X \"%s\" ep=%06X+%X", retto, prevname, prevep, offset);
    }
}

#if 0
int main(int argc, char **argv)
{
    wto_traceback(0);

    return 0;
}
#endif
