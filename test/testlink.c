/* TESTLINK.C test __link() and __linkt() functions */
#include "clibwto.h"
#include "cliblink.h"
#include "clibgrt.h"
#include "clibary.h"

int main(int argc, char **argv)
{
    CLIBGRT *grt    = __grtget();
    int     rc      = 0;
    int     prc     = 0;

    wtof("in TESTLINK, argc=%d, argv=%08X", argc, argv);

    wtof("__link() to IEFBR14");
    rc = __link("IEFBR14", 0, 0, &prc);
    wtof("rc=%d, prc=%d", rc, prc);

    prc = rc = 0;
    wtof("__link() to BADPROG");
    rc = __link("BADPROG", 0, 0, &prc);
    wtof("rc=%d, prc=%d", rc, prc);

    prc = rc = 0;
    wtof("__linkds() to TESTSTAE");
    rc = __linkds("TESTSTAE", 0, 0, &prc);
    wtof("rc=%d, prc=%d", rc, prc);

    prc = rc = 0;
    wtof("__linkt() to IEFBR14");
    rc = __linkt("IEFBR14", 0, 0, &prc);
    wtof("rc=%d, prc=%d", rc, prc);

    prc = rc = 0;
    wtof("__linkds() to BADPROG");
    rc = __linkds("BADPROG", 0, 0, &prc);
    wtof("rc=%d, prc=%d", rc, prc);

    prc = rc = 0;
    wtof("__linkt() to TESTSTAE");
    rc = __linkt("TESTSTAE", 0, 0, &prc);
    wtof("rc=%d, prc=%d", rc, prc);

    if (grt) {
        unsigned n, count = arraycount(&grt->grtptrs);
        wtof("grtptrs=%08X, count=%u", grt->grtptrs, count);
        for(n=0; n < count; n++) {
            wtof("grtptrs#%u = %08X", n, grt->grtptrs[n]);
            wtodumpf(grt->grtptrs[n], 16, "grtptrs#%u", n);
        }
    }

    return rc;
}
