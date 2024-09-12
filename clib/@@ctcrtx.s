 TITLE '/home/mike/repos/crent370/clib/@@ctcrtx.c'
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
         
&FUNC    SETC 'cthread_create_ex'
* Program text area
         DS    0F
         EJECT
* external function 'cthread_create_ex' prologue
* frame base=88, local stack=8, call args=16
&FUNC    SETC  'cthread_create_ex'
@@CTCRTX PDPPRLG CINDEX=0,FRAME=112,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'cthread_create_ex' code
         L     5,0(11) ==> func
         L     3,12(11) ==> stacksize
         SLR   2,2 ==> psa
         L     4,540(2) ==> tcb
         ST    4,88(13) ==> tcb
         LA    1,88(,13)
         L     15,=V(@@CTFIND)
         BALR  14,15
         ST    2,104(13) ==> psa
         LTR   3,3 ==> stacksize
         BNE   @@L2
         L     3,=F'65536' ==> stacksize
@@L2     EQU   *
         LTR   5,5 ==> func
         BNE   @@L3
         L     5,=A(@@2) ==> func
@@L3     EQU   *
         LTR   15,15 ==> owner
         BNE   @@L4
         ST    4,88(13) ==> tcb
         ST    15,92(13) ==> owner
         ST    15,96(13) ==> owner
         LA    1,88(,13)
         L     15,=A(@@3)
         BALR  14,15
         LTR   15,15 ==> owner
         BE    @@L6
@@L4     EQU   *
         MVC   88(4,13),=F'0'
         MVC   92(4,13),8(15) ==> .tcb
         ST    3,96(13) ==> stacksize
         LA    1,88(,13)
         L     15,=A(@@3)
         BALR  14,15
         ST    15,104(13) ==> owner
         LTR   15,15
         BE    @@L6
         ST    5,28(15) ==> func,func
         L     2,104(13)
         MVC   32(4,2),4(11) ==> .arg1,arg1
         L     2,104(13)
         MVC   36(4,2),8(11) ==> .arg2,arg2
         MVC   88(4,13),=A(@@4)
         MVC   92(4,13),104(13)
         LA    1,88(,13)
         L     15,=V(@@@TRY)
         BALR  14,15
         LTR   15,15 ==> rc
         BNE   @@L8
         L     2,104(13)
         L     15,20(2) ==> rc,rc
@@L8     EQU   *
         LTR   15,15 ==> rc
         BE    @@L6
         L     2,104(13)
         MVC   8(4,2),=F'0' ==> .tcb
         LA    2,104(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@CTDEL)
         BALR  14,15
@@L6     EQU   *
         L     15,104(13)
* Function 'cthread_create_ex' epilogue
         PDPEPIL
* Function 'cthread_create_ex' literal pool
         DS    0D
         LTORG
* Function 'cthread_create_ex' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         
&FUNC    SETC 'attach'
         DS    0F
         EJECT
* static function 'attach' prologue
* frame base=88, local stack=64, call args=0
&FUNC    SETC  'attach'
@@4      PDPPRLG CINDEX=1,FRAME=152,BASER=12,ENTRY=NO
         B     @@FEN1
         LTORG
@@FEN1   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         LR    11,1
         L     10,=A(@@PGT1)
* Function 'attach' code
         L     4,0(11) ==> task
         LA    6,88(,13)
         LA    7,64(0,0)
         SLR   2,2
         LR    3,2
         MVCL  6,2
         LR    3,4 ==> task
         A     3,=F'16'
         LA    2,88(,13)
         LA    1,0(,4) ==> task
         ATTACH EP=CTHREAD,ECB=(3),DPMOD=-1,SF=(E,(2))
         ST    1,8(4) ==> .tcb
         ST    15,20(4) ==> .rc
         L     15,20(4) ==> .rc
* Function 'attach' epilogue
         PDPEPIL
* Function 'attach' literal pool
         DS    0D
         LTORG
* Function 'attach' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
         
&FUNC    SETC 'newthread'
         DS    0F
         EJECT
* static function 'newthread' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'newthread'
@@3      PDPPRLG CINDEX=2,FRAME=96,BASER=12,ENTRY=NO
         B     @@FEN2
         LTORG
@@FEN2   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG2    EQU   *
         LR    11,1
         L     10,=A(@@PGT2)
