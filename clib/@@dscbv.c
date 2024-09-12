/* @@DSCBV.C
/*
/* Data Set Control Block access routines
*/
#include "clibdscb.h"
#include "clibstr.h"

#define SEARCH 0xC1000000
#define VTOCDSN "\x04\x04\x04\x04\x04\x04\x04\x04\x04\x04" \
                "\x04\x04\x04\x04\x04\x04\x04\x04\x04\x04" \
                "\x04\x04\x04\x04\x04\x04\x04\x04\x04\x04" \
                "\x04\x04\x04\x04\x04\x04\x04\x04\x04\x04" \
                "\x04\x04\x04\x04"

typedef struct {
    unsigned    flags;
    void        *p1;
    void        *p2;
    void        *p3;
} PARMS;

int
__dscbv(const char vol[6], DSCB *dscb)
{
    int     rc;
    PARMS   parms;
    char    volser[7];

    strcpyp(volser, sizeof(volser)-1, (void*)vol, ' ');
    volser[sizeof(volser)-1] = 0;

    parms.flags = SEARCH;
    parms.p1    = VTOCDSN;
    parms.p2    = volser;
    parms.p3    = dscb;

    __asm__(
    "LR\t1,%1\n\t"
    "SVC\t27\n\t"
    "LR\t%0,15"
    : "=r" (rc)
    : "r" (&parms)
    : "0", "1", "15" );

    return rc;
}
