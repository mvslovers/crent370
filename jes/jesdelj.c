#include <iefsscs.h>
#include <iefssso.h>
#include <clibstr.h>
#include <clibjes2.h>

int jesdelj(const char *jobname, const char *jobid)
{
    int         rc      = -1;
    SSOB        ssob;
    SSSO        ssso;

    /* we must have either job name or job id (both are allowed) */
    if (!jobname && !jobid) goto quit;

    initssob(&ssob, &ssso);         /* initialize the SSOB header   */
    ssob.SSOBFUNC   = SSOBSOUT;     /* request SYSOUT function      */

    memset(&ssso, 0, sizeof(SSSO)); /* clear the SYSOUT parm list   */
    ssso.SSSOLEN    = SSSOSIZE;     /* length of SYSOUT parm list   */
    ssso.SSSOUFLG   = SSSODELC;     /* delete request               */
    ssso.SSSOFLG1  |= SSSOHLD;      /* include HELD output          */

    if (jobname) {
        strcpyp(ssso.SSSOJOBN, sizeof(ssso.SSSOJOBN), (void*)jobname, ' ');
        ssso.SSSOFLG1  |= SSSOSJBN; /* job name present             */
    }

    if (jobid) {
        strcpyp(ssso.SSSOJOBI, sizeof(ssso.SSSOJOBI), (void*)jobid, ' ');
        ssso.SSSOFLG1  |= SSSOSJBI; /* job id present               */
    }

    ssso.SSSOFLG2   = SSSOCTRL;     /* processing completed         */

    iefssreq(&ssob);                /* send request to jes          */

    rc = ssob.SSOBRETN;

quit:
    return rc;
}
