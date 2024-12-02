/* TESTFILE.C - test bed for stdio rewrite */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <mvssupa.h>
#include "osdcb.h"
#include "osjfcb.h"
#include "svc99.h"
#include "clibary.h"
#include "clibdscb.h"
#include "cliblist.h"
#include "clibcrt.h"

static int
myprt(void *udata, const char *fmt, ...)
{
    va_list arg;
    char    *buf    = udata;
    char    *p;

    va_start(arg, fmt);
    vsprintf(buf, fmt, arg);
    va_end(arg);

    printf("Start:");
    for(p = strtok(buf, " -\n"); p; p = strtok(NULL, " -\n")) {
        printf("\"%s\",", p);
    }
    printf("\n");

    return 0;
}

__asm__("\n&FUNC    SETC 'myexit'");
static void
myexit(int status, void *arg)
{
    char    *wsa    = __wsaget((void*)0x1234, 1234);
    char    buf[256];

    wtof("In myexit() status=%d, arg=%08X, wsa=%08X", status, arg, wsa);
    if (wsa) wtodumpf(wsa-16,1234+16,"WSA");
    wtof("Caller \"%s\"", __caller(buf));
}

int
main(int argc, char **argv)
{
    int         rc      = 0;
    FILE        *fp     = 0;
    DSLIST      **dslist= 0;
    DSLIST      *d;
    PDSLIST     **pdslist = 0;
    PDSLIST     *m;
    unsigned    count;
    unsigned    n;
    char        *p;
    DSCB1       *dscb1;
    int         c;
    int         i;
    char        buf[256];
    DSCB        dscb;
    ISPFSTAT    ispfstat;
    LOADSTAT    loadstat;

#if 0
    rc = __listc("MDR", "NONVSAM VOLUME", myprt, buf);

    rc = __dscbdv("MDR.ARRAY.CNTL", "MDR000", &dscb);
    wtof("__dscbdv() rc=%d", rc);
    if (!rc) {
        dscb1 = &dscb.dscb1;
        wtof("MDR.ARRAY.CNTL");
        wtof("credt     %02u.%03u",
            dscb1->credt[0], *(unsigned short*)&dscb1->credt[1]);
        wtof("refd      %02u.%03u",
            dscb1->refd[0], *(unsigned short*)&dscb1->refd[1]);
        wtof("blksz     %u", dscb1->blksz);
        wtof("lrecl     %u", dscb1->lrecl);
    }
#endif

#if 1
    dslist = __listds("HERC01", "NONVSAM VOLUME", NULL /*"*.CNTL"*/);
    wtof("__listds() returned %08X", dslist);
    count = arraycount(&dslist);
    wtof("count %u", count);
    for(n=0; n < count; n++) {
        d = dslist[n];
        wtof("%03u DSN(%s) VOL(%s) LRECL(%u) BLKSIZE(%u) DSORG(%s)",
            n, d->dsn, d->volser, d->lrecl, d->blksize, d->dsorg);
        wtof("    created %u/%02u/%02u (%u) last ref %u/%02u/%02u (%u)",
            d->cryear, d->crmon, d->crday, d->crjday,
            d->rfyear, d->rfmon, d->rfday, d->rfjday);
    }

    __freeds(&dslist);
#endif

#if 0
    fp = fopen("MDR.ARRAY.NCALIB", "r,record");
    wtof("fopen of MDR.ARRAY.NCALIB %08X", fp);
    if (fp) {
        wtof("lrecl     %u", fp->lrecl);
        wtof("blksize   %u", fp->blksize);
        wtof("recfm     %02X", fp->recfm);
        c = fread(buf, 1, sizeof(buf), fp);
        if (c > 0) {
            wtodump("DIR record", buf, c, 16);
        }
    }
    if (fp) fclose(fp);
#endif

#if 0
    pdslist = __listpd("MDR.CLIB.CNTL", NULL);
    wtof("pdslist   %08X", pdslist);
    count = arraycount(&pdslist);
    for(n=0; n < count; n++) {
        m = pdslist[n];
        if (!m) continue;

        c = 12 + ((m->idc & PDSLIST_IDC_UDATA) * 2);
        /* recfm=F or V */
        __fmtisp(m, &ispfstat);
#if 0
        wtodumpf(&ispfstat, sizeof(ispfstat), "ISPFSTAT");
        wtof(" ");
#endif
        wtof("%-8.8s %s %s %s %s %s %s %s %s",
            ispfstat.name, ispfstat.ttr, ispfstat.ver,
            ispfstat.created, ispfstat.changed, ispfstat.init,
            ispfstat.size, ispfstat.mod, ispfstat.userid);
    }
#endif

#if 0
    pdslist = __listpd("SYS1.LINKLIB", "IED*");
    wtof("pdslist   %08X", pdslist);
    count = arraycount(&pdslist);
    for(n=0; n < count; n++) {
        m = pdslist[n];
        if (!m) continue;

        c = 12 + ((m->idc & PDSLIST_IDC_UDATA) * 2);

        /* recfm=U */
        __fmtloa(m, &loadstat);
#if 0
        wtodumpf(&loadstat, sizeof(loadstat), "LOADSTAT");
        wtof(" ");
#endif
        wtof("%-8.8s %s %s %-8.8s %s %s %s %s",
            loadstat.name, loadstat.ttr, loadstat.size, loadstat.aliasof,
            loadstat.ac, loadstat.ep, loadstat.attr, loadstat.ssi);
    }
#endif

#if 0
    fp = fopen("'MDR.CLIB.CNTL(TEST)'", "w");
    if (fp) {
        DCB *dcb = fp->dcb;
        wtof("%s(%s) ttr %06X", fp->dataset, fp->member, dcb->dcbrelad>>8);
        wtof("dsorg     %04X", dcb->dcbdsorg);
        fclose(fp);
    }
#endif

#if 0
    wtof("main() was called by %s", __caller(0));
    on_exit(myexit, (void*)1);
    on_exit(myexit, (void*)2);
    on_exit(myexit, (void*)3);
#endif
quit:
    return rc;
}
