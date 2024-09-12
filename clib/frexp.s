 TITLE '/home/mike/repos/crent370/clib/frexp.c'
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
* external function 'frexp' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'frexp'
FREXP    PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'frexp' code
         LD    2,0(11) ==> x
         L     6,8(11) ==> exp
         LD    0,=D'0.0E0' ==> split
         LTDR  2,2 ==> x
         BE    @@L1
         STD   2,80(,13) ==> x
         LM    4,5,80(13) ==> split
         STE   2,80(,13)
         L     2,80(,13)
         SRL   2,16
         SLL   2,16
         SRA   2,16
         LR    3,2
         N     3,=XL4'0000FFFF'
         SRL   3,8
         N     3,=F'127'
         MH    3,=H'4'
         A     3,=F'-256'
         ST    3,0(6) ==> exp
         N     2,=F'33023'
         SLL   2,16
         N     4,=F'65535'
         OR    4,2
         LR    2,4
         SRL   2,16
         SLL   2,16
         SRA   2,16
         O     2,=F'16384'
         SLL   2,16
         N     4,=F'65535'
         OR    4,2
         B     @@L4
@@L9     EQU   *
         STM   4,5,80(13) ==> split
         LD    0,80(,13) ==> split
         ADR   0,0 ==> split
         STD   0,80(,13) ==> split
         LM    4,5,80(13) ==> split
         L     2,0(6) ==> exp
         BCTR  2,0
         ST    2,0(6) ==> exp
@@L4     EQU   *
         ST    4,88(13) ==> split
         ST    5,4+88(13) ==> split
         LA    1,88(,13)
         L     15,=V(FABS)
         BALR  14,15
         CD    0,=D'5.0E-1' ==> split
         BNL   @@L5
         STM   4,5,80(13)
         LD    0,80(,13)
         LTDR  0,0
         BNE   @@L9
@@L5     EQU   *
         STM   4,5,80(13) ==> split
         LD    0,80(,13) ==> split
@@L1     EQU   *
* Function 'frexp' epilogue
         PDPEPIL
* Function 'frexp' literal pool
         DS    0D
         LTORG
* Function 'frexp' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
