 TITLE '/home/mike/repos/crent370/clib/@@fputs.c'
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
* Program text area
         DS    0F
         EJECT
* external function '__fputs' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  '__fputs'
@@FPUTS  PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__fputs' code
         L     4,0(11) ==> s
         L     5,4(11) ==> fp
         LH    2,40(5) ==> .flags
         N     2,=F'512'
         L     3,=F'-1' ==> i
         CH    2,=H'0'
         BNE   @@L3
         B     @@L2
@@L11    EQU   *
         LR    3,15 ==> i
         B     @@L3
@@L2     EQU   *
         SLR   3,3 ==> i
         IC    2,0(4) ==> s
         CLM   2,1,=XL1'00'
         BE    @@L3
@@L9     EQU   *
         SLR   2,2
         IC    2,0(3,4) ==> i
         ST    2,88(13)
         ST    5,92(13) ==> fp
         LA    1,88(,13)
         L     15,=V(@@FPUTC)
         BALR  14,15
         L     2,=F'-1'
         CLR   15,2 ==> i
         BE    @@L11
         A     3,=F'1' ==> i
         IC    2,0(3,4) ==> i
         CLM   2,1,=XL1'00'
         BNE   @@L9
@@L3     EQU   *
         LR    15,3 ==> i
* Function '__fputs' epilogue
         PDPEPIL
* Function '__fputs' literal pool
         DS    0D
         LTORG
* Function '__fputs' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
