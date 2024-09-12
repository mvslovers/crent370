 TITLE '/home/mike/repos/crent370/clib/@@fpfree.c'
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
* external function '__fpfree' prologue
* frame base=88, local stack=32, call args=8
&FUNC    SETC  '__fpfree'
@@FPFREE PDPPRLG CINDEX=0,FRAME=128,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__fpfree' code
         SLR   15,15 ==> count
         ST    15,120(13) ==> count
         LA    4,96(,13)
         LA    5,20(0,0)
         LR    2,15 ==> count
         LR    3,15 ==> count
         MVCL  4,2 ==> count
         LA    2,120(,13)
         ST    2,88(13)
         L     2,0(11) ==> fp
         A     2,=F'43'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(@@TXDDN)
         BALR  14,15
         LR    5,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L3
         LA    2,120(,13)
         ST    2,88(13)
         ST    15,92(13) ==> err
         LA    1,88(,13)
         L     15,=V(@@TXUNAL)
         BALR  14,15
         LR    5,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L3
         LA    2,120(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LTR   15,15 ==> count
         BE    @@L3
         BCTR  15,0 ==> count
         L     4,120(13)
         LR    3,15 ==> count
         MH    3,=H'4'
         L     2,0(3,4)
         O     2,=F'-2147483648'
         ST    2,0(3,4)
         MVI   96(13),20 ==> .len
         MVI   97(13),2 ==> .request
         STC   5,98(13) ==> err,flag1
         MVC   104(4,13),120(13) ==> .txtptr
         LA    2,96(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@SVC99)
         BALR  14,15
         LR    5,15 ==> err
@@L3     EQU   *
         L     2,120(13)
         LTR   2,2
         BE    @@L6
         LA    2,120(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@FRTX9A)
         BALR  14,15
@@L6     EQU   *
         LR    15,5 ==> err
* Function '__fpfree' epilogue
         PDPEPIL
* Function '__fpfree' literal pool
         DS    0D
         LTORG
* Function '__fpfree' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
