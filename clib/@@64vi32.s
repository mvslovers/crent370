 TITLE '/home/mike/repos/crent370/clib/@@64vi32.c'
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
         
&FUNC    SETC '__64_divmod_i32'
* Program text area
         DS    0F
         EJECT
* external function '__64_divmod_i32' prologue
* frame base=88, local stack=8, call args=16
&FUNC    SETC  '__64_divmod_i32'
@@64VI32 PDPPRLG CINDEX=0,FRAME=112,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__64_divmod_i32' code
         L     3,0(11) ==> a
         L     4,8(11) ==> c
         L     5,12(11) ==> d
         LTR   3,3 ==> a
         BE    @@L1
         LTR   4,4 ==> c
         BE    @@L1
         LTR   5,5 ==> d
         BE    @@L1
         LA    2,104(,13)
         ST    2,88(13)
         MVC   92(4,13),4(11) ==> b
         LA    1,88(,13)
         L     15,=V(@@64FI32)
         BALR  14,15
         ST    3,88(13) ==> a
         LA    2,104(,13)
         ST    2,92(13)
         ST    4,96(13) ==> c
         ST    5,100(13) ==> d
         LA    1,88(,13)
         L     15,=V(@@64DMOD)
         BALR  14,15
@@L1     EQU   *
* Function '__64_divmod_i32' epilogue
         PDPEPIL
* Function '__64_divmod_i32' literal pool
         DS    0D
         LTORG
* Function '__64_divmod_i32' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
