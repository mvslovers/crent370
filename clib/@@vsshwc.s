 TITLE '/home/mike/repos/crent370/clib/@@vsshwc.c'
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
* external function '__vsshwc' prologue
* frame base=88, local stack=72, call args=16
&FUNC    SETC  '__vsshwc'
@@VSSHWC PDPPRLG CINDEX=0,FRAME=176,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__vsshwc' code
         L     5,0(11) ==> acb
         L     4,8(11) ==> buf
         SLR   2,2
         ST    2,168(13)
         LA    8,104(,13)
         LA    9,16(0,0)
         LR    6,2
         LR    7,2
         MVCL  8,6
         L     2,12(11) ==> buflen
         STH   2,0(4) ==> .shwlen1
         LA    3,120(,13)
         ST    3,88(13)
         MVC   92(4,13),=F'44'
         MVC   96(4,13),4(11) ==> name
         MVC   100(4,13),=F'64'
         LA    1,88(,13)
         L     15,=V(STRCPYP)
         BALR  14,15
         LA    2,104(,13)
         SHOWCAT ACB=(5),AREA=(4),NAME=(3),MF=(B,(2)) ==> acb,buf
         SHOWCAT MF=(E,(2))
         ST    15,168(13) ==> rc
         L     15,168(13)
* Function '__vsshwc' epilogue
         PDPEPIL
* Function '__vsshwc' literal pool
         DS    0D
         LTORG
* Function '__vsshwc' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
