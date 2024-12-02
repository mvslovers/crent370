/* @@DSALC.C */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <mvssupa.h>
#include "svc99.h"
#include "clibary.h"
#include "clibcrt.h"
#include "clibio.h"

typedef struct __dsalc    __DSALC;
struct __dsalc {
    char		*blksize;   // blksize=...
    char        *ddn;       // ddname=...
    char        *disp;      // disp=(new,catlg,delete)
    char        *dsn;       // dsname=...
    char        *dsorg;     // dsorg=PS or PO or ...
    char        *lrecl;     // lrecl=...
    char        *recfm;     // recfm=...
    char        *space;     // space=trk(n,n,n) or cyl(n,n,n) 
    char        *unit;      // unit=...
    char        *volser;    // volser=...
};

int
__dsalc(char *ddname, const char *opts)
{
    CLIBCRT     *crt        = __crtget();
    char        *crtstrtk   = crt->crtstrtk;
    int         err         = 1;
    char        *temp       = NULL;
    int         templen     = 0;
    __DSALC     dsalcbuf    = {0};
    __DSALC     *dsalc      = &dsalcbuf;
    TXT99       **txt99     = NULL;
    RB99        rb99        = {0};
    unsigned    count;
    char        *p;
    char 		*t;

	// wtof("%s: enter", __func__);
	
    if (opts) {
        templen = strlen(opts) + 8;
        temp    = calloc(1, templen);
        if (!temp) {
            wtof("%s: Out of memory (%d bytes)", __func__, templen);
            goto quit;
        }
        
        /* copy opts string to temp and upper case */
        for(p=temp, t=(char*)opts; *t; p++, t++) {
            *p = toupper(*t);
        }
            
        /* we want to convert our opts string "dd=test;space=TRK(val1,val2);..."
        * to something like  "DD=TEST;SPACE=TRK,val1,val2;..." 
        */
        // wtof("%s: opts=\"%s\"", __func__, opts);
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
        }
    }
    
	// wtof("%s: temp=\"%s\"", __func__, temp);

	for(p=strtok(temp, ";"); p; p=strtok(NULL, ";")) {
        if (strstr(p, "BLKSIZE=")) dsalc->blksize = p+8;
        else if (strstr(p, "DD=")) dsalc->ddn = p+3;
        else if (strstr(p, "DDNAME=")) dsalc->ddn = p+7;
        else if (strstr(p, "DISP=")) dsalc->disp = p+5;
        else if (strstr(p, "DSN=")) dsalc->dsn = p+4;
        else if (strstr(p, "DSNAME=")) dsalc->dsn = p+7;
        else if (strstr(p, "DSORG=")) dsalc->dsorg = p+6;
		else if (strstr(p, "RECFM=")) dsalc->recfm = p+6;
		else if (strstr(p, "LRECL=")) dsalc->lrecl = p+6;
		else if (strstr(p, "SPACE=")) dsalc->space = p+6;
        else if (strstr(p, "UNIT=")) dsalc->unit = p+5;
        else if (strstr(p, "VOLSER=")) dsalc->volser = p+7;
	}

#if 0 /* debugging */
	wtof("%s: blksize   =\"%s\"", __func__, dsalc->blksize);
    wtof("%s: ddn       =\"%s\"", __func__, dsalc->ddn);
    wtof("%s: disp      =\"%s\"", __func__, dsalc->disp);
    wtof("%s: dsn       =\"%s\"", __func__, dsalc->dsn);
    wtof("%s: dsorg     =\"%s\"", __func__, dsalc->dsorg);
	wtof("%s: lrecl     =\"%s\"", __func__, dsalc->lrecl);
	wtof("%s: recfm     =\"%s\"", __func__, dsalc->recfm);
	wtof("%s: space     =\"%s\"", __func__, dsalc->space);
    wtof("%s: unit      =\"%s\"", __func__, dsalc->unit);
    wtof("%s: volser    =\"%s\"", __func__, dsalc->volser);
