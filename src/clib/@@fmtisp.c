/* @@FMTISP.C */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cliblist.h"

static int cvtdate(int century, unsigned char *date, struct tm *tm);

int
__fmtisp(PDSLIST *pdslist, ISPFSTAT *ispfstat)
{
    int         rc      = -1;
    ISPFDATA    *data   = pdslist ? (ISPFDATA*)pdslist->udata : 0;
    ISPFSTAT    *stat   = ispfstat;
    int         i;
    struct tm   tm;

    if (!data) goto quit;
    if (!stat) goto quit;

    memset(stat, 0, sizeof(ISPFSTAT));

    for(i=0; i < 8 && pdslist->name[i] > ' '; i++) {
        stat->name[i] = pdslist->name[i];
    }
    sprintf(stat->ttr, "%06X", (*(unsigned *)pdslist->ttr) >> 8);

    /* get size of PDS user data */
    rc = (pdslist->idc & PDSLIST_IDC_UDATA) * 2;

    /* do we have statistics? */
    if (!rc) goto quit;  /* nope, we're done, return rc=0 */

    /* format ISPF (like) statistics */
    sprintf(stat->ver, "%02u.%02u", data->ver, data->mod);
    if (cvtdate(data->crecent, data->creydd, &tm)==0) {
        /* format creation date */
        sprintf(stat->created, "%02u-%02u-%02u",
            tm.tm_year % 100, tm.tm_mon + 1, tm.tm_mday);
    }

    if (cvtdate(data->modcent, data->modydd, &tm)==0) {
        /* format changed date */
        sprintf(stat->changed, "%02u-%02u-%02u %02X:%02X:%02X",
            tm.tm_year % 100, tm.tm_mon + 1, tm.tm_mday,
            data->modhm[0], data->modhm[1], data->seconds);
    }

    sprintf(stat->init, "%u", data->initlines);
    sprintf(stat->size, "%u", data->curlines);
    sprintf(stat->mod,  "%u", data->modlines);
    for(i=0; i < 8 && data->userid[i] > ' '; i++) {
        stat->userid[i] = data->userid[i];
    }
    /* return rc=0 */
    rc = 0;

quit:
    return rc;
}

static int
cvtdate(int century, unsigned char *date, struct tm *tm)
{
    memset(tm, 0, sizeof(struct tm));

    /* extract year from packed date */
    tm->tm_year = ((date[0] & 0xF0) >> 4);
    tm->tm_year *= 10;
    tm->tm_year += (date[0] & 0x0F);
    if (century) tm->tm_year += 100;

    /* extract julian days from packed date */
    tm->tm_mday = ((date[1] & 0xF0) >> 4);
    tm->tm_mday *= 10;
    tm->tm_mday += (date[1] & 0x0F);
    tm->tm_mday *= 10;
    tm->tm_mday += ((date[2] & 0xF0) >> 4);

    if (mktime(tm) < 0) return -1;

    return 0;
}
