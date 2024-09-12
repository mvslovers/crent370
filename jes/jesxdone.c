#include <clibstr.h>
#include <clibjes2.h>

int jesxdone(SSSO *ssso)
{
    int         rc      = -1;
    SSOB        ssob;

    initssob(&ssob, ssso);          /* initialize the SSOB header   */
    ssob.SSOBFUNC   = SSOBSOUT;     /* request SYSOUT function      */

    ssso->SSSOFLG1  = 0;            /* no request for SYSOUT        */
    ssso->SSSOFLG2  = SSSOCTRL;     /* tell jes we're done          */

    iefssreq(&ssob);                        /* send request to jes  */
#if 0
    wtodumpf(&ssob, sizeof(ssob), "jesxdone SSOB after IEFSSREQ");
    wtodumpf(ssso, sizeof(SSSO), "jesxdone SSSO after IEFSSREQ");
#endif
    rc = ssob.SSOBRETN;

quit:
    return rc;
}
