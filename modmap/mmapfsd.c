#include "modmap.h"

__asm__("\n&FUNC    SETC 'modmap_find_sd'");
MMSD *
modmap_find_sd(MODMAP *mm, unsigned esdid)
{
    MMSD        *mmsd   = NULL;
    unsigned    n;
    unsigned    count;

    if (!mm) goto quit;

    count = array_count(&mm->mmsd);
    for(n=0; n < count; n++) {
        if (!mm->mmsd[n]) continue;
        if (mm->mmsd[n]->esdid == esdid) {
            mmsd = mm->mmsd[n];
            goto quit;
        }
    }

quit:
    return mmsd;
}
