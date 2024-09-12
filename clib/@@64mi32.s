 TITLE '/home/mike/repos/crent370/clib/@@64mi32.c'
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
         
&FUNC    SETC '__64_mul_i32'
* Program text area
         DS    0F
         EJECT
* external function '__64_mul_i32' prologue
* frame base=88, local stack=8, call args=16
&FUNC    SETC  '__64_mul_i32'
@@64MI32 PDPPRLG CINDEX=0,FRAME=112,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__64_mul_i32' code
         L     3,0(11) ==> a
         L     5,4(11) ==> b
         L     4,8(11) ==> c
         LTR   3,3 ==> a
         BE    @@L1
         LTR   4,4 ==> c
         BE    @@L1
         LA    2,104(,13)
         ST    2,88(13)
         LPR   2,5 ==> b
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(@@64FU32)
         BALR  14,15
         LTR   5,5 ==> b
         BNL   @@L3
         ST    3,88(13) ==> a
         LA    2,104(,13)
         ST    2,92(13)
         ST    4,96(13) ==> c
         LA    1,88(,13)
         L     15,=V(@@64DIV)
         BALR  14,15
         B     @@L1
@@L3     EQU   *
         ST    3,88(13) ==> a
         LA    2,104(,13)
         ST    2,92(13)
         ST    4,96(13) ==> c
         LA    1,88(,13)
         L     15,=V(@@64MUL)
         BALR  14,15
@@L1     EQU   *
* Function '__64_mul_i32' epilogue
         PDPEPIL
* Function '__64_mul_i32' literal pool
         DS    0D
         LTORG
* Function '__64_mul_i32' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
