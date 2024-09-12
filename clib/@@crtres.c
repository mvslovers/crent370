#define __CRTRES__
#define CLIB_C
#include <stdlib.h>
#include <string.h>
#include "clib.h"
#include "clibppa.h"
#include "clibary.h"
#include "cliblock.h"

int
__CRTRES(void)
{
    int         rc      = -1;
    int         locked  = 0;
    unsigned    *psa    = 0;                        /* low core == PSA      */
    unsigned    *tcb    = (unsigned*)psa[0x21c/4];  /* TCB      == PSATOLD  */
    CLIBPPA     *ppa    = __PPAGET();               /* Pgm Props Anchor     */
    CLIBCRT     *crt    = (CLIBCRT *)0;             /* CLIBCRT  or NULL     */
    unsigned    count;
    unsigned    n;

    if (!ppa) goto quit;

    locked  = lock(ppa,0);
    if (locked!=0) goto quit;

    count = arraycou(&ppa->ppacrt);
    for(n=0;n < count; n++) {
        crt = ppa->ppacrt[n];
        if (crt && crt->crttcb == (void*)tcb) {
            arraydel(&ppa->ppacrt, n+1);
            free(crt);
            rc = 0;
            break;
        }
    }

    if (locked==0) {
        unlock(ppa,0);
    }

quit:
    return rc;
}
