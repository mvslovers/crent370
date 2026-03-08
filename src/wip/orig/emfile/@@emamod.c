#include "emfilei.h"

int emfile_allocate_mod(EMFILE *f, char *ddname)
{
    int         err     = 1;
    unsigned    count   = 0;
    TXT99       **txt99 = NULL;
    RB99        rb99    = {0};

	wtof("%s: enter dsn=\"%s\"", __func__, f->dsname);

    /* we want the DDNAME returned to us */
    err = __txrddn(&txt99, NULL);
    if (err) goto quit;

    /* allocate this dataset */
    err = __txdsn(&txt99, f->dsname);
    if (err) goto quit;

    /* DISP=MOD */
    err = __txmod(&txt99, NULL);
    if (err) goto quit;

    count = arraycount(&txt99);
    if (!count) goto quit;

    /* Set high order bit to mark end of list */
    count--;
    txt99[count]    = (TXT99*)((unsigned)txt99[count] | 0x80000000);

    /* construct the request block for dynamic allocation */
    rb99.len        = sizeof(RB99);
    rb99.request    = S99VRBAL;
    rb99.flag1      = S99NOCNV;
    rb99.txtptr     = txt99;

    /* SVC 99 */
    err = __svc99(&rb99);
    if (err) goto quit;

    /* return DDNAME */
    emfile_set_ddn(txt99[0]->text, ddname);

quit:
    if (txt99) FreeTXT99Array(&txt99);

	wtof("%s: exit rc=%d", __func__, err);
    return err;
}
