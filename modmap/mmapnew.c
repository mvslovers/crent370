#include "modmap.h"

__asm__("\n&FUNC    SETC 'modmap_new'");
MODMAP *
modmap_new(void)
{
    MODMAP          *mm = (MODMAP*) calloc(1, sizeof(MODMAP));

    if (mm) {
        mmaprset(mm);
    }

    return mm;
}
