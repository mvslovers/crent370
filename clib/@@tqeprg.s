 TITLE '/home/mike/repos/crent370/clib/@@tqeprg.c'
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
         
&FUNC    SETC 'tqe_purge'
* Program text area
         DS    0F
         EJECT
* external function 'tqe_purge' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'tqe_purge'
@@TQEPRG PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'tqe_purge' code
         L     6,0(11) ==> id
         LA    8,2(0,0) ==> rc
         LA    1,88(,13)
         L     15,=V(@@TMRGET)
         BALR  14,15
         LR    5,15 ==> tmr
         LA    1,88(,13)
         L     15,=V(@@TMINIT)
         BALR  14,15
         ST    5,88(13) ==> tmr
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         LR    7,15 ==> lockrc
         LR    2,5 ==> tmr
         A     2,=F'24'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         SLR   4,4 ==> n
         CLR   4,15 ==> n,count
         BNL   @@L3
@@L8     EQU   *
         L     3,24(5) ==> .tqe
         LR    2,4 ==> n
         MH    2,=H'4'
         L     3,0(2,3) ==> tqe
         LTR   3,3 ==> tqe
         BE    @@L4
         L     2,40(3) ==> .id
         CLR   2,6 ==> id
         BNE   @@L4
         LR    2,5 ==> tmr
         A     2,=F'24'
         ST    2,88(13)
         LR    2,4 ==> n
         A     2,=F'1'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(@@ARDEL)
         BALR  14,15
         ST    3,88(13) ==> tqe
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
         SLR   8,8 ==> rc
         B     @@L3
@@L4     EQU   *
         A     4,=F'1' ==> n
         CLR   4,15 ==> n,count
         BL    @@L8
@@L3     EQU   *
         LTR   7,7 ==> lockrc
         BNE   @@L9
         ST    5,88(13) ==> tmr
         ST    7,92(13) ==> lockrc
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
@@L9     EQU   *
         LR    15,8 ==> rc
* Function 'tqe_purge' epilogue
         PDPEPIL
* Function 'tqe_purge' literal pool
         DS    0D
         LTORG
* Function 'tqe_purge' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
