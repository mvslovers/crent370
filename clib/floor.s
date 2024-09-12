 TITLE '/home/mike/repos/crent370/clib/floor.c'
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
* external function 'floor' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'floor'
FLOOR    PDPPRLG CINDEX=0,FRAME=88,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'floor' code
         LD    2,0(11) ==> x
         LTDR  2,2 ==> x
         BNL   @@L2
         LDR   0,2 ==> x
         AD    0,=XL8'4F08000000000000'
         STD   0,80(,13)
         L     15,84(,13) ==> y
         MVC   80(4,13),=XL8'4E00000080000000'
         ST    15,84(,13) ==> y
         XI    84(13),128
         LD    0,80(,13)
         SD    0,=XL8'4E00000080000000'
         CDR   0,2 ==> x
         BE    @@L6
         BCTR  15,0 ==> y
         B     @@L6
@@L2     EQU   *
         LDR   0,2 ==> x
         AD    0,=XL8'4F08000000000000'
         STD   0,80(,13)
         L     15,84(,13) ==> y
@@L6     EQU   *
         MVC   80(4,13),=XL8'4E00000080000000'
         ST    15,84(,13) ==> y
         XI    84(13),128
         LD    0,80(,13)
         SD    0,=XL8'4E00000080000000'
* Function 'floor' epilogue
         PDPEPIL
* Function 'floor' literal pool
         DS    0D
         LTORG
* Function 'floor' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
