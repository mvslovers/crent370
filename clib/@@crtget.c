#define __CRTGET__
#define CLIB_C
#include <stdlib.h>
#include <string.h>
#include "clib.h"
#include "clibppa.h"
#include "clibary.h"
#include "cliblock.h"

CLIBCRT *
__CRTGET(void)
{
    int         locked  = 0;
    unsigned    *psa    = 0;                        /* low core == PSA      */
    void        *tcb    = (void*)psa[0x21c/4];      /* TCB      == PSATOLD  */
    CLIBPPA     *ppa    = __PPAGET();               /* Pgm Props Anchor     */
    CLIBCRT     *crt    = (CLIBCRT *)0;             /* CLIBCRT  or NULL     */
    unsigned    count   = 0;
    unsigned    n;

    if (!ppa) goto quit;

    locked  = lock(ppa,1);      /* 1=read only (shared) */
    if (locked!=0) goto quit;

    count = arraycou(&ppa->ppacrt);

    for(n=0;n < count; n++) {
        if (ppa->ppacrt[n]->crttcb == tcb) {
            crt = ppa->ppacrt[n];
            break;
        }
    }

    if (locked==0) {
        unlock(ppa,1);
    }

quit:
    if (!crt) {
        wtof("%s CRT for TCB(%08X) was not found in PPA(%08X)", __func__, tcb, ppa);
        if (ppa && count) {
            wtodumpf(ppa->ppacrt, count * 4, "PPACRT");
        }
    }
    return crt;
}
