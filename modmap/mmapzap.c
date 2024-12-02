#include "modmap.h"

static int modmap_zap_sd(MODMAP *mm, MMSD *mmsd, unsigned base, unsigned size);
static int modmap_zap_rl(MODMAP *mm, MMRL *mmrl, unsigned base, unsigned size);
static int zap(unsigned address, unsigned value, unsigned size);

__asm__("\n&FUNC    SETC 'modmap_zap'");
int
modmap_zap(MODMAP *mm, unsigned base, unsigned size)
{
    int         rc      = 0;
    MMSD        *mmsd;
    unsigned    n;
    unsigned    count;

    if (!mm) goto quit;

    count = array_count(&mm->mmsd);

    for(n=0; n < count; n++) {
        mmsd = mm->mmsd[n];
        if (!mmsd) continue;
        if (mmsd->type == ESD_TYPE_WX && mmsd->address == 0) continue;  /* unresolved external */
        rc = modmap_zap_sd(mm, mmsd, base, size);
        if (rc) break;
    }

quit:
    return rc;
}

__asm__("\n&FUNC    SETC 'modmap_zap_sd'");
static int
modmap_zap_sd(MODMAP *mm, MMSD *mmsd, unsigned base, unsigned size)
{
    int         rc      = 0;
    MMLR        *mmlr   = NULL;
    MMRL        *mmrl   = NULL;
    unsigned    last    = base + size - 1;
    unsigned    address = base;
    unsigned    n;
    unsigned    n2;
    unsigned    count;
    unsigned    count2;

    if (mmsd->address < base) return 0;
    if (mmsd->address > last) return 0;

    count = array_count(&mmsd->mmlr);
    count2 = array_count(&mmsd->mmrl);
    for(n=0; n < count; n++) {
        mmlr = mmsd->mmlr[n];
        if (!mmlr) continue;

        /* print relocation info */
        for(n2=0; n2 < count2; n2++) {
            mmrl = mmsd->mmrl[n2];
            if (!mmrl) continue;
            /* wtof("%s address %08X", __func__, mmrl->address); */
            if (mmrl->address < address) continue;
            if (mmrl->address > mmlr->address) break;
            rc = modmap_zap_rl(mm, mmrl, base, size);
            if (rc) goto quit;
        }

        address = mmlr->address;
    }

    for(n2=0; n2 < count2; n2++) {
        mmrl = mmsd->mmrl[n2];
        if (!mmrl) continue;
        /* wtof("%s address %08X", __func__, mmrl->address); */
        if (mmrl->address < address) continue;

        address = mmrl->address;
        rc = modmap_zap_rl(mm, mmrl, base, size);
        if (rc) break;
    }

quit:
    return rc;
}

__asm__("\n&FUNC    SETC 'modmap_zap_rl'");
static int
modmap_zap_rl(MODMAP *mm, MMRL *mmrl, unsigned base, unsigned size)
{
    int         rc      = 0;
    MMSD        *mmsd   = modmap_find_sd(mm, mmrl->esdid);
    MMLR        *mmlr   = mmsd ? NULL: modmap_find_lr(mm, mmrl->esdid);
    char        *sdname = mmsd ? mmsd->name : "(null)";
    unsigned    last    = base + size - 1;
    unsigned    address = base;
#if 0
    wtof("%s mmsd %s", __func__, sdname);
    wtof("%s mmlr %s", __func__, mmlr ? mmlr->name : "(null)");
    wtof("%s address %08X, size %u", __func__, mmrl->address, mmrl->size);
#endif
    /* RLD address must be within the base and base + size area */
    if (mmrl->address < base) return 0;
    if (mmrl->address > last) return 0;

    /* RLD size needs to be between 1 and 4 bytes inclusive */
    if (mmrl->size == 0) return 0;      /* invalid size */
    if (mmrl->size > 4) return 0;       /* invalid size */

    if (mmlr) {
        /* label reference */
        rc = try(zap, mmrl->address, mmlr->address, mmrl->size);
    }
    else {
        /* relocation */
        rc = try(zap, mmrl->address, mmrl->value, mmrl->size);
    }

    if (rc > 0xFFF) {
        wtof("ZAP of %08X failed with ABEND(S%03X)", mmrl->address, (unsigned)rc >> 12);
    }
    else if (rc) {
        wtof("ZAP of %08X failed with ABEND(U%04u)", mmrl->address, rc);
    }

    return rc;
}

__asm__("\n&FUNC    SETC 'zap'");
static int zap(unsigned address, unsigned value, unsigned size)
{
#if 1
    wtof("ZAP(%08X) VALUE(%08X) SIZE(%u)", address, value, size);
#else
    char    *addr   = (char *)address;
    char    *val    = (char *)(((unsigned)&value + sizeof(unsigned)) - size);
    memcpy(addr, val, size);
#endif
    return 0;
}
