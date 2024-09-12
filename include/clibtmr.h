#ifndef CLIBTMR_H
#define CLIBTMR_H

#include <errno.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <float.h>
#include <socket.h> /* has struct timeval */

#include <clibary.h>
#include <clibcrt.h>
#include <clibecb.h>
#include <clibgrt.h>
#include <cliblock.h>
#include <clibppa.h>
#include <clibsa.h>
#include <clibstae.h>
#include <clibthrd.h>
#include <clibwsa.h>
#include <clibwto.h>

typedef struct tmr          TMR;            /* timer instance                       */
typedef struct tqe          TQE;            /* timer queue element                  */
typedef double              TMRSEC;         /* timer seconds                        */
typedef unsigned int        TQEID;          /* timer queue element id               */

struct tmr {
    char            eye[8];                 /* 00 eye catcher for dumps             */
#define TMR_EYE     "**TMR**"               /* ... eye catcher for dumps            */
    char            flags;                  /* 08 processing flags                  */
#define TMR_FLAG_INIT           0x80        /* ... timer handle initialized         */
#define TMR_FLAG_RUNNING        0x40        /* ... timer thread running             */
#define TMR_FLAG_QUIESCE        0x20        /* ... timer thread should terminate    */
#define TMR_FLAG_SHUTDOWN       0x10        /* ... timer thread must terminate      */
    char            unused1[3];             /* 09 unused                            */
    CTHDTASK        *task;                  /* 0C timer thread handle               */
    ECB             timeout;                /* 10 timeout ECB                       */
    ECB             wakeup;                 /* 14 wake up ECB                       */
    TQE             **tqe;                  /* 18 timer queue element array         */
    TQEID           id;                     /* 1C next available TQE ID             */
};                                          /* 20 (32 bytes)                        */

struct tqe {
    char            eye[8];                 /* 00 eye catcher for dumps             */
#define TQE_EYE     "**TQE**"               /* ... eye catcher for dumps            */
    char            flags;                  /* 08 processing flags                  */
#define TQE_FLAG_KEEP           0x80        /* ... do not delete after timeout      */
#define TQE_FLAG_RESET          0x40        /* ... reset expires using bintvl       */
#define TQE_FLAG_DISABLED       0x20        /* ... this element is disabled         */

    char            unused1;                /* 09 unused                            */
    unsigned short  asid;                   /* 0A address space id                  */
    unsigned        *tcb;                   /* 0C task control block                */

    TMRSEC          expires;                /* 10 time this element expires         */
    unsigned        bintvl;                 /* 18 timeout hundred's secs (.01 sec)  */
    ECB             *ecb;                   /* 1C ECB to post for timeout           */

    int             (*func)(void *, TQE*);  /* 20 function to call for timeout      */
    void            *udata;                 /* 24 user data for timeout function    */
    TQEID           id;                     /* 28 TQE ID of this element            */
    unsigned        unused2;                /* 2C unused                            */
};                                          /* 30 (48 bytes)                        */

/* tmr_secs() get current time as seconds.useconds value (.000001), parm can be NULL */
TMRSEC tmr_secs(TMRSEC *secs)                                       asm("@@TMSECS");

/* tmr_get() returns pointer to the static TMR struct */
TMR *tmr_get(void)                                                  asm("@@TMRGET");

/* tmr_init() initialize the static TMR struct */
int tmr_init(void)                                                  asm("@@TMINIT");

/* tmr_start() start timer thread if needed */
int tmr_start(void)                                                 asm("@@TMSTRT");

/* tmr_stop() stop timer thread if needed */
int tmr_stop(void)                                                  asm("@@TMSTOP");

/* tmr_thread() timer processing thread, created by tmr_start() */
int tmr_thread(void *arg1, void *arg2)                              asm("@@TMTHRD");

/* tmr_id() returns next unique timer queue element id */
TQEID tmr_id(void)                                                  asm("@@TMRID");

/* tmr_ecb() create timer element for ECB, returns id of timer element */
TQEID tmr_ecb(ECB *ecb, unsigned bintvl)                            asm("@@TMRECB");

/* tmr_ecb_keep() create timer element for ECB, returns id of timer element, TQE will be kept and disabled after timeout */
TQEID tmr_ecb_keep(ECB *ecb, unsigned bintvl)                       asm("@@TMRECK");

/* tmr_ecb_every() create timer element for ECB, returns id of timer element, ecb will be posted every bintvl (1==.01 sec) */
TQEID tmr_ecb_every(ECB *ecb, unsigned bintvl)                      asm("@@TMRECE");

/* tmr_func() create timer element for function, returns id of timer element */
TQEID tmr_func(int (*func)(void*, TQE*), void *udata, unsigned bintvl)    asm("@@TMRFUN");

/* tmr_func_keep() create timer element for function, returns id of timer element, TQE will be kept and disabled after timeout */
TQEID tmr_func_keep(int (*func)(void*, TQE*), void *udata, unsigned bintvl) asm("@@TMRFUK");

/* tmr_func_every() create timer element for function, returns id of timer element, func will be called every bintvl (1==.01 sec) */
TQEID tmr_func_every(int (*func)(void*, TQE*), void *udata, unsigned bintvl) asm("@@TMRFUE");

/* tqe_get() returns TQE handle for TQEID from static TMR handle */
TQE *tqe_get(TQEID id)                                              asm("@@TQEGET");

/* tqe_purge() removes timer element from static TMR handle and deletes the timer element */
int tqe_purge(TQEID id)                                             asm("@@TQEPRG");

/* tqe_enable() enable timer element */
int tqe_enable(TQEID id)                                            asm("@@TQEENA");

/* tqe_disable() disable timer element */
int tqe_disable(TQEID id)                                           asm("@@TQEDIS");

/* tqe_reset() resets timer element bintvl value */
int tqe_reset(TQEID id, unsigned bintvl)                            asm("@@TQERST");

/* I N T E R N A L   U S E   O N L Y */

/* tqe_new() create a TQE record from parms, returns TQE handle (internal use only) */
TQE *tqe_new(ECB *ecb, int (*func)(void*, TQE*), void *udata, unsigned bintvl, char flags) asm("@@TQNEW");

#endif /* CLIBTMR_H */
