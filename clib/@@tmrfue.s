 TITLE '/home/mike/repos/crent370/clib/@@tmrfue.c'
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
         
&FUNC    SETC 'tmr_func_every'
* Program text area
         DS    0F
         EJECT
* external function 'tmr_func_every' prologue
* frame base=88, local stack=0, call args=24
&FUNC    SETC  'tmr_func_every'
@@TMRFUE PDPPRLG CINDEX=0,FRAME=112,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'tmr_func_every' code
         LA    1,88(,13)
         L     15,=V(@@TMRGET)
         BALR  14,15
         LR    4,15 ==> tmr
         SLR   5,5 ==> id
         LA    1,88(,13)
         L     15,=V(@@TMSTRT)
         BALR  14,15
         ST    5,88(13) ==> id
         MVC   92(4,13),0(11) ==> func
         MVC   96(4,13),4(11) ==> udata
         MVC   100(4,13),8(11) ==> bintvl
         MVC   104(4,13),=F'192'
         LA    1,88(,13)
         L     15,=V(@@TQNEW)
         BALR  14,15
         LR    3,15 ==> tqe
         LTR   15,15 ==> tqe
         BE    @@L2
         L     5,40(15) ==> id,id
         ST    4,88(13) ==> tmr
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         LR    6,15 ==> lockrc
         LR    2,4 ==> tmr
         A     2,=F'24'
         ST    2,88(13)
         ST    3,92(13) ==> tqe
         LA    1,88(,13)
         L     15,=V(@@ARADD)
         BALR  14,15
         A     2,=F'-4'
         ST    2,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@ECBPST)
         BALR  14,15
         LTR   6,6 ==> lockrc
         BNE   @@L2
         ST    4,88(13) ==> tmr
         ST    6,92(13) ==> lockrc
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
@@L2     EQU   *
         LR    15,5 ==> id
* Function 'tmr_func_every' epilogue
         PDPEPIL
* Function 'tmr_func_every' literal pool
         DS    0D
         LTORG
* Function 'tmr_func_every' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
