#ifndef CLIBRES_H
#define CLIBRES_H

#include <stdarg.h>
#include <string.h>
#include <ctype.h>

#include <clibenq.h>
#include <cliblock.h>
#include <clibsvc.h>

/*
** C library resident structs and prototypes
**
*/
typedef struct res          RES;
typedef struct resdisp      RESDISP;
typedef struct resfunc      RESFUNC;

struct res {
    char            prolog[8];              /* 00 dispatcher prolog             */
    void            *disp;                  /* 08 dispatcher function address   */
    char            svcstub[4];             /* 0C   SVC nnn     invoke SVC      */
                                            /* ...  BR  R14     return to caller*/
#define RES_SVCSTUB "\x0A\x00\x07\xFE"      /* ...  initialization code         */
    char            eye[8];                 /* 10 eye catcher                   */
#define RES_EYE     "**RES**"               /* ... eye catcher                  */
    void            *funclp;                /* 18 function array load point     */
    RESFUNC         *func;                  /* 1C array of resident functions   */
    unsigned        funcs;                  /* 20 number of resident functions  */
    void            *afunclp;               /* 24 app function load point       */
    RESFUNC         *afunc;                 /* 28 array of application functions*/
    unsigned        afuncs;                 /* 2C number of application function*/
    void            *ressvc;                /* 30 resident supervisor call      */
    unsigned        ressvctype;             /* 34 resident supervisor type      */
    void            *oldsvc;                /* 38 old SVC address               */
    unsigned        oldsvctype;             /* 3C old SVC type                  */
    void            *ssvt;                  /* 40 associated subsystem          */
    unsigned        unused[3];              /* 44 unused                        */
    void            *appl1;                 /* 50 for use by application        */
    void            *appl2;                 /* 54 for use by application        */
    void            *appl3;                 /* 58 for use by application        */
    void            *appl4;                 /* 5C for use by application        */
};                                          /* 60 (96 bytes)                    */

struct resdisp {
    char            eye[8];                 /* 00 eye catcher                   */
#define RESDISP_EYE "*RESDISP"              /* ... eye catcher                  */
    RES             *res;                   /* 08 resident handle               */
    RESFUNC         *resfunc;               /* 0C function handle               */
    unsigned char   caller_sup;             /* 10 caller in supervisor state    */
    unsigned char   caller_key;             /* 11 caller PSW key                */
    unsigned char   disp_sup;               /* 12 dispatched in supervisor state*/
    unsigned char   disp_key;               /* 13 dispatched in PSW key         */
    unsigned        unused1;                /* 14 unused                        */
    unsigned        unused2;                /* 18 unused                        */
    unsigned        unused3;                /* 1C unused                        */
};                                          /* 20 (32 bytes)                    */

struct resfunc {
    unsigned char   flags;                  /* 00 resident function flags       */
#define RESSUP      0x80                    /* ... switch to supervisor state   */
#define RESPROB     0x40                    /* ... switch to problem state      */
#define RESKEY0     0x20                    /* ... switch to PSW key 0          */
#define RESKEYU     0x10                    /* ... switch to user key           */
#define RESSTACK    0x08                    /* ... allocate a new stack frame   */
    unsigned char   stack_size_k;           /* 01 new stack size Kbytes         */
    unsigned short  fn;                     /* 02 function number               */
    void            *func;                  /* 04 function address              */
};

/* resident function numbers (0x00-0xFF) */
#define RES_GETMAIN         0x00            /* resident GETMAIN                 */
#define RESFUNC_GETMAIN { 0, 0, RES_GETMAIN, res_getmain }

#define RES_FREEMAIN        0x01            /* resident FREEMAIN                */
#define RESFUNC_FREEMAIN { 0, 0, RES_FREEMAIN, res_freemain }

#define RES_WTO             0x02            /* resident WTO                     */
#define RESFUNC_WTO { 0, 0, RES_WTO, res_wto }

#define RES_WTOF            0x03            /* resident WTOF                    */
#define RESFUNC_WTOF { 0, 0, RES_WTOF, res_wtof }

