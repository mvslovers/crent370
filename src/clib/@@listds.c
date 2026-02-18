/* @@LISTDS.C - create DSLIST array */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <time.h>
#include "clibary.h"        /* dynamic array prototypes     */
#include "clibdscb.h"       /* DSCB structs and prototypes  */
#include "cliblist.h"       /* __listc()                    */
#include "clibstr.h"        /* __patmat()                   */

static int  parse(void *vdata, const char *fmt, ...);

typedef struct {
    const char  *level;     /* "HLQ.TEST" */
    const char  *option;    /* NULL or "NONVSAM VOLUME" */
    const char  *filter;    /* dataset name pattern "HLQ.TEST.*DATA" */
    DSLIST      **array;    /* dynamic array of DSLIST records */
    char        dsn[45];    /* dataset name */
    char        volser[7];  /* dataset volser */
    char        buf[256];   /* work buffer for parsing */
    DSCB        dscb;       /* DSCB buffer */
} UDATA;

DSLIST **
__listds(const char *level, const char *option, const char *filter)
{
    int     rc      = 0;
    UDATA   udata   = {0};

    udata.level     = level;
    udata.option    = option;
    udata.filter    = filter;

    rc = __listc(level, option, parse, &udata);

    return udata.array;
}

static int
parse(void *vdata, const char *fmt, ...)
{
    int     rc      = 0;
    UDATA   *udata  = vdata;
    char    *buf    = udata->buf;
    DSCB    *dscb   = &udata->dscb;
    DSCB1   *dscb1  = &dscb->dscb1;
    DSLIST  *dslist = 0;
    struct tm tm    = {0};
    char    *p;
    va_list arg;

    /* format the record passed to us by __listc() */
    va_start(arg, fmt);
    vsprintf(buf, fmt, arg);
    va_end(arg);

    if (buf[0]=='1') goto quit; /* skip page headers */

    /* parse the formatted record looking for keywords */
    p = strtok(buf, " -\n");
    if (!p) goto quit;

    /* skip carriage control characters */
    if (isdigit(*p)) {
        p++;
        if (*p==0) p = strtok(NULL, " -\n");
    }

    if (udata->dsn[0]) goto check_vol;  /* we already have a dataset */

    if (stricmp(p, "NONVSAM")==0    ||
        stricmp(p, "PAGESPACE")==0  ||
        stricmp(p, "CLUSTER")==0    ||
        stricmp(p, "USERCATALOG")==0) {
        /* get next parm */
        p = strtok(NULL, " -\n");
        if (!p) goto quit;

        /* make sure name does not start with a number */
        if (isdigit(*p)) goto quit;

        if (udata->filter) {
            /* match dataset name against filter pattern */
            if (!__patmat(p, udata->filter)) goto quit;
        }

        /* save dataset name */
        strcpy(udata->dsn, p);
        udata->volser[0] = 0;
        goto quit;
    }

check_vol:
    if (!udata->dsn[0]) goto quit;   /* no dataset, we're finished */

    if (stricmp(p, "VOLSER")==0) {
        /* get next parm */
        p = strtok(NULL, " -\n");
        if (!p) {
            udata->dsn[0] = 0;
            goto quit;
        }

        /* save volser for this dataset */
        strcpy(udata->volser, p);
    }

    if (!udata->volser[0]) goto quit;   /* no volser, we're finished */

    /* allocate DSLIST record for dataset */
    dslist = calloc(1, sizeof(DSLIST));
    if (!dslist) {
        udata->dsn[0] = 0;
        udata->volser[0] = 0;
        goto quit;
    }

    /* build DSLIST record */
    strcpy(dslist->dsn, udata->dsn);
    udata->dsn[0] = 0;
    strcpy(dslist->volser, udata->volser);
    udata->volser[0] = 0;

	/* if the dataset is cataloged on the SYSRES volume "******" */
	if (strcmp(dslist->volser, "******")==0) {
		/* get volser for dataset */
		LOCWORK workarea = {0};

		rc = __locate(dslist->dsn, &workarea);
		if (rc==0) {
			memcpy(dslist->volser, workarea.volser, sizeof(dslist->volser));
		}
	}
    /* get DSCB info for dataset + volser */
    rc = __dscbdv(dslist->dsn, dslist->volser, dscb);
#if 0
    wtof("%s __dscbdv(\"%s\",\"%s\",...) rc=%d", __func__, dslist->dsn, dslist->volser, rc);
#endif
    if (rc) goto done;  /* failed, but keep the DSLIST record */

    /* wtof("%s dsn=\"%s\", dsind=%02X", __func__, dslist->dsn, dscb1->dsind); */

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

done:
    /* add DSLIST record to array */
    rc = arrayadd(&udata->array, dslist);
    if (rc) {
        free(dslist);
        goto quit;
    }

quit:
    return 0;
}
