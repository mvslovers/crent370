 TITLE '/home/mike/repos/crent370/clib/@@@try.c'
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
         
&FUNC    SETC 'failed'
* Program text area
         DS    0F
         EJECT
* static function 'failed' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'failed'
@@2      PDPPRLG CINDEX=0,FRAME=88,BASER=12,ENTRY=NO
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'failed' code
         L     15,0(11) ==> sdwa
         L     2,4(11) ==> udata
         L     4,4(2) ==> regs,u
         L     2,4(15) ==> abcode
         N     2,=F'16777215' ==> abcode
         LTR   2,2 ==> abcode
         BE    @@L2
         ST    2,60(4) ==> abcode,r
@@L2     EQU   *
         L     3,=A(RETRY) ==> retry
         MVI   4(15),0 ==> .SDWACMPF
         LR    2,15 ==> sdwa
         A     2,=F'136'
         MVC   0(64,2),0(4) ==> regs
         MVI   252(15),4 ==> .SDWARCDE
         ST    3,240(15) ==> retry,SDWARTYA
         OI    253(15),8 ==> .SDWAACF2
         LA    15,4(0,0)
* Function 'failed' epilogue
         PDPEPIL
* Function 'failed' literal pool
         DS    0D
         LTORG
* Function 'failed' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         
&FUNC    SETC 'call'
         DS    0F
         EJECT
* static function 'call' prologue
* frame base=88, local stack=64, call args=16
&FUNC    SETC  'call'
@@3      PDPPRLG CINDEX=1,FRAME=168,BASER=12,ENTRY=NO
         B     @@FEN1
         LTORG
@@FEN1   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         LR    11,1
         L     10,=A(@@PGT1)
* Function 'call' code
         L     5,0(11) ==> func
         L     4,4(11) ==> plist
         LA    1,88(,13)
         L     15,=V(@@CRTGET)
         BALR  14,15
         LR    3,15 ==> crt
         LA    2,104(,13)
         STM   0,14,0(2)
         MVC   164(4,13),=F'-1' ==> .r
         LTR   15,15 ==> crt
         BE    @@L4
         MVC   376(4,15),=F'0' ==> .crttryrc
@@L4     EQU   *
         MVC   88(4,13),=F'0'
         MVC   92(4,13),=A(@@2)
         LA    2,104(,13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@ESTAE)
         BALR  14,15
         LCR   2,15 ==> rc
         LTR   15,15 ==> rc
         BNE   @@L6
         LR    15,5          => function to call  ==> func
         LR    1,4           => parameter list ==> plist
         BALR  14,15         call function
         SR    15,15         function completed without abend
         LR    2,15         save return code ==> rc
         LTR   2,2 ==> rc
         BE    @@L8
         
RETRY    DS   0H
         LR    2,15 ==> rc
         N     2,=F'16777215' ==> rc
         LTR   3,3 ==> crt
         BE    @@L8
         ST    2,376(3) ==> rc,crttryrc
@@L8     EQU   *
         MVC   88(4,13),=F'2'
         MVC   92(4,13),=F'0'
         MVC   96(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@ESTAE)
         BALR  14,15
@@L6     EQU   *
         LR    15,2 ==> rc
* Function 'call' epilogue
         PDPEPIL
* Function 'call' literal pool
         DS    0D
         LTORG
* Function 'call' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
         DS    0F
         EJECT
* external function '___try' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  '___try'
@@@TRY   PDPPRLG CINDEX=2,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN2
         LTORG
@@FEN2   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG2    EQU   *
         LR    11,1
         L     10,=A(@@PGT2)
* Function '___try' code
         MVC   88(4,13),0(11)
         LA    2,4(,11) ==> r1
         ST    2,92(13) ==> r1
         LA    1,88(,13)
         L     15,=A(@@3)
         BALR  14,15
* Function '___try' epilogue
         PDPEPIL
* Function '___try' literal pool
         DS    0D
         LTORG
* Function '___try' page table
@@PGT2   DS    0F
         DC    A(@@PG2)
         DS    0F
         EJECT
* external function '___tryrc' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  '___tryrc'
@@@TRYRC PDPPRLG CINDEX=3,FRAME=88,BASER=12,ENTRY=YES
         B     @@FEN3
         LTORG
@@FEN3   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG3    EQU   *
         LR    11,1
         L     10,=A(@@PGT3)
* Function '___tryrc' code
         L     2,=F'-1' ==> rc
         LA    1,88(,13)
         L     15,=V(@@CRTGET)
         BALR  14,15
         LTR   15,15 ==> crt
         BE    @@L12
         L     2,376(15) ==> rc,crttryrc
@@L12    EQU   *
         LR    15,2 ==> rc
* Function '___tryrc' epilogue
         PDPEPIL
* Function '___tryrc' literal pool
         DS    0D
         LTORG
* Function '___tryrc' page table
@@PGT3   DS    0F
         DC    A(@@PG3)
         END
