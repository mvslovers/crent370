 TITLE '/home/mike/repos/crent370/clib/@@txdest.c'
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
* external function '__txdest' prologue
* frame base=88, local stack=40, call args=16
&FUNC    SETC  '__txdest'
@@TXDEST PDPPRLG CINDEX=0,FRAME=144,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__txdest' code
         L     5,0(11) ==> txt99
         L     3,4(11) ==> dest
         LA    4,1(0,0) ==> err
         LTR   3,3 ==> dest
         BE    @@L3
         ST    3,88(13) ==> dest
         MVC   92(4,13),=F'75'
         LA    1,88(,13)
         L     15,=V(STRCHR)
         BALR  14,15
         LTR   15,15 ==> len
         BE    @@L4
         ST    3,88(13) ==> dest
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         LR    2,15 ==> len
         LA    6,39(0,0)
         CLR   15,6 ==> len
         BH    @@L3
         LA    6,104(,13)
         ST    6,88(13)
         ST    3,92(13) ==> dest
         ST    15,96(13) ==> len
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         SLR   3,3
         STC   3,104(13,2) ==> buf
         ST    6,88(13)
         MVC   92(4,13),=F'75'
         LA    1,88(,13)
         L     15,=V(STRCHR)
         BALR  14,15
         LR    3,15 ==> p
         LTR   15,15 ==> p
         BE    @@L3
         MVI   0(15),0 ==> p
         AR    3,4 ==> p
         ST    3,88(13) ==> p
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         MVC   88(4,13),=F'99'
         ST    4,92(13) ==> err
         ST    15,96(13) ==> len
         ST    3,100(13) ==> p
         LA    1,88(,13)
         L     15,=V(@@NWTX99)
         BALR  14,15
         LTR   15,15 ==> tu
         BE    @@L3
         ST    5,88(13) ==> txt99
         ST    15,92(13) ==> tu
         LA    1,88(,13)
         L     15,=V(@@ARADD)
         BALR  14,15
         LTR   15,15 ==> len
         BNE   @@L3
         ST    6,88(13)
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         MVC   88(4,13),=F'88'
         ST    4,92(13) ==> err
         ST    15,96(13) ==> len
         ST    6,100(13)
         B     @@L15
@@L4     EQU   *
         ST    3,88(13) ==> dest
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         MVC   88(4,13),=F'88'
         MVC   92(4,13),=F'1'
         ST    15,96(13) ==> len
         ST    3,100(13) ==> dest
@@L15    EQU   *
         LA    1,88(,13)
         L     15,=V(@@NWTX99)
         BALR  14,15
         LTR   15,15 ==> tu
         BE    @@L3
         ST    5,88(13) ==> txt99
         ST    15,92(13) ==> tu
         LA    1,88(,13)
         L     15,=V(@@ARADD)
         BALR  14,15
         LTR   15,15 ==> len
         BNE   @@L3
         SLR   4,4 ==> err
@@L3     EQU   *
         LR    15,4 ==> err
* Function '__txdest' epilogue
         PDPEPIL
* Function '__txdest' literal pool
         DS    0D
         LTORG
* Function '__txdest' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
