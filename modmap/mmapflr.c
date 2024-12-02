#include "modmap.h"

__asm__("\n&FUNC    SETC 'modmap_find_lr'");
MMLR *
modmap_find_lr(MODMAP *mm, unsigned esdid)
{
    MMLR        *mmlr   = NULL;
    MMSD        *mmsd   = NULL;
    unsigned    n;
    unsigned    n2;
    unsigned    count;
    unsigned    count2;

    if (!mm) goto quit;

    count = array_count(&mm->mmsd);
    for(n=0; n < count; n++) {
        mmsd = mm->mmsd[n];
        if (!mmsd) continue;

        count2 = array_count(&mmsd->mmlr);
        for(n2=0; n2 < count2; n2++) {
            if (mmsd->mmlr[n2]->esdid == esdid) {
                mmlr = mmsd->mmlr[n2];
                goto quit;
            }
        }
    }

quit:
    return mmlr;
}
