/* @@FREEPD.C - free array created by __listpd() */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <time.h>
#include "clibary.h"        /* dynamic array prototypes     */
#include "cliblist.h"       /* __listpd()                   */

void
__freepd(PDSLIST ***pdslist)
{
    if (pdslist && *pdslist) {
        unsigned    count = __arcou(pdslist);
        unsigned    n;

        if (count) {
            PDSLIST **list = *pdslist;
            for(n=0; n < count; n++) {
                if (!list[n]) continue;
                free(list[n]);
                list[n] = 0;
            }
        }
        __arfre(pdslist);
        *pdslist = 0;
    }
}
