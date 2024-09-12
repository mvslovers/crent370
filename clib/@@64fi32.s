 TITLE '/home/mike/repos/crent370/clib/@@64fi32.c'
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
         
&FUNC    SETC '__64_from_i32'
* Program text area
         DS    0F
         EJECT
* external function '__64_from_i32' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  '__64_from_i32'
@@64FI32 PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__64_from_i32' code
         L     15,0(11) ==> n
         L     2,4(11) ==> i
         LTR   15,15 ==> n
         BE    @@L1
         MVC   0(4,15),=F'0' ==> .u32
         MVC   4(4,15),=F'0' ==> .u32
         LTR   2,2 ==> i
         BNL   @@L3
         ST    15,88(13) ==> n
         LCR   2,2 ==> i
         ST    2,92(13)
         ST    15,96(13) ==> n
         LA    1,88(,13)
         L     15,=V(@@64SU32)
         BALR  14,15
         B     @@L1
@@L3     EQU   *
         ST    2,4(15) ==> i,u32
@@L1     EQU   *
* Function '__64_from_i32' epilogue
         PDPEPIL
* Function '__64_from_i32' literal pool
         DS    0D
         LTORG
* Function '__64_from_i32' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
