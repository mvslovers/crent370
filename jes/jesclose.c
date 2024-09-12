/* JESCLOSE.C - Close JES spool datasets */
#include <stdio.h>
#include <stdlib.h>
#include "hasphct.h"    /* JES Checkpoint Control Table, record 3 in HASPCKPT */
#include "haspjct.h"    /* JES Job Control Table                            */
#include "hasppddb.h"   /* JES PDDB Print Datasets                          */
#include "haspiot.h"    /* JES IOT                                          */
#include "clibjes2.h"   /* JES prototypes */
#include "clibary.h"    /* dynamic array                                    */

int jesclose(JES **ppjes)
{
    JES         *jes    = NULL;
    unsigned    count;
    unsigned    n;

    if (!ppjes) goto quit;

    jes = *ppjes;
    if (jes) {
        if (jes->js) {
            count = arraycount(&jes->js);
            for (n=0; n < count; n++) {
                if (!jes->js[n]) continue;
                spool_close(jes->js[n]);
                jes->js[n] = NULL;
            }
            arrayfree(&jes->js);
        }
        if (jes->cp) {
            checkpoint_close(jes->cp);
            jes->cp = NULL;
        }
        free(jes);
        *ppjes = NULL;
    }

quit:
    return 0;
}



