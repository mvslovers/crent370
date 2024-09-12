/* @@FPSTAR.C */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <mvssupa.h>
#include "svc99.h"
#include "clibary.h"
#include "clib.h"

int
__fpstar(FILE *fp)
{
	CLIBPPA		*ppa    = __ppaget();
    int         err     = 1;
    unsigned    count   = 0;
    char        *recfm  = 0;
    char        *lrecl  = 0;
    char        *blksize= 0;
    char        *p      = 0;
    TXT99       **txt99 = NULL;
    RB99        rb99    = {0};
    char        temp[sizeof(fp->mode)+1];

    /* we want the DDNAME returned to us */
    err = __txrddn(&txt99, NULL);
    if (err) goto quit;

	/* if we're running under TSO foreground */
	if (ppa->ppaflag & PPAFLAG_TSOFG) {
		/* allocate terminal */
		err = __txterm(&txt99, NULL);
		if (err) goto quit;

		/* permanent */
		err = __txperm(&txt99, NULL);
		if (err) goto quit;

		/* DISP=SHR */
		err = __txshr(&txt99, NULL);
		if (err) goto quit;

		/* DSORG=PS */
		err = __txorg(&txt99, "PS");
		if (err) goto quit;

		/* RECFM=V */
		recfm = getenv("TERMINAL_RECFM");
		if (!recfm) recfm = "V";
		err = __txrecf(&txt99, recfm);
		if (err) goto quit;

		/* LRECL=4000 */
		lrecl = getenv("TERMINAL_LRECL");
		if (!lrecl) lrecl = "4000";
		err = __txlrec(&txt99, lrecl);
		if (err) goto quit;

		if (strchr(recfm, 'B')) {
			/* BLKSIZE=? */
			blksize = getenv("TERMINAL_BLKSIZE");
			if (blksize) {
				err = __txbksz(&txt99, blksize);
				if (err) goto quit;
			}
		}
	}
	else {
		/* allocate SYSOUT dataset */
		p = getenv("SYSOUT_CLASS");
		err = __txsyso(&txt99, p);
		if (err) goto quit;

		/* DSORG=PS */
		err = __txorg(&txt99, "PS");
		if (err) goto quit;

		/* get record format */
		p = strstr(fp->mode, "recfm=");
		if (!p) p = strstr(fp->mode,"recfm(");
		if (p) {
			strcpy(temp,p+6);
			recfm = strtok(temp, " ,)");
		}
		if (!recfm) recfm = getenv("SYSOUT_RECFM");
		if (!recfm) recfm = "V";
		err = __txrecf(&txt99, recfm);
		if (err) goto quit;

		/* get logical record length */
		p = strstr(fp->mode, "lrecl=");
		if (!p) p = strstr(fp->mode, "lrecl(");
		if (p) {
			strcpy(temp,p+6);
			lrecl = strtok(temp, " ,)");
		}
		if (!lrecl) lrecl = getenv("SYSOUT_LRECL");
		if (!lrecl) lrecl = "255";
		err = __txlrec(&txt99, lrecl);
		if (err) goto quit;

		if (strchr(recfm, 'B')) {
			/* get optional block size */
			p = strstr(fp->mode, "blksize=");
			if (!p) p = strstr(fp->mode, "blksize(");
			if (p) {
				strcpy(temp,p+8);
				blksize = strtok(temp, " ,)");
			}
			if (!blksize) blksize = getenv("SYSOUT_BLKSIZE");
			if (blksize) {
				err = __txbksz(&txt99, blksize);
				if (err) goto quit;
			}
		}
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
    memcpy(fp->ddname, txt99[0]->text, 8);
    fp->flags |= _FILE_FLAG_DYNAMIC;
	/* if we're running under TSO foreground */
	if (ppa->ppaflag & PPAFLAG_TSOFG) {
		fp->flags |= _FILE_FLAG_TERM;
	}

quit:
    if (txt99) FreeTXT99Array(&txt99);

    return err;
}
