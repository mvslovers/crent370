#include <clib.h>
#include <clibos.h>
#include <clibwto.h>
#include <clibstr.h>

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

__asm__("\n&FUNC    SETC 'getmain'");
void *getmain(unsigned size, unsigned sp)
{
    int             rc          = 0;
    void            *r1         = (void*)0;
    unsigned        lv;
    unsigned char   pswkey;

    if (!size) return (void*)0;             /* no size, fail    */
    if (size > 0x00FFFFFF) return (void*)0; /* too large, fail  */

    /* are we executing in supervisor state? */
    if (__issup()) {
        /* yes, get the PSW key */
        __asm__("IPK\t0             get psw key in R2\n\t"
                "STC\t2,0(,%0)      save psw key" : : "r"(&pswkey) : "2");
    }
    else {
        unsigned        *psa        = 0;                            /* low core == PSA      */
        void            *tcb        = (void*)psa[0x21c/4];          /* TCB      == PSATOLD  */
        unsigned char   tcbpkf      = *(unsigned char*)(tcb+0x1C);  /* TCBPKF               */

        pswkey = tcbpkf;
    }

    sp &= 0x000000FF;                       /* SP range 0-255 */

    /* calc length value including prefix area, rounded to 64 byte boundary */
    lv = (size + 8 + (64-1)) & 0x00FFFFC0;

    /* request storage allocation for the requested subpool */
    __asm__("GETMAIN RC,LV=(%2),SP=(%3)\n\t"
            "LR\t%0,15              save the return code\n\t"
            "LR\t%1,1               save the returned address"
            : "=r"(rc), "=r"(r1)
            : "r"(lv), "r"(sp)
            : "0", "1", "14", "15");

    if (rc) {
        wtof("%s request for %u bytes from sp=%u failed, rc=0x%02X (%d)", __func__, lv, sp, rc, rc);
        r1 = (void*)0;
    }
    else {
        /* clear allocated storage, initialize storage prefix */
        memclr(r1, lv);
        *(unsigned*)(r1+0) = sp << 24 | lv;         /* requested subpool and getmained size */
        *(unsigned*)(r1+4) = pswkey << 24 | size;   /* psw key and caller requested size */
        r1 += 8;                                    /* address returned to caller */
    }

quit:
    return (void*)r1;
}

__asm__("\n&FUNC    SETC 'freemain'");
int freemain(void *addr)
{
    int             rc          = 0;
    unsigned        size;
    unsigned        lv;
    unsigned        sp;

    if (!addr) goto quit;

    addr    = addr - 8;
    sp      = *(unsigned char *)(addr+0);
    lv      = *(unsigned *)(addr+0) & 0x00FFFFFF;
    size    = *(unsigned *)(addr+4) & 0x00FFFFFF;

    /* sanity checks */
    if (!lv || !size) {
        /* possible duplicate freemain */
        wtodumpf(addr, 64, "%s duplicate freemain", __func__);
        return -1;
    }
    if (lv - (size+8) > 64) {
        /* this shouldn't happen since we allocate rounded to 64 bytes */
        wtodumpf(addr, 64, "%s check storage prefix", __func__);
        return -1;
    }

    /* clear storage we're about to release */
    __asm__("\n"
"         LR    14,%0           => target (s)\n"
"         LR    15,%1           => length (n)\n"
"         SLR   0,0             => source (NULL)\n"
"         SLR   1,1             => fill 0\n"
"         MVCL  14,0            Set target to fill character"
    : : "r"(addr), "r"(lv) : "0", "1", "14", "15");

    /* release allocated storage */
    __asm__("FREEMAIN RC,A=(%1),LV=(%2),SP=(%3)\n\t"
            "LR\t%0,15"
            : "=r"(rc)
            : "r"(addr), "r"(lv), "r"(sp)
            : "0", "1", "14", "15");

quit:
    return rc;
}

#if 0
int main(int argc, char **argv)
{
    int     rc;
    void    *a  = getmain(20, 0);

    if (a) {
        wtodumpf(a-8, 20+8, "GETMAINED");
        rc = freemain(a);
        wtof("freemain %08X rc=%d", a, rc);
    }

    clib_apf_setup(argv[0]);

    a = (void*) super_do(getmain ,56 , 241);
    if (a) {
        wtodumpf(a-8, 56+8, "GETMAINED 8");
        rc = super_do(freemain, a);
        wtof("freemain %08X rc=%d", a, rc);
    }

    a = (void*) super_key_do(PSWKEY0, getmain, 56, 241);
    if (a) {
        wtodumpf(a-8, 56+8, "GETMAINED 0");
        rc = super_key_do(PSWKEY0, freemain, a);
        wtof("freemain %08X rc=%d", a, rc);
    }

    return 0;
}
#endif

/* __asm__("CVT DSECT=YES,LIST=YES"); */
 __asm__("IKJTCB DSECT=YES,LIST=YES");
