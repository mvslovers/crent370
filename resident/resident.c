#include <clibres.h>
#include <clibos.h>
#include <enqpl.h>

#if 0
/* This is a map of the prefix area for the storage we obtain and free.
   We don't actually use this PREFIX as the GCCMVS compiler generates
   correct but inefficient code sequences, so we do our own shifts and
   OR sequences instead to get slightly better code generation. */
typedef struct prefix   PREFIX;
struct prefix {
    unsigned    sp : 8;         /* 1 bytes subpool              */
    unsigned    len : 24;       /* 3 bytes GETMAIN'd length     */
    unsigned    key : 8;        /* 1 byte PSW key for storage   */
    unsigned    size : 24;      /* 3 byte caller requested size */
} __attribute__((packed));      /* 8 byte prefix area           */
#endif

__asm__("\n&FUNC    SETC 'res_getmain'");
static int res_getmain(RESDISP *rd, unsigned size, unsigned sp, void **stg)
{
    int             rc          = 0;
    void            *r1         = (void*)0;
    unsigned        lv;
    unsigned char   pswkey;

    if (!size) return -1;                   /* no size, fail    */
    if (size > 0x00FFFFFF) return -1;       /* too large, fail  */

    /* get the current PSW key */
    pswkey = res_request_key(rd->res, PSWKEYNONE);

    sp &= 0x000000FF;                       /* SP range 0-255 */

    /* calc length value including prefix area, rounded to 64 byte boundary */
    lv = (size + 8 + (64-1)) & 0x00FFFFC0;

    /* request storage allocation for the requested subpool */
    __asm__ __volatile__ ("\n*** GETMAIN ***\n\t"
            "GETMAIN RC,LV=(%2),SP=(%3)\n\t"
            "LR\t%0,15              save the return code\n\t"
            "LR\t%1,1               save the returned address"
            : "=r"(rc), "=r"(r1)
            : "r"(lv), "r"(sp)
            : "0", "1", "14", "15");

    if (rc==0) {
        /* clear allocated storage, initialize storage prefix */
    __asm__ __volatile__ ("\n*** Clear Storage ***\n"
"         LR    14,%0           => target (s)\n"
"         LR    15,%1           => length (n)\n"
"         SLR   0,0             => source (NULL)\n"
"         SLR   1,1             => fill 0\n"
"         MVCL  14,0            Set target to fill character"
    : : "r"(r1), "r"(lv) : "0", "1", "14", "15");

        *(unsigned*)(r1+0) = sp << 24 | lv;         /* requested subpool and getmained size */
        *(unsigned*)(r1+4) = pswkey << 24 | size;   /* psw key and caller requested size */
        r1 += 8;                                    /* address returned to caller */
        if (stg) *stg = (void*)r1;
    }

quit:
    return rc;
}

__asm__("\n&FUNC    SETC 'res_freemain'");
static int res_freemain(RESDISP *rd, void *addr)
{
    int             rc          = 0;
    unsigned        size;
    unsigned        lv;
    unsigned        sp;
    unsigned char   pswkey;
    unsigned char   key;

    if (!addr) goto quit;

    addr    = addr - 8;
    sp      = *(unsigned char *)(addr+0);
    lv      = *(unsigned *)(addr+0) & 0x00FFFFFF;
    size    = *(unsigned *)(addr+4) & 0x00FFFFFF;
    key     = *(unsigned *)(addr+4) >> 24;

    /* sanity checks */
    if (!lv || !size) {
        /* possible duplicate freemain */
        /* wtodumpf(addr, 64, "%s duplicate freemain", __func__); */
        return -1;
    }
    if (lv - (size+8) > 64) {
        /* this shouldn't happen since we allocate rounded to 64 bytes */
        /* wtodumpf(addr, 64, "%s check storage prefix", __func__); */
        return -1;
    }

    /* set the PSW key to match the storage key */
    pswkey = res_request_key(rd->res, key);

    /* clear storage we're about to release */
    __asm__ __volatile__("\n*** Clear Storage ***\n"
"         LR    14,%0           => target (s)\n"
"         LR    15,%1           => length (n)\n"
"         SLR   0,0             => source (NULL)\n"
"         SLR   1,1             => fill 0\n"
"         MVCL  14,0            Set target to fill character"
    : : "r"(addr), "r"(lv) : "0", "1", "14", "15");

    /* release allocated storage */
    __asm__ __volatile__("\n*** FREEMAIN ***\n\t"
            "FREEMAIN RC,A=(%1),LV=(%2),SP=(%3)\n\t"
            "LR\t%0,15"
            : "=r"(rc)
            : "r"(addr), "r"(lv), "r"(sp)
            : "0", "1", "14", "15");

    /* reset the PSW key */
    res_request_key(rd->res, pswkey);

quit:
    return rc;
}

