 TITLE '/home/mike/repos/crent370/clib/memcpyp.c'
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
* external function 'memcpyp' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  'memcpyp'
MEMCPYP  PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'memcpyp' code
         L     5,0(11) ==> target
         L     2,4(11) ==> tlen
         L     3,12(11) ==> slen
         L     6,16(11) ==> pad
         LR    4,5 ==> t,target
         CR    3,2 ==> slen,tlen
         BNH   @@L2
         LR    3,2 ==> slen,tlen
@@L2     EQU   *
         LTR   3,3 ==> slen
         BNH   @@L3
         ST    4,88(13) ==> t
         MVC   92(4,13),8(11) ==> source
         ST    3,96(13) ==> slen
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         AR    4,3 ==> t,slen
         SR    2,3 ==> tlen,slen
@@L3     EQU   *
         LTR   2,2 ==> tlen
         BNH   @@L4
         
*** MEMSET ***
         LR    14,4           => target (s) ==> t
         LR    15,2           => length (n) ==> tlen
         SLR   0,0             => source (NULL)
         LR    1,6            fill character ==> pad
         SLL   1,24            move fill to high byte
         MVCL  14,0            Set target to fill character
@@L4     EQU   *
         LR    15,5 ==> target
* Function 'memcpyp' epilogue
         PDPEPIL
* Function 'memcpyp' literal pool
         DS    0D
         LTORG
* Function 'memcpyp' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
