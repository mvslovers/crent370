 TITLE '/home/mike/repos/crent370/clib/@@ctlock.c'
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
         
&FUNC    SETC 'cthread_lock'
* Program text area
         DS    0F
         EJECT
* external function 'cthread_lock' prologue
* frame base=88, local stack=24, call args=16
&FUNC    SETC  'cthread_lock'
@@CTLOCK PDPPRLG CINDEX=0,FRAME=128,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'cthread_lock' code
         L     5,0(11) ==> shared
         L     3,4(11) ==> rname
         LTR   3,3 ==> rname
         BNE   @@L2
         L     4,540(3) ==> tcb
         L     2,548(3) ==> ascb
         L     2,36(2) ==> asid
         SRL   2,16 ==> asid
         LA    3,104(,13) ==> rname
         ST    3,88(13) ==> rname
         MVC   92(4,13),=A(@@LC0)
         ST    2,96(13) ==> asid
         ST    4,100(13) ==> tcb
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
@@L2     EQU   *
         LTR   5,5 ==> shared
         BE    @@L3
         LA    5,4(0,0) ==> shared
@@L3     EQU   *
         MVC   88(4,13),=A(@@LC1)
         ST    3,92(13) ==> rname
         ST    5,96(13) ==> shared
         MVC   100(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@ENQDEQ)
         BALR  14,15
* Function 'cthread_lock' epilogue
         PDPEPIL
* Function 'cthread_lock' literal pool
         DS    0D
         LTORG
* Function 'cthread_lock' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'CTHDX.%04X.%08X'
         DC    X'0'
@@LC1    EQU   *
         DC    C'LCTHREAD'
         DC    X'0'
         
&FUNC    SETC 'cthread_unlock'
         DS    0F
         EJECT
* external function 'cthread_unlock' prologue
* frame base=88, local stack=24, call args=16
&FUNC    SETC  'cthread_unlock'
@@CTUNLK PDPPRLG CINDEX=1,FRAME=128,BASER=12,ENTRY=YES
         B     @@FEN1
         LTORG
@@FEN1   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         LR    11,1
         L     10,=A(@@PGT1)
* Function 'cthread_unlock' code
         L     3,0(11) ==> rname
         LTR   3,3 ==> rname
         BNE   @@L5
         L     4,540(3) ==> tcb
         L     2,548(3) ==> ascb
         L     2,36(2) ==> asid
         SRL   2,16 ==> asid
         LA    3,104(,13) ==> rname
         ST    3,88(13) ==> rname
         MVC   92(4,13),=A(@@LC0)
         ST    2,96(13) ==> asid
         ST    4,100(13) ==> tcb
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
@@L5     EQU   *
         MVC   88(4,13),=A(@@LC1)
         ST    3,92(13) ==> rname
         MVC   96(4,13),=F'0'
         MVC   100(4,13),=F'1'
         LA    1,88(,13)
         L     15,=V(@@ENQDEQ)
         BALR  14,15
* Function 'cthread_unlock' epilogue
         PDPEPIL
* Function 'cthread_unlock' literal pool
         DS    0D
         LTORG
* Function 'cthread_unlock' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
         END
