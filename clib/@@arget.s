 TITLE '/home/mike/repos/crent370/clib/@@arget.c'
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
         
&FUNC    SETC 'arrayget'
* Program text area
         DS    0F
         EJECT
* external function 'arrayget' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  'arrayget'
@@ARGET  PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'arrayget' code
         L     3,0(11) ==> varray
         L     4,4(11) ==> index
         SLR   5,5 ==> vitem
         LTR   3,3 ==> varray
         BE    @@L6
         L     2,0(3) ==> varray
         LTR   2,2
         BE    @@L6
         A     2,=F'-12' ==> array
         ST    2,88(13) ==> array
         MVC   92(4,13),=A(@@LC0)
         MVC   96(4,13),=F'4'
         LA    1,88(,13)
         L     15,=V(MEMCMP)
         BALR  14,15
         LTR   15,15 ==> vitem
         BNE   @@L6
         LTR   4,4 ==> index
         BE    @@L6
         CL    4,8(2) ==> index,count
         BH    @@L6
         LR    2,4 ==> index
         MH    2,=H'4'
         A     2,0(3) ==> varray
         A     2,=F'-4'
         L     5,0(2) ==> vitem
@@L6     EQU   *
         LR    15,5 ==> vitem
* Function 'arrayget' epilogue
         PDPEPIL
* Function 'arrayget' literal pool
         DS    0D
         LTORG
* Function 'arrayget' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'ARRY'
         DC    X'0'
         END
