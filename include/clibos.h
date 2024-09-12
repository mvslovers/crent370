#ifndef CLIBOS_H
#define CLIBOS_H
#include <cde.h>
#include <clibwto.h>

typedef struct bldl         BLDL;       /* BLDL list                    */
typedef struct de12         DE12;       /* minimum dir entry            */
typedef struct de14         DE14;       /* a little more dir entry info */
typedef struct de76         DE76;       /* dir entry with user data     */

struct de12 {
    char            name[8];            /* name, space filled           */
    char            ttr[3];             /* ttr                          */
    char            k;                  /* concatenation number         */
} __attribute__((packed));

struct de14 {
    char            name[8];            /* name, space filled           */
    char            ttr[3];             /* ttr                          */
    char            k;                  /* concatenation number         */
    char            z;                  /* where found                  */
#define DE_PRIVATE  0                   /* ... private library          */
#define DE_LINK     1                   /* ... link library             */
#define DE_JOB      2                   /* ... job, task or step library*/
/* > 2 job, step or library of parents task n, where n = z - 2 */
    char            c;                  /* type, ttrn's and udata length*/
#define DE_ALIAS    0x80                /* name is an alias             */
#define DE_TTRNS    0x60                /* ttrns, 0x20=1, 0x40=2, 0x60=3*/
#define DE_UDATA    0x1F                /* #udata in half words         */
} __attribute__((packed));

struct de76 {
    char            name[8];            /* name, space filled           */
    char            ttr[3];             /* ttr                          */
    char            k;                  /* concatenation number         */
    char            z;                  /* where found                  */
    char            c;                  /* type, ttrn's and udata length*/
    char            udata[62];          /* user data                    */
} __attribute__((packed));

struct bldl {
    short           ff;                 /* number of DEnn structs       */
    short           ll;                 /* length of each DEnn struct   */
    union {
        DE12        de12[1];            /* 12 byte dir entry            */
        DE14        de14[1];            /* 14 byte dir entry            */
        DE76        de76[1];            /* 76 byte dir entry            */
    };
} __attribute__((packed));

/* __bldl() search for member in dcb or default link libraries when dcb is NULL */
int __bldl(BLDL *bldl, void *dcb);

/* __cs() compare and swap in new_value to memory, returns old_value */
unsigned __cs(void *mem, unsigned new_value);

/* __uinc() unsigned increment of memory, returns old value, wraps new value to 0 if old value is max unsigned */
unsigned __uinc(void *mem);

/* __udec() unsigned decrement of memory, returns old value, wraps new value to max unsigned if old value is 0 */
unsigned __udec(void *mem);

/* __inc() signed increment of memory, returns old value, wraps new value to 0 if old value is max signed */
int __inc(void *mem);

/* __dec() signed decrement of memory, returns old value, wraps new value to max signed if old value is min signed */
int __dec(void *mem);

/* __ascb() get ASCB for ASID, or current ASCB if 0 */
void *__ascb(unsigned asid);

/* __xmpost() POST ECB with postcode in address space for ascb */
void __xmpost(void *ascb, void *ecb, unsigned postcode);

/* __super() set supervisor mode and set PSW key, must be APF auth first */
/* returns error code if not APF authorized */
int __super(unsigned char pswkey, unsigned char *savekey);
#define PSWKEY0     0x00    /* key 0  0000 .... */
#define PSWKEY1     0x10    /* key 1  0001 .... */
#define PSWKEY2     0x20    /* key 2  0010 .... */
#define PSWKEY3     0x30    /* key 3  0011 .... */
#define PSWKEY4     0x40    /* key 4  0100 .... */
#define PSWKEY5     0x50    /* key 5  0101 .... */
#define PSWKEY6     0x60    /* key 6  0110 .... */
#define PSWKEY7     0x70    /* key 7  0111 .... */
#define PSWKEY8     0x80    /* key 8  1000 .... */
#define PSWKEY9     0x90    /* key 9  1001 .... */
#define PSWKEY10    0xA0    /* key 10 1010 .... */
#define PSWKEY11    0xB0    /* key 11 1011 .... */
#define PSWKEY12    0xC0    /* key 12 1100 .... */
#define PSWKEY13    0xD0    /* key 13 1101 .... */
#define PSWKEY14    0xE0    /* key 14 1110 .... */
#define PSWKEY15    0xF0    /* key 15 1111 .... */
#define PSWKEYNONE  0xFF    /* don't change PSW key */

/* __pswkey() get current PSW key, must be APF auth first */
/* returns error code if not APF authorized */
int __pswkey(unsigned char *savekey);

/* __prob() set problem mode (non-supervisor) and set PSW key, must be APF auth first */
/* returns error code if not APF authorized */
int __prob(unsigned char pswkey, unsigned char *savekey);

/* __isauth() returns true if APF authorized AC(1), false if not APF authorized */
int __isauth(void);

/* __issup() returns true if in supervisor mode, false if not in supervisor mode */
int __issup(void);

/* __call() call func with plist value as R1, returns func return code as int */
int __call(void *func, void *plist);

/* __sudo() - switch to super state, call function, return to previous state, return func return code as int */
int __sudo(void *func, ...);
int super_do(void *func, ...) asm("@@SUDO");

/* __sukydo() - switch to super state, switch to pswkey, call function, return to previous key and state, return func return code as int */
int __sukydo(unsigned char pswkey, void *func, ...);
int super_key_do(unsigned char pswkey, void *func, ...) asm("@@SUKYDO");

/* getmain() returns allocated storage of size in requested subpool or NULL */
/* request with SP > 127 require the caller to be in supervisor state */
void *getmain(unsigned size, unsigned sp);

/* freemain() release storage allocated by getmain() function */
int freemain(void *addr);

/* __steplb() - returns DCB address or NULL for STEPLIB DD */
void *__steplb(void) asm("@@STEPLB");

/* clib_apf_setup() - make this task and steplib APF authorized */
int clib_apf_setup(const char *pgm)                         asm("@@APFSET");

/* clib_find_cde() - find CDE entry for program name */
CDE *clib_find_cde(const char *name)                        asm("@@FNDCDE");

/* clib_auth_cde() - make CDE entry APF authorized AC(1) */
int clib_auth_cde(CDE *cde)                                 asm("@@AUTCDE");

/* clib_auth_name() - find CDE for program name and make APF authorized AC(1) */
int clib_auth_name(const char *name)                        asm("@@AUTNAM");

/* clib_identify_cthread() - find CDE for CTHREAD program and make APF authorized AC(1) */
int clib_identify_cthread(void)                             asm("@@IDECTH");

/* __load() - bring load module into storage returning the entry point or 0 for failure */
/* also returns size and access code value if not NULL */
/* dcb value can be NULL to search all possible locations, linklib, tasklib, steplib */
void *__load(void *dcb, const char *module, unsigned *size, char *ac) asm("@@LOAD");

/* __delete() - remove module from storage, return 0 on success, 4 if not found */
int __delete(const char *module);

/* __loadhi() - load module into high memory (CSA subpool 241) */
/* returns 0 on success, 4 if failure (wto messages may be issued) */
/* notes:
**  The load module is loaded and read from the STEPLIB dataset only.
**  The caller must be APF authorized and key zero to use __loadhi().
**  If authorized but not in key zero use:
**      super_key_do(PSWKEY0, __loadhi, module, &lpa, &epa, &size).
*/
int __loadhi(const char *module, void **lpa, void **epa, unsigned *size) asm("@@LOADHI");

#endif /* !CLIBOS_H */
