#include <clibtmr.h>

static int timed_waitlist(ECB **waitlist, ECB *timeout_ecb, unsigned bintvl, unsigned postcode);

__asm__("\n&FUNC    SETC 'tmr_thread'");
int tmr_thread(void *arg1, void *arg2)
{
    TMR         *tmr        = arg1;
    TQE         *tqe        = 0;
    int         rc          = 0;
    int         lockrc      = 0;
    unsigned    bintvl      = 100;  /* 100 = 1 second */
    unsigned    count;
    unsigned    n;
    ECB         *waitlist[2];
    TMRSEC      now;
    TMRSEC      diff;
    unsigned    udiff;

    lockrc = lock(tmr, 0);
    tmr->flags      |= TMR_FLAG_RUNNING;
    tmr->timeout    = 0;
    count           = array_count(&tmr->tqe);
    tmr->wakeup     = count ? ECB_POSTED_BIT : 0;
    if (lockrc==0) unlock(tmr, 0);
#if 0
    wtof("%s RUNNING", __func__);
#endif
    while (tmr) {
        /* wtof("- - - - - - - - - - - - - - - - - - - - - - - - -"); */
        if (tmr->flags & TMR_FLAG_SHUTDOWN) break;

        if (!bintvl) bintvl = 1;  /* 1 = .01 second */

        /* wait for work or timeout */
        waitlist[0] = &tmr->timeout;
        waitlist[1] = &tmr->wakeup;
        waitlist[1] = (void*)((unsigned)waitlist[1] | 0x80000000);
        now = tmr_secs(NULL);
        /* wtof("%s WAITING BINTVL(%u) NOW is %.6f", __func__, bintvl, now); */
        timed_waitlist(waitlist, &tmr->timeout, bintvl, 0);

        lockrc = lock(tmr, 0);
        now = tmr_secs(NULL);

        /* wtof("%s RUNNING, NOW is %.6f", __func__, now); */

        if (tmr->timeout & ECB_POSTED_BIT) {
            tmr->timeout = 0;
            /* wtof("%s TIMEOUT", __func__); */
        }

        if (tmr->wakeup & ECB_POSTED_BIT) {
            tmr->wakeup = 0;
            /* wtof("%s WAKEUP", __func__); */
        }

        /* get the number of elements in the timer element array */
        count = array_count(&tmr->tqe);

        /* check for quiesce */
        if ((tmr->flags & TMR_FLAG_QUIESCE) && !count) {
            /* quiesce desired and no timer elements exist */
            if (lockrc==0) unlock(tmr, 0);
            break;  /* terminate the timer thread */
        }

        /* default timeout value, 200 = 2 seconds */
        bintvl = 200;
        /* examine the timer elements for expired times */
        for(n=count; n > 0; n--) {
            tqe = array_get(&tmr->tqe, n);

            if (!tqe) continue;

            /* disabled timer element? */
            if (tqe->flags & TQE_FLAG_DISABLED) continue;

            /* has this timer element expired yet? */
            if (tqe->expires > now) {
                /* not expired, calc timeout interval for next timed_waitlist() */
                diff = (tqe->expires - now) + 0.005;
                udiff = (unsigned)(diff * 100.0);       /* scale diff for bintvl */
                if (udiff < bintvl) bintvl = udiff;
                /* wtof("%s NOT EXPIRED DIFF(%.6f) UDIFF(%u) BINTVL(%u)", __func__, diff, udiff, bintvl); */
                /* we're done with this timer element */
                continue;
            }

            /* wtof("%s TQEID(%08X) tqe->expires <= now (%.6f <= %.6f)", __func__, tqe->id, tqe->expires, now); */

            /* this timer element has expired, POST or call function */
            if (tqe->ecb) {
                /* POST the ECB for this timer element */
                /* wtof("%s POSTING TQE(%08X) ID(%u)", __func__, tqe, tqe->id); */
                try(ecb_post, tqe->ecb, tqe->id);
            }
            if (tqe->func) {
                /* call the function for this timer element */
                /* wtof("%s CALLING FUNC TQE(%08X) ID(%u)", __func__, tqe, tqe->id); */
                try(tqe->func, tqe->udata, tqe);
            }

            /* should we keep this element? */
            if (!(tqe->flags & TQE_FLAG_KEEP)) {
                /* no, discard this TQE element */
                /* wtof("%s DISCARD TQE(%08X) ID(%u)", __func__, tqe, tqe->id); */
                free(tqe);
                /* remove this TQE from the array */
                array_del(&tmr->tqe, n);
                continue;
            }

            /* TQE is to be kept */
            if (!(tqe->flags & TQE_FLAG_RESET)) {
                /* KEEP desired but no RESET option, so we have to disable the TQE */
                /* wtof("%s DISABLING TQE(%08X) ID(%u)", __func__, tqe, tqe->id); */
                tqe->flags |= TQE_FLAG_DISABLED;
                continue;
            }

            /* KEEP and RESET desired */
            tqe->expires = now;
            if (tqe->bintvl) {
                /* RESET using timer element bintvl value */
                tqe->expires += ((TMRSEC)tqe->bintvl / 100.0);
                tqe->expires -= 0.006;  /* adjustment for timer thread processing time */
            }
            else {
                /* RESET using minimum increment */
                tqe->expires += 0.006;   /* minimum is .006 seconds */
            }

            /* calc next timeout value */
            diff = (tqe->expires - now) + 0.005;
            udiff = (unsigned)(diff * 100.0);       /* scale diff for bintvl */
            if (udiff < bintvl) bintvl = udiff;
            /* wtof("%s KEEP DIFF(%.6f) UDIFF(%u) BINTVL(%u)", __func__, diff, udiff, bintvl); */
        }
        if (lockrc==0) unlock(tmr, 0);
#if 0
        diff = tmr_secs(NULL) - now;
        wtof("%s RUNNING %u elements processed in %.6f seconds", __func__, count, diff);
#endif
    }

quit:
    lockrc = lock(tmr, 0);
    tmr->flags &= ~TMR_FLAG_RUNNING;
    if (lockrc==0) unlock(tmr, 0);
#if 0
    wtof("%s TERMINATED", __func__);
#endif
    return rc;
}


