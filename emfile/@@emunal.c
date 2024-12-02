#include "emfilei.h"

int emfile_unallocate(const char *ddname)
{
    int         err     = 1;
    unsigned    count   = 0;
    TXT99       **txt99 = NULL;
    RB99        rb99    = {0};

	wtof("%s: enter ddname=\"%s\"", __func__, ddname);

    /* we want to unallocate the DDNAME */
    err = __txddn(&txt99, ddname);
    if (err) goto quit;

    count = arraycount(&txt99);
    if (!count) goto quit;

    /* Set high order bit to mark end of list */
    count--;
    txt99[count]    = (TXT99*)((unsigned)txt99[count] | 0x80000000);

    /* construct the request block for dynamic allocation */
    rb99.len        = sizeof(RB99);
    rb99.request    = S99VRBUN;
    rb99.flag1      = S99NOCNV;
    rb99.txtptr     = txt99;

    /* SVC 99 */
    err = __svc99(&rb99);
    if (err) {
		wtof("%s: err=%d error=0x%04X info=0x%04X", __func__, err, rb99.error, rb99.info);
		goto quit;
	}

quit:
    if (txt99) FreeTXT99Array(&txt99);

	wtof("%s: exit rc=%d", __func__, err);
    return err;
}
