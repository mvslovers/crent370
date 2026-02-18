#include <clibssct.h>
#include <clibos.h>
#include <iefjesct.h>

__asm__("\n&FUNC    SETC 'ssct_find'");
SSCT *ssct_find(const char *name)
{
    unsigned    *psa        = (unsigned*) 0;
    unsigned    *cvt        = (unsigned*) psa[16/4];    /* get CVT pointer from PSA */
    JESCT       *jesct      = (JESCT*) cvt[0x128/4];    /* get JESCT (CVTJESCT)     */
    SSCT        *ssct       = (SSCT*) jesct->jesssct;   /* get first subsystem      */
    char        name4[4];

    if (!name) goto quit;           /* return first subsystem   */
    if (*name==0) goto quit;        /* return first subsystem   */
    if (*name==' ') goto quit;      /* return first subsystem   */

    strcpyp(name4, sizeof(name4), (void*)name, ' ');
    while(ssct) {
        if (memcmp(ssct->ssctsnam, name4, sizeof(ssct->ssctsnam))==0) break;
        ssct = ssct->ssctscta;
    }

quit:
    return ssct;
}

#if 0
int main(int argc, char **argv)
{
    SSCT    *ssct   = ssct_find(0);

    while(ssct) {
        wtodumpf(ssct, sizeof(SSCT), "SSCT");
        ssct = ssct->ssctscta;
    }

    ssct = ssct_find("MSTR");
    wtodumpf(ssct, sizeof(SSCT), "MSTR");

    ssct = ssct_find("JES2");
    wtodumpf(ssct, sizeof(SSCT), "JES2");

    return 0;
}
#endif
