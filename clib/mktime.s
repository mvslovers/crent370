 TITLE '/home/mike/repos/crent370/clib/mktime.c'
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
* external function 'mktime' prologue
* frame base=88, local stack=8, call args=16
&FUNC    SETC  'mktime'
MKTIME   PDPPRLG CINDEX=0,FRAME=112,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'mktime' code
         L     3,0(11) ==> timeptr
         L     2,20(3) ==> .tm_year
         A     2,=F'-70'
         LA    4,135(0,0)
         CLR   2,4
         BNH   @@L2
         MVC   104(4,13),=F'-1'
         B     @@L3
@@L2     EQU   *
         L     2,20(3) ==> .tm_year
         A     2,=F'1900'
         ST    2,88(13)
         L     2,16(3) ==> .tm_mon
         A     2,=F'1'
         ST    2,92(13)
         MVC   96(4,13),12(3) ==> .tm_mday
         LA    1,88(,13)
         L     15,=V(@@YMDTS)
         BALR  14,15
         A     15,=F'-719163'
         ST    15,104(13)
         LR    2,15
         SLL   2,1
         AR    2,15
         SLL   2,3
         A     2,8(3) ==> .tm_hour
         ST    2,104(13)
         SLL   2,4
         S     2,104(13)
         SLL   2,2
         A     2,4(3) ==> .tm_min
         ST    2,104(13)
         SLL   2,4
         S     2,104(13)
         SLL   2,2
         A     2,0(3) ==> .tm_sec
         ST    2,104(13)
@@L3     EQU   *
         LA    2,104(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(GMTIME)
         BALR  14,15
         MVC   0(36,3),0(15) ==> timeptr
         L     15,104(13)
* Function 'mktime' epilogue
         PDPEPIL
* Function 'mktime' literal pool
         DS    0D
         LTORG
* Function 'mktime' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
