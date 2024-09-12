 TITLE '/home/mike/repos/crent370/clib/@@ecbtwl.c'
         COPY  PDPTOP
         CSECT
* GNU C version 3.2.3 - c2asm370 version 1.0 (mvs)
*        compiled by GNU C version 13.2.0.
*
* options passed:  -lang-c -I. -I/home/mike/repos/crent370/include
* -iprefix -D__GNUC__=3 -D__GNUC_MINOR__=2 -D__GNUC_PATCHLEVEL__=3
* -D__GXX_ABI_VERSION=102 -D__GCC__ -D__MVS__ -D__GCC__ -D__MVS__
* -Asystem=mvs -Acpu=i370 -Amachine=i370 -D__OPTIMIZE__
* -D__STDC_HOSTED__=1 -trigraphs -O1 -fverbose-asm
* 
* options enabled:  -fdefer-pop -fthread-jumps -fpeephole
* -ffunction-cse -fkeep-static-consts -fpcc-struct-return -fgcse-lm
* -fgcse-sm -fsched-interblock -fsched-spec -fbranch-count-reg
* -fcprop-registers -fcommon -fverbose-asm -fgnu-linker
* -fargument-alias -fmerge-constants -fident
* -fguess-branch-probability -fmath-errno -ftrapping-math
* -mchar-instructions -mno-pickax -mno-constants-first
*
         
&FUNC    SETC 'ecb_timed_waitlist'
* Program text area
         DS    0F
         EJECT
* external function 'ecb_timed_waitlist' prologue
* frame base=88, local stack=24, call args=0
&FUNC    SETC  'ecb_timed_waitlist'
@@ECBTWL PDPPRLG CINDEX=0,FRAME=112,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'ecb_timed_waitlist' code
         L     5,0(11) ==> waitlist
         L     3,4(11) ==> timeout_ecb
         SLR   2,2 ==> psa
         L     2,540(2) ==> tcb
         L     4,112(2) ==> fsa
         N     4,=F'16777215' ==> fsa
         L     6,0(4) ==> save,fsa
         LTR   3,3 ==> timeout_ecb
         BNE   @@L2
         L     3,0(5) ==> timeout_ecb,waitlist
@@L2     EQU   *
         MVC   88(4,13),=F'0' ==> plist
         ST    3,92(13) ==> timeout_ecb,plist
         L     2,12(11) ==> postcode
         N     2,=F'1073741823'
         ST    2,96(13) ==> plist
         LA    2,100(,13)
         L     0,76(,13)       get NAB
         ST    0,0(,2)         save in plist
         LA    2,88(,13)
         ST    2,0(4) ==> fsa
         LA    3,8(,11)
         LA    2,104(,13)
         L     0,=A(EXITDRVR)
         STIMER REAL,(0),BINTVL=(3),ERRET=SAVERC
SAVERC   ST    15,0(,2)
         WAIT ECBLIST=(5) ==> waitlist
         TTIMER CANCEL
         ST    6,0(4) ==> save,fsa
@@L3     EQU   *
         SLR   15,15
* Function 'ecb_timed_waitlist' epilogue
         PDPEPIL
* Function 'ecb_timed_waitlist' literal pool
         DS    0D
         LTORG
* Function 'ecb_timed_waitlist' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         
EXITDRVR DS    0H
         SAVE  (14,12),,'EXITDRVR STIMER REAL'
         LA    12,0(,15)
         USING EXITDRVR,12
*
         LA    11,0              A(PSA)
         L     11,X'21C'(,11)    A(TCB) from PSATOLD
         L     11,X'70'(,11)     TCBFSAB first save area
         L     11,0(,11)         A(PLIST) from save area
         LTR   11,11             do we have a plist?
         BNZ   CHKFUNC           yes, continue
         B     RETURN

         
         USING PLIST,11
CHKFUNC  DS    0H
*
* Check function address
         CLC   FUNC,=F'0'        do we have a function to call
         BE    POSTIT            no, try posting ECB directly
*
* Chain stack with callers save area
         L     1,STACKNEW        => stack for function
         ST    13,4(,1)          ... chain stack areas
         ST    1,8(,13)          ... chain stack areas
         LR    13,1              new stack

         
         USING STACK,13
*
* Set next available byte in stack
         LA    0,STACKNAB        next available byte in stack
         ST    0,SAVENAB         next available byte in stack
*
* Call thread function
         L     15,FUNC           get function address from plist
         LA    1,ECB             => parameters for function
         BALR  14,15             call function
*
* Get callers save area
         L     13,SAVEAREA+4     switch back to callers stack
RETURN   DS    0H
         RETURN (14,12)
*
POSTIT   DS    0H
         ICM   1,B'1111',ECB
         BZ    RETURN            no ECB address
         L     0,POSTCODE        vale to post to ECB
         POST  (1),(0)           
         B     RETURN
         LTORG ,
         
STACK    DSECT
SAVEAREA DS    18F               00 (0)  callers registers go here
SAVELWS  DS    A                 48 (72) PL/I Language Work Space N/A
SAVENAB  DS    A                 4C (76) next available byte -------+
         DS    0D                                                   |
STACKNAB DS    0X                50 stack next available byte <-----+
*
         
PLIST    DSECT
FUNC     DS    A                 00 C exit function address
ECB      DS    A                 04 arg1 for C exit
POSTCODE DS    F                 08 arg2 for C exit
STACKNEW DS    A                 0C new stack for C exit
         COPY  CLIBCRT
         CSECT ,
         END
