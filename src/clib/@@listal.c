/* @@LISTDS.C - create DSLIST array */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <time64.h>
#include "clibary.h"        /* dynamic array prototypes     */
#include "clibdscb.h"       /* DSCB structs and prototypes  */
#include "cliblist.h"       /* __listc()                    */
#include "clibstr.h"        /* __patmat()                   */
#include "clibdsab.h"       /* DSAB structs and prototypes  */
#include "ieftiot.h"
#include "osjfcb.h"

static int get_dscb_values(DSLIST *dslist);
static int get_jfcb_values(DSLIST *dslist, JFCB *jfcb);

ALCLIST **__listal(void *tcbptr, const char *ddname, unsigned opt)
{
    unsigned    flg1        = opt & __LISTAL_OPT_FLG1;
    int         skip_nodd   = 0;
    ALCLIST     **alclist   = NULL;
    ALCLIST     *al         = NULL;
    DSAB        *ds         = NULL;
    DSLIST      *dslist     = NULL;
    int         i;
    int         rc;
    struct tm   tm          = {0};
    char        *p;

    for(ds = get_dsab(tcbptr, ddname); ds; ds=next_dsab(ds, tcbptr, ddname)) {
        TIOTDD  *tiotdd = ds->dsabtiot;
        JFCB    *jfcb = (JFCB*)((tiotdd->TIOEJFCB[0]<<16 | tiotdd->TIOEJFCB[1]<<8 | tiotdd->TIOEJFCB[2]) + 16);

        if (skip_nodd && tiotdd->TIOEDDNM[0] <= ' ') continue;

        if (tiotdd->TIOEDDNM[0] > ' ') {
            if (flg1) {
                /* we have filtering options */
                if (flg1 & __LISTAL_OPT_PERM) {
                    /* caller wants permanent dataset allocations */
                    if (!(ds->dsabflg1 & (DSABPALC|DSABPCAT))) {
                        /* not permanent */
                        goto skip_dd;
                    }
                }
                if (flg1 & __LISTAL_OPT_DYNM) {
                    /* caller wants dynamic dataset allocations */
                    if (!(ds->dsabflg1 & (DSABDALC|DSABDCNV|DSABDCAT))) {
                        /* not dynamic */
                        goto skip_dd;
                    }
                }
                if (flg1 & __LISTAL_OPT_CONCAT) {
                    /* caller wants concatenated dataset allocations */
                    if (!(ds->dsabflg1 & (DSABDCAT|DSABPCAT|DSABCATM))) {
                        /* not concatenated */
                        goto skip_dd;
                    }
                }
                if (flg1 & __LISTAL_OPT_INUSE) {
                    /* caller wants in use dataset allocations */
                    if (!(ds->dsabflg1 & DSABNUSE)) {
                        /* not in use */
                        goto skip_dd;
                    }
                }
            }   /* flg1 filters */

            if (opt & __LISTAL_OPT_NOCAT) {
                /* caller does not want catalog allocations */
                if (ds->dsabflg3 & (DSABCATL|DSABJSCT|DSABVVDS)) {
                    /* this is a catalog allocations */
                    goto skip_dd;
                }
            }
            
            if (opt & __LISTAL_OPT_NOJES) {
                /* caller does not want JESx dataset allocations */
                if (memcmp(ds->dsabssnm, "JES", 3)==0) {
                    /* this is a JESx dataset allocation */
                    goto skip_dd;
                }
            }

            goto new_dd;

skip_dd:
            /* skip this dd allocation and concatenated allocations for this dd */
            skip_nodd=1;
            continue;
new_dd:
            /* reset skip_nodd */
            skip_nodd=0;
            
            /* allocate a new record for this dd name */
            al = calloc(1, sizeof(ALCLIST));
            if (!al) goto quit;

            rc = array_add(&alclist, al);
            if (rc) goto quit;
            
            for(i=0; tiotdd->TIOEDDNM[i] > ' ' && i < 8; i++) {
                al->ddname[i] = tiotdd->TIOEDDNM[i];
            }
        }


#define __LISTAL_OPT_DSCB   0x00000100  /* on = get DSCB values for dataset      
                                           off = use JSCB values for dataset*/
        
        dslist = calloc(1, sizeof(DSLIST));
        if (!dslist) goto quit;

        rc = arrayadd(&al->dslist, dslist);
        if (rc) goto quit;
        
        al->count++;    /* update count of dslist records */
        
        /* build DSLIST record */
        for(i=0; jfcb->jfcbdsnm[i] > ' ' && i < sizeof(dslist->dsn)-1; i++) {
            dslist->dsn[i] = jfcb->jfcbdsnm[i];
        }
        for(i=0; jfcb->jfcbvols[i] > ' ' && i < sizeof(dslist->volser)-1; i++) {
            dslist->volser[i] = jfcb->jfcbvols[i];
        }

        if (opt & __LISTAL_OPT_DSCB) {
            /* get dscb values for this dataset */
            rc = get_dscb_values(dslist);
            if (rc==0) continue;
        }
        
        /* default, use jfcb values */
        rc = get_jfcb_values(dslist, jfcb);
    }
    
quit:
    return alclist;
}

