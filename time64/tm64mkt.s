 TITLE '/home/mike/repos/crent370/time64/tm64mkt.c'
         COPY  PDPTOP
         CSECT
* GNU C version 3.2.3 - c2asm370 version 1.0 (mvs)
*        compiled by GNU C version 13.2.0.
*
* options passed:  -lang-c -I. -I/home/mike/repos/crent370/time64
* -I/home/mike/repos/crent370/include -iprefix -D__GNUC__=3
* -D__GNUC_MINOR__=2 -D__GNUC_PATCHLEVEL__=3 -D__GXX_ABI_VERSION=102
* -D__GCC__ -D__MVS__ -D__GCC__ -D__MVS__ -Asystem=mvs -Acpu=i370
* -Amachine=i370 -D__OPTIMIZE__ -D__STDC_HOSTED__=1 -trigraphs -O1
* -fverbose-asm
* 
* options enabled:  -fdefer-pop -fthread-jumps -fpeephole
* -ffunction-cse -fkeep-static-consts -fpcc-struct-return -fgcse-lm
* -fgcse-sm -fsched-interblock -fsched-spec -fbranch-count-reg
* -fcprop-registers -fcommon -fverbose-asm -fgnu-linker
* -fargument-alias -fmerge-constants -fident
* -fguess-branch-probability -fmath-errno -ftrapping-math
* -mchar-instructions -mno-pickax -mno-constants-first
*
         
&FUNC    SETC 'mktime64'
* Program text area
         DS    0F
         EJECT
* external function 'mktime64' prologue
* frame base=88, local stack=96, call args=16
&FUNC    SETC  'mktime64'
TM64MKT  PDPPRLG CINDEX=0,FRAME=200,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'mktime64' code
         LR    5,0
         L     4,0(11) ==> input_date
         L     3,20(4) ==> year,tm_year
         A     3,=F'1900' ==> year
         LA    2,192(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@64INIT)
         BALR  14,15
         LR    2,3 ==> year
         A     2,=F'-1970'
         L     6,=F'8029'
         CLR   2,6
         BNH   @@L2
         LA    2,192(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'1'
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@64SI32)
         BALR  14,15
         B     @@L3
@@L2     EQU   *
         LR    2,3 ==> year
         A     2,=F'-1970'
         LA    6,67(0,0)
         CLR   2,6
         BH    @@L4
         ST    4,88(13) ==> input_date
         LA    1,88(,13)
         L     15,=V(MKTIME)
         BALR  14,15
         LA    2,192(,13)
         ST    2,88(13)
         ST    15,92(13)
         LA    1,88(,13)
         L     15,=V(@@64FU32)
         BALR  14,15
         B     @@L3
@@L4     EQU   *
         MVC   144(36,13),0(4) ==> date,input_date
         ST    3,88(13) ==> year
         LA    1,88(,13)
         L     15,=V(TM64SYR)
         BALR  14,15
         A     15,=F'-1900'
         ST    15,164(13) ==> .tm_year
         MVC   104(36,13),144(13) ==> safe_date,date
         LA    2,104(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(MKTIME)
         BALR  14,15
         LA    2,192(,13)
         ST    2,88(13)
         ST    15,92(13)
         LA    1,88(,13)
         L     15,=V(@@64FU32)
         BALR  14,15
         ST    3,88(13) ==> year
         L     2,124(13) ==> .tm_year
         A     2,=F'1900'
         ST    2,92(13)
         LA    0,184(,13)
         LA    1,88(,13)
         L     15,=V(TM64SBY)
         BALR  14,15
         LA    2,192(,13)
         ST    2,88(13)
         MVC   92(8,13),184(13)
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(@@64AU64)
         BALR  14,15
         LA    2,192(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(TM64GMT)
         BALR  14,15
         MVC   0(36,4),0(15) ==> input_date
@@L3     EQU   *
         MVC   0(8,5),192(13) ==> <result>
         LR    15,5
* Function 'mktime64' epilogue
         PDPEPIL
* Function 'mktime64' literal pool
         DS    0D
         LTORG
* Function 'mktime64' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
