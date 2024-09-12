 TITLE '/home/mike/repos/crent370/clib/@@tqnew.c'
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
         
&FUNC    SETC 'tqe_new'
* Program text area
         DS    0F
         EJECT
* external function 'tqe_new' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'tqe_new'
@@TQNEW  PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'tqe_new' code
         L     7,12(11) ==> bintvl
         L     5,16(11) ==> flags
         SLR   3,3 ==> psa
         L     6,540(3) ==> tcb
         L     2,548(3) ==> ascb
         L     4,36(2) ==> asid
         SRL   4,16 ==> asid
         MVC   88(4,13),=F'1'
         MVC   92(4,13),=F'48'
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         LR    2,15 ==> tqe
         LTR   15,15 ==> tqe
         BE    @@L2
         ST    15,88(13) ==> tqe
         MVC   92(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         STC   5,8(2) ==> flags,flags
         STH   4,10(2) ==> asid,asid
         ST    6,12(2) ==> tcb,tcb
         ST    3,88(13) ==> psa
         LA    1,88(,13)
         L     15,=V(@@TMSECS)
         BALR  14,15
         LDR   2,0
         MVC   80(4,13),=XL8'4E00000080000000'
         ST    7,84(,13) ==> bintvl
         XI    84(13),128
         LD    0,80(,13)
         SD    0,=XL8'4E00000080000000'
         LTR   7,7 ==> bintvl
         BNL   @@L3
         AD    0,=D'4.294967296E9'
@@L3     EQU   *
         DD    0,=D'1.0E2'
         ADR   0,2
         STD   0,16(2) ==> .expires
         ST    7,24(2) ==> bintvl,bintvl
         MVC   28(4,2),0(11) ==> .ecb,ecb
         MVC   32(4,2),4(11) ==> .func,func
         MVC   36(4,2),8(11) ==> .udata,udata
         LA    1,88(,13)
         L     15,=V(@@TMRID)
         BALR  14,15
         ST    15,40(2) ==> tqe,id
@@L2     EQU   *
         LR    15,2 ==> tqe
* Function 'tqe_new' epilogue
         PDPEPIL
* Function 'tqe_new' literal pool
         DS    0D
         LTORG
* Function 'tqe_new' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'**TQE**'
         DC    X'0'
         END
