 TITLE '/home/mike/repos/crent370/clib/@@64su64.c'
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
         
&FUNC    SETC '__64_sub_u64'
* Program text area
         DS    0F
         EJECT
* external function '__64_sub_u64' prologue
* frame base=88, local stack=8, call args=16
&FUNC    SETC  '__64_sub_u64'
@@64SU64 PDPPRLG CINDEX=0,FRAME=112,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__64_sub_u64' code
         L     3,0(11) ==> a
         L     4,4(11) ==> b
         L     5,4+4(11) ==> b
         L     6,12(11) ==> c
         LTR   3,3 ==> a
         BE    @@L1
         LTR   6,6 ==> c
         BE    @@L1
         LA    2,104(,13)
         ST    2,88(13)
         ST    4,92(13) ==> b
         ST    5,4+92(13) ==> b
         LA    1,88(,13)
         L     15,=V(@@64FU64)
         BALR  14,15
         ST    3,88(13) ==> a
         LA    2,104(,13)
         ST    2,92(13)
         ST    6,96(13) ==> c
         LA    1,88(,13)
         L     15,=V(@@64SUB)
         BALR  14,15
@@L1     EQU   *
* Function '__64_sub_u64' epilogue
         PDPEPIL
* Function '__64_sub_u64' literal pool
         DS    0D
         LTORG
* Function '__64_sub_u64' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
