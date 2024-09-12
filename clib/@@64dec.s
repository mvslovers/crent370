 TITLE '/home/mike/repos/crent370/clib/@@64dec.c'
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
         
&FUNC    SETC '__64_dec'
* Program text area
         DS    0F
         EJECT
* external function '__64_dec' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  '__64_dec'
@@64DEC  PDPPRLG CINDEX=0,FRAME=88,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__64_dec' code
         L     5,0(11) ==> n
         LTR   5,5 ==> n
         BE    @@L1
         LA    15,3(0,0) ==> i
@@L8     EQU   *
         LR    2,15 ==> i
         MH    2,=H'2'
         LH    4,0(2,5) ==> tmp,array
         LR    3,4 ==> res,tmp
         BCTR  3,0 ==> res
         STH   3,0(2,5) ==> res,array
         STH   4,80(,13) ==> tmp
         CLM   3,3,80(13) ==> res
         BNH   @@L1
         BCTR  15,0 ==> i
         LTR   15,15 ==> i
         BNL   @@L8
@@L1     EQU   *
* Function '__64_dec' epilogue
         PDPEPIL
* Function '__64_dec' literal pool
         DS    0D
         LTORG
* Function '__64_dec' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
