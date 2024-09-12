 TITLE '/home/mike/repos/crent370/clib/realloc.c'
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
* external function 'realloc' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  'realloc'
REALLOC  PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'realloc' code
         L     5,0(11) ==> ptr
         L     3,4(11) ==> size
         LTR   3,3 ==> size
         BNE   @@L2
         ST    5,88(13) ==> ptr
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
         LR    15,3 ==> newptr,size
         B     @@L1
@@L2     EQU   *
         ST    3,88(13) ==> size
         LA    1,88(,13)
         L     15,=V(MALLOC)
         BALR  14,15
         LR    4,15 ==> newptr
         LTR   15,15 ==> newptr
         BE    @@L1
         LTR   5,5 ==> ptr
         BE    @@L4
         LR    2,5 ==> ptr
         A     2,=F'-4'
         L     2,0(2) ==> oldsize
         CLR   2,3 ==> oldsize,size
         BNL   @@L5
         LR    3,2 ==> size,oldsize
@@L5     EQU   *
         ST    4,88(13) ==> newptr
         ST    5,92(13) ==> ptr
         ST    3,96(13) ==> size
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         ST    5,88(13) ==> ptr
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
@@L4     EQU   *
         LR    15,4 ==> newptr
@@L1     EQU   *
* Function 'realloc' epilogue
         PDPEPIL
* Function 'realloc' literal pool
         DS    0D
         LTORG
* Function 'realloc' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
