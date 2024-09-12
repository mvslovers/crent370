 TITLE '/home/mike/repos/crent370/clib/@@txbfal.c'
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
* Program text area
         DS    0F
         EJECT
* external function '__txbfal' prologue
* frame base=88, local stack=8, call args=16
&FUNC    SETC  '__txbfal'
@@TXBFAL PDPPRLG CINDEX=0,FRAME=112,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__txbfal' code
         L     3,4(11) ==> align
         LA    4,1(0,0) ==> err
         LTR   3,3 ==> align
         BE    @@L2
         ST    3,88(13) ==> align
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         LR    2,15 ==> len
         B     @@L3
@@L2     EQU   *
         SLR   2,2 ==> len
@@L3     EQU   *
         LTR   2,2 ==> len
         BE    @@L9
         ST    3,88(13) ==> align
         MVC   92(4,13),=A(@@LC0)
         ST    2,96(13) ==> len
         LA    1,88(,13)
         L     15,=V(MEMCMP)
         BALR  14,15
         LTR   15,15 ==> len
         BNE   @@L5
         MVI   104(13),1
         B     @@L6
@@L5     EQU   *
         ST    3,88(13) ==> align
         MVC   92(4,13),=A(@@LC1)
         ST    2,96(13) ==> len
         LA    1,88(,13)
         L     15,=V(MEMCMP)
         BALR  14,15
         LTR   15,15 ==> len
         BNE   @@L9
         MVI   104(13),2
@@L6     EQU   *
         MVC   88(4,13),=F'46'
         MVC   92(4,13),=F'1'
         MVC   96(4,13),=F'1'
         LA    2,104(,13)
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(@@NWTX99)
         BALR  14,15
         LTR   15,15 ==> tu
         BE    @@L9
         MVC   88(4,13),0(11) ==> txt99
         ST    15,92(13) ==> tu
         LA    1,88(,13)
         L     15,=V(@@ARADD)
         BALR  14,15
         LR    4,15 ==> err
@@L9     EQU   *
         LR    15,4 ==> err
* Function '__txbfal' epilogue
         PDPEPIL
* Function '__txbfal' literal pool
         DS    0D
         LTORG
* Function '__txbfal' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'FULL'
         DC    X'0'
@@LC1    EQU   *
         DC    C'DOUBLE'
         DC    X'0'
         END
