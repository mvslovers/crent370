#include <clib.h>

__asm__("\n&FUNC    SETC 'clib_find_cde'");
CDE *
clib_find_cde(const char *name)
{
    unsigned    *psa    = 0;                        /* low core == PSA      */
    unsigned    *tcb    = (unsigned*)psa[0x21c/4];  /* TCB      == PSATOLD  */
    unsigned    *jstcb  = (unsigned*)tcb[0x7c/4];   /* JSTCB    == TCBJSTCB */
    CDE         *cde    = (CDE*)jstcb[0x2c/4];      /* CDE      == TCBJPQ   */
    int         i;
    char        temp[9] = "        ";

    for(i=0; i < 8 && name[i]; i++) {
        temp[i] = name[i];
    }

    while(cde) {
        if (memcmp(cde->CDNAME, temp, 8)==0) {
            return cde;
            break;
        }
        cde = cde->CDCHAIN;
    }

    return NULL;
}