__asm__("\n&FUNC    SETC 'timed_waitlist'");
static int
timed_waitlist(ECB **waitlist, ECB *timeout_ecb, unsigned bintvl, unsigned postcode)
{
    unsigned    *psa    = 0;                        /* low core == PSA      */
    unsigned    *tcb    = (unsigned*)psa[0x21c/4];  /* TCB      == PSATOLD  */
    unsigned    *fsa    = (unsigned*)(tcb[0x70/4] & 0x00FFFFFF);
                                /* FSA == TCB first save area address */
    unsigned    save    = fsa[0];
    unsigned    plist[4];       /* parameter list for postexit plist */
    int         rc;
#if 0
    wtof("%s(%08X,%08X,%u,%08X) TCB(%08X) SAVE(%08X)",
          __func__, waitlist, timeout_ecb, bintvl, postcode, tcb, save);
#endif
    if (!timeout_ecb) timeout_ecb = waitlist[0];

    /* cancel the timer exit */
    __asm__("TTIMER CANCEL" : : :"0", "1", "14", "15");

    /* build parameter list for our EXITDRVR routine */
#if 0
    plist[0] = (unsigned)ecb_post;
#else
    plist[0] = 0;   /* use POST routine in EXITDRVR */
#endif
    plist[1] = (unsigned)timeout_ecb;
    plist[2] = (unsigned)postcode & 0X3FFFFFFF;
    __asm__("L\t0,76(,13)       get NAB\n\t"
            "ST\t0,0(,%0)         save in plist"
            : : "r"(&plist[3]) : "0");

    /* save the plist address in TCB first save area "next" so the EXITDRVR can find it */
    fsa[0]   = (unsigned)plist;

#if 0
    /* debugging */
    if (waitlist) {
        int i;
        for(i=0; waitlist[i]; i++) {
            wtof("%s waitlist[%d]=%08X  %08X", __func__, i, waitlist[i], *waitlist[i]);
            if ((unsigned)waitlist[i] & 0x80000000) break;
        }
    }

    wtof("%s issuing STIMER REAL BINTVL(%u)", __func__, bintvl);
#endif
    __asm__("L\t0,=A(EXITDRVR)\n\tSTIMER REAL,(0),BINTVL=(%0),ERRET=SAVERC\n"
            "SAVERC\tST\t15,0(,%1)"
            : : "r"(&bintvl), "r"(&rc) : "0", "1", "14", "15");
#if 0
    wtof("%s STIMER REAL RC=%d",__func__, rc);
    /* debugging */
    wtof("%s WAIT ECBLIST=(%08X) TCB(%06X)", __func__, waitlist, tcb);
#endif

    /* wait for ECB post */
    __asm__("WAIT ECBLIST=(%0)" : : "r"(waitlist));

#if 0
    wtof("%s RUNNING TCB(%06X)", __func__, tcb);

    /* timer exit has not run yet */
    wtof("%s issuing TTIMER CANCEL", __func__);
#endif

    /* cancel the timer exit */
    __asm__("TTIMER CANCEL" : : :"0", "1", "14", "15");

    /* restore fsa value */
    fsa[0]   = save;

quit:
    return 0;
}