static int get_dscb_values(DSLIST *dslist)
{
    DSCB        dscbbuf     = {0};
    DSCB        *dscb       = &dscbbuf;
    DSCB1       *dscb1      = &dscb->dscb1;
    int         rc;
    int         i;
    struct tm   tm          = {0};
    char        *p;

    if (dslist->volser[0] <= ' ') {
		/* get volser for dataset */
		LOCWORK workarea = {0};

		rc = __locate(dslist->dsn, &workarea);
		if (rc==0) {
			memcpy(dslist->volser, workarea.volser, sizeof(dslist->volser));
            for(i=0; workarea.volser[i] > ' ' && i < 6; i++) {
                dslist->volser[i] = workarea.volser[i];
            }
            dslist->volser[i] = 0;
		}
        else {
            /* locate failed, we can't proceed */
            goto quit;
        }
    }

    /* get DSCB info for dataset + volser */
    rc = __dscbdv(dslist->dsn, dslist->volser, dscb);
    if (rc) goto quit;

    /* extract values from DSCB for this dataset */
    p = 0;
    switch(dscb1->dsorg1 & 0x7F) {
    case DSGIS: p = "IS";   break;
    case DSGPS: p = "PS";   break;
    case DSGDA: p = "DA";   break;
    case DSGPO: p = "PO";   break;
    }
    if (dscb1->dsorg2 == ORGAM) p = "VS";
    if (p) strcpy(dslist->dsorg, p);

    p = 0;
    switch (dscb1->recfm & 0xC0) {
    case RECFF: p = "F";    break;
    case RECFV: p = "V";    break;
    case RECFU: p = "U";    break;
    }
    if (p) strcat(dslist->recfm,p);
    if (dscb1->recfm & RECFB) strcat(dslist->recfm, "B");
    if (dscb1->recfm & RECFS) strcat(dslist->recfm, "S");
    if (dscb1->recfm & RECFA) strcat(dslist->recfm, "A");
    if (dscb1->recfm & RECMC) strcat(dslist->recfm, "M");

    dslist->extents = dscb1->noepv;
    dslist->lrecl   = dscb1->lrecl;
    dslist->blksize = dscb1->blksz;

    dslist->cryear  = 1900 + dscb1->credt[0];
    if (dslist->cryear < 1980) {
        dslist->cryear += 100;
    }
    dslist->crjday  = *(unsigned short*)&dscb1->credt[1];
    tm.tm_year      = dslist->cryear - 1900;
    tm.tm_mday      = dslist->crjday;
    mktime(&tm);
    dslist->crmon   = tm.tm_mon + 1;
    dslist->crday   = tm.tm_mday;

    dslist->rfyear  = 1900 + dscb1->refd[0];
    if (dslist->rfyear < 1980) {
        dslist->rfyear += 100;
    }
    dslist->rfjday  = *(unsigned short *)&dscb1->refd[1];
    memset(&tm, 0, sizeof(tm));
    tm.tm_year      = dslist->rfyear - 1900;
    tm.tm_mday      = dslist->rfjday;
    mktime(&tm);
    dslist->rfmon   = tm.tm_mon + 1;
    dslist->rfday   = tm.tm_mday;

quit:
    return rc;
}

static int get_jfcb_values(DSLIST *dslist, JFCB *jfcb)
{
    int         rc          = 0;
    struct tm   tm          = {0};
    struct tm   *t;
    char        *p;
    time64_t    now;

    /* extract values from JFCB for this dataset */
    p = 0;
    switch(jfcb->jfcdsrg1) {
    case JFCORGIS: p = "IS";   break;
    case JFCORGPS: p = "PS";   break;
    case JFCORGDA: p = "DA";   break;
    case JFCORGPO: p = "PO";   break;
    }
    if (jfcb->jfcdsrg2 == JFCORGAM) p = "VS";
    if (p) strcpy(dslist->dsorg, p);

    p = 0;
    switch (jfcb->jfcrecfm & 0xC0) {
    case JFCFIX: p = "F";    break;
    case JFCVAR: p = "V";    break;
    case JFCUND: p = "U";    break;
    }
    if (p) strcat(dslist->recfm,p);
    if (jfcb->jfcrecfm & JFCRFB) strcat(dslist->recfm, "B");
    if (jfcb->jfcrecfm & JFCRFS) strcat(dslist->recfm, "S");
    if (jfcb->jfcrecfm & JFCASA) strcat(dslist->recfm, "A");
    if (jfcb->jfcrecfm & JFCMAC) strcat(dslist->recfm, "M");

    dslist->extents = 0;    /* not in JFCB, need dscb1->noepv; */
    dslist->lrecl   = jfcb->jfclrecl;
    dslist->blksize = jfcb->jfcblksi;

    dslist->cryear  = 1900 + jfcb->jfcbcrdt[0];
    if (dslist->cryear < 1980) {
        dslist->cryear += 100;
    }
    dslist->crjday  = *(unsigned short*)&jfcb->jfcbcrdt[1];
    tm.tm_year      = dslist->cryear - 1900;
    tm.tm_mday      = dslist->crjday;
    mktime(&tm);
    dslist->crmon   = tm.tm_mon + 1;
    dslist->crday   = tm.tm_mday;

#if 1   /* we don't have ref date in JFCB, so we fake it to now */
    time64(&now);
    t = localtime64(&now);
    dslist->rfyear  = t->tm_year + 1900;
    dslist->rfmon   = t->tm_mon + 1;
    dslist->rfday   = t->tm_mday;
    dslist->rfjday  = t->tm_yday + 1;
#endif

    p = "???";
    switch (jfcb->jfcbind2 & JFCDISP) {
    case JFCNEW: p = "NEW"; break;
    case JFCMOD: p = "MOD"; break;
    case JFCOLD: p = "OLD"; break;
    }
    if (jfcb->jfcbind2 & JFCSHARE) p = "SHR";
    strcpy(dslist->disp, p);

quit:
    return rc;
}
