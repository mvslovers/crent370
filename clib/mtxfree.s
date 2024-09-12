 TITLE '/home/mike/repos/crent370/clib/mtxfree.c'
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
* external function 'mtxfree' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'mtxfree'
MTXFREE  PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'mtxfree' code
         L     4,0(11) ==> mutex
         L     2,0(4) ==> .owner
         LTR   2,2
         BE    @@L2
         ST    4,88(13) ==> mutex
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
@@L2     EQU   *
         SLR   3,3 ==> c
         LA    2,8(0,0) ==> n
         
*** MEMSET ***
         LR    14,4           => target (s) ==> mutex
         LR    15,2           => length (n) ==> n
         SLR   0,0             => source (NULL)
         LR    1,3            fill character ==> c
         SLL   1,24            move fill to high byte
         MVCL  14,0            Set target to fill character
         ST    4,88(13) ==> mutex
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
@@L4     EQU   *
* Function 'mtxfree' epilogue
         PDPEPIL
* Function 'mtxfree' literal pool
         DS    0D
         LTORG
* Function 'mtxfree' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
