 TITLE '/home/mike/repos/crent370/clib/@@freeds.c'
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
* external function '__freeds' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  '__freeds'
@@FREEDS PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__freeds' code
         L     6,0(11) ==> dslist
         LTR   6,6 ==> dslist
         BE    @@L1
         L     2,0(6) ==> dslist
         LTR   2,2
         BE    @@L1
         ST    6,88(13) ==> dslist
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    5,15 ==> count
         LTR   15,15 ==> count
         BE    @@L3
         L     7,0(6) ==> list,dslist
         SLR   4,4 ==> n
         CLR   4,15 ==> n,count
         BNL   @@L3
@@L9     EQU   *
         LR    3,4 ==> n
         MH    3,=H'4'
         L     2,0(3,7)
         LTR   2,2
         BE    @@L6
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
         SLR   2,2
         ST    2,0(3,7)
@@L6     EQU   *
         A     4,=F'1' ==> n
         CLR   4,5 ==> n,count
         BL    @@L9
@@L3     EQU   *
         ST    6,88(13) ==> dslist
         LA    1,88(,13)
         L     15,=V(@@ARFRE)
         BALR  14,15
         MVC   0(4,6),=F'0' ==> dslist
@@L1     EQU   *
* Function '__freeds' epilogue
         PDPEPIL
* Function '__freeds' literal pool
         DS    0D
         LTORG
* Function '__freeds' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
