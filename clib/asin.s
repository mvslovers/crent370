 TITLE '/home/mike/repos/crent370/clib/asin.c'
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
* external function 'asin' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'asin'
ASIN     PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'asin' code
         LM    4,5,0(11) ==> x,y
         STM   4,5,80(13) ==> x
         LD    0,80(,13)
         LTDR  0,0
         BNL   @@L2
         LCDR  0,0
         STD   0,88(13)
         LA    1,88(,13)
         L     15,=A(ASIN)
         BALR  14,15
         LCDR  2,0 ==> answer,x
         B     @@L1
@@L2     EQU   *
         STM   4,5,80(13) ==> x
         LD    2,80(,13)
         CD    0,=D'1.0E0'
         BNH   @@L4
         LA    1,88(,13)
         L     15,=V(@@ERRNO)
         BALR  14,15
         MVC   0(4,15),=F'33'
         LD    2,=D'9.99999999999999983034E72' ==> answer
         B     @@L1
@@L4     EQU   *
         STM   4,5,80(13) ==> x
         LD    0,80(,13)
         CD    2,=D'7.5E-1'
         BNH   @@L6
         MDR   0,0
         LD    2,=D'1.0E0'
         SDR   2,0
         STD   2,88(13)
         LA    1,88(,13)
         L     15,=V(SQRT)
         BALR  14,15
         STD   0,88(13) ==> x
         LA    1,88(,13)
         L     15,=A(ASIN)
         BALR  14,15
         LD    2,=D'1.570796326794896558E0' ==> answer
         SDR   2,0 ==> answer,x
         B     @@L1
@@L6     EQU   *
         LA    15,1(0,0) ==> i
         LR    2,4 ==> answer,x
         LR    3,5 ==> answer,x
         LD    4,=D'1.0E0' ==> coef
         STM   4,5,80(13) ==> answer
         LD    6,80(,13) ==> powx
@@L13    EQU   *
         MVC   80(4,13),=XL8'4E00000080000000'
         ST    15,84(,13) ==> i
         XI    84(13),128
         LD    2,80(,13) ==> work
         SD    2,=XL8'4E00000080000000' ==> work
         MDR   4,2 ==> work
         LDR   0,2 ==> work
         AD    0,=D'1.0E0'
         DDR   4,0 ==> coef
         STM   4,5,80(13) ==> x
         LD    0,80(,13)
         MDR   0,6 ==> powx
         STM   4,5,80(13) ==> x
         LD    6,80(,13) ==> powx
         MDR   6,0 ==> powx
         LDR   0,4 ==> coef
         MDR   0,6 ==> powx
         AD    2,=D'2.0E0'
         DDR   0,2 ==> term
         STM   2,3,80(13) ==> answer
         LD    2,80(,13)
         ADR   0,2 ==> answer
         CDR   2,0 ==> answer
         BE    @@L9
         STD   0,80(,13) ==> answer
         LM    2,3,80(13) ==> answer
         A     15,=F'2' ==> i
         B     @@L13
@@L9     EQU   *
         STM   2,3,80(13) ==> answer
         LD    2,80(,13) ==> answer
@@L1     EQU   *
         LDR   0,2 ==> answer
* Function 'asin' epilogue
         PDPEPIL
* Function 'asin' literal pool
         DS    0D
         LTORG
* Function 'asin' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
