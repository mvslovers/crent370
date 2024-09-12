 TITLE '/home/mike/repos/crent370/clib/memcmp.c'
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
* external function 'memcmp' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'memcmp'
MEMCMP   PDPPRLG CINDEX=0,FRAME=88,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'memcmp' code
         L     5,8(11) ==> n
         SLR   15,15 ==> x
         L     4,0(11) ==> p1,s1
         L     3,4(11) ==> p2,s2
         CLR   15,5 ==> x,n
         BNL   @@L10
@@L8     EQU   *
         IC    2,0(15,4) ==> x
         IC    6,0(15,3) ==> x
         STC   6,80(,13)
         CLM   2,1,80(13)
         BNL   @@L5
         L     15,=F'-1'
         B     @@L1
@@L5     EQU   *
         IC    2,0(15,4) ==> x
         IC    6,0(15,3) ==> x
         STC   6,80(,13)
         CLM   2,1,80(13)
         BNH   @@L6
         LA    15,1(0,0)
         B     @@L1
@@L6     EQU   *
         A     15,=F'1' ==> x
         CLR   15,5 ==> x,n
         BL    @@L8
@@L10    EQU   *
         SLR   15,15
@@L1     EQU   *
* Function 'memcmp' epilogue
         PDPEPIL
* Function 'memcmp' literal pool
         DS    0D
         LTORG
* Function 'memcmp' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
