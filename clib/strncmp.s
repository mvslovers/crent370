 TITLE '/home/mike/repos/crent370/clib/strncmp.c'
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
* external function 'strncmp' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'strncmp'
STRNCMP  PDPPRLG CINDEX=0,FRAME=88,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'strncmp' code
         L     6,8(11) ==> n
         SLR   3,3 ==> x
         L     4,0(11) ==> p1,s1
         L     5,4(11) ==> p2,s2
         CLR   3,6 ==> x,n
         BNL   @@L12
@@L10    EQU   *
         IC    2,0(3,4) ==> x
         IC    7,0(3,5) ==> x
         L     15,=F'-1'
         STC   7,80(,13)
         CLM   2,1,80(13)
         BL    @@L1
         IC    2,0(3,4) ==> x
         IC    7,0(3,5) ==> x
         LA    15,1(0,0)
         STC   7,80(,13)
         CLM   2,1,80(13)
         BH    @@L1
         IC    2,0(3,4) ==> x
         SLR   15,15
         CLM   2,1,=XL1'00'
         BE    @@L1
         A     3,=F'1' ==> x
         CLR   3,6 ==> x,n
         BL    @@L10
@@L12    EQU   *
         SLR   15,15
@@L1     EQU   *
* Function 'strncmp' epilogue
         PDPEPIL
* Function 'strncmp' literal pool
         DS    0D
         LTORG
* Function 'strncmp' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
