 TITLE '/home/mike/repos/crent370/clib/div.c'
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
* external function 'div' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'div'
DIV      PDPPRLG CINDEX=0,FRAME=88,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'div' code
         SLR   6,6 ==> x
         SLR   7,7 ==> x
         LR    2,6 ==> numer
         LR    3,7 ==> numer
         LR    4,6 ==> numer
         LR    5,7 ==> numer
         LR    15,0
         L     8,0(11) ==> numer
         L     9,4(11) ==> denom
         LR    2,8 ==> numer
         SRDA  2,32 ==> numer
         DR    2,9 ==> numer,denom
         LR    6,3 ==> numer
         LR    4,8 ==> numer
         SRDA  4,32 ==> numer
         DR    4,9 ==> numer,denom
         LR    7,4 ==> x
         ST    6,0(15) ==> x,<result>
         ST    7,4+0(15) ==> x,<result>
* Function 'div' epilogue
         PDPEPIL
* Function 'div' literal pool
         DS    0D
         LTORG
* Function 'div' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
