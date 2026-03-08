#include "emfilei.h"

int emfile_allocate_new(EMFILE *f)
{
	EMFILEWSA	*wsa	= emfile_get_wsa();
    int         err     = 1;
    unsigned    count   = 0;
    TXT99       **txt99 = NULL;
    RB99        rb99    = {0};
    char		blkstr[16];
    char 		prisec[40];

	wtof("%s: enter dsn=\"%s\"", __func__, f->dsname);

	snprintf(blkstr, sizeof(blkstr), "%u", wsa->blksize);
	blkstr[sizeof(blkstr)-1] = 0;

	snprintf(prisec, sizeof(prisec)-1, "%u,%u", wsa->primary, wsa->secondary);
	prisec[sizeof(prisec)-1] = 0;

    /* we want the DDNAME returned to us */
    err = __txrddn(&txt99, NULL);
    if (err) goto quit;

    /* allocate this dataset */
    err = __txdsn(&txt99, f->dsname);
    if (err) goto quit;

    /* DISP=NEW */
    err = __txnew(&txt99, NULL);
    if (err) goto quit;

	/* DISP=(,CATLG) */
	err = __txcat(&txt99, NULL);
    if (err) goto quit;

	/* BLKSIZE=4096 */
	err = __txbksz(&txt99, blkstr);
    if (err) goto quit;

	/* LRECL=4096 */
	err = __txlrec(&txt99, blkstr);
    if (err) goto quit;

	/* SPACE=...(pri,sec) */
	err = __txspac(&txt99, prisec);
    if (err) goto quit;

	if (wsa->space == EMFILE_SPACE_TRACK) {
		/* SPACE=TRACKS */
		err = __txtrk(&txt99, NULL);
	}
	else {
		/* SPACE=CYL */
		err = __txcyl(&txt99, NULL);
	}
	if (err) goto quit;

	/* RECFM=FB */
    err = __txrecf(&txt99, "FB");
    if (err) goto quit;

	/* DSORG=PS */
	err = __txorg(&txt99, "PS");
    if (err) goto quit;
    
    if (wsa->vols) {
		/* VOLSER=... */
		err = __txvols(&txt99, wsa->vols);
		if (err) goto quit;
	}

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
    emfile_set_ddn(txt99[0]->text, f->ddname);
    f->flags |= EMFILE_FLAG_DYNAMIC;
    f->flags |= EMFILE_FLAG_NEW;

quit:
    if (txt99) FreeTXT99Array(&txt99);

	wtof("%s: exit rc=%d", __func__, err);
    return err;
}