* Function 'newthread' code
         L     3,8(11) ==> stacksize
         LA    1,88(,13)
         L     15,=V(@@GRTGET)
         BALR  14,15
         LR    5,15 ==> grt
         LR    2,3 ==> stacksize
         BCTR  2,0
         LA    4,78(0,0)
         CLR   2,4
         BNH   @@L12
         LR    4,3 ==> newstack,stacksize
         A     4,=F'7' ==> newstack
         N     4,=F'1048568' ==> newstack
         B     @@L13
@@L12    EQU   *
         LA    4,80(0,0) ==> newstack
@@L13    EQU   *
         MVC   88(4,13),=F'1'
         LR    2,4 ==> newstack
         A     2,=F'44'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         LR    3,15 ==> task
         LTR   15,15 ==> task
         BE    @@L14
         ST    15,88(13) ==> task
         MVC   92(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         MVC   8(4,3),0(11) ==> .tcb,tcb
         MVC   12(4,3),4(11) ==> .owntcb,owntcb
         ST    4,24(3) ==> newstack,stacksize
         LR    2,5 ==> grt
         A     2,=F'64'
         ST    2,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         ST    2,88(13)
         ST    3,92(13) ==> task
         LA    1,88(,13)
         L     15,=V(@@ARADD)
         BALR  14,15
         ST    2,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
@@L14    EQU   *
         LR    15,3 ==> task
* Function 'newthread' epilogue
         PDPEPIL
* Function 'newthread' literal pool
         DS    0D
         LTORG
* Function 'newthread' page table
@@PGT2   DS    0F
         DC    A(@@PG2)
@@LC0    EQU   *
         DC    C'CTHDTASK'
         DC    X'0'
         
&FUNC    SETC 'dummy'
         DS    0F
         EJECT
* static function 'dummy' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  'dummy'
@@2      PDPPRLG CINDEX=3,FRAME=104,BASER=12,ENTRY=NO
         B     @@FEN3
         LTORG
@@FEN3   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG3    EQU   *
         LR    11,1
         L     10,=A(@@PGT3)
* Function 'dummy' code
         LA    1,88(,13)
         L     15,=V(@@CTSELF)
         BALR  14,15
         LR    2,15 ==> task
         MVC   88(4,13),=A(@@LC1)
         MVC   92(4,13),0(11) ==> arg1
         MVC   96(4,13),4(11) ==> arg2
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         MVC   88(4,13),=A(@@LC2)
         ST    2,92(13) ==> task
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         LTR   2,2 ==> task
         BE    @@L16
         MVC   88(4,13),=A(@@LC3)
         ST    2,92(13) ==> task
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         MVC   88(4,13),=A(@@LC4)
         MVC   92(4,13),8(2) ==> .tcb
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         MVC   88(4,13),=A(@@LC5)
         MVC   92(4,13),12(2) ==> .owntcb
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         MVC   88(4,13),=A(@@LC6)
         MVC   92(4,13),16(2) ==> .termecb
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         MVC   88(4,13),=A(@@LC7)
         MVC   92(4,13),20(2) ==> .rc
         MVC   96(4,13),20(2) ==> .rc
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         MVC   88(4,13),=A(@@LC8)
         MVC   92(4,13),24(2) ==> .stacksize
         MVC   96(4,13),24(2) ==> .stacksize
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         MVC   88(4,13),=A(@@LC9)
         MVC   92(4,13),28(2) ==> .func
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         MVC   88(4,13),=A(@@LC10)
         MVC   92(4,13),32(2) ==> .arg1
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         MVC   88(4,13),=A(@@LC11)
         MVC   92(4,13),36(2) ==> .arg2
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
@@L16    EQU   *
         L     15,=F'-1'
* Function 'dummy' epilogue
         PDPEPIL
* Function 'dummy' literal pool
         DS    0D
         LTORG
* Function 'dummy' page table
@@PGT3   DS    0F
         DC    A(@@PG3)
@@LC1    EQU   *
         DC    C'dummy(arg1=%08X, arg2=%08X)'
         DC    X'15'
         DC    X'0'
@@LC2    EQU   *
         DC    C'CTHDTASK handle=%08X'
         DC    X'15'
         DC    X'0'
@@LC3    EQU   *
         DC    C'task->eye         %-8.8s'
         DC    X'15'
         DC    X'0'
@@LC4    EQU   *
         DC    C'task->tcb         %08X'
         DC    X'15'
         DC    X'0'
@@LC5    EQU   *
         DC    C'task->owntcb      %08X'
         DC    X'15'
         DC    X'0'
@@LC6    EQU   *
         DC    C'task->termecb     %08X'
         DC    X'15'
         DC    X'0'
@@LC7    EQU   *
         DC    C'task->rc          %08X (%d)'
         DC    X'15'
         DC    X'0'
@@LC8    EQU   *
         DC    C'task->stacksize   %08X (%d)'
         DC    X'15'
         DC    X'0'
@@LC9    EQU   *
         DC    C'task->func        %08X'
         DC    X'15'
         DC    X'0'
@@LC10   EQU   *
         DC    C'task->arg1        %08X'
         DC    X'15'
         DC    X'0'
@@LC11   EQU   *
         DC    C'task->arg2        %08X'
         DC    X'15'
         DC    X'0'
         
&FUNC    SETC 'cleanup_thread'
         DS    0F
         EJECT
* static function 'cleanup_thread' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'cleanup_thread'
@@5      PDPPRLG CINDEX=4,FRAME=96,BASER=12,ENTRY=NO
         B     @@FEN4
         LTORG
@@FEN4   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG4    EQU   *
         LR    11,1
         L     10,=A(@@PGT4)
* Function 'cleanup_thread' code
         LA    1,88(,13)
         L     15,=V(@@CRTGET)
         BALR  14,15
         LR    3,15 ==> crt
         LTR   15,15 ==> crt
         BE    @@L17
         L     2,332(15) ==> .crtpush
         LTR   2,2
         BE    @@L20
         LR    2,15 ==> crt
         A     2,=F'332'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    2,15 ==> count
         LTR   15,15 ==> count
         BE    @@L32
@@L24    EQU   *
         MVC   88(4,13),=F'2'
         LA    1,88(,13)
         L     15,=V(@@CTPOP)
         BALR  14,15
         BCTR  2,0 ==> count
         LTR   2,2 ==> count
         BNE   @@L24
@@L32    EQU   *
         LR    2,3 ==> crt
         A     2,=F'332'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARFRE)
         BALR  14,15
         A     2,=F'4'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARFRE)
         BALR  14,15
