/* @@FREEDS.C - free array created by __listds() */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <time.h>
#include "clibary.h"        /* dynamic array prototypes     */
#include "cliblist.h"       /* __listc()                    */

void
__freeds(DSLIST ***dslist)
{
    if (dslist && *dslist) {
        unsigned    count = arraycount(dslist);
        unsigned    n;

        if (count) {
            DSLIST  **list = *dslist;
            for(n=0; n < count; n++) {
                if (!list[n]) continue;
                free(list[n]);
                list[n] = 0;
            }
        }
        arrayfree(dslist);
        *dslist = 0;
    }
}
