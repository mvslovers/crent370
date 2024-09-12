/* @@ECBWA.C - ecb_waitarray()
*/
#include <clibecb.h>

#define ECB_MAX     256

__asm__("\n&FUNC    SETC 'ecb_waitarray'");
int
ecb_waitarray(ECB **ecbarray)
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

        /* wait for ECB post */
        rc = ecb_waitlist(ecblist);
    }

quit:
    return rc;
}
