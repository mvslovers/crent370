 TITLE '/home/mike/repos/crent370/time64/tm64dtim.c'
         COPY  PDPTOP
         CSECT
* GNU C version 3.2.3 - c2asm370 version 1.0 (mvs)
*        compiled by GNU C version 13.2.0.
*
* options passed:  -lang-c -I. -I/home/mike/repos/crent370/time64
* -I/home/mike/repos/crent370/include -iprefix -D__GNUC__=3
* -D__GNUC_MINOR__=2 -D__GNUC_PATCHLEVEL__=3 -D__GXX_ABI_VERSION=102
* -D__GCC__ -D__MVS__ -D__GCC__ -D__MVS__ -Asystem=mvs -Acpu=i370
* -Amachine=i370 -D__OPTIMIZE__ -D__STDC_HOSTED__=1 -trigraphs -O1
* -fverbose-asm
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
* external function 'difftime64' prologue
* frame base=88, local stack=24, call args=16
&FUNC    SETC  'difftime64'
TM64DTIM PDPPRLG CINDEX=0,FRAME=128,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'difftime64' code
         MVC   104(8,13),0(11) ==> time1
         MVC   112(8,13),8(11) ==> time0
         LA    3,104(,13) ==> t1
         LA    2,112(,13) ==> t0
         ST    3,88(13) ==> t1
         ST    2,92(13) ==> t0
         LA    1,88(,13)
         L     15,=V(@@64CMP)
         BALR  14,15
         L     4,=F'-1'
         CLR   15,4
         BNE   @@L2
         LA    4,1(0,0) ==> neg
         LR    3,2 ==> t1,t0
         LA    2,104(,13) ==> t0
         B     @@L3
@@L2     EQU   *
         SLR   4,4 ==> neg
@@L3     EQU   *
         ST    3,88(13) ==> t1
         ST    2,92(13) ==> t0
         LA    2,120(,13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@64SUB)
         BALR  14,15
         LA    2,124(,13)
         L     3,0(2) ==> .u32
         MVC   80(4,13),=XL8'4E00000080000000'
         ST    3,84(,13)
         XI    84(13),128
         LD    0,80(,13) ==> result
         SD    0,=XL8'4E00000080000000' ==> result
         LTR   3,3
         BNL   @@L4
         AD    0,=D'4.294967296E9' ==> result
@@L4     EQU   *
         LTR   4,4 ==> neg
         BE    @@L5
         LCDR  0,0 ==> result
@@L5     EQU   *
* Function 'difftime64' epilogue
         PDPEPIL
* Function 'difftime64' literal pool
         DS    0D
         LTORG
* Function 'difftime64' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