#define RES_VWTOF           0x04            /* resident VWTOF                   */
#define RESFUNC_VWTOF { 0, 0, RES_VWTOF, res_vwtof }

#define RES_VSNPRINTF       0x05            /* resident VSNPRINTF               */
#define RESFUNC_VSNPRINTF { 0, 0, RES_VSNPRINTF, res_vsnprintf }

#define RES_SNPRINTF        0x06            /* resident SNPRINTF                */
#define RESFUNC_SNPRINTF { 0, 0, RES_SNPRINTF, res_snprintf }

#define RES_WTODUMP         0x07            /* resident WTODUMP                 */
#define RESFUNC_WTODUMP { 0, 0, RES_WTODUMP, res_wtodump }

#define RES_GETSTACK        0x08            /* resident GETSTACK                */
#define RESFUNC_GETSTACK { RESPROB | RESKEYU, 0, RES_GETSTACK, res_getstack }

#define RES_FREESTACK       0x09            /* resident FREESTACK               */
#define RESFUNC_FREESTACK { RESPROB | RESKEYU, 0, RES_FREESTACK, res_freestack }

#define RES_STEP_LOCK       0x0A            /* resident STEP_LOCK               */
#define RESFUNC_STEP_LOCK { 0, 0, RES_STEP_LOCK, res_step_lock }

#define RES_STEP_UNLOCK     0x0B            /* resident STEP_UNLOCK             */
#define RESFUNC_STEP_UNLOCK { 0, 0, RES_STEP_UNLOCK, res_step_unlock }

#define RES_SYSTEM_LOCK     0x0C            /* resident SYSTEM_LOCK             */
#define RESFUNC_SYSTEM_LOCK { RESSUP | RESKEY0, 0, RES_SYSTEM_LOCK, res_system_lock }

#define RES_SYSTEM_UNLOCK   0x0D            /* resident SYSTEM_UNLOCK           */
#define RESFUNC_SYSTEM_UNLOCK { RESSUP | RESKEY0, 0, RES_SYSTEM_UNLOCK, res_system_unlock }

/* application function numbers (0x100-0x1FF) */


static __inline int res_request_sup(RES *res)
{
    int     rc;

    __asm__ __volatile__("\n*** SVCMAIN_SUP REQUEST ***");
    __asm__ __volatile__(
        "SLR\tR0,R0         R0 parm\n\t"
        "LR\tR1,%2          request code\n\t"
        "BALR\tR14,%1       call SVC stub\n\t"
        "LR\t%0,R15         save return code"
        : "=r"(rc) : "r"(res->svcstub), "r"(SVCMAIN_SUP) : "0", "1", "14", "15");

    /* rc==0 caller was in problem state before call
    ** rc!=0 caller was already in supervisor state before call
    */
    return rc;
}

static __inline int res_request_prob(RES *res)
{
    int     rc;

    __asm__ __volatile__("\n*** SVCMAIN_PROB REQUEST ***");
    __asm__ __volatile__(
        "SLR\tR0,R0         R0 parm\n\t"
        "LR\tR1,%2          request code\n\t"
        "BALR\tR14,%1       call SVC stub\n\t"
        "LR\t%0,R15         save return code"
        : "=r"(rc) : "r"(res->svcstub), "r"(SVCMAIN_PROB) : "0", "1", "14", "15");

    /* rc==0 caller was in supervisor state before call
    ** rc!=0 caller was already in problem state before call
    */
    return rc;
}

static __inline int res_request_key(RES *res, unsigned char pswkey)
{
    int     rc;

    __asm__ __volatile__("\n*** SVCMAIN_KEY REQUEST ***");
    __asm__ __volatile__(
        "LR\tR15,%3         new pswkey\n\t"
        "SLR\tR0,R0         R0 parm\n\t"
        "LR\tR1,%2          request code\n\t"
        "BALR\tR14,%1       call SVC stub\n\t"
        "LR\t%0,R15         save old psw key"
        : "=r"(rc) : "r"(res->svcstub), "r"(SVCMAIN_KEY), "r"(pswkey) : "0", "1", "14", "15");

    /* rc==previous psw key */
    return rc;
}

