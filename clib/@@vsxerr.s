 TITLE '/home/mike/repos/crent370/clib/@@vsxerr.c'
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
* external function '__vsxerr' prologue
* frame base=88, local stack=72, call args=8
&FUNC    SETC  '__vsxerr'
@@VSXERR PDPPRLG CINDEX=0,FRAME=168,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__vsxerr' code
         L     4,0(11) ==> rpl
         LR    5,4 ==> vs,rpl
         A     5,=F'-104' ==> vs
         LA    6,96(,13)
         LA    7,64(0,0)
         SLR   2,2
         LR    3,2
         MVCL  6,2
         MVC   160(4,13),=F'0'
         OI    17(5),2 ==> .flags
         LA    3,96(,13)
         LA    2,160(,13)
         
         SHOWCB RPL=(4),                                               X ==> rpl
               FIELDS=FDBK,AREA=(2),LENGTH=4,MF=(G,(3))
         MVC   18(1,5),161(13) ==> .rc,fdbk
         MVC   20(1,5),162(13) ==> .component,fdbk
         MVC   19(1,5),163(13) ==> .rsn,fdbk
         L     3,188(5) ==> .vsreset
         LTR   3,3
         BE    @@L2
         L     2,16(5)
         N     2,=F'6291456'
         LTR   2,2
         BE    @@L2
         ST    5,88(13) ==> vs
         LA    1,88(,13)
         LA    15,0(3)
         BALR  14,15
@@L2     EQU   *
         L     15,4(11) ==> code
* Function '__vsxerr' epilogue
         PDPEPIL
* Function '__vsxerr' literal pool
         DS    0D
         LTORG
* Function '__vsxerr' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
