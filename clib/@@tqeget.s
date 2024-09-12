 TITLE '/home/mike/repos/crent370/clib/@@tqeget.c'
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
         
&FUNC    SETC 'tqe_get'
* Program text area
         DS    0F
         EJECT
* external function 'tqe_get' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'tqe_get'
@@TQEGET PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'tqe_get' code
         L     9,0(11) ==> id
         LA    1,88(,13)
         L     15,=V(@@TMRGET)
         BALR  14,15
         LR    6,15 ==> tmr
         SLR   7,7 ==> tqe
         LA    1,88(,13)
         L     15,=V(@@TMINIT)
         BALR  14,15
         ST    6,88(13) ==> tmr
         ST    7,92(13) ==> tqe
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         LR    8,15 ==> lockrc
         LR    2,6 ==> tmr
         A     2,=F'24'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    4,7 ==> n,tqe
         CLR   7,15 ==> tqe,count
         BNL   @@L3
         L     5,24(6) ==> .tqe
@@L8     EQU   *
         LR    2,4 ==> n
         MH    2,=H'4'
         L     3,0(2,5) ==> t
         LTR   3,3 ==> t
         BE    @@L4
         L     2,40(3) ==> .id
         CLR   2,9 ==> id
         BNE   @@L4
         LR    7,3 ==> tqe,t
         B     @@L3
@@L4     EQU   *
         A     4,=F'1' ==> n
         CLR   4,15 ==> n,count
         BL    @@L8
@@L3     EQU   *
         LTR   8,8 ==> lockrc
         BNE   @@L9
         ST    6,88(13) ==> tmr
         ST    8,92(13) ==> lockrc
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
@@L9     EQU   *
         LR    15,7 ==> tqe
* Function 'tqe_get' epilogue
         PDPEPIL
* Function 'tqe_get' literal pool
         DS    0D
         LTORG
* Function 'tqe_get' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
