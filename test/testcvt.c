#include <iharb.h>
#include <cvt.h>
#include <ihascvt.h>
#include <clibwto.h>

int main(int argc, char **argv)
{
    CVT         *cvt        = CVTPTR;
    SCVT        *scvt       = cvt->cvtabend;
    SVCTABLE    *svctable   = scvt->scvtsvct;
    SVCENTRY    *svcentry   = svctable->svcentry;

    wtodumpf(cvt, sizeof(CVT), "CVT");
    wtodumpf(scvt, sizeof(SCVT), "SCVT");
    wtodumpf(svctable, sizeof(SVCTABLE), "SVCTABLE");

    return 0;
}

__asm__("IKJRB DSECT=YES");
