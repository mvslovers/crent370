#include <clibecb.h>

#define ECB_MAX     256

__asm__("\n&FUNC    SETC 'ecb_timed_waitarray'");
int
ecb_timed_waitarray(ECB **ecbarray, ECB *timeout_ecb, unsigned bintvl, unsigned postcode)
{
    int         rc      = 0;
    unsigned    count;
    unsigned    n;
    unsigned    i;
    ECB         *ecblist[ECB_MAX];

    if (!ecbarray) goto quit;

    count = array_count(&ecbarray);
    for(n=0, i=0; n < count; n++) {
        if (ecbarray[n]) {
            ecblist[i] = ecbarray[n];
            i++;
            if (i >= ECB_MAX) break;
        }
    }

    if (i) {
        ecblist[i-1] = (void*)((unsigned)ecblist[i-1] | 0x80000000);

        rc = ecb_timed_waitlist(ecblist, timeout_ecb, bintvl, postcode);
    }

quit:
    return rc;
}
