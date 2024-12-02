#include "modmap.h"

__asm__("\n&FUNC    SETC 'modmap_free_rl'");
void
modmap_free_rl(MMRL **mmrl)
{
    if (mmrl && *mmrl) {
        free(*mmrl);
        *mmrl = NULL;
    }
}
