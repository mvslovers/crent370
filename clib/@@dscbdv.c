/* @@DSCBDV.C */
/*
/* Data Set Control Block access routines
*/
#include <ctype.h>
#include "clibdscb.h"
#include "clibstr.h"

#define SEARCH 0xC1000000

typedef struct {
    unsigned    flags;
    void        *p1;
    void        *p2;
    void        *p3;
} PARMS;

int
__dscbdv(const char dsn[44], const char vol[6], DSCB *dscb)
{
    int     rc;
    char    dataset[45];
    char    volser[7];
    PARMS   parms;

    strcpyp(dataset, sizeof(dataset)-1, (void*)dsn, ' ');
    dataset[sizeof(dataset)-1] = 0;

    strcpyp(volser, sizeof(volser)-1, (void*)vol, ' ');
    volser[sizeof(volser)-1] = 0;

    parms.flags     = SEARCH;
    parms.p1        = dataset;
    parms.p2        = volser;
    parms.p3        = dscb;

    __asm__(
    "LR\t1,%1\n\t"
    "SVC\t27\n\t"
    "LR\t%0,15"
    : "=r" (rc)
    : "r" (&parms)
    : "0", "1", "15" );

    return rc;
}

    __asm__(
          "LOCATE    INDAB  READ CATALOG ENTRY FOR DATA SET A.B\n"
"*                          INTO VIRTUAL STORAGE AREA NAMED LOCAREA.\n"
"*                          LOCAREA MAY ALSO CONTAIN A 3-BYTE\n"
"*                          TTR OR A 6-BYTE SERIAL NUMBER\n"
"INDAB     CAMLST    NAME,AB,,LOCAREA\n"
"AB        DC        CL44'A.B'\n"
"LOCAREA   DS        0D\n"
"          DS        265C\n");
