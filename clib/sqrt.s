 TITLE '/home/mike/repos/crent370/clib/sqrt.c'
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
* external function 'sqrt' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'sqrt'
SQRT     PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'sqrt' code
         LD    0,0(11) ==> x
         LTDR  0,0 ==> x
         BNL   @@L2
         LA    1,88(,13)
         L     15,=V(@@ERRNO)
         BALR  14,15
         MVC   0(4,15),=F'33'
         LD    2,=D'0.0E0'
         B     @@L1
@@L2     EQU   *
         LD    2,=D'0.0E0'
         LTDR  0,0 ==> x
         BE    @@L1
         STD   0,80(,13) ==> x
         LM    6,7,80(13) ==> xs
         LM    8,9,=D'1.0E0' ==> pow1
         CD    0,=D'1.0E0' ==> x
         BNL   @@L24
@@L9     EQU   *
         STM   6,7,80(13) ==> xs
         LD    0,80(,13)
         MD    0,=D'4.0E0'
         STD   0,80(,13)
         LM    6,7,80(13) ==> xs
         STM   8,9,80(13) ==> pow1
         LD    2,80(,13)
         MD    2,=D'5.0E-1'
         STD   2,80(,13)
         LM    8,9,80(13) ==> pow1
         CD    0,=D'1.0E0'
         BL    @@L9
@@L24    EQU   *
         STM   6,7,80(13) ==> xs
         LD    0,80(,13)
         CD    0,=D'4.0E0'
         BL    @@L26
@@L13    EQU   *
         STM   6,7,80(13) ==> xs
         LD    2,80(,13)
         MD    2,=D'2.5E-1'
         STD   2,80(,13)
         LM    6,7,80(13) ==> xs
         STM   8,9,80(13) ==> pow1
         LD    0,80(,13)
         ADR   0,0
         STD   0,80(,13)
         LM    8,9,80(13) ==> pow1
         STM   6,7,80(13) ==> xs
         LD    0,80(,13)
         CD    0,=D'4.0E0'
         BNL   @@L13
@@L26    EQU   *
         SLR   3,3 ==> i
         STM   6,7,80(13) ==> xs
         LD    2,80(,13) ==> yn
         MD    2,=D'5.0E-1' ==> yn
@@L22    EQU   *
         STM   6,7,80(13) ==> xs
         LD    0,80(,13)
         DDR   0,2 ==> yn
         ADR   0,2 ==> yn
         MD    0,=D'5.0E-1'
         STD   0,80(,13)
         LM    4,5,80(13) ==> ynn
         SDR   0,2 ==> yn
         STD   0,88(13)
         LA    1,88(,13)
         L     15,=V(FABS)
         BALR  14,15
         L     2,=V(@DBLMIN)
         SDR   2,2
         LE    2,0(2) ==> ._Fval
         MD    2,=D'1.0E1'
         CDR   0,2
         BNH   @@L15
         STM   4,5,80(13) ==> ynn
         LD    2,80(,13) ==> yn
         LA    2,10(0,0)
         CR    3,2 ==> i
         BH    @@L15
         A     3,=F'1' ==> i
         B     @@L22
@@L15    EQU   *
         STM   4,5,80(13) ==> ynn
         LD    2,80(,13)
         STM   8,9,80(13) ==> pow1
         LD    0,80(,13)
         MDR   2,0
@@L1     EQU   *
         LDR   0,2
* Function 'sqrt' epilogue
         PDPEPIL
* Function 'sqrt' literal pool
         DS    0D
         LTORG
* Function 'sqrt' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
