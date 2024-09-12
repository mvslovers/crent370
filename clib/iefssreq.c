#include <iefssobh.h>

int iefssreq(SSOB *ssob)
{
    int         rc      = 0;
    unsigned    *psa    = (unsigned *)0;
    unsigned    *cvt    = (unsigned *)psa[16/4];
    unsigned    *jesct  = (unsigned *)cvt[296/4];
    int         (*ssreq)(SSOB *) = (void*)jesct[20/4];

    /* we need to set the high order bit in the SSOB pointer */
    ssob = (SSOB*) ((unsigned)ssob + 0x80000000);

    __asm("MODESET MODE=SUP" : : : "15","0","1");

    rc = ssreq(ssob);

    __asm("MODESET MODE=PROB" : : : "15","0","1");

    return rc;
}
