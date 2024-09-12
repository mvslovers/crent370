 TITLE '/home/mike/repos/crent370/clib/@@areach.c'
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
         
&FUNC    SETC 'arrayeach'
* Program text area
         DS    0F
         EJECT
* external function 'arrayeach' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  'arrayeach'
@@AREACH PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'arrayeach' code
         L     8,4(11) ==> fn
         L     7,8(11) ==> udata
         SLR   2,2 ==> rc
         L     6,0(11) ==> carray,varray
         ST    6,88(13) ==> carray
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    5,15 ==> count
         LR    4,2 ==> n,rc
         CLR   2,15 ==> rc,count
         BNL   @@L3
@@L7     EQU   *
         ST    4,88(13) ==> n
         L     3,0(6) ==> carray
         LR    2,4 ==> n
         MH    2,=H'4'
         L     3,0(2,3)
         ST    3,92(13)
         ST    7,96(13) ==> udata
         LA    1,88(,13)
         LA    15,0(8) ==> fn
         BALR  14,15
         LR    2,15 ==> rc
         LTR   15,15 ==> rc
         BNE   @@L3
         A     4,=F'1' ==> n
         CLR   4,5 ==> n,count
         BL    @@L7
@@L3     EQU   *
         LR    15,2 ==> rc
* Function 'arrayeach' epilogue
         PDPEPIL
* Function 'arrayeach' literal pool
         DS    0D
         LTORG
* Function 'arrayeach' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
