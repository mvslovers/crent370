 TITLE '/home/mike/repos/crent370/clib/cos.c'
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
* external function 'cos' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'cos'
COS      PDPPRLG CINDEX=0,FRAME=88,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'cos' code
         LD    4,0(11) ==> x
         LDR   2,4 ==> x
         DD    2,=D'6.283185307179586232E0'
         LDR   0,2
         AD    0,=XL8'4F08000000000000'
         STD   0,80(,13)
         L     15,84(,13) ==> i
         MVC   80(4,13),=XL8'4E00000080000000'
         ST    15,84(,13) ==> i
         XI    84(13),128
         LD    0,80(,13)
         SD    0,=XL8'4E00000080000000'
         MD    0,=D'6.283185307179586232E0'
         SDR   4,0 ==> x
         STD   4,80(,13) ==> x
         LM    2,3,80(13) ==> x1
         LA    15,1(0,0) ==> i
         LD    6,=D'1.0E0' ==> answer
         LDR   2,6 ==> term,answer
@@L7     EQU   *
         MVC   80(4,13),=XL8'4E00000080000000'
         ST    15,84(,13) ==> i
         XI    84(13),128
         LD    0,80(,13) ==> work
         SD    0,=XL8'4E00000080000000' ==> work
         STM   2,3,80(13) ==> x1
         LD    4,80(,13)
         MDR   2,4
         MDR   2,4
         LCDR  2,2
         LDR   4,0 ==> work
         AD    4,=D'1.0E0'
         MDR   0,4
         DDR   2,0 ==> term
         LDR   0,6 ==> answer
         ADR   0,2 ==> answer,term
         CDR   6,0 ==> answer
         BE    @@L3
         LDR   6,0 ==> answer
         A     15,=F'2' ==> i
         B     @@L7
@@L3     EQU   *
         LDR   0,6 ==> answer
* Function 'cos' epilogue
         PDPEPIL
* Function 'cos' literal pool
         DS    0D
         LTORG
* Function 'cos' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
