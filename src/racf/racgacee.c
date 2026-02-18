/* RACGACEE.C - racf_get_acee()
** get ACEE from ASXBSENV
*/
#include "racf.h"

__asm__("\n&FUNC    SETC 'racf_get_acee'");
ACEE *
racf_get_acee(void)
{
    unsigned    *psa        = (unsigned *)0;
    unsigned    *ascb       = (unsigned *)psa[0x224/4]; /* A(ASCB)      */
    unsigned    *asxb       = (unsigned *)ascb[0x6C/4]; /* A(ASXB)      */
    ACEE        **asxbsenv  = (ACEE **)  &asxb[0xC8/4]; /* A(ASXBSENV)  */
    ACEE        *acee       = *asxbsenv;

    return acee;
}
