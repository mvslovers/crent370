#include <clibsrb.h>

__asm__("\n&FUNC    SETC 'srb_getmain'");
void *srb_getmain(unsigned size, int subpool)
{
#if 1
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
#else
    return inline_srb_getmain(size,subpool);
#endif
}
