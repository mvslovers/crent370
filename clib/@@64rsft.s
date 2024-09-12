 TITLE '/home/mike/repos/crent370/clib/@@64rsft.c'
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
         
&FUNC    SETC '__64_rshift'
* Program text area
         DS    0F
         EJECT
* external function '__64_rshift' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  '__64_rshift'
@@64RSFT PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__64_rshift' code
         L     3,0(11) ==> a
         L     6,4(11) ==> b
         L     5,8(11) ==> nbits
         LR    2,5 ==> nbits
         LTR   5,5 ==> nbits
         BNL   @@L2
         A     2,=F'15' ==> nbits
@@L2     EQU   *
         SRA   2,4 ==> nwords
         LTR   3,3 ==> a
         BE    @@L1
         LTR   6,6 ==> b
         BE    @@L1
         LTR   5,5 ==> nbits
         BL    @@L1
         ST    3,88(13) ==> a
         ST    6,92(13) ==> b
         LA    1,88(,13)
         L     15,=V(@@64COPY)
         BALR  14,15
         LTR   2,2 ==> nwords
         BE    @@L4
         ST    6,88(13) ==> b
         ST    2,92(13) ==> nwords
         LA    1,88(,13)
         L     15,=V(@@64RSHW)
         BALR  14,15
         MH    2,=H'16'
         SR    5,2 ==> nbits
@@L4     EQU   *
         LTR   5,5 ==> nbits
         BE    @@L1
         LA    15,3(0,0) ==> i
         L     8,=F'-2'
         LA    7,16(0,0)
         SR    7,5 ==> nbits
@@L10    EQU   *
         LR    4,15 ==> i
         MH    4,=H'2'
         LH    3,0(4,6) ==> .array
         N     3,=XL4'0000FFFF'
         SRA   3,0(5) ==> nbits
         AR    4,6 ==> b
         LH    2,0(8,4) ==> .array
         N     2,=XL4'0000FFFF'
         SLL   2,0(7)
         OR    3,2
         STH   3,0(4) ==> .array
         BCTR  15,0 ==> i
         LTR   15,15 ==> i
         BH    @@L10
         LH    2,0(6) ==> .array
         N     2,=XL4'0000FFFF'
         SRA   2,0(5) ==> nbits
         STH   2,0(6) ==> .array
@@L1     EQU   *
* Function '__64_rshift' epilogue
         PDPEPIL
* Function '__64_rshift' literal pool
         DS    0D
         LTORG
* Function '__64_rshift' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
