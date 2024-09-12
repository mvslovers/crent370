/* RACSACEE.C - racf_set_acee()
** set ASXBSENV with new ACEE value, returns previous ACEE value.
*/
#include "racf.h"

__asm__("\n&FUNC    SETC 'racf_set_acee'");
ACEE *
racf_set_acee(ACEE *newacee)
{
    int         rc          = 0;
    int         key         = 0;
    unsigned    *psa        = (unsigned *)0;
    unsigned    *ascb       = (unsigned *)psa[0x224/4]; /* A(ASCB)      */
    unsigned    *asxb       = (unsigned *)ascb[0x6C/4]; /* A(ASXB)      */
    ACEE        **asxbsenv  = (ACEE **)  &asxb[0xC8/4]; /* A(ASXBSENV)  */
    ACEE        *oldacee    = *asxbsenv;                /* prev ACEE    */

#if 1
    __asm__("\n"
"*\n"
"* See if we're in supervisor state\n"
"*\n"
"         TESTAUTH FCTN=0,STATE=YES,KEY=NO,RBLEVEL=1\n\tST\t15,%0" : "=m"(rc)
        : : "1", "14", "15");
    if (rc==0) {
        /* we're in supervisor state, switch to key 0 */
        __asm__("\n"
"*\n"
"* we're in supervisor state, switch to key 0\n"
"*\n"
"         IPK\t,\n\tST\t2,%0\n\tSPKA\t0(0)" : "=m"(key) : : "2");

        /* set ASXBSENV with the new ACEE pointer */
        *asxbsenv = newacee;

        __asm__("\n"
"*\n"
"* we're in supervisor state, switch back to callers key\n"
"*\n"
"         SPKA\t0(%0)" : : "r"(key));
        goto quit;
    }
#endif

    __asm__("\n"
"*\n"
"* enter supervisor state\n"
"*\n"
"         MODESET KEY=ZERO,MODE=SUP\n"
        : : : "1", "14", "15");

    /* set ASXBSENV with the new ACEE pointer */
    *asxbsenv = newacee;

    __asm__("\n"
"*\n"
"* return to problem state\n"
"*\n"
"         MODESET KEY=NZERO,MODE=PROB\n"
        : : : "1", "14", "15");

quit:
    return oldacee;
}
