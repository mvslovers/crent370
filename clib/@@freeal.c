/* @@FREEAL.C - free array created by __listal() */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <time.h>
#include "clibary.h"        /* dynamic array prototypes     */
#include "cliblist.h"

void
__freeal(ALCLIST ***alclist)
{
    if (alclist && *alclist) {
        unsigned    count = arraycount(alclist);
        unsigned    n;

        if (count) {
            ALCLIST  **list = *alclist;
            for(n=0; n < count; n++) {
                ALCLIST *l = list[n];
                
                if (!l) continue;
                if (l->dslist) __freeds(&l->dslist);
                free(l);
            }
        }
        arrayfree(alclist);
        *alclist = 0;
    }
}
