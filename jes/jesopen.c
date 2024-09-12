/* JESOPEN.C - Open JES spool datasets */
#include <stdio.h>
#include <stdlib.h>
#include "hasphct.h"    /* JES Checkpoint Control Table, record 3 in HASPCKPT */
#include "haspjct.h"    /* JES Job Control Table                            */
#include "hasppddb.h"   /* JES PDDB Print Datasets                          */
#include "haspiot.h"    /* JES IOT                                          */
#include "clibjes2.h"   /* JES prototypes */
#include "clibstae.h"   /* ESTAE functions */
#include "clibary.h"    /* dynamic array */

static void try_jesopen(JES **jespp);

JES *jesopen(void)
{
    JES         *jes    = NULL;

    try(try_jesopen, &jes);

    return jes;
}

__asm__("\n&FUNC    SETC 'try_jesopen'");
static void try_jesopen(JES **jespp)
{
    JES         *jes    = NULL;
    HASPCP      *cp     = NULL;
    HASPJS      *js     = NULL;

    jes = calloc(1, sizeof(JES));
    if (!jes) {
        wtof("Unable to allocate storage for JES handle");
        goto quit;
    }

    cp = checkpoint_open("DD:HASPCKPT");
    if (!cp) {
        wtof("Unable to open checkpoint dataset DD:HASPCKPT");
        jesclose(&jes);
        goto quit;
    }

    /* Put checkpoint handle into our JES handle */
    jes->cp = cp;

    js = spool_open("DD:HASPACE1");
    if (!js) {
        wtof("Unable to open spool dataset DD:HASPACE1");
        jesclose(&jes);
        goto quit;
    }

    /* Add spool handle to array of spool handle in our JES handle */
    arrayadd(&jes->js, js);

quit:
    *jespp = jes;
    return;
}


