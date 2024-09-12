/* @@FPFREE.C */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <mvssupa.h>
#include "svc99.h"
#include "clibary.h"

int
__fpfree(FILE *fp)
{
    int         err     = 1;
    unsigned    count   = 0;
    TXT99       **txt99 = NULL;
    RB99        rb99    = {0};

	// wtof("%s: fp=%p fp->ddname=\"%s\"", __func__, fp, fp->ddname);

    /* this DDNAME */
    err = __txddn(&txt99, fp->ddname);
    // wtodumpf(txt99[0], sizeof(TXT99)+8, "%s: txt99 ddname", __func__);
    if (err) goto quit;

    /* unallocate */
    err = __txunal(&txt99, NULL);
    // wtodumpf(txt99[1], sizeof(TXT99), "%s: txt99 unallocate", __func__);
    if (err) goto quit;

    count = arraycount(&txt99);
    if (!count) goto quit;

    /* Set high order bit to mark end of list */
    count--;
    txt99[count]    = (TXT99*)((unsigned)txt99[count] | 0x80000000);

    /* construct the request block for dynamic allocation */
    rb99.len        = sizeof(RB99);
    rb99.request    = S99VRBUN;
    rb99.flag1      = 0; // S99NOCNV;
    rb99.txtptr     = txt99;

    /* SVC 99 */
    err = __svc99(&rb99);
    // wtof("%s: __svc99() err=%d %p", __func__, err, err);
    // wtodumpf(&rb99, sizeof(rb99), "%s: RB99", __func__);

quit:
    if (txt99) FreeTXT99Array(&txt99);

    return err;
}