static __inline int res_request_authon(RES *res)
{
    int     rc;

    __asm__ __volatile__("\n*** SVCMAIN_AUTHON REQUEST ***");
    __asm__ __volatile__(
        "SLR\tR0,R0         R0 parm\n\t"
        "LR\tR1,%2          request code\n\t"
        "BALR\tR14,%1       call SVC stub\n\t"
        "LR\t%0,R15         save return code"
        : "=r"(rc) : "r"(res->svcstub), "r"(SVCMAIN_AUTHON) : "0", "1", "14", "15");

    /* rc==0 caller was not authorized before call
    ** rc!=0 caller was already authorized before call
    */
    return rc;
}

static __inline int res_request_authoff(RES *res)
{
    int     rc;

    __asm__ __volatile__("\n*** SVCMAIN_AUTHOFF REQUEST ***");
    __asm__ __volatile__(
        "SLR\tR0,R0         R0 parm\n\t"
        "LR\tR1,%2          request code\n\t"
        "BALR\tR14,%1       call SVC stub\n\t"
        "LR\t%0,R15         save return code"
        : "=r"(rc) : "r"(res->svcstub), "r"(SVCMAIN_AUTHOFF) : "0", "1", "14", "15");

    /* rc==0 caller was authorized before call
    ** rc!=0 caller was not authorized before call
    */
    return rc;
}

static __inline int res_request_state(void)
{
    int     rc;

    __asm__ __volatile__("\n*** ARE WE IN SUPERVISOR STATE ***");
    __asm__ __volatile__(
        "TESTAUTH FCTN=0,STATE=YES,KEY=NO,RBLEVEL=1,BRANCH=NO\n\t"
        "LR\t%0,R15     R15==0 is supervisor state" : "=r"(rc) : : "0", "1", "14", "15");

    return rc;  /* rc==0 in supervisor state, rc!=0 in problem state */
}

static __inline int res_request_issup(void)
{
    /* res_request_state() == 0 is supervisor, otherwise problem state */
    return !res_request_state();
}

static __inline int res_request_isprob(void)
{
    return res_request_state();
}

static __inline void *res_request_getmain(RES *res, unsigned size, unsigned sp)
{
    __asm__ __volatile__("\n*** REQUEST GETMAIN ***");
    int     rc;
    void    *stg    = 0;
    __volatile__ struct {
        unsigned    fn;
        unsigned    size;
        unsigned    sp;
        void        **stg;
    } plist = { RES_GETMAIN, size, sp, &stg };

    __asm__ __volatile__(
        "LR\tR15,%1         => resident address\n\t"
        "LA\tR1,%2          => parameter list\n\t"
        "BALR\tR14,R15      call dispatcher\n\t"
        "LR\t%0,R15         save return code"
        : "=r"(rc) : "r"(res), "m"(plist) : "0", "1", "14", "15");

    if (rc!=0) return 0;
    return (void*)*(plist.stg);
}

static __inline int res_request_freemain(RES *res, void *stg)
{
    __asm__ __volatile__("\n*** REQUEST FREEMAIN ***");
    int     rc;
    __volatile__ struct {
        unsigned    fn;
        void        *stg;
    } plist = { RES_FREEMAIN, stg };

    __asm__ __volatile__(
        "LR\tR15,%1         => resident address\n\t"
        "LA\tR1,%2          => parameter list\n\t"
        "BALR\tR14,R15      call dispatcher\n\t"
        "LR\t%0,R15         save return code"
        : "=r"(rc) : "r"(res), "m"(plist) : "0", "1", "14", "15");

    return rc;
}

static __inline int res_request_wto(RES *res, const char *buf)
{
    __asm__ __volatile__("\n*** REQUEST WTO ***");
    __volatile__ struct {
        unsigned    fn;
        const char  *buf;
    } plist = { RES_WTO, buf };

    __asm__ __volatile__(
        "LR\tR15,%1         => resident address\n\t"
        "LA\tR1,%2          => parameter list\n\t"
        "BALR\tR14,R15      call dispatcher\n\t"
        : : "r"(res), "m"(plist) : "0", "1", "14", "15");

    return 0;
}

