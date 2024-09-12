 TITLE '/home/mike/repos/crent370/clib/@@stymd.c'
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
* external function '__stymd' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  '__stymd'
@@STYMD  PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__stymd' code
         SLR   2,2 ==> n
         SLR   3,3 ==> n
         LR    4,2 ==> n
         LR    5,3 ==> n
         LR    8,2
         LR    9,3
         L     6,0(11) ==> scalar
         L     7,4(11) ==> pyr
         LR    2,6 ==> scalar
         MH    2,=H'400'
         SRDA  2,32 ==> n
         L     15,=F'146097'
         DR    2,15 ==> n
         B     @@L2
@@L5     EQU   *
         A     3,=F'1' ==> n
@@L2     EQU   *
         ST    3,88(13) ==> n
         LA    1,88(,13)
         L     15,=V(@@YTD)
         BALR  14,15
         CR    15,6 ==> scalar
         BL    @@L5
         LR    4,6 ==> scalar
         MH    4,=H'400'
         SRDA  4,32 ==> n
         L     2,=F'146097'
         DR    4,2 ==> n
         LR    3,5 ==> n
         B     @@L6
@@L10    EQU   *
         A     3,=F'1' ==> n
@@L6     EQU   *
         ST    3,88(13) ==> n
         LA    1,88(,13)
         L     15,=V(@@YTD)
         BALR  14,15
         CR    15,6 ==> scalar
         BL    @@L10
         ST    3,0(7) ==> n,pyr
         LR    2,3 ==> n
         BCTR  2,0
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@YTD)
         BALR  14,15
         LR    3,6 ==> n,scalar
         SR    3,15 ==> n
         LA    4,59(0,0)
         CLR   3,4 ==> n
         BNH   @@L11
         A     3,=F'2' ==> n
         MVC   88(4,13),0(7) ==> pyr
         LA    1,88(,13)
         L     15,=V(@@ISLEAP)
         BALR  14,15
         LTR   15,15
         BE    @@L11
         LR    2,3 ==> n
         BCTR  2,0 ==> n
         LA    15,62(0,0)
         CLR   3,15 ==> n
         BH    @@L14
         LR    2,3 ==> n
         A     2,=F'-2' ==> n
@@L14    EQU   *
         LR    3,2 ==> n
@@L11    EQU   *
         LR    2,3 ==> n
         MH    2,=H'100'
         LR    8,2
         A     8,=F'3007'
         SRDL  8,32
         LA    2,3057(0,0)
         DR    8,2
         L     2,8(11) ==> pmo
         ST    9,0(2) ==> pmo
         ST    9,88(13)
         LA    1,88(,13)
         L     15,=V(@@MTD)
         BALR  14,15
         SR    3,15
         L     2,12(11) ==> pday
         ST    3,0(2) ==> pday
* Function '__stymd' epilogue
         PDPEPIL
* Function '__stymd' literal pool
         DS    0D
         LTORG
* Function '__stymd' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
