 TITLE '/home/mike/repos/crent370/clib/@@vssteq.c'
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
* external function '__vssteq' prologue
* frame base=88, local stack=72, call args=24
&FUNC    SETC  '__vssteq'
@@VSSTEQ PDPPRLG CINDEX=0,FRAME=184,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__vssteq' code
         L     3,0(11) ==> vs
         LA    6,112(,13)
         LA    7,64(0,0)
         SLR   4,4
         LR    5,4
         MVCL  6,4
         MVC   176(4,13),=F'0' ==> rc
         ST    3,88(13) ==> vs
         MVC   92(4,13),4(11) ==> rec
         MVC   96(4,13),8(11) ==> reclen
         MVC   100(4,13),12(11) ==> key
         MVC   104(4,13),16(11) ==> keylen
         LA    1,88(,13)
         L     15,=V(@@VSMDFY)
         BALR  14,15
         MVC   188(4,3),=F'0' ==> .vsreset
         A     3,=F'104'
         LA    2,112(,13)
         MODCB RPL=(3),OPTCD=(KEQ),MF=(G,(2))
         LA    2,DONE
         POINT RPL=(3)
DONE     DS    0H
         ST    15,176(13) ==> rc
@@L2     EQU   *
         L     15,176(13) ==> rc
* Function '__vssteq' epilogue
         PDPEPIL
* Function '__vssteq' literal pool
         DS    0D
         LTORG
* Function '__vssteq' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