static __inline int res_request_wtof(RES *res, const char *buf, ...)
{
    __asm__ __volatile__("\n*** REQUEST VWTOF for WTOF ***");
    __volatile__ struct {
        unsigned    fn;
        const char  *buf;
        va_list     tlist;
    } plist = { RES_VWTOF, buf };

    va_start(plist.tlist, buf);

    __asm__ __volatile__(
        "LR\tR15,%1         => resident address\n\t"
        "LA\tR1,%2          => parameter list\n\t"
        "BALR\tR14,R15      call dispatcher\n\t"
        : : "r"(res), "m"(plist) : "0", "1", "14", "15");

    va_end(plist.tlist);

    return 0;
}

static __inline int res_request_vsnprintf(RES *res, char *s, int n, const char *fmt, va_list arg)
{
    __asm__ __volatile__("\n*** REQUEST VSNPRINTF ***");
    int             rc;
    __volatile__ struct {
        unsigned    fn;
        char        *s;
        int         n;
        const char  *fmt;
        va_list     arg;
    } plist = { RES_VSNPRINTF, s, n, fmt, arg };

    __asm__ __volatile__(
        "LR\tR15,%1         => resident address\n\t"
        "LA\tR1,%2          => parameter list\n\t"
        "BALR\tR14,R15      call dispatcher\n\t"
        "LR\t%0,R15         save return code"
        : "=r"(rc) : "r"(res), "m"(plist) : "0", "1", "14", "15");

    return rc;
}

static __inline int res_request_snprintf(RES *res, char *s, int n, const char *fmt, ...)
{
    __asm__ __volatile__("\n*** REQUEST VSNPRINTF for SNPRINTF ***");
    int             rc;
    __volatile__ struct {
        unsigned    fn;
        char        *s;
        int         n;
        const char  *fmt;
        va_list     arg;
    } plist = { RES_VSNPRINTF, s, n, fmt };

    va_start(plist.arg, fmt);

    __asm__ __volatile__(
        "LR\tR15,%1         => resident address\n\t"
        "LA\tR1,%2          => parameter list\n\t"
        "BALR\tR14,R15      call dispatcher\n\t"
        "LR\t%0,R15         save return code"
        : "=r"(rc) : "r"(res), "m"(plist) : "0", "1", "14", "15");

    va_end(plist.arg);

    return rc;
}

static __inline int res_request_wtodump(RES *res, const char *title, void *varea, int size, int chunk)
{
    __asm__ __volatile__("\n*** REQUEST WTODUMP ***");
    __volatile__ struct {
        unsigned    fn;
        const char  *title;
        void        *varea;
        int         size;
        int         chunk;
    } plist = { RES_WTODUMP, title, varea, size, chunk };

    __asm__ __volatile__(
        "LR\tR15,%1         => resident address\n\t"
        "LA\tR1,%2          => parameter list\n\t"
        "BALR\tR14,R15      call dispatcher\n\t"
        : : "r"(res), "m"(plist) : "0", "1", "14", "15");

    return 0;
}

static __inline int res_request_wtodumpf(RES *res, void *buf, int len, const char *fmt, ...)
{
    __asm__ __volatile__("\n*** REQUEST WTODUMP for WTODUMPF ***");
    va_list list;
    char    title[80];
    __volatile__ struct {
        unsigned    fn;
        const char  *title;
        void        *varea;
        int         size;
        int         chunk;
    } plist = { RES_WTODUMP, title, buf, len, 16 };

    va_start(list, fmt);
    res_request_vsnprintf(res ,title, sizeof(title), fmt, list);
    va_end(list);

    title[sizeof(title)-1] = 0;

    __asm__ __volatile__(
        "LR\tR15,%1         => resident address\n\t"
        "LA\tR1,%2          => parameter list\n\t"
        "BALR\tR14,R15      call dispatcher\n\t"
        : : "r"(res), "m"(plist) : "0", "1", "14", "15");

    return 0;
}

