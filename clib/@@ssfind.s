 TITLE '/home/mike/repos/crent370/clib/@@ssfind.c'
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
         
&FUNC    SETC 'ssct_find'
* Program text area
         DS    0F
         EJECT
* external function 'ssct_find' prologue
* frame base=88, local stack=8, call args=16
&FUNC    SETC  'ssct_find'
@@SSFIND PDPPRLG CINDEX=0,FRAME=112,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'ssct_find' code
         L     15,0(11) ==> name
         SLR   2,2 ==> psa
         L     2,16(2) ==> cvt
         L     2,296(2) ==> jesct
         L     3,24(2) ==> ssct,jesssct
         LTR   15,15 ==> name
         BE    @@L3
         IC    2,0(15) ==> name
         CLM   2,1,=XL1'00'
         BE    @@L3
         CLM   2,1,=XL1'40'
         BE    @@L3
         LA    2,104(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'4'
         ST    15,96(13) ==> name
         MVC   100(4,13),=F'64'
         LA    1,88(,13)
         L     15,=V(STRCPYP)
         BALR  14,15
         LTR   3,3 ==> ssct
         BE    @@L3
         LA    4,104(,13)
@@L10    EQU   *
         LR    2,3 ==> ssct
         A     2,=F'8'
         ST    2,88(13)
         ST    4,92(13)
         MVC   96(4,13),=F'4'
         LA    1,88(,13)
         L     15,=V(MEMCMP)
         BALR  14,15
         LTR   15,15 ==> ssct
         BE    @@L3
         L     3,4(3) ==> ssct,ssctscta
         LTR   3,3 ==> ssct
         BNE   @@L10
@@L3     EQU   *
         LR    15,3 ==> ssct
* Function 'ssct_find' epilogue
         PDPEPIL
* Function 'ssct_find' literal pool
         DS    0D
         LTORG
* Function 'ssct_find' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
