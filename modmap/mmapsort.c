#include "modmap.h"

static int cmpmmsd(const void *a, const void *b);
static int sortmmsd(MMSD **mmsd, unsigned count);
static int cmpmmlr(const void *a, const void *b);
static int sortmmlr(MMLR **mmlr, unsigned count);
static int cmpmmrl(const void *a, const void *b);
static int sortmmrl(MMRL **mmrl, unsigned count);

__asm__("\n&FUNC    SETC 'modmap_sort'");
int
modmap_sort(MODMAP *mm)
{
    unsigned    n;
    unsigned    count;
    unsigned    lr;
    unsigned    rl;

    if (!mm) goto quit;

    count = array_count(&mm->mmsd);
    if (count > 1) {
        sortmmsd(mm->mmsd, count);
    }

    for(n=0; n < count; n++) {
        if (!mm->mmsd[n]) continue;
        lr = array_count(&mm->mmsd[n]->mmlr);
        if (lr > 1) {
            sortmmlr(mm->mmsd[n]->mmlr, lr);
        }
        rl = array_count(&mm->mmsd[n]->mmrl);
        if (rl > 1) {
            sortmmrl(mm->mmsd[n]->mmrl, rl);
        }
    }

quit:
    return 0;
}

__asm__("\n&FUNC    SETC 'cmpmmsd'");
static int
cmpmmsd(const void *a, const void *b)
{
    MMSD    *asd    = *(MMSD**)a;
    MMSD    *bsd    = *(MMSD**)b;

    return ((int)asd->address - (int)bsd->address);
}

__asm__("\n&FUNC    SETC 'sortmmsd'");
static int
sortmmsd(MMSD **mmsd, unsigned count)
{
    qsort(mmsd, count, sizeof(MMSD*), cmpmmsd);
}

__asm__("\n&FUNC    SETC 'cmpmmlr'");
static int
cmpmmlr(const void *a, const void *b)
{
    MMLR    *alr    = *(MMLR**)a;
    MMLR    *blr    = *(MMLR**)b;

    return ((int)alr->address - (int)blr->address);
}

__asm__("\n&FUNC    SETC 'sortmmlr'");
static int
sortmmlr(MMLR **mmlr, unsigned count)
{
    qsort(mmlr, count, sizeof(MMLR*), cmpmmlr);
}

__asm__("\n&FUNC    SETC 'cmpmmrl'");
static int
cmpmmrl(const void *a, const void *b)
{
    MMRL    *arl    = *(MMRL**)a;
    MMRL    *brl    = *(MMRL**)b;

    return ((int)arl->address - (int)brl->address);
}

__asm__("\n&FUNC    SETC 'sortmmrl'");
static int
sortmmrl(MMRL **mmrl, unsigned count)
{
    qsort(mmrl, count, sizeof(MMRL*), cmpmmrl);
}
