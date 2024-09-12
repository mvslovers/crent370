#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "clibstae.h"

typedef struct {
    unsigned u[2];
} PARAM;

__asm__("\n&FUNC    SETC 'get_offset'");
static void
get_offset(SDWA *sdwa, char *buf)
{
    unsigned    *psw    = (unsigned*)sdwa->SDWANXT1;
    unsigned    *np     = (unsigned*)sdwa->SDWAGR13;
    unsigned    *ep;
    unsigned    len;
    unsigned    offset;
    unsigned char *cp;

    *buf = 0;
    if (np < (unsigned*)8192) goto quit;

    np = (unsigned*)np[1];  /* prev save area   */
    ep = (unsigned*)np[4];  /* R15              */
    offset = ((unsigned)psw - (unsigned)ep);

#if 0
    wtof("psw %08X, ep %08X, offset %08X", psw, ep, offset);
#endif

    if (ep > psw) goto quit;    /* can't be right */
    if ((ep[0] >> 8) == 0x0047F0F0) {
        cp  = (unsigned char*)ep;
        if (cp[4] > cp[3]) goto quit;   /* that doesn't look right */

        len = cp[4];
        if (len > 40) len = 40;         /* keep it reasonable */

        sprintf(buf, "epname %-*.*s offset %08X",
            len, len, &cp[5], offset);
    }

quit:
    return;
}

__asm__("\n&FUNC    SETC 'get_addr'");
static void
get_addr(unsigned addr, char *buf)
{
    int         rc;
    int         i;
    int         j;
    int         pos;
    int         pos2;
    unsigned    *np;
    char        *cp;
    char        hex[12];

#if 0
    /* force a bad address to test failed() recovery */
    if (!addr) addr = 0x00654320;
#endif

    /* preload "default" values */
    strcpy(buf,
        "........ ........ ........ ........ *................*");

    pos  = 0;
    pos2 = 37;
    np = (unsigned*)addr;   /* unsigned pointer to mem */
    cp = (char*)addr;       /* character pointer to mem */

    for(i=0; i < 4; i++, np++, pos+=9) {
        sprintf(hex, "%08X", *np);
        memcpy(&buf[pos], hex, 8);

        for(j=0; j < 4; j++, cp++, pos2++) {
            if (isgraph(*cp)) {
                buf[pos2] = *cp;
            }
        }
    }

quit:
    return;
}

__asm__("\n&FUNC    SETC 'get_epname'");
static void
get_epname(unsigned addr, char *buf)
{
    unsigned    *ep = (unsigned*)addr;
    unsigned    len;

    *buf = 0;
    if ((ep[0] >> 8) == 0x0047F0F0) {
        unsigned char *cp  = (unsigned char*)ep;
        if (cp[4] > cp[3]) goto quit;   /* that doesn't look right */

        len = cp[4];
        if (len > 40) len = 40;         /* keep it reasonable */

        sprintf(buf, "%-*.*s", len, len, &cp[5]);
    }

quit:
    return;
}

__asm__("\n&FUNC    SETC 'dump_regs'");
static int
dump_regs(SDWA *sdwa)
{
    int         i;
    unsigned    *n;
    char        buf[80];

    for(i=0, n=&sdwa->SDWAGR00; i<16; i++, n++) {
        try(get_addr, *n, buf);

        wtof("R%02d:%08X:%s", i, *n, buf);
    }

    return 0;
}

__asm__("\n&FUNC    SETC 'get_sa_prev'");
static int
get_sa_prev(unsigned *n, unsigned **prev)
{
    /* wtof("%s stack=%08X", __func__, n); */
    if (n[1] >= 0x00002000 && n[1] < 0x00FF0000) {
        *prev = (unsigned*)n[1];
    }
    /* wtof("%s prev=%08X", __func__, *prev); */
    return 0;
}

__asm__("\n&FUNC    SETC 'get_sa_next'");
static int
get_sa_next(unsigned *n, unsigned **next)
{
    /* wtof("%s stack=%08X", __func__, n); */
    if (n[2] >= 0x00002000 && n[2] < 0x00FF0000) {
        *next = (unsigned*)n[2];
    }
    /* wtof("%s next=%08X", __func__, *next); */
    return 0;
}

