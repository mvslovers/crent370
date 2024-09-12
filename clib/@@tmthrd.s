 TITLE '/home/mike/repos/crent370/clib/@@tmthrd.c'
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
         
&FUNC    SETC 'tmr_thread'
* Program text area
         DS    0F
         EJECT
* external function 'tmr_thread' prologue
* frame base=88, local stack=8, call args=16
&FUNC    SETC  'tmr_thread'
@@TMTHRD PDPPRLG CINDEX=0,FRAME=112,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'tmr_thread' code
         L     5,0(11) ==> tmr,arg1
         LA    9,100(0,0) ==> bintvl
         ST    5,88(13) ==> tmr
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         LR    8,15 ==> lockrc
         OI    8(5),64 ==> .flags
         MVC   16(4,5),=F'0' ==> .timeout
         LR    2,5 ==> tmr
         A     2,=F'24'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LPR   2,15 ==> count
         LCR   2,2
         SRL   2,31
         SLL   2,30
         ST    2,20(5) ==> .wakeup
         LTR   8,8 ==> lockrc
         BNE   @@L4
         ST    5,88(13) ==> tmr
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
@@L4     EQU   *
         LTR   5,5 ==> tmr
         BE    @@L34
@@L33    EQU   *
         IC    2,8(5) ==> .flags
         N     2,=F'16'
         CLM   2,1,=XL1'00'
         BNE   @@L34
         LTR   9,9 ==> bintvl
         BNE   @@L9
         LA    9,1(0,0) ==> bintvl
@@L9     EQU   *
         LR    4,5 ==> tmr
         A     4,=F'16'
         ST    4,104(13)
         LA    2,108(,13)
         LR    3,5 ==> tmr
         A     3,=F'20'
         ST    3,0(2) ==> waitlist
         OC    0(4,2),=F'-2147483648' ==> waitlist
         MVC   88(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@TMSECS)
         BALR  14,15
         LA    2,104(,13)
         ST    2,88(13)
         ST    4,92(13)
         ST    9,96(13) ==> bintvl
         MVC   100(4,13),=F'0'
         LA    1,88(,13)
         L     15,=A(@@6)
         BALR  14,15
         ST    5,88(13) ==> tmr
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         LR    8,15 ==> lockrc
         MVC   88(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@TMSECS)
         BALR  14,15
         STD   0,80(,13)
         LM    6,7,80(13) ==> now
         L     2,0(4) ==> .timeout
         N     2,=F'1073741824'
         LTR   2,2
         BE    @@L10
         MVC   0(4,4),=F'0' ==> .timeout
@@L10    EQU   *
         L     2,20(5) ==> .wakeup
         N     2,=F'1073741824'
         LTR   2,2
         BE    @@L11
         MVC   20(4,5),=F'0' ==> .wakeup
@@L11    EQU   *
         LR    2,5 ==> tmr
         A     2,=F'24'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         IC    2,8(5) ==> .flags
         N     2,=F'32'
         CLM   2,1,=XL1'00'
         BE    @@L12
         LTR   15,15 ==> count
         BNE   @@L12
         LTR   8,8 ==> lockrc
         BNE   @@L34
         ST    5,88(13) ==> tmr
         ST    8,92(13) ==> lockrc
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
         B     @@L34
@@L12    EQU   *
         LA    9,200(0,0) ==> bintvl
         LR    4,15 ==> n,count
         LTR   15,15 ==> n
         BE    @@L38
@@L31    EQU   *
         LR    2,5 ==> tmr
         A     2,=F'24'
         ST    2,88(13)
         ST    4,92(13) ==> n
         LA    1,88(,13)
         L     15,=V(@@ARGET)
         BALR  14,15
         LR    3,15 ==> tqe
         LTR   15,15 ==> tqe
         BE    @@L16
         IC    2,8(15) ==> .flags
         N     2,=F'32'
         SLL   2,24
         SRA   2,24
         C     2,=F'0'
         BNE   @@L16
         STM   6,7,80(13) ==> now
         LD    0,80(,13)
         CD    0,16(15) ==> .expires
         BL    @@L41
         L     2,28(15) ==> .ecb
         LTR   2,2
         BE    @@L23
         MVC   88(4,13),=V(@@ECBPST)
         MVC   92(4,13),28(15) ==> .ecb
         MVC   96(4,13),40(15) ==> .id
         LA    1,88(,13)
         L     15,=V(@@@TRY)
         BALR  14,15
