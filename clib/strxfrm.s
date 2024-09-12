 TITLE '/home/mike/repos/crent370/clib/strxfrm.c'
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
* external function 'strxfrm' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  'strxfrm'
STRXFRM  PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'strxfrm' code
         L     4,0(11) ==> s1
         L     3,4(11) ==> s2
         ST    3,88(13) ==> s2
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         LR    2,15 ==> oldlen
         CL    15,8(11) ==> oldlen,n
         BNL   @@L2
         ST    4,88(13) ==> s1
         ST    3,92(13) ==> s2
         ST    15,96(13) ==> oldlen
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         SLR   3,3
         STC   3,0(2,4) ==> oldlen
@@L2     EQU   *
         LR    15,2 ==> oldlen
* Function 'strxfrm' epilogue
         PDPEPIL
* Function 'strxfrm' literal pool
         DS    0D
         LTORG
* Function 'strxfrm' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
