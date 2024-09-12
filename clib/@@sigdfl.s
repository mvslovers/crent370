 TITLE '/home/mike/repos/crent370/clib/@@sigdfl.c'
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
* external function '__sigdfl' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  '__sigdfl'
@@SIGDFL PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__sigdfl' code
         L     3,0(11) ==> sig
         LR    2,3 ==> sig
         BCTR  2,0
         LA    4,5(0,0)
         CLR   2,4
         BH    @@L2
         LA    1,88(,13)
         L     15,=V(@@SIGHDL)
         BALR  14,15
         LR    2,3 ==> sig
         MH    2,=H'4'
         L     4,=A(@@SIGDFL)
         ST    4,0(2,15)
@@L2     EQU   *
         LA    2,1(0,0)
         CLR   3,2 ==> sig
         BNE   @@L1
         MVC   88(4,13),=F'12'
         LA    1,88(,13)
         L     15,=V(EXIT)
         BALR  14,15
@@L1     EQU   *
* Function '__sigdfl' epilogue
         PDPEPIL
* Function '__sigdfl' literal pool
         DS    0D
         LTORG
* Function '__sigdfl' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
