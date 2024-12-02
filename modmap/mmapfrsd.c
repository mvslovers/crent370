#include <modmap.h>

__asm__("\n&FUNC    SETC 'modmap_free_sd'");
void
modmap_free_sd(MMSD **mmsd)
{
    if (mmsd && *mmsd) {
        if ((*mmsd)->text) {
            free((*mmsd)->text);
            (*mmsd)->text = NULL;
        }

        if ((*mmsd)->mmlr) {
            unsigned n, count = array_count(&(*mmsd)->mmlr);

            for(n=0; n < count; n++) {
                if (!(*mmsd)->mmlr[n]) continue;
                modmap_free_lr(&(*mmsd)->mmlr[n]);
            }

            array_free(&(*mmsd)->mmlr);
        }

        if ((*mmsd)->mmrl) {
            unsigned n, count = array_count(&(*mmsd)->mmrl);

            for(n=0; n < count; n++) {
                if (!(*mmsd)->mmrl[n]) continue;
                modmap_free_rl(&(*mmsd)->mmrl[n]);
            }

            array_free(&(*mmsd)->mmrl);
        }

        free(*mmsd);
        *mmsd = NULL;
    }
}
