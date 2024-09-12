/* @@DSCBAV.C
/*
/* Data Set Control Block access routines
 */
#include "clibdscb.h"
#include "clibstr.h"

#define SEEK   0xC0800000

typedef struct {
    unsigned    flags;
    void        *p1;
    void        *p2;
    void        *p3;
} PARMS;

int
__dscbav(const char cchhr[5], const char vol[6], DSCB *dscb)
{
    int     rc;
    PARMS   parms;
    char    addr[6];
    char    volser[7];

    strcpyp(addr, sizeof(addr)-1, (void*)cchhr, ' ');
    addr[sizeof(addr)-1] = 0;

    strcpyp(volser, sizeof(volser)-1, (void*)vol, ' ');
    volser[sizeof(volser)-1] = 0;

    parms.flags     = SEEK;
    parms.p1        = addr;
    parms.p2        = volser;
    parms.p3        = dscb;

    __asm__(
    "LR\t1,%1\n\t"
    "SVC\t27    OBTAIN\n\t"
    "LR\t%0,15"
    : "=r" (rc)
    : "r" (&parms)
    : "0", "1", "15" );

   return rc;
}
