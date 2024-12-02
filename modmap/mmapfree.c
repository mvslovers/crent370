#include "modmap.h"

__asm__("\n&FUNC    SETC 'modmap_free'");
void
modmap_free(MODMAP **mm)
{
    if (mm && *mm) {
        mmaprset(*mm);
        free(*mm);
        *mm = NULL;
    }
}
