 TITLE '/home/mike/repos/crent370/clib/@@64add.c'
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
         
&FUNC    SETC '__64_add'
* Program text area
         DS    0F
         EJECT
* external function '__64_add' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  '__64_add'
@@64ADD  PDPPRLG CINDEX=0,FRAME=88,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__64_add' code
         L     7,0(11) ==> a
         L     6,4(11) ==> b
         L     5,8(11) ==> c
         SLR   4,4 ==> carry
         LTR   7,7 ==> a
         BE    @@L1
         LTR   6,6 ==> b
         BE    @@L1
         LTR   5,5 ==> c
         BE    @@L1
         LA    15,3(0,0) ==> i
@@L8     EQU   *
         LR    2,15 ==> i
         MH    2,=H'2'
         LH    3,0(2,7) ==> .array
         N     3,=XL4'0000FFFF'
         LH    2,0(2,6) ==> .array
         N     2,=XL4'0000FFFF'
         AR    3,2
         LR    2,3 ==> tmp
         AR    2,4 ==> tmp,carry
         SLR   4,4 ==> carry
         L     3,=F'65535'
         CLR   2,3 ==> tmp
         BNH   @@L7
         LA    4,1(0,0) ==> carry
@@L7     EQU   *
         LR    3,15 ==> i
         MH    3,=H'2'
         N     2,=F'65535'
         STH   2,0(3,5) ==> .array
         BCTR  15,0 ==> i
         LTR   15,15 ==> i
         BNL   @@L8
@@L1     EQU   *
* Function '__64_add' epilogue
         PDPEPIL
* Function '__64_add' literal pool
         DS    0D
         LTORG
* Function '__64_add' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