@@L20    EQU   *
         L     2,340(3) ==> .crtmutx
         LTR   2,2
         BE    @@L17
         LR    2,3 ==> crt
         A     2,=F'340'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    2,15 ==> count
         LTR   15,15 ==> count
         BE    @@L34
         LR    4,3 ==> crt
         A     4,=F'340'
@@L30    EQU   *
         ST    4,88(13)
         ST    2,92(13) ==> count
         LA    1,88(,13)
         L     15,=V(@@ARDEL)
         BALR  14,15
         LTR   15,15 ==> x
         BE    @@L29
         ST    15,88(13) ==> x
         LA    1,88(,13)
         L     15,=V(MTXCLUP)
         BALR  14,15
@@L29    EQU   *
         BCTR  2,0 ==> count
         LTR   2,2 ==> count
         BNE   @@L30
@@L34    EQU   *
         LR    2,3 ==> crt
         A     2,=F'340'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARFRE)
         BALR  14,15
@@L19    EQU   *
@@L17    EQU   *
* Function 'cleanup_thread' epilogue
         PDPEPIL
* Function 'cleanup_thread' literal pool
         DS    0D
         LTORG
* Function 'cleanup_thread' page table
@@PGT4   DS    0F
         DC    A(@@PG4)
         DS    0F
         EJECT
* external function '__ctclup' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  '__ctclup'
@@CTCLUP PDPPRLG CINDEX=5,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN5
         LTORG
@@FEN5   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG5    EQU   *
         LR    11,1
         L     10,=A(@@PGT5)
* Function '__ctclup' code
         MVC   88(4,13),=A(@@5)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@@TRY)
         BALR  14,15
* Function '__ctclup' epilogue
         PDPEPIL
* Function '__ctclup' literal pool
         DS    0D
         LTORG
* Function '__ctclup' page table
@@PGT5   DS    0F
         DC    A(@@PG5)
         END