__asm__("\n&FUNC    SETC 'res_vsnprintf'");
static int
res_vsnprintf(RESDISP *rd, char *s, int n, const char *format, va_list arg)
{
    return vsnprintf(s, n, format, arg);
}

__asm__("\n&FUNC    SETC 'res_snprintf'");
static int
res_snprintf(RESDISP *rd, char *s, int n, const char *format, ...)
{
    va_list arg;
    int ret;

    va_start(arg, format);
    ret = vsnprintf(s, n, format, arg);
    va_end(arg);
    return (ret);
}

__asm__("\n&FUNC    SETC 'res_sprintf'");
static int
res_sprintf(char *s, const char *format, ...)
{
    va_list arg;
    int ret;

    va_start(arg, format);
    ret = vsnprintf(s, 1024, format, arg);
    va_end(arg);
    return (ret);
}

typedef struct wtomsg {
    short   len;
    short   mcsflags;
    char    buf[128];
} WTOMSG;

static void __inline
wtoline(const WTOMSG *msg)
{
    __asm__ __volatile__("\n*** WTO ***\n\t"
            "LA\t1,0(,%0)\n\t"
            "SVC\t35        WTO"
            : /* no output */
            : "r" (msg));
}

__asm__("\n&FUNC    SETC 'res_wto'");
static void
res_wto(RESDISP *rd, char *buf)
{
    int     len = strlen(buf);
    WTOMSG  msg;

    do {
        if (len <= 124) {
            msg.len = len + 4;
            msg.mcsflags = 0;
            if (len > 0) memcpy(msg.buf, buf, len);
            len = 0;
        }
        else {
            char *p = &buf[124];

            while(*p != ' ' && p > buf) p--;

            if (p==buf) {
                p = &buf[124];  /* no spaces, use 124 characters */
            }
            else if (*p==' ') {
                p++; /* include last space */
            }

            msg.len = (int)(p-buf);     /* length of message segment */
            msg.mcsflags = 0;
            memcpy(msg.buf, buf, msg.len);
            msg.buf[msg.len] = 0;

            /* shift the buffer left and adjust length */
            len -= msg.len;
            if (len > 0) memcpy(buf, p, len);
            buf[len] = 0;
            msg.len += 4;
        }
        wtoline(&msg);
    } while(len > 0);
}

__asm__("\n&FUNC    SETC 'res_vwtof'");
static void
res_vwtof(RESDISP *rd, const char *text, va_list tList)
{
    int     len;
    char    *p;
    char    buf[512];

    len = vsnprintf(buf, sizeof(buf), text, tList);
    if (len >= sizeof(buf)) len = sizeof(buf) - 1;
    buf[len] = 0;

    /* if the buffer is formatted with newlines */
    p = strchr(buf, '\n');
    if (p) {
        while(p) {
            /* truncate at the newline */
            *p++ = 0;
            /* write out the buffer */
            res_wto(rd, buf);
            /* shift everything left */
            strcpy(buf, p);
            /* look for next newline */
            p = strchr(buf, '\n');
        }
        /* done */
        len = strlen(buf);
        if (len==0) return;
    }

    /* no newlines, do normal wto processing */
    buf[len] = 0;
    res_wto(rd, buf);
}

