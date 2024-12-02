#include <clibsrb.h>

__asm__("\n&FUNC    SETC 'srb_freemain'");
void srb_freemain(void *storage, unsigned size, int subpool)
{
#if 1
    if (size < SRBSIZE) size    = SRBSIZE;

    __asm("MODESET MODE=SUP,KEY=ZERO" : : : "0", "1", "14", "15");
    __asm("FREEMAIN R,A=(%0),LV=(%1),SP=(%2)\n\t" : :
          "r"(storage), "r"(size), "r" (subpool) : "0", "1", "14", "15");
    __asm("MODESET MODE=PROB,KEY=NZERO" : :  : "0", "1", "14", "15");
#else
    inline_srb_freemain(storage,size,subpool);
#endif
}
