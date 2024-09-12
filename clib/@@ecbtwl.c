#include <clibecb.h>

__asm__("\n&FUNC    SETC 'ecb_timed_waitlist'");
int
ecb_timed_waitlist(ECB **waitlist, ECB *timeout_ecb, unsigned bintvl, unsigned postcode)
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

    /* build parameter list for our EXITDRVR routine */
#if 0
    plist[0] = (unsigned)ecb_post;
#else
    plist[0] = 0;
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
            : : "r"(&bintvl), "r"(&rc) : "1", "14", "15");
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
    __asm__("TTIMER CANCEL");

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
