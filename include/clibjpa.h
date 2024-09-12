#ifndef CLIBJPA_H
#define CLIBJPA_H
/*
** Maps load module @@JPA (Job Pack Area Anchor) KEY=8 SP=251.
**
** The @@JPA module provides an address space level anchor for
** CLIB areas (CLIBGRT, CLIBCRT).
*/
typedef struct clibjpa  CLIBJPA;    /* Job Pack Area Anchor                 */

#include "cde.h"

struct clibjpa {
    char        jpaeye[8];          /* 00 Eye catcher for dumps "@@CLIB  "  */
    CLIBCRT     **jpacrt;           /* 08 Runtime Library Anchor Array      */
    void        *unused[5];         /* 0C unused                            */
};                                  /* 20 (32 bytes)                        */

extern CLIBJPA *__jpaget(void);

#ifdef __JPAGET__
extern CLIBJPA * __JPAGET(void);
#else
static __inline CLIBJPA *
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
#endif

#endif  /* CLIBJPA_H    */
