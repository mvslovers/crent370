 TITLE '/home/mike/repos/crent370/clib/exp.c'
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
* external function 'exp' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'exp'
EXP      PDPPRLG CINDEX=0,FRAME=88,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'exp' code
         LD    6,0(11) ==> x
         LA    15,2(0,0) ==> i
         LDR   4,6 ==> answer,x
         LDR   0,6 ==> term,answer
@@L7     EQU   *
         MVC   80(4,13),=XL8'4E00000080000000'
         ST    15,84(,13) ==> i
         XI    84(13),128
         LD    2,80(,13) ==> work
         SD    2,=XL8'4E00000080000000' ==> work
         MDR   0,6 ==> x
         DDR   0,2 ==> term,work
         LDR   2,4 ==> answer
         ADR   2,0 ==> answer,term
         CDR   4,2 ==> answer
         BE    @@L3
         LDR   4,2 ==> answer
         A     15,=F'1' ==> i
         B     @@L7
@@L3     EQU   *
         AD    4,=D'1.0E0' ==> answer
         LDR   0,4 ==> answer
* Function 'exp' epilogue
         PDPEPIL
* Function 'exp' literal pool
         DS    0D
         LTORG
* Function 'exp' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
