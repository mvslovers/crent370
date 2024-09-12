#include <iefssobh.h>
#include <stdlib.h>
#include <string.h>

int initssob(SSOB *ssob, void *ssobindv)
{
    int         rc      = 0;

    memset(ssob, 0, SSOBHSIZ);
    memcpy(ssob->SSOBID, SSOBID_EYE, sizeof(ssob->SSOBID));
    ssob->SSOBLEN   = SSOBHSIZ;
    ssob->SSOBINDV  = ssobindv;

    return 0;
}
