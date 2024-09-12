 TITLE '/home/mike/repos/crent370/clib/@@svfree.c'
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
         
&FUNC    SETC 'ssvt_free'
* Program text area
         DS    0F
         EJECT
* external function 'ssvt_free' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'ssvt_free'
@@SVFREE PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'ssvt_free' code
         L     15,0(11) ==> ssvt
         SLR   4,4 ==> restore
         LTR   15,15 ==> ssvt
         BE    @@L1
         IPK   0             get psw key in R2
         LR    3,2           save psw key in register ==> prevkey
         CLM   3,1,=XL1'00' ==> prevkey
         BE    @@L3
         LA    4,1(0,0) ==> restore
         SLR   2,2               PSW key 0 value
         SPKA  0(2)             save in psw
@@L3     EQU   *
         ST    15,88(13) ==> ssvt
         LA    1,88(,13)
         L     15,=V(FREEMAIN)
         BALR  14,15
         LTR   4,4 ==> restore
         BE    @@L1
         LR    2,3               get prev psw key ==> prevkey
         SPKA  0(2)             save in psw
@@L1     EQU   *
* Function 'ssvt_free' epilogue
         PDPEPIL
* Function 'ssvt_free' literal pool
         DS    0D
         LTORG
* Function 'ssvt_free' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