__asm__("\n&FUNC    SETC 'res_wtof'");
static void
res_wtof(RESDISP *rd, const char *text, ...)
{
    va_list tList;

    va_start(tList, text);
    res_vwtof(rd ,text, tList);
    va_end(tList);
}

__asm__("\n&FUNC    SETC 'res_wtodump'");
static void
res_wtodump(RESDISP *rd, const char *title, void *varea, int size, int chunk)
{
    int             indent  = 0;
    int             i, j;
    int             iHex    = 0;
    int             ie      = 0;
    int             x       = (chunk * 2) + ((chunk / 4) - 1);
    unsigned char   *area   = (unsigned char*)varea;
    unsigned char   e;
    char            sHex[80];
    char            eChar[80];

    res_wtof(rd, "%*.*sDump of %08X \"%s\" (%d bytes)\n",
        indent, indent, "",
        area, title, size);

    for (i=0, j=0; size > 0;i++ ) {
        if ( i==chunk ) {
            res_wtof(rd, "%*.*s+%05X %-*.*s :%-*.*s:\n",
                indent, indent, "", j, x, x, sHex, chunk, chunk, eChar);
            j += i;
            ie = iHex = i = 0;
        }
        iHex += res_sprintf(&sHex[iHex], "%02X", *area);
        if ((i & 3) == 3) iHex += res_sprintf(&sHex[iHex], " ");

        e = *area;

        ie += res_sprintf(&eChar[ie], "%c", isgraph(e)?e:e==' '?e:'.');
        area++;
        size--;
    }

    if ( iHex ) {
        res_wtof(rd, "%*.*s+%05X %-*.*s :%-*.*s:\n",
            indent, indent, "", j, x, x, sHex, chunk, chunk, eChar);
    }

quit:
    return;
}

__asm__("\n&FUNC    SETC 'res_wtodumpf'");
static void
res_wtodumpf(RESDISP *rd, void *buf, int len, const char *fmt, ...)
{
    int     rc  = 0;
    va_list list;
    char    title[80];

    va_start(list, fmt);
    vsnprintf(title, sizeof(title), fmt, list);
    va_end(list);

    title[sizeof(title)-1] = 0;

    res_wtodump(rd, title, buf, len, 16);

    return;
}

__asm__("\n&FUNC    SETC 'res_getstack'");
static int res_getstack(RESDISP *rd, unsigned size, void **stg)
{
    if (!size) size = 8192;
    return res_getmain(rd, size, 3, stg);
}

__asm__("\n&FUNC    SETC 'res_freestack'");
static int res_freestack(RESDISP *rd, void *addr)
{
    return res_freemain(rd, addr);
}

/* note: res_enqdeq() is a helper function for various res_lock... functions */
__asm__("\n&FUNC    SETC 'res_enqdeq'");
static int res_enqdeq(const char *qn, const char *rn, unsigned options, int deq)
{
    ENQPL       pl      = {0};
    int         err     = 1;
    int         len;
    char        qname[8];

    if (!qn || !rn) goto quit;

    len = strlen(rn);
    if (!len) goto quit;

    pl.end = ENQ_END_LAST | ENQ_END_OLD;
    pl.len = (unsigned char)len;

    for(len=0; len<8 && qn[len]; len++) {
        qname[len] = qn[len];
    }
    while(len < 8) qname[len++] = ' ';
    pl.qname = qname;

    pl.rname = (char*)rn;

    switch(options & ENQ_SCOPE) {
    case ENQ_SYSTEMS:   pl.opt |= ENQ_OPT_SYSTEMS;  break;
    case ENQ_SYSTEM:    pl.opt |= ENQ_OPT_SYSTEM;   break;
    default:            break;      /* default is STEP                  */
    }

    if (deq) {
        pl.opt = ENQ_OPT_HAVE;
        __asm__ __volatile__(
            "DS\t0H       Request DEQ\n\t"
            "LA\t1,%0\n\t"
            "SVC\t48       DEQ" : : "m"(pl) : "0", "1", "15");
    }
    else {
        if (options & ENQ_SHR) pl.opt |= ENQ_OPT_SHARED;
        switch(options & ENQ_RET) {
        case ENQ_TEST:      pl.opt |= ENQ_OPT_TEST;     break;
        case ENQ_USE:       pl.opt |= ENQ_OPT_USE;      break;
        case ENQ_CHNG:      pl.opt |= ENQ_OPT_CHNG;     break;
        default:            pl.opt |= ENQ_OPT_HAVE;     break;
        }
        __asm__ __volatile__(
            "DS\t0H       Request ENQ\n\t"
            "LA\t1,%0\n\t"
            "SVC\t56       ENQ" : : "m"(pl) : "0", "1", "15");
    }

    err = pl.rc;

quit:
    return err;
}

