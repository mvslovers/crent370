 TITLE '/home/mike/repos/crent370/clib/strncmpi.c'
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
* external function 'strncmpi' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'strncmpi'
STRNCMPI PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'strncmpi' code
         L     7,8(11) ==> n
         SLR   4,4 ==> x
         L     6,0(11) ==> p1,s1
         L     5,4(11) ==> p2,s2
         CLR   4,7 ==> x,n
         BNL   @@L12
@@L10    EQU   *
         SLR   2,2
         IC    2,0(4,6) ==> x
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(TOLOWER)
         BALR  14,15
         LR    3,15 ==> c1
         SLR   2,2
         IC    2,0(4,5) ==> x
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(TOLOWER)
         BALR  14,15
         L     2,=F'-1' ==> c1
         STC   15,80(,13) ==> c2
         CLM   3,1,80(13) ==> c1
         BL    @@L1
         LA    2,1(0,0) ==> c1
         BH    @@L1
         SLR   2,2 ==> c1
         CLM   3,1,=XL1'00' ==> c1
         BE    @@L1
         A     4,=F'1' ==> x
         CLR   4,7 ==> x,n
         BL    @@L10
@@L12    EQU   *
         SLR   2,2 ==> c1
@@L1     EQU   *
         LR    15,2 ==> c1
* Function 'strncmpi' epilogue
         PDPEPIL
* Function 'strncmpi' literal pool
         DS    0D
         LTORG
* Function 'strncmpi' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
