#include "modmap.h"

static int modmap_base_lr(MODMAP *mm, MMLR *mmlr, unsigned base);   /* Label    */
static int modmap_base_rl(MODMAP *mm, MMRL *mmrl, unsigned base);   /* RLD      */
static int modmap_base_sd(MODMAP *mm, MMSD *mmsd, unsigned base);   /* Section  */

__asm__("\n&FUNC    SETC 'modmap_base'");
int
modmap_base(MODMAP *mm, unsigned base)
{
    MMSD        *mmsd;
    unsigned    n;
    unsigned    count;

    if (!mm) goto quit;

    count = array_count(&mm->mmsd);

    for(n=0; n < count; n++) {
        mmsd = mm->mmsd[n];
        if (!mmsd) continue;
        if (mmsd->type == ESD_TYPE_WX && mmsd->address == 0) continue;  /* unresolved external */
        modmap_base_sd(mm, mmsd, base);
    }

quit:
    return 0;
}

__asm__("\n&FUNC    SETC 'modmap_base_sd'");
static int
modmap_base_sd(MODMAP *mm, MMSD *mmsd, unsigned base)
{
    MMLR        *mmlr   = NULL;
    MMRL        *mmrl   = NULL;
    unsigned    n;
    unsigned    count;

    mmsd->address += base;              /* adjust address of this section */

    count = array_count(&mmsd->mmlr);   /* label reference          */
    for(n=0; n < count; n++) {
        mmlr = mmsd->mmlr[n];           /* label reference          */
        if (!mmlr) continue;

        modmap_base_lr(mm, mmlr, base);
    }

    count = array_count(&mmsd->mmrl);   /* relocation dictionary    */
    for(n=0; n < count; n++) {
        mmrl = mmsd->mmrl[n];           /* relocation dictionary    */
        if (!mmrl) continue;

        modmap_base_rl(mm, mmrl, base);
    }

    return 0;
}

__asm__("\n&FUNC    SETC 'modmap_base_lr'");
static int
modmap_base_lr(MODMAP *mm, MMLR *mmlr, unsigned base)
{
#if 0
    if (mmlr->address) {
        if (mmlr->type != ESD_TYPE_ER && mmlr->type != ESD_TYPE_WX) {
            mmlr->address += base;
        }
    }
#else
    if (mmlr->type != ESD_TYPE_ER && mmlr->type != ESD_TYPE_WX) {
        mmlr->address += base;
    }
#endif
    return 0;
}

__asm__("\n&FUNC    SETC 'modmap_base_rl'");
static int
modmap_base_rl(MODMAP *mm, MMRL *mmrl, unsigned base)
{
    MMLR    *mmlr = modmap_find_lr(mm, mmrl->esdid);

    if (mmlr) {
        if (mmlr->address == 0) {
            /* label address is zero */
            if (mmlr->type == ESD_TYPE_ER) {
                /* external reference, don't adjust RLD address */
                return 0;
            } else if (mmlr->type == ESD_TYPE_WX) {
                /* weak external reference, don't adjust RLD address */
                return 0;
            }
        }
    }

    /* adjust RLD address */
    mmrl->address += base;
    mmrl->value   += base;

    return 0;
}
