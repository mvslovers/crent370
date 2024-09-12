/* @@FPTMP.C */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <mvssupa.h>
#include "svc99.h"
#include "clibary.h"

int
__fptmp(FILE *fp)
{
    int         err     = 1;
    unsigned    count   = 0;
    char        *recfm  = 0;
    char        *lrecl  = 0;
    char        *space  = 0;
    char        *p      = 0;
    TXT99       **txt99 = NULL;
    RB99        rb99    = {0};
    char        temp[sizeof(fp->mode)+1];

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
    p = strstr(fp->mode, "recfm=");
    if (!p) p = strstr(fp->mode,"recfm(");
    if (p) {
        strcpy(temp,p+6);
        recfm = strtok(temp, " ,)");
    }
    if (!recfm) recfm = getenv("TEMP_RECFM");
    if (!recfm) recfm = "V";
    err = __txrecf(&txt99, recfm);
    if (err) goto quit;

    /* get logical record length */
    p = strstr(fp->mode, "lrecl=");
    if (!p) p = strstr(fp->mode,"lrecl(");
    if (p) {
        strcpy(temp,p+6);
        lrecl = strtok(temp, " ,)");
    }
    if (!lrecl) lrecl = getenv("TEMP_LRECL");
    if (!lrecl) lrecl = "255";
    err = __txlrec(&txt99, lrecl);
    if (err) goto quit;

    if (strchr(recfm, 'B')) {
        /* get optional block size */
        p = strstr(fp->mode, "blksize=");
        if (!p) p = strstr(fp->mode,"blksize(");
        if (p) {
            strcpy(temp,p+8);
            recfm = strtok(temp, " ,)");
        }
        if (!p) p = getenv("TEMP_BLKSIZE");
        if (p) {
            err = __txbksz(&txt99, p);
            if (err) goto quit;
        }
    }

    /* get optional space "[CYL|TRK](pri[,sec])" or "blksize(pri[,sec])" */
    p = strstr(fp->mode, "space=");
    if (p) {
        strcpy(temp,p+6);
        p = strchr(temp, '(');
        if (p) {
            p = strchr(p, ')');
            if (p) {
                space = temp;
                p++;    /* skip over the ')' */
                *p=0;   /* terminate the string here */
            }
        }
    }
    if (!space) space = getenv("TEMP_SPACE");
    if (space) {
        char *x = strchr(space,'(');
        if (x) {
            if (memcmp(space, "CYL", 3)==0) {
                /* CYLINDERS */
                err = __txcyl(&txt99, NULL);
            }
            else if (memcmp(space, "TRK", 3)==0) {
                /* TRACKS */
                err = __txtrk(&txt99, NULL);
            }
            else {
                /* BLOCKS */
                err = __txblk(&txt99, p);
            }
            space = x+1;
        }
        while(*space && !isdigit(*space)) space++;
        err = __txspac(&txt99, space);  /* "pri[,sec]" */
        if (err) goto quit;
    }

    /* we want temp dataset allocated to VIO */
    err = __txunit(&txt99, "VIO");
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
    memcpy(fp->ddname, txt99[0]->text, 8);
    fp->flags |= _FILE_FLAG_DYNAMIC;

quit:
    if (txt99) FreeTXT99Array(&txt99);

    return err;
}
