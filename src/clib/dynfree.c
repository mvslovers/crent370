/* DYNFREE.C - Dynamic unallocation using SVC 99 */
#include <stdlib.h>
#include <string.h>
#include "dynit.h"
#include "svc99.h"
#include "clibary.h"

int
dynfree(__dyn_t *dyn_parms)
{
    int         rc;
    unsigned    count;
    TXT99       **txt99     = NULL;
    RB99        rb99;

    if (!dyn_parms) return -1;
    if (!dyn_parms->__ddname || strlen(dyn_parms->__ddname) == 0)
        return -1;

    memset(&rb99, 0, sizeof(rb99));

    /* DDNAME to unallocate */
    rc = arrayadd(&txt99,
        NewTXT99(DUNDDNAM, 1,
                 strlen(dyn_parms->__ddname),
                 dyn_parms->__ddname));
    if (rc) goto quit;

    /* unallocate option */
    rc = arrayadd(&txt99, NewTXT99(DUNUNALC, 0, 0, NULL));
    if (rc) goto quit;

    count = arraycount(&txt99);
    if (!count) {
        rc = -1;
        goto quit;
    }

    /* set high order bit to mark end of text unit pointer list */
    count--;
    txt99[count] = (TXT99 *)((unsigned)txt99[count] | 0x80000000);

    rb99.len     = sizeof(RB99);
    rb99.request = S99VRBUN;
    rb99.txtptr  = txt99;

    rc = __svc99(&rb99);

    dyn_parms->__errcode  = rb99.error;
    dyn_parms->__infocode = rb99.info;

quit:
    if (txt99) FreeTXT99Array(&txt99);
    return rc;
}
