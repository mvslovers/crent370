#include <clibos.h>
#include <ihaasvt.h>

/* __ascb() get ASCB for ASID, or current ASCB if 0 */
void *__ascb(unsigned asid)
{
    unsigned    *psa    = (unsigned *)0;
    unsigned    *cvt    = (unsigned *)psa[0x10/4];
    ASVT        *asvt   = (ASVT *)cvt[0x22C/4];
    void        *ascb   = 0;

    if (!asid) {
        /* get current ASCB for this address space */
        ascb = (void *)psa[0x224/4];    /* A(ASCB)      */
        goto quit;
    }

    if (asid < asvt->asvtmaxu) {
        ascb = (void*)((unsigned)asvt->asvtenty[asid-1] & 0x7FFFFFFF);
        if (ascb && memcmp(ascb, "ASCB", 4)!=0) ascb = 0;
    }

quit:
    return ascb;
}

#if 0
__asm__("IHAPSA ,");
__asm__("CVT DSECT=YES,LIST=YES");
__asm__("IHAASVT ,");
#endif

#if 0
#include <clibwto.h>
int main(int argc, char **argv)
{
    unsigned    n;
    void        *ascb   = 0;
#if 1
    unsigned    *psa    = (unsigned *)0;
    unsigned    *cvt    = (unsigned *)psa[0x10/4];
    ASVT        *asvt   = (ASVT *)cvt[0x22C/4];

    wtodumpf(asvt, sizeof(ASVT), "ASVT");
    wtodumpf(asvt->asvtenty, asvt->asvtmaxu * 4, "ASVTENTY");
#endif

#if 1
    for(n=1; n < asvt->asvtmaxu; n++) {
        ascb = __ascb(n);
        if (ascb) {
            wtof("ASID(%u) ASCB(%08X)", n, ascb);
            wtodumpf(ascb, 256, "ASCB");
        }
    }
#endif
    return 0;
}
#endif
