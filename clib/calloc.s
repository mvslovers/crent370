 TITLE '/home/mike/repos/crent370/clib/calloc.c'
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
* external function 'calloc' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'calloc'
CALLOC   PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'calloc' code
         SLR   2,2 ==> size
         SLR   3,3 ==> size
         L     3,4(11) ==> size
         M     2,0(11) ==> size,nmemb
         A     3,=F'7' ==> total
         N     3,=F'16777208' ==> total
         ST    3,88(13) ==> total
         LA    1,88(,13)
         L     15,=V(MALLOC)
         BALR  14,15
         LR    2,15 ==> ptr
         LTR   15,15 ==> ptr
         BE    @@L2
         
* Clear allocated memory
         LR    14,2   => ptr ==> ptr
         LR    15,3   == total size ==> total
         SLR   0,0
         LR    1,0
         MVCL  14,0

@@L2     EQU   *
         LR    15,2 ==> ptr
* Function 'calloc' epilogue
         PDPEPIL
* Function 'calloc' literal pool
         DS    0D
         LTORG
* Function 'calloc' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
