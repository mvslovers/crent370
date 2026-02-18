#define __JPAGET__
#include "clibcrt.h"
#include "clibjpa.h"

CLIBJPA *
__JPAGET(void)
{
    unsigned    *psa    = 0;                        /* low core == PSA      */
    unsigned    *tcb    = (unsigned*)psa[0x21c/4];  /* TCB      == PSATOLD  */
    unsigned    *jstcb  = (unsigned*)tcb[0x7c/4];   /* JSTCB    == TCBJSTCB */
    CDE         *cde    = (CDE*)jstcb[0x2c/4];      /* CDE      == TCBJPQ   */
    CLIBJPA     *jpa    = (CLIBJPA*)0;              /* A(@@JPA) or NULL     */

    while(cde) {
        if (memcmp(cde->CDNAME, "@@CLIB  ", 8)==0) {
            jpa = (CLIBJPA*)cde->CDENTPT;
            break;
        }
        cde = cde->CDCHAIN;
    }

    return jpa;
}