__asm__("\n&FUNC    SETC 'dump_sa'");
static int
dump_sa(SDWA *sdwa)
{
    unsigned    *psa    = 0;                            /* low core == PSA      */
    unsigned    *tcb    = (unsigned*)psa[0x21c/4];      /* TCB      == PSATOLD  */
    unsigned    *fsa    = (unsigned*)(tcb[0x70/4] & 0x00FFFFFF);    /* first save area for TCB */
    unsigned    *ppa    = (unsigned*)(fsa[2]);          /* A(@PPA) */
    int         i;
    unsigned    *n;
    unsigned    *prev;
    unsigned    *next;
    char        buf[80];

#if 0
    if (sdwa->SDWAGR13 < 0x00002000 || sdwa->SDWAGR13 > 0x00FF0000) {
        wtof("Invalid stack pointer");
        goto quit;
    }
#endif
    n = (unsigned*)sdwa->SDWAGR13;

    for(prev=0, try(get_sa_prev, n, &prev); prev ; prev=0, try(get_sa_prev, n, &prev)) {
        n = prev;
        wtof("------------------------------------------------");
        try(get_epname, n[4], buf);
        if (buf[0]) wtof("%s", buf);
        try(get_addr, n, buf);
        wtof("DSA:%08X:%s", n, buf);
        try(get_addr, n[3], buf);
        wtof("R14:%08X:%s", n[3], buf);
        try(get_addr, n[4], buf);
        wtof("R15:%08X:%s", n[4], buf);
        try(get_addr, n[5], buf);
        wtof("R00:%08X:%s", n[5], buf);
        try(get_addr, n[6], buf);
        wtof("R01:%08X:%s", n[6], buf);
        if (n == ppa) goto quit;        /* stop at A(@PPA) */
    }

    wtof("------------------------------------------------");
    wtof("Traceback interrupted, Forward from PPA %08X", ppa);
    wtof("------------------------------------------------");

    for(next=ppa; next ; next=0, try(get_sa_next, n, &next)) {
        n = next;
        wtof("------------------------------------------------");
        try(get_epname, n[4], buf);
        if (buf[0]) wtof("%s", buf);
        try(get_addr, n, buf);
        wtof("DSA:%08X:%s", n, buf);
        try(get_addr, n[3], buf);
        wtof("R14:%08X:%s", n[3], buf);
        try(get_addr, n[4], buf);
        wtof("R15:%08X:%s", n[4], buf);
        try(get_addr, n[5], buf);
        wtof("R00:%08X:%s", n[5], buf);
        try(get_addr, n[6], buf);
        wtof("R01:%08X:%s", n[6], buf);
    }

quit:
    return 0;
}

__asm__("\n&FUNC    SETC 'suppress_dump'");
static int
suppress_dump(SDWA *sdwa)
{
    wtof("suppress dump requested");
    sdwa->SDWACMPF &= (0XFF - SDWAREQ); /* turn off dump flag */
    return 0;
}

__asm__("\n&FUNC    SETC 'snap_dump'");
static int
snap_dump(SDWA *sdwa)
{
    int     rc;

    wtof("snap dump requested");

    /* open SNAP DCB for output */
    __asm__( "OPEN  (SNAPDCB,(OUTPUT))         Open SNAP DCB\n\t"
"         LR\t%0,15" : "=r" (rc));
    if (rc) {
        wtof("OPEN for SNAP DD failed, rc=%d", rc);
        goto quit;
    }

    __asm__( "LA\t2,SNAPDCB\n\tSNAP DCB=(2),SDATA=ALL,PDATA=ALL"
    : : : "0", "1", "2", "14", "15");

    __asm__( "CLOSE SNAPDCB                    Close the SNAP DCB");

    sdwa->SDWACMPF &= (0XFF - SDWAREQ); /* turn off dump flag */

quit:
    return 0;
}

__asm__("\n"
"SNAPDCB  DCB   DDNAME=SNAP,DSORG=PS,LRECL=125,BLKSIZE=1632,            @\n"
"               RECFM=VBA,MACRF=(W)");

