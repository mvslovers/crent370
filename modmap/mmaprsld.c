#include "modmap.h"

__asm__("\n&FUNC    SETC 'modmap_reset_ld'");
MODMAP *
modmap_reset_ld(MODMAP *mm)
{
    if (mm) {
        if (strcmp(mm->eye,MODMAP_EYE)==0) {
            if (mm->mmld) {
                /* free the text load array */
                unsigned n, count=array_count(&mm->mmld);

                for(n=0; n < count; n++) {
                    if (!mm->mmld[n]) continue;
                    modmap_free_ld(&mm->mmld[n]);
                }

                array_free(&mm->mmld);
            }
        }
    }

    return mm;
}
