#include "enqpl.h"
#include "clibenq.h"

int
__enqdeq(const char *qn, const char *rn, unsigned options, int deq)
{
    ENQPL       pl      = {0};
    int         err     = 1;
    int         len;
    char        qname[8];

    if (!qn || !rn) goto quit;

    len = strlen(rn);
    if (!len) goto quit;

    pl.end = ENQ_END_LAST | ENQ_END_OLD;
    pl.len = (unsigned char)len;

    for(len=0; len<8 && qn[len]; len++) {
        qname[len] = qn[len];
    }
    while(len < 8) qname[len++] = ' ';
    pl.qname = qname;

    pl.rname = (char*)rn;

    switch(options & ENQ_SCOPE) {
    case ENQ_SYSTEMS:   pl.opt |= ENQ_OPT_SYSTEMS;  break;
    case ENQ_SYSTEM:    pl.opt |= ENQ_OPT_SYSTEM;   break;
    default:            break;      /* default is STEP                  */
    }

    if (deq) {
        pl.opt = ENQ_OPT_HAVE;
        __asm__( "DS    0H       Request DEQ\n"
        "         LA    1,%0\n"
        "         SVC   48       DEQ" : : "m"(pl) : "0", "1", "15");
    }
    else {
        if (options & ENQ_SHR) pl.opt |= ENQ_OPT_SHARED;
        switch(options & ENQ_RET) {
        case ENQ_TEST:      pl.opt |= ENQ_OPT_TEST;     break;
        case ENQ_USE:       pl.opt |= ENQ_OPT_USE;      break;
        case ENQ_CHNG:      pl.opt |= ENQ_OPT_CHNG;     break;
        default:            pl.opt |= ENQ_OPT_HAVE;     break;
        }
        __asm__( "DS    0H       Request ENQ\n"
        "         LA    1,%0\n"
        "         SVC   56       ENQ" : : "m"(pl) : "0", "1", "15");
    }

    err = pl.rc;

quit:
    return err;
}
