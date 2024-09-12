#define CLIB_C
#include <stdlib.h>
#include <string.h>
#include "clib.h"
#include "clibppa.h"
#include "clibary.h"
#include "cliblock.h"

int
__grtset(void)
{
    int         rc      = -1;
    CLIBCRT     *crt    = __crtget();

    if (crt) {
        CLIBPPA *ppa = __PPAGET();
        if (ppa) {
            CLIBGRT *grt = calloc(1, sizeof(CLIBGRT));
            if (grt) {
                memcpy(grt->grteye, "CLIBGRT ", 8);
                grt->grtclibl = sizeof(CLIBGRT);
                crt->crtgrt = grt;
                ppa->ppagrt = grt;
                rc = 0;
            }
        }
    }

quit:
    return rc;
}
