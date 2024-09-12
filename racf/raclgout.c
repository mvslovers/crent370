/* RACLGOUT.C - racf_logout()
** releases ACEE.
*/
#include "racf.h"
#include "cliblock.h"

__asm__("\n&FUNC    SETC 'racf_logout'");
int
racf_logout(ACEE **acee)
{
    volatile int    rc          = 0;
    int             sup         = 0;
    int             key         = 0;
    unsigned        *psa        = (unsigned *)0;
    unsigned        *ascb       = (unsigned *)psa[0x224/4]; /* A(ASCB)      */
    unsigned        *asxb       = (unsigned *)ascb[0x6C/4]; /* A(ASXB)      */
    ACEE            **asxbsenv  = (ACEE **)  &asxb[0xC8/4]; /* A(ASXBSENV)  */
    ACEE            *oldacee    = *asxbsenv;                /* prev ACEE    */
    RACINIT         plist;

    /* lock the ASXB (ENQ) address */
    lock(asxb,0);

    __asm__("XC\t0(0,%0),0(%0)      clear plist *** executed ***\n\t"
            "EX\t%1,*-6" : : "r"(&plist), "r"(sizeof(plist)-1));
    plist.len   = sizeof(plist);

    __asm__("\n"
"*\n"
"* See if we're in supervisor state\n"
"*\n"
"         TESTAUTH FCTN=0,STATE=YES,KEY=NO,RBLEVEL=1\n\tST\t15,%0" : "=m"(rc)
        : : "1", "14", "15");
    if (rc==0) {
        /* we're in supervisor state */
        sup = 1;
    }

    if (sup) {
        /* we're in supervisor state, switch to key 0 */
        __asm__("\n"
"*\n"
"* we're in supervisor state, switch to key 0\n"
"*\n"
"         IPK\t,\n\tST\t2,%0\n\tSPKA\t0(0)" : "=m"(key) : : "2");
    }
    else {
        __asm__("\n"
"*\n"
"* enter supervisor state\n"
"*\n"
"         MODESET KEY=ZERO,MODE=SUP\n" : : : "1", "14", "15");
    }

    /* put this ACEE in ASXBSENV */
    *asxbsenv = *acee;

    __asm__("\n"
"*\n"
"* delete ACEE\n"
"*\n"
"         RACINIT ENVIR=DELETE,ACEE=(%1),MF=(E,%2)\n"
"         ST\t15,%0" : "=m"(rc) : "r"(acee), "m"(plist) : "1", "14", "15");

    if (oldacee != *acee) {
        /* restore previous ACEE in ASXBSENV */
        *asxbsenv = oldacee;
    }
    else {
        *asxbsenv = (ACEE*)0;
    }

    if (sup) {
        __asm__("\n"
"*\n"
"* we're in supervisor state, switch back to callers key\n"
"*\n"
"         SPKA\t0(%0)" : : "r"(key));
    }
    else {
        __asm__("\n"
"*\n"
"* return to problem state\n"
"*\n"
"         MODESET KEY=NZERO,MODE=PROB\n" : : : "1", "14", "15");
    }

quit:
    /* unlock the ASXB (ENQ) address */
    unlock(asxb,0);
    *acee = (ACEE*)0;
    return rc;
}
