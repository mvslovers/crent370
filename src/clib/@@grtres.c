#define CLIB_C
#include <stdlib.h>
#include <string.h>
#include "clib.h"
#include "clibppa.h"

int
__grtres(void)
{
    int         rc      = -1;
    CLIBCRT     *crt    = __crtget();
    CLIBPPA     *ppa    = __PPAGET();

    if (crt) {
        CLIBGRT *grt = crt->crtgrt;
        if (grt) {
            if (memcmp(grt->grteye, "CLIBGRT ", 8)==0) {
                memset(grt->grteye, 0, sizeof(grt->grteye));
                free(grt);
                rc = 0;
            }
            if (rc==0 && ppa) {
                if (ppa->ppagrt == grt) ppa->ppagrt = 0;
            }
        }
    }

quit:
    return rc;
}
