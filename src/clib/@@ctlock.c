/* @@CTLOCK.C - cthread_lock(), cthread_unlock()
*/
#include "clibthrd.h"
#include "clibenq.h"

#define QNAME   "LCTHREAD"

/* __ctlock() rname = "string value" */
__asm__("\n&FUNC    SETC 'cthread_lock'");
int
cthread_lock(int shared, const char *rname)
{
    int             rc;
    int             len;
    unsigned char   buf[24];

    if (!rname) {
        unsigned    *psa    = (unsigned *)0;
        unsigned    tcb     = psa[0x21C/4];
        unsigned    *ascb   = (unsigned *)psa[0x224/4];
        unsigned    asid    = ((ascb[0x24/4]) >> 16);

        sprintf(buf, "CTHDX.%04X.%08X", asid, tcb);
        rname = buf;
    }

    if (shared) {
        shared = ENQ_SHR;
    }

    rc = ENQ(QNAME, rname, shared);

    return rc;
}

__asm__("\n&FUNC    SETC 'cthread_unlock'");
int
cthread_unlock(const char *rname)
{
    int             rc;
    int             len;
    unsigned char   buf[24];

    if (!rname) {
        unsigned    *psa    = (unsigned *)0;
        unsigned    tcb     = psa[0x21C/4];
        unsigned    *ascb   = (unsigned *)psa[0x224/4];
        unsigned    asid    = ((ascb[0x24/4]) >> 16);

        sprintf(buf, "CTHDX.%04X.%08X", asid, tcb);
        rname = buf;
    }

    rc = DEQ(QNAME, rname, 0);

    return rc;
}
