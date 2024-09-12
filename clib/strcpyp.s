 TITLE '/home/mike/repos/crent370/clib/strcpyp.c'
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
* external function 'strcpyp' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  'strcpyp'
STRCPYP  PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'strcpyp' code
         L     6,0(11) ==> target
         L     3,4(11) ==> tlen
         L     5,8(11) ==> source
         L     7,12(11) ==> pad
         LR    4,6 ==> t,target
         LTR   5,5 ==> source
         BE    @@L2
         ST    5,88(13) ==> source
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         LR    2,15 ==> slen
         B     @@L3
@@L2     EQU   *
         SLR   2,2 ==> slen
@@L3     EQU   *
         CR    2,3 ==> slen,tlen
         BNH   @@L4
         LR    2,3 ==> slen,tlen
@@L4     EQU   *
         LTR   2,2 ==> slen
         BNH   @@L5
         ST    4,88(13) ==> t
         ST    5,92(13) ==> source
         ST    2,96(13) ==> slen
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         AR    4,2 ==> t,slen
         SR    3,2 ==> tlen,slen
@@L5     EQU   *
         LTR   3,3 ==> tlen
         BNH   @@L6
         
*** MEMSET ***
         LR    14,4           => target (s) ==> t
         LR    15,3           => length (n) ==> tlen
         SLR   0,0             => source (NULL)
         LR    1,7            fill character ==> pad
         SLL   1,24            move fill to high byte
         MVCL  14,0            Set target to fill character
@@L6     EQU   *
         LR    15,6 ==> target
* Function 'strcpyp' epilogue
         PDPEPIL
* Function 'strcpyp' literal pool
         DS    0D
         LTORG
* Function 'strcpyp' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
