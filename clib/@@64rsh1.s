 TITLE '/home/mike/repos/crent370/clib/@@64rsh1.c'
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
         
&FUNC    SETC '__64_rshift_one_bit'
* Program text area
         DS    0F
         EJECT
* external function '__64_rshift_one_bit' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  '__64_rshift_one_bit'
@@64RSH1 PDPPRLG CINDEX=0,FRAME=88,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__64_rshift_one_bit' code
         L     5,0(11) ==> a
         LTR   5,5 ==> a
         BE    @@L1
         LA    15,3(0,0) ==> i
         L     6,=F'-2'
@@L7     EQU   *
         LR    2,15 ==> i
         MH    2,=H'2'
         LH    4,0(2,5) ==> .array
         N     4,=XL4'0000FFFF'
         SRL   4,1
         AR    2,5 ==> a
         LH    3,0(6,2) ==> .array
         N     3,=XL4'0000FFFF'
         SLL   3,15
         SLL   3,16
         SRA   3,16
         OR    4,3
         STH   4,0(2) ==> .array
         BCTR  15,0 ==> i
         LTR   15,15 ==> i
         BH    @@L7
         LH    2,0(5) ==> .array
         N     2,=XL4'0000FFFF'
         SRL   2,1
         STH   2,0(5) ==> .array
@@L1     EQU   *
* Function '__64_rshift_one_bit' epilogue
         PDPEPIL
* Function '__64_rshift_one_bit' literal pool
         DS    0D
         LTORG
* Function '__64_rshift_one_bit' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