static __inline void *res_request_getstack(RES *res, unsigned size)
{
    __asm__ __volatile__("\n*** REQUEST GETSTACK ***");
    int     rc;
    void    *stg    = 0;
    __volatile__ struct {
        unsigned    fn;
        unsigned    size;
        void        **stg;
    } plist = { RES_GETSTACK, size, &stg };

    __asm__ __volatile__(
        "LR\tR15,%1         => resident address\n\t"
        "LA\tR1,%2          => parameter list\n\t"
        "BALR\tR14,R15      call dispatcher\n\t"
        "LR\t%0,R15         save return code"
        : "=r"(rc) : "r"(res), "m"(plist) : "0", "1", "14", "15");

    if (rc!=0) return 0;
    return (void*)*(plist.stg);
}

static __inline int res_request_freestack(RES *res, void *stg)
{
    __asm__ __volatile__("\n*** REQUEST FREESTACK ***");
    int     rc;
    __volatile__ struct {
        unsigned    fn;
        void        *stg;
    } plist = { RES_FREESTACK, stg };

    __asm__ __volatile__(
        "LR\tR15,%1         => resident address\n\t"
        "LA\tR1,%2          => parameter list\n\t"
        "BALR\tR14,R15      call dispatcher\n\t"
        "LR\t%0,R15         save return code"
        : "=r"(rc) : "r"(res), "m"(plist) : "0", "1", "14", "15");

    return rc;
}

static __inline int res_request_step_lock(RES *res, void *stg, int read)
{
    __asm__ __volatile__("\n*** REQUEST STEP LOCK ***");
    int     rc;
    __volatile__ struct {
        unsigned    fn;
        void        *stg;
        int         read;
    } plist = { RES_STEP_LOCK, stg, read };

    __asm__ __volatile__(
        "LR\tR15,%1         => resident address\n\t"
        "LA\tR1,%2          => parameter list\n\t"
        "BALR\tR14,R15      call dispatcher\n\t"
        "LR\t%0,R15         save return code"
        : "=r"(rc) : "r"(res), "m"(plist) : "0", "1", "14", "15");

    return rc;
}

static __inline int res_request_step_unlock(RES *res, void *stg, int read)
{
    __asm__ __volatile__("\n*** REQUEST STEP UNLOCK ***");
    int     rc;
    __volatile__ struct {
        unsigned    fn;
        void        *stg;
        int         read;
    } plist = { RES_STEP_UNLOCK, stg, read };

    __asm__ __volatile__(
        "LR\tR15,%1         => resident address\n\t"
        "LA\tR1,%2          => parameter list\n\t"
        "BALR\tR14,R15      call dispatcher\n\t"
        "LR\t%0,R15         save return code"
        : "=r"(rc) : "r"(res), "m"(plist) : "0", "1", "14", "15");

    return rc;
}

static __inline int res_request_system_lock(RES *res, void *stg, int read)
{
    __asm__ __volatile__("\n*** REQUEST SYSTEM LOCK ***");
    int     rc;
    __volatile__ struct {
        unsigned    fn;
        void        *stg;
        int         read;
    } plist = { RES_SYSTEM_LOCK, stg, read };

    __asm__ __volatile__(
        "LR\tR15,%1         => resident address\n\t"
        "LA\tR1,%2          => parameter list\n\t"
        "BALR\tR14,R15      call dispatcher\n\t"
        "LR\t%0,R15         save return code"
        : "=r"(rc) : "r"(res), "m"(plist) : "0", "1", "14", "15");

    return rc;
}

static __inline int res_request_system_unlock(RES *res, void *stg, int read)
{
    __asm__ __volatile__("\n*** REQUEST SYSTEM UNLOCK ***");
    int     rc;
    __volatile__ struct {
        unsigned    fn;
        void        *stg;
        int         read;
    } plist = { RES_SYSTEM_UNLOCK, stg, read };

    __asm__ __volatile__(
        "LR\tR15,%1         => resident address\n\t"
        "LA\tR1,%2          => parameter list\n\t"
        "BALR\tR14,R15      call dispatcher\n\t"
        "LR\t%0,R15         save return code"
        : "=r"(rc) : "r"(res), "m"(plist) : "0", "1", "14", "15");

    return rc;
}

#endif /* CLIBRES_H */
