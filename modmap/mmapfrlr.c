#include "modmap.h"

__asm__("\n&FUNC    SETC 'modmap_free_lr'");
void
modmap_free_lr(MMLR **mmlr)
{
    if (mmlr && *mmlr) {
        free(*mmlr);
        *mmlr = NULL;
    }
}
