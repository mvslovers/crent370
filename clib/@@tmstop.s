 TITLE '/home/mike/repos/crent370/clib/@@tmstop.c'
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
         
&FUNC    SETC 'tmr_stop'
* Program text area
@@6      EQU   *
         DC    C'tmr_stop'
         DC    X'0'
         DS    0F
         EJECT
* external function 'tmr_stop' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'tmr_stop'
@@TMSTOP PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'tmr_stop' code
         LA    1,88(,13)
         L     15,=V(@@TMRGET)
         BALR  14,15
         LR    3,15 ==> tmr
         LA    1,88(,13)
         L     15,=V(@@TMINIT)
         BALR  14,15
         ST    3,88(13) ==> tmr
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         LR    4,15 ==> lockrc
         L     2,12(3) ==> .task
         LTR   2,2
         BE    @@L2
         IC    2,8(3) ==> .flags
         N     2,=F'64'
         CLM   2,1,=XL1'00'
         BE    @@L2
         MVC   88(4,13),=A(@@LC0)
         MVC   92(4,13),=A(@@6)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         OI    8(3),32 ==> .flags
         LR    2,3 ==> tmr
         A     2,=F'20'
         ST    2,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@ECBPST)
         BALR  14,15
@@L2     EQU   *
         LTR   4,4 ==> lockrc
         BNE   @@L3
         ST    3,88(13) ==> tmr
         ST    4,92(13) ==> lockrc
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
@@L3     EQU   *
         ST    3,88(13) ==> tmr
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         LR    4,15 ==> lockrc
         L     2,12(3) ==> .task
         LTR   2,2
         BE    @@L4
         IC    2,8(3) ==> .flags
         N     2,=F'64'
         CLM   2,1,=XL1'00'
         BE    @@L4
         MVC   88(4,13),=A(@@LC1)
         MVC   92(4,13),=A(@@6)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         OI    8(3),16 ==> .flags
         LR    2,3 ==> tmr
         A     2,=F'20'
         ST    2,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@ECBPST)
         BALR  14,15
@@L4     EQU   *
         LTR   4,4 ==> lockrc
         BNE   @@L5
         ST    3,88(13) ==> tmr
         ST    4,92(13) ==> lockrc
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
@@L5     EQU   *
         ST    3,88(13) ==> tmr
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         LR    4,15 ==> lockrc
         L     2,12(3) ==> .task
         LTR   2,2
         BE    @@L6
         IC    2,8(3) ==> .flags
         N     2,=F'16'
         CLM   2,1,=XL1'00'
         BE    @@L6
         MVC   88(4,13),=A(@@LC2)
         MVC   92(4,13),=A(@@6)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         LR    2,3 ==> tmr
         A     2,=F'12'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@CTDEL)
         BALR  14,15
         MVC   0(4,2),=F'0' ==> .task
@@L6     EQU   *
         LTR   4,4 ==> lockrc
         BNE   @@L7
         ST    3,88(13) ==> tmr
         ST    4,92(13) ==> lockrc
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
@@L7     EQU   *
         ST    3,88(13) ==> tmr
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         LR    4,15 ==> lockrc
         L     2,12(3) ==> .task
         LTR   2,2
         BE    @@L8
         IC    2,8(3) ==> .flags
         N     2,=F'16'
         CLM   2,1,=XL1'00'
         BNE   @@L8
         MVC   88(4,13),=A(@@LC3)
         MVC   92(4,13),=A(@@6)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         MVC   88(4,13),12(3) ==> .task
         LA    1,88(,13)
         L     15,=V(@@CTDET)
         BALR  14,15
         MVC   12(4,3),=F'0' ==> .task
@@L8     EQU   *
         LTR   4,4 ==> lockrc
         BNE   @@L10
         ST    3,88(13) ==> tmr
         ST    4,92(13) ==> lockrc
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
@@L10    EQU   *
         SLR   15,15
* Function 'tmr_stop' epilogue
         PDPEPIL
* Function 'tmr_stop' literal pool
         DS    0D
         LTORG
* Function 'tmr_stop' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'%s QUIESCE posted'
         DC    X'0'
@@LC1    EQU   *
         DC    C'%s SHUTDOWN posted'
         DC    X'0'
@@LC2    EQU   *
         DC    C'%s thread DELETE'
         DC    X'0'
@@LC3    EQU   *
         DC    C'%s thread DETACH'
         DC    X'0'
         END
