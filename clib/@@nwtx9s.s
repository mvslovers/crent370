 TITLE '/home/mike/repos/crent370/clib/@@nwtx9s.c'
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
* external function '__nwtx9s' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  '__nwtx9s'
@@NWTX9S PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__nwtx9s' code
         LA    6,8(,11) ==> list
         SLR   4,4 ==> len
         LR    5,4 ==> i,len
         C     4,4(11) ==> len
         BNL   @@L3
@@L7     EQU   *
         A     6,=F'4' ==> list
         LR    2,6 ==> list
         A     2,=F'-4'
         L     3,0(2) ==> text
         LTR   3,3 ==> text
         BE    @@L3
         ST    3,88(13) ==> text
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         AR    4,15 ==> len
         A     5,=F'1' ==> i
         C     5,4(11) ==> i
         BL    @@L7
@@L3     EQU   *
         L     2,4(11) ==> bytes
         SLL   2,1 ==> bytes
         AR    2,4 ==> bytes,len
         MVC   88(4,13),=F'1'
         A     2,=F'8'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         LR    7,15 ==> txt99
         LTR   15,15 ==> txt99
         BE    @@L8
         L     2,0(11) ==> dal
         STH   2,0(15) ==> .dal
         MVC   2(2,15),6(11) ==> .count,count
         LA    6,8(,11) ==> list
         LR    5,15 ==> next,txt99
         A     5,=F'4' ==> next
         LA    2,4(,11)
         L     3,0(2) ==> count
         LR    4,3
         BCTR  3,0
         ST    3,0(2) ==> count
         LTR   4,4
         BNH   @@L8
         LR    8,2
@@L13    EQU   *
         A     6,=F'4' ==> list
         LR    2,6 ==> list
         A     2,=F'-4'
         L     3,0(2) ==> text
         LTR   3,3 ==> text
         BE    @@L8
         ST    3,88(13) ==> text
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         LR    4,15 ==> len
         STH   15,0(5) ==> len,size
         LR    2,5 ==> next
         A     2,=F'2'
         ST    2,88(13)
         ST    3,92(13) ==> text
         ST    15,96(13) ==> len
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         LR    2,5 ==> next
         AR    2,4 ==> len
         LR    5,2 ==> next
         A     5,=F'2' ==> next
         L     2,0(8) ==> count
         LR    3,2
         BCTR  2,0
         ST    2,0(8) ==> count
         LTR   3,3
         BH    @@L13
@@L8     EQU   *
         LR    15,7 ==> txt99
* Function '__nwtx9s' epilogue
         PDPEPIL
* Function '__nwtx9s' literal pool
         DS    0D
         LTORG
* Function '__nwtx9s' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
