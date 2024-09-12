 TITLE '/home/mike/repos/crent370/clib/@@fputc.c'
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
* external function '__fputc' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  '__fputc'
@@FPUTC  PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__fputc' code
         L     6,0(11) ==> c
         L     4,4(11) ==> fp
         LR    5,6 ==> rc,c
         LH    3,40(4) ==> .flags
         LR    2,3
         N     2,=F'4096'
         CH    2,=H'0'
         BE    @@L3
         LR    2,3
         N     2,=F'512'
         CH    2,=H'0'
         BNE   @@L3
         LR    2,3
         N     2,=F'1024'
         CH    2,=H'0'
         BNE   @@L5
         LA    2,21(0,0)
         CLR   6,2 ==> rc
         BNE   @@L5
         L     2,24(4) ==> .filepos
         A     2,=F'1'
         ST    2,24(4) ==> .filepos
         ST    4,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(@@FFLUSH)
         BALR  14,15
         LTR   15,15 ==> rc
         BE    @@L3
         B     @@L10
@@L5     EQU   *
         L     2,32(4) ==> .upto
         CL    2,36(4) ==> .endbuf
         BNE   @@L8
         ST    4,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(@@FFLUSH)
         BALR  14,15
         LTR   15,15 ==> rc
         BE    @@L8
@@L10    EQU   *
         L     5,=F'-1' ==> rc
         B     @@L3
@@L8     EQU   *
         LR    2,4 ==> fp
         A     2,=F'32'
         L     3,0(2) ==> .upto
         STC   6,0(3) ==> c
         A     3,=F'1'
         ST    3,0(2) ==> .upto
         L     2,24(4) ==> .filepos
         A     2,=F'1'
         ST    2,24(4) ==> .filepos
@@L3     EQU   *
         LR    15,5 ==> rc
* Function '__fputc' epilogue
         PDPEPIL
* Function '__fputc' literal pool
         DS    0D
         LTORG
* Function '__fputc' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
