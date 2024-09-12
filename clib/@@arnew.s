 TITLE '/home/mike/repos/crent370/clib/@@arnew.c'
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
         
&FUNC    SETC 'arraynew'
* Program text area
         DS    0F
         EJECT
* external function 'arraynew' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  'arraynew'
@@ARNEW  PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'arraynew' code
         L     3,0(11) ==> size
         LTR   3,3 ==> size
         BNE   @@L2
         LA    3,20(0,0) ==> size
@@L2     EQU   *
         LR    2,3 ==> size
         A     2,=F'3'
         ST    2,88(13)
         MVC   92(4,13),=F'4'
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         LR    2,15 ==> vnew
         LTR   15,15 ==> vnew
         BE    @@L4
         ST    15,88(13) ==> vnew
         MVC   92(4,13),=A(@@LC0)
         MVC   96(4,13),=F'4'
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         ST    3,4(2) ==> size,size
         MVC   8(4,2),=F'0' ==> .count
         A     2,=F'12' ==> vnew
@@L4     EQU   *
         LR    15,2 ==> vnew
* Function 'arraynew' epilogue
         PDPEPIL
* Function 'arraynew' literal pool
         DS    0D
         LTORG
* Function 'arraynew' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'ARRY'
         DC    X'0'
         END
