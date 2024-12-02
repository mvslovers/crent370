#include "modmap.h"

static int dumpmmlr(MODMAP *mm, MMSD *mmsd, MMLR *mmlr);
static int dumpmmsd(MODMAP *mm, MMSD *mmsd);

__asm__("\n&FUNC    SETC 'modmap_dump'");
int
modmap_dump(MODMAP *mm)
{
    MMSD        *mmsd;
    unsigned    n;
    unsigned    count;

    if (!mm) goto quit;

    count = array_count(&mm->mmsd);
    wtof("Dump of module map for dataset \"%s\"", mm->fn);

    for(n=0; n < count; n++) {
        mmsd = mm->mmsd[n];
        if (!mmsd) continue;
        if (mmsd->type == ESD_TYPE_WX && mmsd->address == 0) continue;  /* unresolved external */
        wtof("Csect    Label    Address  Info        ID ...");
        dumpmmsd(mm, mmsd);
    }

quit:
    return 0;
}

__asm__("\n&FUNC    SETC 'dumpmmlr'");
static int
dumpmmlr(MODMAP *mm, MMSD *mmsd, MMLR *mmlr)
{
    if (mmlr->type == ESD_TYPE_ER || mmlr->type == ESD_TYPE_WX) return;
    wtof("         %-8.8s %08X             %u %02X", mmlr->name, mmlr->address, mmlr->esdid, mmlr->type);

quit:
    return 0;
}

__asm__("\n&FUNC    SETC 'dumpmmrl'");
static int
dumpmmrl(MODMAP *mm, MMRL *mmrl)
{
    MMSD    *mmsd = modmap_find_sd(mm, mmrl->esdid);
    MMLR    *mmlr = mmsd ? NULL: modmap_find_lr(mm, mmrl->esdid);
    const char *fmt = "???";
    char    msg[80] = "";

    /* get the RLD target address size */
    if (mmrl->size == 2) {
        fmt = "==> %04X";
    }
    else if (mmrl->size == 3) {
        fmt = "==> %06X";
    }
    else if (mmrl->size == 4) {
        fmt = "==> %08X";
    }

    if (mmlr) {
        sprintf(msg, fmt, mmlr->address);
        if (mmlr->address == 0) {
            if (mmlr->type == ESD_TYPE_ER) {
                strcat(msg, " $UNRESOLVED");
            } else if (mmlr->type == ESD_TYPE_WX) {
                strcat(msg, " $UNRESOLVED(W)");
            }
        }
        if (mmlr->type == ESD_TYPE_SD) {
            fmt = "                  %08X A(%s) %u %02X %s";
        }
        else {
            fmt = "                  %08X V(%s) %u %02X %s";
        }
        wtof(fmt, mmrl->address, mmlr->name, mmrl->esdid, mmlr->type, msg);
    }
    else if (mmsd) {
#if 0
        strcpy(msg, "MMSD");
        wtof("                  %08X V(%s) %u %02X %s",
            mmrl->address, mmsd->name, mmrl->esdid, mmsd->type, msg);
#else
        strcpy(msg, "MMRL");
        wtof("                  %08X A(%06X) %u %02X %s",
            mmrl->address, mmrl->value, mmrl->esdid, mmrl->type, msg);
#endif
    }
    else {
        strcpy(msg, "MMRL");
        wtof("                  %08X             %u %s", mmrl->address, mmrl->esdid, msg);
    }

    return 0;
}

__asm__("\n&FUNC    SETC 'dumpmmsd'");
static int
dumpmmsd(MODMAP *mm, MMSD *mmsd)
{
    MMLR        *mmlr   = NULL;
    MMRL        *mmrl   = NULL;
    unsigned    address = 0;
    unsigned    n;
    unsigned    n2;
    unsigned    count;
    unsigned    count2;

    wtof("%-8.8s          %08X %06X      %u (%u bytes) %02X",
        mmsd->name, mmsd->address, mmsd->size, mmsd->esdid, mmsd->size, mmsd->type);

    count = array_count(&mmsd->mmlr);
    count2 = array_count(&mmsd->mmrl);
    for(n=0; n < count; n++) {
        mmlr = mmsd->mmlr[n];
        if (!mmlr) continue;

        /* print relocation info */
        for(n2=0; n2 < count2; n2++) {
            mmrl = mmsd->mmrl[n2];
            if (!mmrl) continue;
            if (mmrl->address < address) continue;
            if (mmrl->address > mmlr->address) break;
            dumpmmrl(mm, mmrl);
        }

        address = mmlr->address;
        dumpmmlr(mm, mmsd, mmlr);
    }

    for(n2=0; n2 < count2; n2++) {
        mmrl = mmsd->mmrl[n2];
        if (!mmrl) continue;
        if (mmrl->address < address) continue;

        address = mmrl->address;
        dumpmmrl(mm, mmrl);
    }
    wtof(" ");

quit:
    return 0;
}
