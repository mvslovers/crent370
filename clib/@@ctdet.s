 TITLE '/home/mike/repos/crent370/clib/@@ctdet.c'
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
         
&FUNC    SETC 'cthread_detach'
* Program text area
         DS    0F
         EJECT
* external function 'cthread_detach' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'cthread_detach'
@@CTDET  PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'cthread_detach' code
         L     3,0(11) ==> task
         SLR   15,15 ==> rc
         LTR   3,3 ==> task
         BE    @@L3
         L     2,8(3) ==> .tcb
         LTR   2,2
         BE    @@L3
         MVC   88(4,13),=A(@@2)
         ST    3,92(13) ==> task
         LA    1,88(,13)
         L     15,=V(@@@TRY)
         BALR  14,15
         LTR   15,15 ==> rc
         BNE   @@L5
         L     15,20(3) ==> rc,rc
@@L5     EQU   *
         MVC   8(4,3),=F'0' ==> .tcb
@@L3     EQU   *
* Function 'cthread_detach' epilogue
         PDPEPIL
* Function 'cthread_detach' literal pool
         DS    0D
         LTORG
* Function 'cthread_detach' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         
&FUNC    SETC 'detach'
         DS    0F
         EJECT
* static function 'detach' prologue
* frame base=88, local stack=8, call args=0
&FUNC    SETC  'detach'
@@2      PDPPRLG CINDEX=1,FRAME=96,BASER=12,ENTRY=NO
         B     @@FEN1
         LTORG
@@FEN1   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         LR    11,1
         L     10,=A(@@PGT1)
* Function 'detach' code
         L     4,0(11) ==> task
         MVC   88(4,13),8(4) ==> .tcb
         LR    3,4 ==> task
         A     3,=F'20'
         LA    2,88(,13)
         DS    0H
         DETACH (2),STAE=YES   detach the subtask
         ST    15,0(,3)          save the return code
         MVC   8(4,4),=F'0' ==> .tcb
         L     15,0(3) ==> .rc
* Function 'detach' epilogue
         PDPEPIL
* Function 'detach' literal pool
         DS    0D
         LTORG
* Function 'detach' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
         END
