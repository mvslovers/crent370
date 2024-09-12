#include <iefssso.h>
#include <clibstr.h>
#include <clibjes2.h>

int jesxwrtr(SSSO *ssso, const char *class_list, const char *dest, const char *form)
{
    int         rc      = -1;
    SSOB        ssob;

    if (!ssso) goto quit;

    initssob(&ssob, ssso);          /* initialize the SSOB header   */
    ssob.SSOBFUNC   = SSOBSOUT;     /* request SYSOUT function      */

    memset(ssso, 0, sizeof(SSSO));  /* clear the SYSOUT parm list   */
    ssso->SSSOLEN   = SSSOSIZE;     /* length of SYSOUT parm list   */

    if (class_list) {
        strcpyp(ssso->SSSOCLSL, sizeof(ssso->SSSOCLSL), (char*)class_list, ' ');
        if (ssso->SSSOCLSL[0] > ' ') {
            ssso->SSSOFLG1  |= SSSOSCLS;    /* use SYSOUT class     */
        }
    }

    if (dest) {
        strcpyp(ssso->SSSODEST, sizeof(ssso->SSSODEST), (char*)dest, ' ');
        if (ssso->SSSODEST[0] > ' ') {
            ssso->SSSOFLG1  |= SSSODST;     /* use SYSOUT dest      */
        }
    }

    if (form) {
        strcpyp(ssso->SSSOFORM, sizeof(ssso->SSSOFORM), (char*)form, ' ');
        if (ssso->SSSOFORM[0] > ' ') {
            ssso->SSSOFLG1  |= SSSOSFRM;     /* use SYSOUT form     */
        }
    }

    if (!ssso->SSSOFLG1) goto quit;     /* no selection criteria    */

    iefssreq(&ssob);                        /* send request to jes  */
#if 0
    wtodumpf(&ssob, sizeof(ssob), "jesxwrtr SSOB after IEFSSREQ");
    wtodumpf(ssso, sizeof(SSSO), "jesxwrtr SSSO after IEFSSREQ");
#endif
#if 0
    if (ssso->SSSOWTRC) {
        __asm__("MODESET KEY=ZERO,MODE=SUP");
        wtodumpf(ssso->SSSOWTRC, sizeof(WTRC), "WTRC");
        __asm__("MODESET KEY=NZERO,MODE=PROB");
    }
#endif

    rc = ssob.SSOBRETN;

quit:
    return rc;
}
