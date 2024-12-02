#include "modmap.h"

__asm__("\n&FUNC    SETC 'modmap_reset'");
MODMAP *
modmap_reset(MODMAP *mm)
{
    if (mm) {
        if (strcmp(mm->eye,MODMAP_EYE)==0) {
            if (mm->fp) {
                fclose(mm->fp);
                mm->fp = NULL;
            }
            if (mm->mmsd) {
                /* free the section array */
                unsigned n, count=array_count(&mm->mmsd);

                for(n=0; n < count; n++) {
                    if (!mm->mmsd[n]) continue;
                    modmap_free_sd(&mm->mmsd[n]);
                }

                array_free(&mm->mmsd);
            }
            modmap_reset_ld(mm);
        }
        memset(mm, 0, sizeof(MODMAP));
        strcpy(mm->eye, MODMAP_EYE);
    }

    return mm;
}
