 TITLE '/home/mike/repos/crent370/clib/pow.c'
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
* external function 'pow' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'pow'
POW      PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'pow' code
         LD    4,0(11) ==> x
         LM    2,3,8(11) ==> y
         SLR   4,4 ==> neg
         STM   2,3,80(13) ==> y
         LD    2,80(,13)
         LDR   0,2
         AD    0,=XL8'4F08000000000000'
         STD   0,80(,13)
         L     15,84(,13) ==> j
         MVC   80(4,13),=XL8'4E00000080000000'
         ST    15,84(,13) ==> j
         XI    84(13),128
         LD    0,80(,13) ==> yy
         SD    0,=XL8'4E00000080000000' ==> yy
         CDR   0,2 ==> yy
         BNE   @@L2
         LDR   2,4 ==> xx,x
         STM   2,3,80(13) ==> y
         LD    6,80(,13)
         LTDR  6,6
         BNL   @@L4
         LA    4,1(0,0) ==> neg
         LCR   15,15 ==> j
@@L4     EQU   *
         LD    0,=D'1.0E0' ==> xx
         STM   2,3,80(13) ==> y
         LD    6,80(,13)
         LTDR  6,6
         BE    @@L1
         BCTR  15,0 ==> j
         LTR   15,15 ==> j
         BNH   @@L18
@@L11    EQU   *
         MDR   2,4 ==> xx,x
         BCTR  15,0 ==> j
         LTR   15,15 ==> j
         BH    @@L11
@@L18    EQU   *
         LTR   4,4 ==> neg
         BE    @@L12
         LD    0,=D'1.0E0'
         DDR   0,2 ==> xx
         LDR   2,0 ==> xx
@@L12    EQU   *
         LDR   0,2 ==> xx
         B     @@L1
@@L2     EQU   *
         LTDR  4,4 ==> x
         BNL   @@L13
         LA    1,88(,13)
         L     15,=V(@@ERRNO)
         BALR  14,15
         MVC   0(4,15),=F'33'
         LD    0,=D'0.0E0' ==> xx
         B     @@L1
@@L13    EQU   *
         LD    0,=D'1.0E0' ==> xx
         STM   2,3,80(13) ==> y
         LD    2,80(,13)
         LTDR  2,2
         BE    @@L1
         STD   4,88(13) ==> x
         LA    1,88(,13)
         L     15,=V(LOG)
         BALR  14,15
         STM   2,3,80(13) ==> y
         LD    6,80(,13)
         MDR   0,6
         STD   0,88(13)
         LA    1,88(,13)
         L     15,=V(EXP)
         BALR  14,15
@@L1     EQU   *
* Function 'pow' epilogue
         PDPEPIL
* Function 'pow' literal pool
         DS    0D
         LTORG
* Function 'pow' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
