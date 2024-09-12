 TITLE '/home/mike/repos/crent370/clib/@@64sub.c'
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
         
&FUNC    SETC '__64_sub'
* Program text area
         DS    0F
         EJECT
* external function '__64_sub' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  '__64_sub'
@@64SUB  PDPPRLG CINDEX=0,FRAME=88,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__64_sub' code
         L     8,0(11) ==> a
         L     7,4(11) ==> b
         L     6,8(11) ==> c
         SLR   5,5 ==> borrow
         LTR   8,8 ==> a
         BE    @@L1
         LTR   7,7 ==> b
         BE    @@L1
         LTR   6,6 ==> c
         BE    @@L1
         LA    15,3(0,0) ==> i
@@L8     EQU   *
         LR    4,15 ==> i
         MH    4,=H'2'
         LH    3,0(4,8) ==> .array
         N     3,=XL4'0000FFFF'
         A     3,=F'65536' ==> tmp1
         LH    2,0(4,7) ==> .array
         N     2,=XL4'0000FFFF'
         AR    2,5 ==> tmp2,borrow
         SR    3,2 ==> res,tmp2
         LR    2,3 ==> res
         N     2,=F'65535'
         STH   2,0(4,6) ==> .array
         SLR   5,5 ==> borrow
         L     2,=F'65535'
         CLR   3,2 ==> res
         BH    @@L5
         LA    5,1(0,0) ==> borrow
@@L5     EQU   *
         BCTR  15,0 ==> i
         LTR   15,15 ==> i
         BNL   @@L8
@@L1     EQU   *
* Function '__64_sub' epilogue
         PDPEPIL
* Function '__64_sub' literal pool
         DS    0D
         LTORG
* Function '__64_sub' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
