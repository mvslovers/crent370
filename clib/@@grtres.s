 TITLE '/home/mike/repos/crent370/clib/@@grtres.c'
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
* external function '__grtres' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  '__grtres'
@@GRTRES PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__grtres' code
         L     6,=F'-1' ==> rc
         LA    1,88(,13)
         L     15,=V(@@CRTGET)
         BALR  14,15
         LR    2,15 ==> crt
         LA    1,88(,13)
         L     15,=V(@@PPAGET)
         BALR  14,15
         LR    5,15 ==> ppa
         LTR   2,2 ==> crt
         BE    @@L8
         L     4,280(2) ==> grt,crtgrt
         LTR   4,4 ==> grt
         BE    @@L8
         ST    4,88(13) ==> grt
         MVC   92(4,13),=A(@@LC0)
         MVC   96(4,13),=F'8'
         LA    1,88(,13)
         L     15,=V(MEMCMP)
         BALR  14,15
         LR    3,15 ==> crt
         LTR   15,15 ==> crt
         BNE   @@L4
         LA    2,8(0,0) ==> n
         
*** MEMSET ***
         LR    14,4           => target (s) ==> grt
         LR    15,2           => length (n) ==> n
         SLR   0,0             => source (NULL)
         LR    1,3            fill character ==> crt
         SLL   1,24            move fill to high byte
         MVCL  14,0            Set target to fill character
         ST    4,88(13) ==> grt
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
         LR    6,3 ==> rc,crt
@@L4     EQU   *
         LTR   6,6 ==> rc
         BNE   @@L8
         LTR   5,5 ==> ppa
         BE    @@L8
         L     2,16(5) ==> .ppagrt
         CLR   2,4 ==> grt
         BNE   @@L8
         ST    6,16(5) ==> rc,ppagrt
@@L8     EQU   *
         LR    15,6 ==> rc
* Function '__grtres' epilogue
         PDPEPIL
* Function '__grtres' literal pool
         DS    0D
         LTORG
* Function '__grtres' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'CLIBGRT '
         DC    X'0'
         END
