#define __CRTSET__
#define CLIB_C
#include <stdlib.h>
#include <string.h>
#include "clib.h"
#include "clibppa.h"
#include "clibary.h"
#include "cliblock.h"

int
__CRTSET(void)
{
    int         rc      = -1;
    int         locked  = 0;
    unsigned    *psa    = 0;                        /* low core == PSA      */
    unsigned    *tcb    = (unsigned*)psa[0x21c/4];  /* TCB      == PSATOLD  */
    unsigned    *otcb   = (unsigned*)tcb[0x84/4];   /* OTCB     == TCBOTC   */
    unsigned    *jscb   = (unsigned*)tcb[0xB4/4];   /* JSCB     == TCBJSCB  */
    CLIBPPA     *ppa    = __PPAGET();               /* Pgm Prop Anchor      */
    CLIBCRT     *crt    = (CLIBCRT *)0;             /* CLIBCRT  or NULL     */
    CLIBGRT     *grt    = (CLIBGRT *)0;

    if (!ppa) goto quit;

    locked  = lock(ppa,0);
    if (locked!=0) goto quit;

    crt = calloc(1, sizeof(CLIBCRT));
    if (crt) {
        unsigned count = arraycou(&ppa->ppacrt);
        unsigned n;

        for(n=0;n < count; n++) {
            if (ppa->ppacrt[n]->crttcb == (void*)otcb) {
                CLIBCRT *ocrt = ppa->ppacrt[n];

                if (ocrt) {
                    grt = ocrt->crtgrt;
                }
                break;
            }
        }

        memcpy(crt->crteye, "CLIBCRT ", 8);
        crt->crttcb     = tcb;
        crt->crtgrt     = grt;
#if 0 /* GETTZOFF() is not working, replaced with CVTTZ value */
        crt->crttzoff   = GETTZOFF();
#else
        do {
            int *cvt = *(int**)16;                      /* get CVT pointer from PSA */
            crt->crttzoff = (int)(cvt[0x130/4] * 1.0485765);  /* convert CVTTZ to seconds from UTC */
        } while(0);
#endif
        crt->crtuserl   = sizeof(CLIBCRT);
        crt->crtauth    = *((char*)jscb + 0xEC);    /* JSCBAUTH byte */

        rc = arrayadd(&ppa->ppacrt, crt);
    }

    if (locked==0) {
        unlock(ppa,0);
    }

quit:
    return rc;
}
