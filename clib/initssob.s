 TITLE '/home/mike/repos/crent370/clib/initssob.c'
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
* external function 'initssob' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  'initssob'
INITSSOB PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'initssob' code
         L     2,0(11) ==> ssob
         SLR   4,4 ==> rc
         LA    3,20(0,0) ==> n
         
*** MEMSET ***
         LR    14,2           => target (s) ==> ssob
         LR    15,3           => length (n) ==> n
         SLR   0,0             => source (NULL)
         LR    1,4            fill character ==> rc
         SLL   1,24            move fill to high byte
         MVCL  14,0            Set target to fill character
         ST    2,88(13) ==> ssob
         MVC   92(4,13),=A(@@LC0)
         MVC   96(4,13),=F'4'
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         MVC   4(2,2),=H'20' ==> .SSOBLEN
         MVC   16(4,2),4(11) ==> .SSOBINDV,ssobindv
         LR    15,4 ==> rc
* Function 'initssob' epilogue
         PDPEPIL
* Function 'initssob' literal pool
         DS    0D
         LTORG
* Function 'initssob' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'SSOB'
         DC    X'0'
         END
