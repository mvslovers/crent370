 TITLE '/home/mike/repos/crent370/clib/@@tmsecs.c'
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
         
&FUNC    SETC 'tmr_secs'
* Program text area
         DS    0F
         EJECT
* external function 'tmr_secs' prologue
* frame base=88, local stack=24, call args=0
&FUNC    SETC  'tmr_secs'
@@TMSECS PDPPRLG CINDEX=0,FRAME=112,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'tmr_secs' code
         L     15,0(11) ==> secs
         LTR   15,15 ==> secs
         BNE   @@L2
         LA    15,88(,13) ==> secs
@@L2     EQU   *
         LA    2,96(,13)
         STCK  0(2)
         L     4,96(13)
         L     5,4+96(13)
         LR    3,5
         A     3,=F'905969664'
         LA    6,1(0,0)
         CLR   3,5
         BH    @@L3
         SLR   6,6
@@L3     EQU   *
         LR    2,4
         A     2,=F'-2106655883'
         SR    2,6
         ST    2,96(13)
         ST    3,4+96(13)
         SRDL  2,12
         ST    2,96(13)
         ST    3,4+96(13)
         LA    3,96(,13)
         LA    2,104(,13)
         LM    0,1,0(3)       load TOD microseconds
         D     0,=F'1000000'  divide by 1000000
         ST    1,0(0,2)       store seconds (quotient)
         ST    0,4(0,2)       store microseconds (remainder)
         L     2,104(13)
         MVC   80(4,13),=XL8'4E00000080000000'
         ST    2,84(,13)
         XI    84(13),128
         LD    0,80(,13)
         SD    0,=XL8'4E00000080000000'
         L     2,108(13) ==> .tv_usec
         MVC   80(4,13),=XL8'4E00000080000000'
         ST    2,84(,13)
         XI    84(13),128
         LD    2,80(,13)
         SD    2,=XL8'4E00000080000000'
         DD    2,=D'1.0E6'
         ADR   0,2
         STD   0,0(15) ==> secs
@@L4     EQU   *
* Function 'tmr_secs' epilogue
         PDPEPIL
* Function 'tmr_secs' literal pool
         DS    0D
         LTORG
* Function 'tmr_secs' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
