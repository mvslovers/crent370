 TITLE '/home/mike/repos/crent370/clib/@@64ou32.c'
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
         
&FUNC    SETC '__64_or_u32'
* Program text area
         DS    0F
         EJECT
* external function '__64_or_u32' prologue
* frame base=88, local stack=8, call args=8
&FUNC    SETC  '__64_or_u32'
@@64OU32 PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__64_or_u32' code
         L     4,0(11) ==> a
         L     5,8(11) ==> c
         LTR   4,4 ==> a
         BE    @@L1
         LTR   5,5 ==> c
         BE    @@L1
         LA    2,96(,13)
         ST    2,88(13)
         MVC   92(4,13),4(11) ==> b
         LA    1,88(,13)
         L     15,=V(@@64FU32)
         BALR  14,15
         L     2,0(4) ==> .u64
         O     2,96(13)
         L     3,4(4) ==> .u64
         O     3,100(13) ==> .u64
         ST    2,0(5) ==> .u64
         ST    3,4+0(5) ==> .u64
@@L1     EQU   *
* Function '__64_or_u32' epilogue
         PDPEPIL
* Function '__64_or_u32' literal pool
         DS    0D
         LTORG
* Function '__64_or_u32' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
