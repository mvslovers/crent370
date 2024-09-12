#include <iefsscs.h>
#include <iefssso.h>
#include <clibstr.h>
#include <clibjes2.h>

int jescanj(const char *jobname, const char *jobid, int purge)
{
    int         rc      = -1;
    SSOB        ssob;
    SSCS        sscs;

    initssob(&ssob, &sscs);         /* initialize the SSOB header   */
    ssob.SSOBFUNC   = SSOBCANC;     /* request CACNEL function      */

    memset(&sscs, 0, sizeof(SSCS)); /* clear the CANCEL parm list   */
    sscs.SSCSLEN    = SSCSIZE;      /* length of CANCEL parm list   */

    if (jobname) {
        strcpyp(sscs.SSCSJOBN, sizeof(sscs.SSCSJOBN), (void*)jobname, ' ');
    }

    if (jobid) {
        strcpyp(sscs.SSCSJOBI, sizeof(sscs.SSCSJOBI), (void*)jobid, ' ');
    }

    if (purge) {
        sscs.SSCSFLGS = SSCSCOUT;   /* purge the output             */
    }

    sscs.SSCSDIMP = SSCSELSZ;       /* size of SSCSARAY area        */

    iefssreq(&ssob);                /* send request to jes          */

    rc = ssob.SSOBRETN;

quit:
    return rc;
}
