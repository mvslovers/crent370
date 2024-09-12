#include "clibcib.h"
#include "clibcrt.h"

COM *
__gtcom(void)
{
    CLIBGRT     *grt    = __grtget();
    COM         *com    = grt->grtcom;
    unsigned    work[3] = {0};

    if (!com) {
        __asm__("EXTRACT (%0),FIELDS=COMM,MF=(E,(%1))" : :
            "r" (&grt->grtcom), "r"(work) : "1", "14", "15");
        return grt->grtcom;
    }

    return com;
}
