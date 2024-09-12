 TITLE '/home/mike/repos/crent370/clib/@@vstell.c'
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
* external function '__vstell' prologue
* frame base=88, local stack=72, call args=0
&FUNC    SETC  '__vstell'
@@VSTELL PDPPRLG CINDEX=0,FRAME=160,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__vstell' code
         MVC   152(4,13),=F'0'
         LA    4,88(,13)
         LA    5,64(0,0)
         SLR   2,2
         LR    3,2
         MVCL  4,2
         L     4,0(11) ==> vs
         A     4,=F'104'
         LA    3,88(,13)
         LA    2,152(,13)
         SHOWCB RPL=(4),FIELDS=RBA,AREA=(2),LENGTH=4,MF=(G,(3))
@@L2     EQU   *
         L     15,152(13)
* Function '__vstell' epilogue
         PDPEPIL
* Function '__vstell' literal pool
         DS    0D
         LTORG
* Function '__vstell' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
