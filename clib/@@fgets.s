 TITLE '/home/mike/repos/crent370/clib/@@fgets.c'
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
* external function '__fgets' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  '__fgets'
@@FGETS  PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__fgets' code
         L     4,0(11) ==> s
         L     3,4(11) ==> n
         L     5,8(11) ==> fp
         LH    2,40(5) ==> .flags
         N     2,=F'513'
         CH    2,=H'0'
         BNE   @@L13
         BCTR  3,0 ==> n
         SLR   2,2 ==> cnt
         CR    2,3 ==> cnt,n
         BNL   @@L5
@@L10    EQU   *
         ST    5,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(@@FGETC)
         BALR  14,15
         L     6,=F'-1'
         CLR   15,6 ==> c
         BE    @@L5
         STC   15,0(2,4) ==> c,cnt
         A     2,=F'1' ==> cnt
         LA    6,21(0,0)
         CR    15,6 ==> c
         BE    @@L5
         CR    2,3 ==> cnt,n
         BL    @@L10
@@L5     EQU   *
         LTR   2,2 ==> cnt
         BNE   @@L11
         L     3,=F'-1'
         CLR   15,3 ==> c
         BNE   @@L11
@@L13    EQU   *
         SLR   4,4 ==> s
         B     @@L3
@@L11    EQU   *
         SLR   6,6
         STC   6,0(2,4) ==> cnt
@@L3     EQU   *
         LR    15,4 ==> s
* Function '__fgets' epilogue
         PDPEPIL
* Function '__fgets' literal pool
         DS    0D
         LTORG
* Function '__fgets' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
