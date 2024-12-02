#include "modmap.h"

__asm__("\n&FUNC    SETC 'modmap_free_ld'");
void
modmap_free_ld(MMLD **mmld)
{
    if (mmld && *mmld) {
        free(*mmld);
        *mmld = NULL;
    }
}
