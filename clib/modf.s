 TITLE '/home/mike/repos/crent370/clib/modf.c'
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
* external function 'modf' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'modf'
MODF     PDPPRLG CINDEX=0,FRAME=88,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'modf' code
         LD    2,0(11) ==> value
         SLR   15,15 ==> neg
         LTDR  2,2 ==> value
         BNL   @@L2
         LA    15,1(0,0) ==> neg
         LCDR  2,2 ==> value
@@L2     EQU   *
         LDR   0,2 ==> value
         AD    0,=XL8'4F08000000000000'
         STD   0,80(,13)
         L     2,84(,13) ==> i
         MVC   80(4,13),=XL8'4E00000080000000'
         ST    2,84(,13) ==> i
         XI    84(13),128
         LD    0,80(,13)
         SD    0,=XL8'4E00000080000000'
         SDR   2,0 ==> value
         LTR   15,15 ==> neg
         BE    @@L4
         LCDR  2,2 ==> value
         LCR   2,2 ==> i
@@L4     EQU   *
         MVC   80(4,13),=XL8'4E00000080000000'
         ST    2,84(,13) ==> i
         XI    84(13),128
         LD    0,80(,13)
         SD    0,=XL8'4E00000080000000'
         L     2,8(11) ==> iptr
         STD   0,0(2) ==> iptr
         LDR   0,2 ==> value
* Function 'modf' epilogue
         PDPEPIL
* Function 'modf' literal pool
         DS    0D
         LTORG
* Function 'modf' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
