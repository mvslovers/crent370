 TITLE '/home/mike/repos/crent370/clib/@@vsclos.c'
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
* external function '__vsclos' prologue
* frame base=88, local stack=8, call args=8
&FUNC    SETC  '__vsclos'
@@VSCLOS PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__vsclos' code
         L     4,0(11) ==> vs
         MVC   96(8,13),=F'0'
         LTR   4,4 ==> vs
         BE    @@L2
         IC    2,17(4) ==> .flags
         N     2,=F'-128'
         CLM   2,1,=XL1'00'
         BE    @@L3
         LR    3,4 ==> vs
         A     3,=F'24'
         LA    2,96(,13)
         MVC   0($CLSLEN,2),CLSMODEL
         CLOSE ((3)),MF=(E,(2))
@@L3     EQU   *
         ST    4,88(13) ==> vs
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
@@L2     EQU   *
         SLR   15,15
* Function '__vsclos' epilogue
         PDPEPIL
* Function '__vsclos' literal pool
         DS    0D
         LTORG
* Function '__vsclos' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         DS    0F
CLSMODEL CLOSE (*-*),MF=L
$CLSLEN  EQU   *-CLSMODEL
         END
