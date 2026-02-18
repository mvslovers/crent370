/* @@LOCATE.C */
/*
/* Locate Data Set By Name
/* If dataset is found (rc==0) volser is returned in the &workarea[6]
*/
#include <ctype.h>
#include "clibdscb.h"
#include "clibstr.h"

#define LOCATE 0x44000000

typedef struct {
    unsigned    flags;
    void        *p1;
    void        *p2;
    void        *p3;
} PARMS;

int
__locate(const char dsn[44], LOCWORK *workarea)
{
    int     rc;
    char    dataset[45];
    PARMS   parms;

    strcpyp(dataset, sizeof(dataset)-1, (void*)dsn, ' ');
    dataset[sizeof(dataset)-1] = 0;

    parms.flags     = LOCATE;
    parms.p1        = dataset;	/* dataset name */
    parms.p2        = NULL;		/* volser */
    parms.p3        = workarea; /* locate work area */

    __asm__(
    "LR\t1,%1\n\t"
    "SVC\t26\n\t"
    "LR\t%0,15"
    : "=r" (rc)
    : "r" (&parms)
    : "0", "1", "15" );

    return rc;
}
#if 0
    __asm__(
          "LOCATE    INDAB  READ CATALOG ENTRY FOR DATA SET A.B\n"
"*                          INTO VIRTUAL STORAGE AREA NAMED LOCAREA.\n"
"*                          LOCAREA MAY ALSO CONTAIN A 3-BYTE\n"
"*                          TTR OR A 6-BYTE SERIAL NUMBER\n"
"INDAB     CAMLST    NAME,AB,,LOCAREA\n"
"AB        DC        CL44'A.B'\n"
"LOCAREA   DS        0D\n"
"          DS        265C\n");
#endif
