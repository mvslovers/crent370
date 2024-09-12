 TITLE '/home/mike/repos/crent370/clib/@@64isqr.c'
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
         
&FUNC    SETC '__64_isqrt'
* Program text area
         DS    0F
         EJECT
* external function '__64_isqrt' prologue
* frame base=88, local stack=32, call args=16
&FUNC    SETC  '__64_isqrt'
@@64ISQR PDPPRLG CINDEX=0,FRAME=136,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__64_isqrt' code
         L     3,0(11) ==> a
         L     4,4(11) ==> b
         LTR   3,3 ==> a
         BE    @@L1
         LTR   4,4 ==> b
         BE    @@L1
         LA    2,104(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@64INIT)
         BALR  14,15
         ST    3,88(13) ==> a
         LA    2,112(,13)
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(@@64COPY)
         BALR  14,15
         LA    2,112(,13)
         ST    2,88(13)
         LA    2,120(,13)
         ST    2,92(13)
         MVC   96(4,13),=F'1'
         LA    1,88(,13)
         L     15,=V(@@64RSFT)
         BALR  14,15
         B     @@L9
@@L8     EQU   *
         LA    2,120(,13)
         ST    2,88(13)
         ST    2,92(13)
         LA    2,128(,13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@64MUL)
         BALR  14,15
         LA    2,128(,13)
         ST    2,88(13)
         ST    3,92(13) ==> a
         LA    1,88(,13)
         L     15,=V(@@64CMP)
         BALR  14,15
         LTR   15,15
         BNH   @@L6
         LA    2,120(,13)
         ST    2,88(13)
         LA    2,112(,13)
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(@@64COPY)
         BALR  14,15
         LA    2,112(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@64DEC)
         BALR  14,15
         B     @@L7
@@L6     EQU   *
         LA    2,120(,13)
         ST    2,88(13)
         LA    2,104(,13)
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(@@64COPY)
         BALR  14,15
@@L7     EQU   *
         LA    2,112(,13)
         ST    2,88(13)
         LA    2,104(,13)
         ST    2,92(13)
         LA    2,120(,13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@64SUB)
         BALR  14,15
         LA    2,120(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@64RSH1)
         BALR  14,15
         LA    2,104(,13)
         ST    2,88(13)
         LA    2,120(,13)
         ST    2,92(13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@64ADD)
         BALR  14,15
@@L9     EQU   *
         LA    2,120(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@64INC)
         BALR  14,15
         LA    2,112(,13)
         ST    2,88(13)
         LA    2,104(,13)
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(@@64CMP)
         BALR  14,15
         LTR   15,15
         BH    @@L8
         LA    2,104(,13)
         ST    2,88(13)
         ST    4,92(13) ==> b
         LA    1,88(,13)
         L     15,=V(@@64COPY)
         BALR  14,15
@@L1     EQU   *
* Function '__64_isqrt' epilogue
         PDPEPIL
* Function '__64_isqrt' literal pool
         DS    0D
         LTORG
* Function '__64_isqrt' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