__asm__("\n&FUNC    SETC 'system_dump'");
static int
system_dump(SDWA *sdwa)
{
    wtof("system_dump requested");
    goto quit;

    sdwa->SDWACMPF &= (0XFF - SDWAREQ); /* turn off dump flag */

quit:
    return 0;
}

__asm__("\n&FUNC    SETC 'recovery'");
static int
recovery(SDWA *sdwa, void *udata)
{
    PARAM       *param  = (PARAM*)udata;
    int         dump    = DUMP_DEFAULT;
    unsigned    *psa    = 0;                        /* low core == PSA      */
    void        *tcb    = (void*)psa[0x21c/4];      /* TCB      == PSATOLD  */
    char        *p;
    int         i;
    unsigned    abcode;
    unsigned    epa;
    unsigned    ilc;
    unsigned    cc;
    unsigned    psw[2];
    char        epname[12];
    char        abend[24];
    char        buf[80];

#if 0
    wtof("Enter recovery(), dump option=%d", dump);
#endif

    if (param && param->u[1]) {
        dump = (int)param->u[1];
#if 0
        wtof("dump option from SDWAPARM %08X=%d", param, dump);
#endif
    }

    abcode = *(unsigned*)&sdwa->SDWACMPF;
    if (abcode & 0x00FFF000) {
        /* system abend */
        abcode = (abcode & 0x00FFF000) >> 12;
        sprintf(abend, "S%03X", abcode);
    }
    else {
        abcode = (abcode & 0x00000FFF);
        sprintf(abend, "U%04D", abcode);
    }

    __asm__("MVC\t0(8,%0),0(%1)" : : "r" (psw), "r" (&sdwa->SDWAEMK1));
    epa = sdwa->SDWAEPA;
    if (sdwa->SDWANAME[0] <= ' ') {
        sprintf(epname, "%08X", sdwa->SDWAEPA);
    }
    else {
        sprintf(epname, "%-8.8s", sdwa->SDWANAME);
        for(i=0; i < 8; i++) {
            if (epname[i]==' ') {
                epname[i]=0;
                break;
            }
        }
    }

    try(get_offset, sdwa, buf);
    wtof("ABEND %s detected for module %s %s TCB=%08X",
        abend, epname, buf, tcb);

    ilc = (sdwa->SDWAPMKP & SDWAILP) >> 5;
    cc  = (sdwa->SDWAINT1 & SDWACC1) >> 4;
    wtof("PSW:%08X %08X KEY(%u) MODE(%s) ILC(%u) CC(%u)",
        psw[0], psw[1], (sdwa->SDWAMWP1 & SDWAKEY1) >> 4,
        (sdwa->SDWAMWP1 & SDWAPGM1) ? "PROB" : "SUP", ilc, cc);

    psw[1] &= 0x00FFFFFF;           /* remove high byte noise */
    if (psw[1] > ilc) psw[1]-=ilc;  /* back up instruction length */
    try(get_addr, psw[1], buf);
    wtof(">>>:%08X:%s", psw[1], buf);

    dump_regs(sdwa);
    dump_sa(sdwa);

    switch(dump) {
    case DUMP_SUPPRESS:
        suppress_dump(sdwa);
        break;
    case DUMP_DEFAULT:
        /* nothing to do */
        break;
    case DUMP_SNAP:
        snap_dump(sdwa);
        break;
    case DUMP_SDUMP:
        system_dump(sdwa);
        break;
    }

    /* set RC=0, RETRY=NULL, RETREGS=NO */
    SETRP(sdwa,0,0,0);

#if 0
    wtof("Exit recovery()");
#endif
    return 0;   /* 0=continue with abend, 4=continue with retry */
}

int
__abrpt(ESTAE_OP estae_op, DUMP_OP dump_op)
{
    int         rc      = -1;
    int         dump    = (int)dump_op;

    switch(estae_op) {
    case ESTAE_CREATE:
    case ESTAE_OVERLAY:
    case ESTAE_DELETE:
        rc = __estae(estae_op, recovery, (void*)dump);
        break;
    }

    return rc;
}
