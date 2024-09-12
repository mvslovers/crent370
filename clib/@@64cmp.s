 TITLE '/home/mike/repos/crent370/clib/@@64cmp.c'
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
         
&FUNC    SETC '__64_cmp'
* Program text area
         DS    0F
         EJECT
* external function '__64_cmp' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  '__64_cmp'
@@64CMP  PDPPRLG CINDEX=0,FRAME=88,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__64_cmp' code
         L     3,0(11) ==> a
         L     15,4(11) ==> b
         LTR   3,3 ==> a
         BE    @@L2
         LTR   15,15 ==> b
         BE    @@L2
         DS    0H if (a->u64 > b->u64) return __64_LARGER;
         L     2,0(3) ==> .u64
         CL    2,0(15) ==> .u64
         BH    @@L4
         BNE   @@L3
         L     2,4(3) ==> .u64
         CL    2,4(15) ==> .u64
         BNH   @@L3
@@L4     EQU   *
         LA    15,1(0,0)
         B     @@L1
@@L3     EQU   *
         DS    0H if (a->u64 < b->u64) return __64_SMALLER;
         L     2,0(15) ==> .u64
         CL    2,0(3) ==> .u64
         BH    @@L6
         BNE   @@L2
         L     2,4(15) ==> .u64
         CL    2,4(3) ==> .u64
         BNH   @@L2
@@L6     EQU   *
         L     15,=F'-1'
         B     @@L1
@@L2     EQU   *
         DS    0H return __64_EQUAL;
         SLR   15,15
@@L1     EQU   *
* Function '__64_cmp' epilogue
         PDPEPIL
* Function '__64_cmp' literal pool
         DS    0D
         LTORG
* Function '__64_cmp' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
