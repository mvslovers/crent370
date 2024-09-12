#ifndef CLIBSRB_H
#define CLIBSRB_H

#include <ihasrb.h>
void *srb_getmain(unsigned size, int subpool) asm("SRBGMAIN");
static __inline void *inline_srb_getmain(unsigned size, int subpool)
{
    void    *storage;

    if (size < SRBSIZE) size    = SRBSIZE;
    if (!subpool)       subpool = SRB_SUBPOOL;

    __asm("MODESET MODE=SUP,KEY=ZERO" : :  : "0", "1", "14", "15");
    __asm("GETMAIN R,LV=(%0),SP=(%1)\n\t"
          "ST\t1,0(,%2)" : :
          "r"(size), "r"(subpool), "r"(&storage) : "0", "1", "14", "15");
          memset(storage, 0, size);
    __asm("MODESET MODE=PROB,KEY=NZERO" : :  : "0", "1", "14", "15");

    return storage;
}


void srb_freemain(void *storage, unsigned size, int subpool) asm("SRBFMAIN");
static __inline void inline_srb_freemain(void *storage, unsigned size, int subpool)
{
    if (size < SRBSIZE) size    = SRBSIZE;
    if (!subpool)       subpool = SRB_SUBPOOL;

    __asm("MODESET MODE=SUP,KEY=ZERO" : : : "0", "1", "14", "15");
    __asm("FREEMAIN R,A=(%0),LV=(%1),SP+(%2)\n\t" : :
          "r"(storage), "r"(size), "r"(subpool) : "0", "1", "14", "15");
    __asm("MODESET MODE=PROB,KEY=NZERO" : :  : "0", "1", "14", "15");
}


#endif /* CLIBSRB_H */