/* EXITDRVR called by STIMER REAL */
__asm__("\n"
"EXITDRVR DS    0H\n"
"         SAVE  (14,12),,'EXITDRVR STIMER REAL'\n"
"         LA    12,0(,15)\n"
"         USING EXITDRVR,12\n"
"*\n"
"         LA    11,0              A(PSA)\n"
"         L     11,X'21C'(,11)    A(TCB) from PSATOLD\n"
"         L     11,X'70'(,11)     TCBFSAB first save area\n"
"         L     11,0(,11)         A(PLIST) from save area\n"
"         LTR   11,11             do we have a plist?\n"
"         BNZ   CHKFUNC           yes, continue\n"
"         B     RETURN\n"
);
__asm__("\n"
"         USING PLIST,11\n"
"CHKFUNC  DS    0H\n"
"*\n"
"* Check function address\n"
"         CLC   FUNC,=F'0'        do we have a function to call\n"
"         BE    POSTIT            no, try posting ECB directly\n"
"*\n"
"* Chain stack with callers save area\n"
"         L     1,STACKNEW        => stack for function\n"
"         ST    13,4(,1)          ... chain stack areas\n"
"         ST    1,8(,13)          ... chain stack areas\n"
"         LR    13,1              new stack\n"
);
__asm__("\n"
"         USING STACK,13\n"
"*\n"
"* Set next available byte in stack\n"
"         LA    0,STACKNAB        next available byte in stack\n"
"         ST    0,SAVENAB         next available byte in stack\n"
"*\n"
"* Call thread function\n"
"         L     15,FUNC           get function address from plist\n"
"         LA    1,ECB             => parameters for function\n"
"         BALR  14,15             call function\n"
"*\n"
"* Get callers save area\n"
"         L     13,SAVEAREA+4     switch back to callers stack\n"
"RETURN   DS    0H\n"
"         RETURN (14,12)\n"
"*\n"
"POSTIT   DS    0H\n"
"         ICM   1,B'1111',ECB\n"
"         BZ    RETURN            no ECB address\n"
"         L     0,POSTCODE        vale to post to ECB\n"
"         POST  (1),(0)           \n"
"         B     RETURN\n"
"         LTORG ,");

__asm__("\n"
"STACK    DSECT\n"
"SAVEAREA DS    18F               00 (0)  callers registers go here\n"
"SAVELWS  DS    A                 48 (72) PL/I Language Work Space N/A\n"
"SAVENAB  DS    A                 4C (76) next available byte -------+\n"
"         DS    0D                                                   |\n"
"STACKNAB DS    0X                50 stack next available byte <-----+\n"
"*");

__asm__("\n"
"PLIST    DSECT\n"
"FUNC     DS    A                 00 C exit function address\n"
"ECB      DS    A                 04 arg1 for C exit\n"
"POSTCODE DS    F                 08 arg2 for C exit\n"
"STACKNEW DS    A                 0C new stack for C exit\n"
"         COPY  CLIBCRT\n"
"         CSECT ,");
