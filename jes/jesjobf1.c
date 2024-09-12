/* JESJOBF1.C - Free 1 JESJOB */
#include <stdio.h>
#include <stdlib.h>
#include "hasphct.h"    /* JES Checkpoint Control Table, record 3 in HASPCKPT */
#include "haspjct.h"    /* JES Job Control Table                            */
#include "hasppddb.h"   /* JES PDDB Print Datasets                          */
#include "haspiot.h"    /* JES IOT                                          */
#include "clibjes2.h"   /* JES prototypes */
#include "clibary.h"    /* dynamic array */

int jesjobf1(JESJOB **ppjesjob)
{
    JESJOB      *jesjob = NULL;
    unsigned    count;
    unsigned    n;

    if (!ppjesjob) goto quit;

    jesjob = *ppjesjob;
    if (jesjob) {
        if (jesjob->jesdd) {
            count = arraycount(&jesjob->jesdd);
            for (n=0; n < count; n++) {
                if (!jesjob->jesdd[n]) continue;
                free(jesjob->jesdd[n]);
                jesjob->jesdd[n] = NULL;
            }
            arrayfree(&jesjob->jesdd);
        }
        free(jesjob);
        *ppjesjob = NULL;
    }

quit:
    return 0;
}
