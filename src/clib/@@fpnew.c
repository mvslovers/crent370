/* @@FPNEW.C */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <mvssupa.h>
#include "svc99.h"
#include "clibary.h"

int
__fpnew(FILE *fp)
{
    int         err     = 1;
    unsigned    count   = 0;
    char        *recfm  = getenv("DATASET_RECFM");
    char        *lrecl  = getenv("DATASET_LRECL");
    char		*blksize= getenv("DATASET_BLKSIZE");
    char        *space  = getenv("DATASET_SPACE");
    char        *p      = 0;
    char 		*t;
    TXT99       **txt99 = NULL;
    RB99        rb99    = {0};
    char        temp[sizeof(fp->mode)+1];

	// wtof("%s: enter", __func__);
	
	memset(temp, 0, sizeof(temp));
	strcpy(temp, fp->mode);
	
	/* we want to convert our mode string "w,record,name=(val1,val2),..."
	 * to something like  "w;record;name=val1,val2;..." 
	 */
	// wtof("%s: fp->mode=\"%s\"", __func__, fp->mode);
	for(p=temp; *p; p++) {
		if (*p=='(') {
			if (*(p-1) != '=') {
				/* convert "TRK(n,n)" to "TRK=n,n" 
				 * or "nnnn(n,n)" to "nnnn=n,n" */
				*p = '=';
			}
			else {
				/* convert "name=(val1,val2)..." to "name=val1,val2..." */
				strcpy(p, p+1);
			}
			for(p++;*p; p++) {
				if (*p==')') {
					strcpy(p,p+1);
					break;
				}
			}
		}
		
		if (*p==',') *p = ';';
		else *p = toupper(*p);
	}
	// wtof("%s:     mode=\"%s\"", __func__, temp);

	for(p=strtok(temp, ";"); p; p=strtok(NULL, ";")) {
		if (strstr(p, "RECFM=")) recfm = p+6;
		else if (strstr(p, "LRECL=")) lrecl = p+6;
		else if (strstr(p, "BLKSIZE=")) blksize = p+8;
		else if (strstr(p, "SPACE=")) space = p+6;
	}

#if 0 /* debugging */
	wtof("%s: recfm=\"%s\"", __func__, recfm);
	wtof("%s: lrecl=\"%s\"", __func__, lrecl);
	wtof("%s: blksize=\"%s\"", __func__, blksize);
	wtof("%s: space=\"%s\"", __func__, space);
#endif

    /* we want the DDNAME returned to us */
    err = __txrddn(&txt99, NULL);
    if (err) goto quit;

    /* allocate this dataset */
    err = __txdsn(&txt99, fp->dataset);
    if (err) goto quit;

    /* DISP=NEW */
    err = __txnew(&txt99, NULL);
    if (err) goto quit;

    /* DISP=,CATALOG */
    err = __txcat(&txt99, NULL);
    if (err) goto quit;

    /* DSORG=PS */
    err = __txorg(&txt99, "PS");
    if (err) goto quit;

    /* get record format */
    if (!recfm) recfm = "V";
    err = __txrecf(&txt99, recfm);
    if (err) goto quit;

    /* get logical record length */
    if (!lrecl) lrecl = "255";
    err = __txlrec(&txt99, lrecl);
    // wtof("%s: __txlrec(&txt99, \"%s\") err=%d", __func__, lrecl, err);
    if (err) goto quit;

    if (strchr(recfm, 'B')) {
        /* get optional block size */
        if (blksize) {
            err = __txbksz(&txt99, blksize);
            // wtof("%s: __txbksz(&txt99, \"%s\") err=%d", __func__, blksize, err);
            if (err) goto quit;
        }
    }

    /* get optional space "[CYL|TRK],pri[,sec]," or "blksize,pri[,sec]," */
    if (space) {
		if (memcmp(space, "CYL=", 4)==0) {
			/* CYLINDERS */
			err = __txcyl(&txt99, NULL);
			// wtof("%s: __txcyl(&txt99, NULL) err=%d", __func__, err);
			space += 4;
		}
		else if (memcmp(space, "TRK=", 4)==0) {
			/* TRACKS */
			err = __txtrk(&txt99, NULL);
			// wtof("%s: __txtrk(&txt99, NULL) err=%d", __func__, err);
			space += 4;
		}
		else {
			/* BLOCKS */
			char *x = strchr(space, '=');
			if (x) *x = 0;
			err = __txblk(&txt99, space);
			// wtof("%s: __txblk(&txt99, \"%s\") err=%d", __func__, space, err);
			if (x) space = x+1;
        }

        while(*space && !isdigit(*space)) space++;
        err = __txspac(&txt99, space);  /* "pri[,sec]" */
		// wtof("%s: __txspac(&txt99, \"%s\") err=%d", __func__, space, err);
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
    memcpy(fp->ddname, txt99[0]->text, 8);
    fp->flags |= _FILE_FLAG_DYNAMIC;

quit:
    if (txt99) FreeTXT99Array(&txt99);

	// wtof("%s: exit err=%d", __func__, err);
    return err;
}
