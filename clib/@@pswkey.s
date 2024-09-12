 TITLE '/home/mike/repos/crent370/clib/@@pswkey.c'
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
         
&FUNC    SETC '__pswkey'
* Program text area
         DS    0F
         EJECT
* external function '__pswkey' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  '__pswkey'
@@PSWKEY PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__pswkey' code
         L     3,0(11) ==> savekey
         LA    1,88(,13)
         L     15,=V(@@AUTH)
         BALR  14,15
         LA    2,1(0,0) ==> rc
         LTR   15,15 ==> rc
         BE    @@L1
         LA    1,88(,13)
         L     15,=V(@@ISSUP)
         BALR  14,15
         LTR   15,15 ==> rc
         BE    @@L3
         IPK   0
         STC   2,0(,3) ==> savekey
         B     @@L4
@@L3     EQU   *
         MVC   88(4,13),=F'255'
         ST    3,92(13) ==> savekey
         LA    1,88(,13)
         L     15,=V(@@SUPER)
         BALR  14,15
         MVC   88(4,13),=F'255'
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@PROB)
         BALR  14,15
@@L4     EQU   *
         SLR   2,2 ==> rc
@@L1     EQU   *
         LR    15,2 ==> rc
* Function '__pswkey' epilogue
         PDPEPIL
* Function '__pswkey' literal pool
         DS    0D
         LTORG
* Function '__pswkey' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
