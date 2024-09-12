 TITLE '/home/mike/repos/crent370/clib/memmove.c'
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
* external function 'memmove' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'memmove'
MEMMOVE  PDPPRLG CINDEX=0,FRAME=88,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'memmove' code
         L     15,0(11) ==> s1
         L     5,8(11) ==> n
         LR    4,15 ==> p,s1
         L     3,4(11) ==> cs2,s2
         CLR   15,3 ==> s1,cs2
         BH    @@L2
         SLR   2,2 ==> x
         CLR   2,5 ==> x,n
         BNL   @@L8
@@L7     EQU   *
         MVC   0(1,4),0(3) ==> p,cs2
         A     4,=F'1' ==> p
         A     3,=F'1' ==> cs2
         A     2,=F'1' ==> x
         CLR   2,5 ==> x,n
         BNL   @@L8
         B     @@L7
@@L2     EQU   *
         LTR   5,5 ==> n
         BE    @@L8
         LR    2,5 ==> x,n
         BCTR  2,0 ==> x
         LTR   2,2 ==> x
         BE    @@L17
@@L14    EQU   *
         IC    5,0(2,3) ==> x
         STC   5,0(2,4) ==> x
         BCTR  2,0 ==> x
         LTR   2,2 ==> x
         BNE   @@L14
@@L17    EQU   *
         IC    3,0(2,3) ==> x
         STC   3,0(2,4) ==> x
@@L8     EQU   *
* Function 'memmove' epilogue
         PDPEPIL
* Function 'memmove' literal pool
         DS    0D
         LTORG
* Function 'memmove' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
