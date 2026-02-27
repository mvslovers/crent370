/* TRKCALC.C - calculate number of records that fit on a track
*/
#include "osio.h"
#include "trkcalc.h"

int
trkcalc(DEVTYPE devtype, int keylen, int blksize)
{
    int         rc      = 0;
    int         count   = 0;
    unsigned    work[3] = {0,0,0};

    devtype = devtype & 0x0F;

    __asm__("\n"
"         TRKCALC FUNCTN=TRKCAP,REGSAVE=YES,                            X\n"
"               TYPE=(%0),R=1,K=(%1),DD=(%2),MF=(E,(%3))\n"
"         ST    15,0(%4)\n"
"         ST    0,0(%5)" : : "r"(devtype), "r"(keylen), "r"(blksize),
        "r"(work), "r"(&rc), "r"(&count) );

    if (rc) {
        count = 0;
    }

quit:
    return count;
}
#if 0
__asm__("TRKCALC MF=D");
__asm__("CSECT");
#endif
