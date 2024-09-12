 TITLE '/home/mike/repos/crent370/clib/log.c'
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
* external function 'log' prologue
* frame base=88, local stack=8, call args=16
&FUNC    SETC  'log'
LOG      PDPPRLG CINDEX=0,FRAME=112,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'log' code
         LD    2,0(11) ==> x
         LTDR  2,2 ==> x
         BH    @@L2
         LA    1,88(,13)
         L     15,=V(@@ERRNO)
         BALR  14,15
         MVC   0(4,15),=F'33'
         LD    0,=D'9.99999999999999983034E72' ==> answer
         B     @@L1
@@L2     EQU   *
         LD    0,=D'0.0E0' ==> answer
         CD    2,=D'1.0E0' ==> x
         BE    @@L1
         STD   2,88(13) ==> x
         LA    2,104(,13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(FREXP)
         BALR  14,15
         SD    0,=D'1.0E0'
         STD   0,80(,13)
         LM    4,5,80(13) ==> xs
         LA    2,2(0,0) ==> i
         LDR   4,0 ==> answer,xs
         LDR   2,0 ==> term,answer
@@L11    EQU   *
         MVC   80(4,13),=XL8'4E00000080000000'
         ST    2,84(,13) ==> i
         XI    84(13),128
         LD    0,80(,13) ==> work
         SD    0,=XL8'4E00000080000000' ==> work
         STM   4,5,80(13) ==> xs
         LD    6,80(,13)
         MDR   2,6
         LCDR  2,2 ==> term
         LDR   6,2 ==> term
         DDR   6,0 ==> work
         LDR   0,6
         ADR   0,4 ==> answer
         CDR   4,0 ==> answer
         BE    @@L7
         LDR   4,0 ==> answer
         A     2,=F'1' ==> i
         B     @@L11
@@L7     EQU   *
         L     2,104(13)
         MVC   80(4,13),=XL8'4E00000080000000'
         ST    2,84(,13)
         XI    84(13),128
         LD    0,80(,13)
         SD    0,=XL8'4E00000080000000'
         MD    0,=D'6.93147180559945313982E-1'
         ADR   0,4 ==> answer
@@L1     EQU   *
* Function 'log' epilogue
         PDPEPIL
* Function 'log' literal pool
         DS    0D
         LTORG
* Function 'log' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