@@L23    EQU   *
         L     2,32(3) ==> .func
         LTR   2,2
         BE    @@L24
         ST    2,88(13)
         MVC   92(4,13),36(3) ==> .udata
         ST    3,96(13) ==> tqe
         LA    1,88(,13)
         L     15,=V(@@@TRY)
         BALR  14,15
@@L24    EQU   *
         IC    2,8(3) ==> .flags
         N     2,=F'-128'
         CLM   2,1,=XL1'00'
         BNE   @@L25
         ST    3,88(13) ==> tqe
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
         LR    2,5 ==> tmr
         A     2,=F'24'
         ST    2,88(13)
         ST    4,92(13) ==> n
         LA    1,88(,13)
         L     15,=V(@@ARDEL)
         BALR  14,15
         B     @@L16
@@L25    EQU   *
         IC    2,8(3) ==> .flags
         N     2,=F'64'
         CLM   2,1,=XL1'00'
         BNE   @@L26
         OI    8(3),32 ==> .flags
         B     @@L16
@@L26    EQU   *
         ST    6,16(3) ==> now,expires
         ST    7,4+16(3) ==> now,expires
         L     2,24(3) ==> .bintvl
         LTR   2,2
         BE    @@L27
         MVC   80(4,13),=XL8'4E00000080000000'
         ST    2,84(,13)
         XI    84(13),128
         LD    0,80(,13)
         SD    0,=XL8'4E00000080000000'
         LTR   2,2
         BNL   @@L28
         AD    0,=D'4.294967296E9'
@@L28    EQU   *
         DD    0,=D'1.0E2'
         AD    0,16(3) ==> .expires
         STD   0,16(3) ==> .expires
         SD    0,=D'5.99999999999999925754E-3'
         B     @@L39
@@L27    EQU   *
         LD    0,16(3) ==> .expires
         AD    0,=D'5.99999999999999925754E-3'
@@L39    EQU   *
         STD   0,16(3) ==> .expires
@@L41    EQU   *
         LD    0,16(3) ==> diff,expires
         STM   6,7,80(13) ==> now
         LD    2,80(,13)
         SDR   0,2 ==> diff
         AD    0,=D'4.99999999999999923672E-3' ==> diff
         LDR   2,0 ==> diff
         MD    2,=D'1.0E2'
         LDR   0,2
         AD    0,=XL8'4F08000000000000'
         STD   0,80(,13)
         L     15,84(,13) ==> udiff
         CLR   15,9 ==> udiff,bintvl
         BNL   @@L16
         LR    9,15 ==> bintvl,udiff
@@L16    EQU   *
         BCTR  4,0 ==> n
         LTR   4,4 ==> n
         BNE   @@L31
@@L38    EQU   *
         LTR   8,8 ==> lockrc
         BNE   @@L5
         ST    5,88(13) ==> tmr
         ST    8,92(13) ==> lockrc
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
@@L5     EQU   *
         LTR   5,5 ==> tmr
         BNE   @@L33
@@L34    EQU   *
         ST    5,88(13) ==> tmr
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         NI    8(5),191 ==> .flags
         LTR   15,15 ==> lockrc
         BNE   @@L35
         ST    5,88(13) ==> tmr
         ST    15,92(13) ==> lockrc
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
@@L35    EQU   *
         SLR   15,15
* Function 'tmr_thread' epilogue
         PDPEPIL
* Function 'tmr_thread' literal pool
         DS    0D
         LTORG
* Function 'tmr_thread' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         
&FUNC    SETC 'timed_waitlist'
         DS    0F
         EJECT
* static function 'timed_waitlist' prologue
* frame base=88, local stack=24, call args=0
&FUNC    SETC  'timed_waitlist'
@@6      PDPPRLG CINDEX=1,FRAME=112,BASER=12,ENTRY=NO
         B     @@FEN1
         LTORG
@@FEN1   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         LR    11,1
         L     10,=A(@@PGT1)
* Function 'timed_waitlist' code
         L     5,0(11) ==> waitlist
         L     3,4(11) ==> timeout_ecb
         SLR   2,2 ==> psa
         L     2,540(2) ==> tcb
         L     4,112(2) ==> fsa
         N     4,=F'16777215' ==> fsa
         L     6,0(4) ==> save,fsa
         LTR   3,3 ==> timeout_ecb
         BNE   @@L43
         L     3,0(5) ==> timeout_ecb,waitlist
@@L43    EQU   *
         TTIMER CANCEL
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
@@L44    EQU   *
         SLR   15,15
* Function 'timed_waitlist' epilogue
         PDPEPIL
* Function 'timed_waitlist' literal pool
         DS    0D
         LTORG
* Function 'timed_waitlist' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
         
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
