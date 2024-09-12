 TITLE '/home/mike/repos/crent370/clib/gmtimer.c'
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
* external function 'gmtime_r' prologue
* frame base=88, local stack=128, call args=16
&FUNC    SETC  'gmtime_r'
GMTIMER  PDPPRLG CINDEX=0,FRAME=232,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'gmtime_r' code
         SLR   6,6 ==> days
         SLR   7,7 ==> days
         LR    4,6 ==> days
         LR    5,7 ==> days
         ST    6,120(13) ==> days
         ST    7,4+120(13) ==> days
         ST    6,128(13) ==> days
         ST    7,4+128(13) ==> days
         ST    6,136(13) ==> days
         ST    7,4+136(13) ==> days
         ST    6,144(13) ==> days
         ST    7,4+144(13) ==> days
         ST    6,152(13) ==> days
         ST    7,4+152(13) ==> days
         ST    6,160(13) ==> days
         ST    7,4+160(13) ==> days
         ST    6,168(13) ==> days
         ST    7,4+168(13) ==> days
         ST    6,176(13) ==> days
         ST    7,4+176(13) ==> days
         ST    6,184(13) ==> days
         ST    7,4+184(13) ==> days
         ST    6,192(13) ==> days
         ST    7,4+192(13) ==> days
         ST    6,200(13) ==> days
         ST    7,4+200(13) ==> days
         ST    6,208(13) ==> days
         ST    7,4+208(13) ==> days
         ST    6,216(13) ==> days
         ST    7,4+216(13) ==> days
         ST    6,224(13) ==> days
         ST    7,4+224(13) ==> days
         L     9,4(11) ==> tms
         L     2,0(11) ==> timer
         L     2,0(2) ==> days,timer
         LR    6,2 ==> days
         SRDL  6,32 ==> days
         L     3,=F'86400'
         DR    6,3 ==> days
         LR    4,2 ==> days
         SRDL  4,32 ==> days
         DR    4,3 ==> days
         LR    2,7
         A     2,=F'719163'
         ST    2,88(13)
         LA    2,104(,13)
         ST    2,92(13)
         LA    2,108(,13)
         ST    2,96(13)
         LA    2,112(,13)
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(@@STYMD)
         BALR  14,15
         L     2,104(13)
         A     2,=F'-1900'
         ST    2,20(9) ==> .tm_year
         L     2,108(13)
         BCTR  2,0
         ST    2,16(9) ==> .tm_mon
         MVC   12(4,9),112(13) ==> .tm_mday
         L     2,20(9) ==> .tm_year
         A     2,=F'1900'
         ST    2,88(13)
         MVC   92(4,13),108(13)
         MVC   96(4,13),112(13)
         LA    1,88(,13)
         L     15,=V(@@YMDTS)
         BALR  14,15
         LR    3,15 ==> tms
         L     2,20(9) ==> .tm_year
         A     2,=F'1900'
         ST    2,88(13)
         MVC   92(4,13),=F'1'
         MVC   96(4,13),=F'1'
         LA    1,88(,13)
         L     15,=V(@@YMDTS)
         BALR  14,15
         SR    3,15 ==> tms
         ST    3,28(9) ==> .tm_yday
         L     5,108(13)
         A     5,=F'9'
         ST    5,120(13)
         L     6,120(13)
         L     7,4+120(13)
         SRDL  6,32
         LA    2,12(0,0)
         DR    6,2
         ST    6,120(13)
         ST    7,4+120(13)
         L     8,120(13)
         A     8,=F'1'
         SLL   8,4
         ST    8,128(13)
         L     6,128(13)
         L     7,4+128(13)
         SRDL  6,32
         LA    2,27(0,0)
         DR    6,2
         ST    6,128(13)
         ST    7,4+128(13)
         L     8,128(13)
         A     8,112(13)
         L     3,20(9) ==> .tm_year
         A     3,=F'1900'
         ST    3,136(13)
         L     6,136(13)
         L     7,4+136(13)
         SRDA  6,32
         LA    2,400(0,0)
         DR    6,2
         AR    8,6
         LR    2,6
         A     2,=F'400'
         BNL   @@L2
         A     2,=F'3'
@@L2     EQU   *
         SRA   2,2
         AR    8,2
         L     3,20(9) ==> .tm_year
         A     3,=F'1900'
         ST    3,144(13)
         L     6,144(13)
         L     7,4+144(13)
         SRDA  6,32
         LA    2,400(0,0)
         DR    6,2
         AR    6,2
         ST    6,152(13)
         L     6,152(13)
         L     7,4+152(13)
         SRDA  6,32
         LA    2,100(0,0)
         DR    6,2
         ST    6,152(13)
         ST    7,4+152(13)
         SR    8,7
         A     8,=F'401'
         L     2,108(13)
         LA    5,2(0,0)
         CLR   2,5
         BH    @@L3
         LR    2,3
         N     2,=F'3'
         LTR   2,2
         BNE   @@L8
         ST    3,160(13)
         L     6,160(13)
         L     7,4+160(13)
         SRDA  6,32
         LA    2,100(0,0)
         DR    6,2
         LTR   6,6
         BNE   @@L7
@@L8     EQU   *
         L     3,20(9) ==> .tm_year
         A     3,=F'1900'
         ST    3,168(13)
         L     6,168(13)
         L     7,4+168(13)
         SRDA  6,32
         LA    2,400(0,0)
         DR    6,2
         LTR   6,6
         BNE   @@L5
@@L7     EQU   *
         A     8,=F'5'
         ST    8,176(13)
         L     6,176(13)
         L     7,4+176(13)
         B     @@L9
@@L5     EQU   *
         A     8,=F'6'
         ST    8,184(13)
         L     6,184(13)
         L     7,4+184(13)
         B     @@L9
@@L3     EQU   *
         ST    8,192(13)
         L     6,192(13)
         L     7,4+192(13)
@@L9     EQU   *
         SRDL  6,32
         LA    2,7(0,0)
         DR    6,2
         ST    6,24(9) ==> .tm_wday
         MVC   32(4,9),=F'-1' ==> .tm_isdst
         ST    4,200(13) ==> secs
         L     6,200(13)
         L     7,4+200(13)
         SRDL  6,32
         LA    2,60(0,0)
         DR    6,2
         ST    6,200(13)
         ST    7,4+200(13)
         MVC   0(4,9),200(13) ==> .tm_sec
         ST    4,208(13) ==> secs
         L     4,208(13)
         L     5,4+208(13)
         SRDL  4,32
         LR    6,2
         DR    4,2
         ST    4,208(13)
         ST    5,4+208(13)
         MVC   216(4,13),212(13)
         L     2,216(13)
         L     3,4+216(13)
         SRDL  2,32
         LR    4,6
         DR    2,6
         ST    2,216(13)
         ST    3,4+216(13)
         MVC   4(4,9),216(13) ==> .tm_min
         MVC   224(4,13),212(13)
         L     6,224(13)
         L     7,4+224(13)
         SRDL  6,32
         DR    6,4
         ST    6,224(13)
         ST    7,4+224(13)
         MVC   8(4,9),228(13) ==> .tm_hour
         LR    15,9 ==> tms
* Function 'gmtime_r' epilogue
         PDPEPIL
* Function 'gmtime_r' literal pool
         DS    0D
         LTORG
* Function 'gmtime_r' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
