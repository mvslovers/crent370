 TITLE '/home/mike/repos/crent370/clib/bsearch.c'
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
* external function 'bsearch' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'bsearch'
BSEARCH  PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'bsearch' code
         SLR   6,6 ==> size
         SLR   7,7 ==> size
         L     8,4(11) ==> base
         L     2,8(11) ==> nmemb
         L     9,12(11) ==> size
         LTR   2,2 ==> nmemb
         BE    @@L11
@@L9     EQU   *
         LR    3,2 ==> try,nmemb
         SRL   3,1 ==> try
         LR    7,9 ==> size
         MR    6,3 ==> size,try
         LR    4,8 ==> ptr,base
         AR    4,7 ==> ptr,size
         ST    4,88(13) ==> ptr
         MVC   92(4,13),0(11) ==> key
         L     5,16(11) ==> compar
         LA    1,88(,13)
         LA    15,0(5)
         BALR  14,15
         LR    5,4 ==> ptr
         LTR   15,15 ==> res
         BE    @@L1
         BNL   @@L7
         SR    2,3 ==> nmemb,try
         BCTR  2,0 ==> nmemb
         LR    8,4 ==> base,ptr
         AR    8,9 ==> base,size
         B     @@L2
@@L7     EQU   *
         LR    2,3 ==> nmemb,try
@@L2     EQU   *
         LTR   2,2 ==> nmemb
         BNE   @@L9
@@L11    EQU   *
         SLR   5,5 ==> ptr
@@L1     EQU   *
         LR    15,5 ==> ptr
* Function 'bsearch' epilogue
         PDPEPIL
* Function 'bsearch' literal pool
         DS    0D
         LTORG
* Function 'bsearch' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