__asm__("\n&FUNC    SETC 'res_step_lock'");
static int res_step_lock(RESDISP *rd, void *thing, int read)
{
    unsigned    opts    = ENQ_HAVE;
    char        rname[LOCKRNAMESZ];

    if (read) opts |= ENQ_SHR;

    res_snprintf(rd, rname, sizeof(rname), LOCKRNAME, thing);

    return res_enqdeq(LOCKQNAME, rname, opts, 0);
}

__asm__("\n&FUNC    SETC 'res_step_unlock'");
static int res_step_unlock(RESDISP *rd, void *thing, int read)
{
    unsigned    opts    = ENQ_HAVE;
    char        rname[LOCKRNAMESZ];

    res_snprintf(rd, rname, sizeof(rname), LOCKRNAME, thing);

    return res_enqdeq(LOCKQNAME, rname, opts, 1);
}

__asm__("\n&FUNC    SETC 'res_system_lock'");
static int res_system_lock(RESDISP *rd, void *thing, int read)
{
    unsigned    opts    = ENQ_SYSTEM | ENQ_HAVE;
    char        rname[SYSLOCKRNAMESZ];

    if (read) opts |= ENQ_SHR;

    res_snprintf(rd, rname, sizeof(rname), SYSLOCKRNAME, thing);

    return res_enqdeq(SYSLOCKQNAME, rname, opts, 0);
}

__asm__("\n&FUNC    SETC 'res_system_unlock'");
static int res_system_unlock(RESDISP *rd, void *thing, int read)
{
    unsigned    opts    = ENQ_SYSTEM | ENQ_HAVE;
    char        rname[SYSLOCKRNAMESZ];

    res_snprintf(rd, rname, sizeof(rname), SYSLOCKRNAME, thing);

    return res_enqdeq(SYSLOCKQNAME, rname, opts, 1);
}

/* static resident function table */
static RESFUNC resfunc[] = {
    RESFUNC_GETMAIN,        /* 0x00 */
    RESFUNC_FREEMAIN,       /* 0x01 */
    RESFUNC_WTO,            /* 0x02 */
    RESFUNC_WTOF,           /* 0x03 */
    RESFUNC_VWTOF,          /* 0x04 */
    RESFUNC_VSNPRINTF,      /* 0x05 */
    RESFUNC_SNPRINTF,       /* 0x06 */
    RESFUNC_WTODUMP,        /* 0x07 */
    RESFUNC_GETSTACK,       /* 0x08 */
    RESFUNC_FREESTACK,      /* 0x09 */
    RESFUNC_STEP_LOCK,      /* 0x0A */
    RESFUNC_STEP_UNLOCK,    /* 0x0B */
    RESFUNC_SYSTEM_LOCK,    /* 0x0C */
    RESFUNC_SYSTEM_UNLOCK,  /* 0x0D */
};

/* returns resident function table address and number of functions in table */
__asm__("\n&FUNC    SETC 'resident'");
unsigned resident(RESFUNC **func, unsigned *funcs)
{
    unsigned    size    = sizeof(resfunc) / sizeof(resfunc[0]);

    if (func)   *func   = &resfunc[0];
    if (funcs)  *funcs  = size;

    return size;
}
