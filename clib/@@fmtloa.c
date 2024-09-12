/* @@FMTLOA.C */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cliblist.h"
#include "clibwto.h"

int
__fmtloa(PDSLIST *pdslist, LOADSTAT *loadstat)
{
    int         rc      = -1;
    LOADDATA    *data   = pdslist ? (LOADDATA*)pdslist->udata : 0;
    LOADSTAT    *stat   = loadstat;
    LOADS01     *s01    = 0;    /* scatter  */
    LOADS02     *s02    = 0;    /* alias    */
    LOADS03     *s03    = 0;    /* SSI      */
    LOADS04     *s04    = 0;    /* APF      */
    const char  *ne     = "NE";
    const char  *ol     = "OL";
    const char  *pg     = "PG";
    const char  *rf     = "RF";
    const char  *rn     = "RN";
    const char  *ru     = "RU";
    const char  *ov     = "OV";
    const char  *ts     = "TS";
    int         i;
    struct tm   tm;

    if (!data) goto quit;
    if (!stat) goto quit;

    memset(stat, 0, sizeof(LOADSTAT));

    for(i=0; i < 8 && pdslist->name[i] > ' '; i++) {
        stat->name[i] = pdslist->name[i];
    }
    sprintf(stat->ttr, "%06X", (*(unsigned *)pdslist->ttr) >> 8);

    /* get size of PDS user data */
    rc = (pdslist->idc & PDSLIST_IDC_UDATA) * 2;

    /* do we have statistics? */
    if (!rc) goto quit;  /* nope, we're done, return rc=0 */
#if 0
    wtodumpf(data, rc, "%s LOADDATA", stat->name);
#endif
    if (data->loadatr1 & LOADSCTR) {
        s01 = (LOADS01*)data->loadbcend;
#if 0
        wtof("LOADSCTR %08X", s01);
#endif
    }
    if (pdslist->idc & PDSLIST_IDC_ALIAS) {
        if (s01) {
            s02 = (LOADS02*)s01->load01nd;
        }
        else {
            s02 = (LOADS02*)data->loadbcend;
        }
#if 0
        wtof("ALIAS     %08X", s02);
#endif
    }
    if (data->loadftb1 & LOADSSI) {
        if (s02) {
            s03 = (LOADS03*)s02->load02nd;
        }
        else if (s01) {
            s03 = (LOADS03*)s01->load01nd;
        }
        else {
            s03 = (LOADS03*)data->loadbcend;
        }
        /* align to half word */
        s03 = (LOADS03*)(((unsigned)s03 + 1) & 0x7FFFFFFE);
#if 0
        wtof("SSI       %08X", s03);
#endif
    }
    if (data->loadftb1 & LOADAPFLG) {
        if (s03) {
            s04 = (LOADS04*)s03->load03nd;
        }
        else if (s02) {
            s04 = (LOADS04*)s02->load02nd;
        }
        else if (s01) {
            s04 = (LOADS04*)s01->load01nd;
        }
        else {
            s04 = (LOADS04*)data->loadbcend;
        }
#if 0
        wtof("APF       %08X", s04);
#endif
    }

    /* format LOAD statistics */
    sprintf(stat->size, "%02X%02X%02X",
        data->loadstor[0], data->loadstor[1], data->loadstor[2]);

    if (s02) {
        for(i=0; i < 8 && s02->loadmnm[i] > ' '; i++) {
            stat->aliasof[i] = s02->loadmnm[i];
        }
    }

    if (s04) {
        sprintf(stat->ac, "%02X", s04->loadapfac);
    }
    else {
        sprintf(stat->ac, "00");
    }

    sprintf(stat->ep, "%02X%02X%02X",
        data->loadepa[0], data->loadepa[1], data->loadepa[2]);

    if (data->loadatr1 & LOADEXEC)      ne = "  ";
    if (!(data->loadatr1 & LOADLOAD))   ol = "  ";
    if (!(data->loadftb1 & LOADPAGA))   pg = "  ";
    if (!(data->loadatr2 & LOADREFR))   rf = "  ";
    if (!(data->loadatr1 & LOADRENT))   rn = "  ";
    if (!(data->loadatr1 & LOADREUS))   ru = "  ";
    if (!(data->loadatr1 & LOADOVLY))   ov = "  ";
    if (!(data->loadatr1 & LOADTEST))   ts = "  ";
    sprintf(stat->attr, "%s %s %s %s %s %s %s %s",
        ne, ol, pg, rf, rn, ru, ov, ts);

    if (s03) {
        sprintf(stat->ssi, "%02X%02X%02X%02X",
            s03->loadchlvl, s03->loadssifb,
            s03->loadmbrsn[0], s03->loadmbrsn[1]);
    }

    /* return rc=0 */
    rc = 0;

quit:
    return rc;
}
