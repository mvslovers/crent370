 TITLE '/home/mike/repos/crent370/clib/@@ecbwa.c'
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
         
&FUNC    SETC 'ecb_waitarray'
* Program text area
         DS    0F
         EJECT
* external function 'ecb_waitarray' prologue
* frame base=88, local stack=1024, call args=8
&FUNC    SETC  'ecb_waitarray'
@@ECBWA  PDPPRLG CINDEX=0,FRAME=1120,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'ecb_waitarray' code
         SLR   7,7 ==> rc
         L     2,0(11)
         LTR   2,2
         BE    @@L3
         ST    11,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    4,7 ==> n,rc
         LR    5,7 ==> i,rc
         CLR   7,15 ==> rc,count
         BNL   @@L5
         L     6,0(11)
@@L10    EQU   *
         LR    2,4 ==> n
         MH    2,=H'4'
         L     3,0(2,6)
         LTR   3,3
         BE    @@L6
         LR    2,5 ==> i
         MH    2,=H'4'
         ST    3,96(13,2) ==> ecblist
         A     5,=F'1' ==> i
         LA    2,255(0,0)
         CLR   5,2 ==> i
         BH    @@L5
@@L6     EQU   *
         A     4,=F'1' ==> n
         CLR   4,15 ==> n,count
         BL    @@L10
@@L5     EQU   *
         LTR   5,5 ==> i
         BE    @@L3
         LR    2,5 ==> i
         MH    2,=H'4'
         LA    3,96(,13)
         AR    2,3
         A     2,=F'-4'
         OC    0(4,2),=F'-2147483648' ==> ecblist
         ST    3,88(13)
         LA    1,88(,13)
         L     15,=V(@@ECBWL)
         BALR  14,15
         LR    7,15 ==> rc
@@L3     EQU   *
         LR    15,7 ==> rc
* Function 'ecb_waitarray' epilogue
         PDPEPIL
* Function 'ecb_waitarray' literal pool
         DS    0D
         LTORG
* Function 'ecb_waitarray' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
