 TITLE '/home/mike/repos/crent370/clib/fread.c'
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
* external function 'fread' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  'fread'
FREAD    PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'fread' code
         L     2,12(11) ==> fp
         ST    2,88(13) ==> fp
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         MVC   88(4,13),0(11) ==> ptr
         MVC   92(4,13),4(11) ==> size
         MVC   96(4,13),8(11) ==> nmemb
         ST    2,100(13) ==> fp
         LA    1,88(,13)
         L     15,=V(@@FREAD)
         BALR  14,15
         LR    3,15 ==> rc
         ST    2,88(13) ==> fp
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
         LR    15,3 ==> rc
* Function 'fread' epilogue
         PDPEPIL
* Function 'fread' literal pool
         DS    0D
         LTORG
* Function 'fread' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
