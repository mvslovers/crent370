 TITLE '/home/mike/repos/crent370/clib/@@tmstrt.c'
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
         
&FUNC    SETC 'tmr_start'
* Program text area
@@6      EQU   *
         DC    C'tmr_start'
         DC    X'0'
         DS    0F
         EJECT
* external function 'tmr_start' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  'tmr_start'
@@TMSTRT PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'tmr_start' code
         LA    1,88(,13)
         L     15,=V(@@TMRGET)
         BALR  14,15
         LR    5,15 ==> tmr
         SLR   6,6 ==> rc
         LR    4,6 ==> task,rc
         LA    1,88(,13)
         L     15,=V(@@TMINIT)
         BALR  14,15
         ST    5,88(13) ==> tmr
         ST    6,92(13) ==> rc
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         LR    3,15 ==> lockrc
         L     2,12(5) ==> .task
         LTR   2,2
         BNE   @@L2
         MVC   88(4,13),=V(@@TMTHRD)
         ST    5,92(13) ==> tmr
         ST    6,96(13) ==> rc
         MVC   100(4,13),=F'32768'
         LA    1,88(,13)
         L     15,=V(@@CTCRTX)
         BALR  14,15
         LR    4,15 ==> task
         LTR   15,15 ==> task
         BNE   @@L3
         MVC   88(4,13),=A(@@LC0)
         MVC   92(4,13),=A(@@6)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         LA    6,12(0,0) ==> rc
         B     @@L2
@@L3     EQU   *
         ST    15,12(5) ==> task,task
         LTR   3,3 ==> lockrc
         BNE   @@L5
         ST    5,88(13) ==> tmr
         ST    3,92(13) ==> lockrc
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
@@L5     EQU   *
         LA    1,88(,13)
         L     15,=V(@@CTYIEL)
         BALR  14,15
         LA    3,8(0,0) ==> lockrc
@@L2     EQU   *
         LTR   3,3 ==> lockrc
         BNE   @@L6
         ST    5,88(13) ==> tmr
         ST    3,92(13) ==> lockrc
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
@@L6     EQU   *
         LTR   6,6 ==> rc
         BNE   @@L8
         LTR   4,4 ==> task
         BE    @@L8
         LR    4,6 ==> i,rc
@@L17    EQU   *
         ST    5,88(13) ==> tmr
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         IC    2,8(5) ==> running,flags
         N     2,=F'64' ==> running
         N     2,=XL4'000000FF' ==> running
         LTR   15,15 ==> lockrc
         BNE   @@L14
         ST    5,88(13) ==> tmr
         ST    15,92(13) ==> lockrc
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
@@L14    EQU   *
         LTR   2,2 ==> running
         BNE   @@L11
         LR    2,4 ==> i
         N     2,=F'3'
         LA    3,3(0,0)
         CLR   2,3
         BNE   @@L16
         MVC   88(4,13),=A(@@LC1)
         MVC   92(4,13),=A(@@6)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
@@L16    EQU   *
         LA    1,88(,13)
         L     15,=V(@@CTYIEL)
         BALR  14,15
         A     4,=F'1' ==> i
         LA    2,99(0,0)
         CR    4,2 ==> i
         BNH   @@L17
@@L11    EQU   *
         LA    3,100(0,0)
         CLR   4,3 ==> i
         BNE   @@L8
         MVC   88(4,13),=A(@@LC2)
         MVC   92(4,13),=A(@@6)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         ST    5,88(13) ==> tmr
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         LR    3,15 ==> lockrc
         LR    2,5 ==> tmr
         A     2,=F'12'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@CTDEL)
         BALR  14,15
         NI    8(5),191 ==> .flags
         LTR   3,3 ==> lockrc
         BNE   @@L19
         ST    5,88(13) ==> tmr
         ST    3,92(13) ==> lockrc
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
@@L19    EQU   *
         LA    6,12(0,0) ==> rc
@@L8     EQU   *
         LR    15,6 ==> rc
* Function 'tmr_start' epilogue
         PDPEPIL
* Function 'tmr_start' literal pool
         DS    0D
         LTORG
* Function 'tmr_start' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'%s unable to create timer thread'
         DC    X'0'
@@LC1    EQU   *
         DC    C'%s waiting for timer thread to start'
         DC    X'0'
@@LC2    EQU   *
         DC    C'%s timer thread failed to start'
         DC    X'0'
         END
