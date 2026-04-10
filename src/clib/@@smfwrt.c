/* @@smfwrt.c
** smf_write() - write SMF record via SVC 83.
** Handles TESTAUTH + MODESET internally (same pattern as racf_login).
** Returns: 0=success, non-zero=error (SVC 83 R15 or -1 if SMF inactive)
*/
#include "clibsmf.h"

__asm__("\n&FUNC    SETC 'smf_write'");
int
smf_write(void *record)
{
    volatile int rc  = 0;
    int          sup = 0;

    if (!smf_active()) return -1;

    /* TESTAUTH — already in supervisor state? */
    __asm__("\n"
"*\n"
"* See if we're in supervisor state\n"
"*\n"
"         TESTAUTH FCTN=0,STATE=YES,KEY=NO,RBLEVEL=1\n\tST\t15,%0"
        : "=m"(rc) : : "1", "14", "15");
    if (rc == 0) {
        sup = 1;
    }

    if (!sup) {
        /* switch to supervisor state */
        __asm__("\n"
"*\n"
"* enter supervisor state\n"
"*\n"
"         MODESET KEY=ZERO,MODE=SUP\n"
        : : : "1", "14", "15");
    }

    /* SVC 83 — write SMF record: R0=0, R1=record address */
    __asm__("\n"
"*\n"
"* write SMF record via SVC 83\n"
"*\n"
"         SLR\t0,0\n\t"
"         LR\t1,%1\n\t"
"         SVC\t83\n\t"
"         ST\t15,%0"
        : "=m"(rc) : "r"(record) : "0", "1", "14", "15");

    if (!sup) {
        /* switch back to problem state */
        __asm__("\n"
"*\n"
"* return to problem state\n"
"*\n"
"         MODESET KEY=NZERO,MODE=PROB\n"
        : : : "1", "14", "15");
    }

    return rc;
}
