 TITLE '/home/mike/repos/crent370/clib/@@arcou.c'
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
         
&FUNC    SETC 'arraycount'
* Program text area
         DS    0F
         EJECT
* external function 'arraycount' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  'arraycount'
@@ARCOU  PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'arraycount' code
         L     15,0(11) ==> varray
         SLR   3,3 ==> count
         LTR   15,15 ==> varray
         BE    @@L5
         L     2,0(15) ==> varray
         LTR   2,2
         BE    @@L5
         A     2,=F'-12' ==> array
         ST    2,88(13) ==> array
         MVC   92(4,13),=A(@@LC0)
         MVC   96(4,13),=F'4'
         LA    1,88(,13)
         L     15,=V(MEMCMP)
         BALR  14,15
         LTR   15,15 ==> count
         BNE   @@L5
         L     3,8(2) ==> count,count
@@L5     EQU   *
         LR    15,3 ==> count
* Function 'arraycount' epilogue
         PDPEPIL
* Function 'arraycount' literal pool
         DS    0D
         LTORG
* Function 'arraycount' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'ARRY'
         DC    X'0'
         END
