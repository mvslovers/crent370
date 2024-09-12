 TITLE '/home/mike/repos/crent370/clib/fmod.c'
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
* external function 'fmod' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'fmod'
FMOD     PDPPRLG CINDEX=0,FRAME=88,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'fmod' code
         LD    6,0(11) ==> x
         LD    4,8(11) ==> y
         LD    0,=D'0.0E0'
         LTDR  4,4 ==> y
         BE    @@L1
         LDR   2,6 ==> x
         DDR   2,4 ==> y
         LDR   0,2
         AD    0,=XL8'4F08000000000000'
         STD   0,80(,13)
         L     2,84(,13) ==> imod
         MVC   80(4,13),=XL8'4E00000080000000'
         ST    2,84(,13) ==> imod
         XI    84(13),128
         LD    0,80(,13)
         SD    0,=XL8'4E00000080000000'
         MDR   0,4 ==> y
         SDR   6,0 ==> x
         LDR   0,6 ==> x
@@L1     EQU   *
* Function 'fmod' epilogue
         PDPEPIL
* Function 'fmod' literal pool
         DS    0D
         LTORG
* Function 'fmod' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