#endif

    if (dsalc->ddn && *dsalc->ddn) {
        /* allocate to this DD name */
        err = __txddn(&txt99, dsalc->ddn);
    }
    else {
        /* we want the DDNAME returned to us */
        err = __txrddn(&txt99, NULL);
    }
    if (err) goto quit;

    if (dsalc->dsn && *dsalc->dsn) {
        /* allocate this dataset */
        err = __txdsn(&txt99, dsalc->dsn);
        if (err) goto quit;
    }

    if (dsalc->disp) {
        /* DISP=alloc[,normal[,abnormal]] */
        p = strtok(dsalc->disp, " ,");
        if (!p || *p==0) err = __txnew(&txt99, NULL);
        else if (strstr(p, "NEW")) err = __txnew(&txt99, NULL);
        else if (strstr(p, "OLD")) err = __txold(&txt99, NULL);
        else if (strstr(p, "MOD")) err = __txmod(&txt99, NULL);
        else if (strstr(p, "SHR")) err = __txshr(&txt99, NULL);
        else wtof("%s: Invalid DISP=%s", __func__, p);
        if (err) goto quit;
        
        p = strtok(NULL, " ,");
        if (p) {
            /* normal disposition */
            if (strstr(p, "DEL")) err = __txdel(&txt99, NULL);
            else if (strstr(p, "DELETE")) err = __txdel(&txt99, NULL);
            else if (strstr(p, "CAT")) err = __txcat(&txt99, NULL);
            else if (strstr(p, "CATLG")) err = __txcat(&txt99, NULL);
            else if (strstr(p, "KEEP")) err = __txkeep(&txt99, NULL);
            else if (strstr(p, "UNCAT")) err = __txucat(&txt99, NULL);
            else if (strstr(p, "UNCATLG")) err = __txucat(&txt99, NULL);
            else wtof("%s: Invalid DISP=,%s", __func__, p);
            if (err) goto quit;
        }
        
        p = strtok(NULL, " ,");
        if (p) {
            /* abnormal disposition */
            if (strstr(p, "DEL")) err = __txadel(&txt99, NULL);
            else if (strstr(p, "DELETE")) err = __txadel(&txt99, NULL);
            else if (strstr(p, "CAT")) err = __txacat(&txt99, NULL);
            else if (strstr(p, "CATLG")) err = __txacat(&txt99, NULL);
            else if (strstr(p, "KEEP")) err = __txakee(&txt99, NULL);
            else if (strstr(p, "UNCAT")) err = __txauca(&txt99, NULL);
            else if (strstr(p, "UNCATLG")) err = __txauca(&txt99, NULL);
            else wtof("%s: Invalid DISP=,,%s", __func__, p);
            if (err) goto quit;
        }
    }

    if (dsalc->dsorg) {
        /* DSORG=xx */
        err = __txorg(&txt99, dsalc->dsorg);
        if (err) {
            wtof("%s: Invalid DSORG=%s", __func__, dsalc->dsorg);
            goto quit;
        }
    }

    if (dsalc->recfm) {
        /* RECFM=xx */
        err = __txrecf(&txt99, dsalc->recfm);
        if (err) {
            wtof("%s: Invalid RECFM=%s", __func__, dsalc->recfm);
            goto quit;
        }
    }
    
    if (dsalc->lrecl) {
        /* LRECL=xx */
        err = __txlrec(&txt99, dsalc->lrecl);
        if (err) {
            wtof("%s: Invalid LRECL=%s", __func__, dsalc->lrecl);
            goto quit;
        }
    }

    if (dsalc->blksize) {
        /* BLKSIZE=xx */
        err = __txbksz(&txt99, dsalc->blksize);
        if (err) {
            wtof("%s: Invalid BLKSIZE=%s", __func__, dsalc->blksize);
            goto quit;
        }
    }

    /* get optional space "[CYL|TRK],pri[,sec]," or "blksize,pri[,sec]," */
    if (dsalc->space) {
		if (memcmp(dsalc->space, "CYL=", 4)==0) {
			/* CYLINDERS */
			err = __txcyl(&txt99, NULL);
            if (err) {
                wtof("%s: Invalid CYL value SPACE=%s", __func__, dsalc->space);
                goto quit;
            }
			dsalc->space += 4;
		}
		else if (memcmp(dsalc->space, "TRK=", 4)==0) {
			/* TRACKS */
			err = __txtrk(&txt99, NULL);
            if (err) {
                wtof("%s: Invalid TRK value SPACE=%s", __func__, dsalc->space);
                goto quit;
            }
			dsalc->space += 4;
		}
		else {
			/* BLOCKS */
			char *x = strchr(dsalc->space, '=');
			if (x) *x = 0;
			err = __txblk(&txt99, dsalc->space);
            if (err) {
                wtof("%s: Invalid blocks value SPACE=%s", __func__, dsalc->space);
                goto quit;
            }
			if (x) dsalc->space = x+1;
        }

        while(*dsalc->space && !isdigit(*dsalc->space)) dsalc->space++;
        err = __txspac(&txt99, dsalc->space);  /* "pri[,sec][,dir]" */
        if (err) {
            wtof("%s: Invalid SPACE=%s", __func__, dsalc->space);
            goto quit;
        }
        if (err) goto quit;
    }

    if (dsalc->unit) {
        err = __txunit(&txt99, dsalc->unit);
        if (err) {
            wtof("%s: Invalid UNIT=%s", __func__, dsalc->unit);
            goto quit;
        }
    }

    if (dsalc->volser) {
        err = __txvols(&txt99, dsalc->volser);
        if (err) {
            wtof("%s: Invalid VOLSER=%s", __func__, dsalc->volser);
            goto quit;
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
    if (err) {
        wtof("%s: __svc99() err=%d", __func__, err);
        wtodumpf(&rb99, sizeof(RB99), "%s RB99", __func__);
        goto quit;
    }

    if (ddname) {
        /* return DDNAME */
        memcpy(ddname, txt99[0]->text, 8);
        ddname[8] = 0;
    }

quit:
    if (temp)   free(temp);
    
    /* restore the strtok() "old" pointer */
    crt->crtstrtk = crtstrtk;

    if (txt99) FreeTXT99Array(&txt99);

	// wtof("%s: exit err=%d", __func__, err);
    return err;
}
