 TITLE '/home/mike/repos/crent370/time64/tm64ascr.c'
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
* Program text area
@@2      EQU   *
         DC    C'Sun'
         DC    C'Mon'
         DC    C'Tue'
         DC    C'Wed'
         DC    C'Thu'
         DC    C'Fri'
         DC    C'Sat'
@@3      EQU   *
         DC    C'Jan'
         DC    C'Feb'
         DC    C'Mar'
         DC    C'Apr'
         DC    C'May'
         DC    C'Jun'
         DC    C'Jul'
         DC    C'Aug'
         DC    C'Sep'
         DC    C'Oct'
         DC    C'Nov'
         DC    C'Dec'
         
&FUNC    SETC 'valid_tm_wday'
         DS    0F
         EJECT
* static function 'valid_tm_wday' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'valid_tm_wday'
@@4      PDPPRLG CINDEX=0,FRAME=88,BASER=12,ENTRY=NO
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'valid_tm_wday' code
         L     2,0(11) ==> date
         L     2,24(2) ==> .tm_wday
         LA    15,1(0,0)
         LA    3,6(0,0)
         CLR   2,3
         BNH   @@L1
         SLR   15,15
@@L1     EQU   *
* Function 'valid_tm_wday' epilogue
         PDPEPIL
* Function 'valid_tm_wday' literal pool
         DS    0D
         LTORG
* Function 'valid_tm_wday' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         
&FUNC    SETC 'valid_tm_mon'
         DS    0F
         EJECT
* static function 'valid_tm_mon' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'valid_tm_mon'
@@5      PDPPRLG CINDEX=1,FRAME=88,BASER=12,ENTRY=NO
         B     @@FEN1
         LTORG
@@FEN1   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         LR    11,1
         L     10,=A(@@PGT1)
* Function 'valid_tm_mon' code
         L     2,0(11) ==> date
         L     2,16(2) ==> .tm_mon
         LA    15,1(0,0)
         LA    3,11(0,0)
         CLR   2,3
         BNH   @@L4
         SLR   15,15
@@L4     EQU   *
* Function 'valid_tm_mon' epilogue
         PDPEPIL
* Function 'valid_tm_mon' literal pool
         DS    0D
         LTORG
* Function 'valid_tm_mon' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
         
&FUNC    SETC 'asctime64_r'
         DS    0F
         EJECT
* external function 'asctime64_r' prologue
* frame base=88, local stack=0, call args=40
&FUNC    SETC  'asctime64_r'
TM64ASCR PDPPRLG CINDEX=2,FRAME=128,BASER=12,ENTRY=YES
         B     @@FEN2
         LTORG
@@FEN2   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG2    EQU   *
         LR    11,1
         L     10,=A(@@PGT2)
* Function 'asctime64_r' code
         L     3,0(11) ==> date
         L     4,4(11) ==> result
         ST    3,88(13) ==> date
         LA    1,88(,13)
         L     15,=A(@@4)
         BALR  14,15
         LTR   15,15 ==> result
         BE    @@L9
         ST    3,88(13) ==> date
         LA    1,88(,13)
         L     15,=A(@@5)
         BALR  14,15
         LTR   15,15 ==> result
         BNE   @@L8
@@L9     EQU   *
         SLR   15,15 ==> result
         B     @@L7
@@L8     EQU   *
         L     2,20(3) ==> .tm_year
         A     2,=F'1900'
         SLR   15,15 ==> result
         L     5,=F'9999'
         CR    2,5
         BH    @@L7
         LTR   4,4 ==> result
         BE    @@L11
         ST    4,88(13) ==> result
         MVC   92(4,13),=F'26'
         MVC   96(4,13),=A(@@LC0)
         L     2,24(3) ==> .tm_wday
         SLL   2,1
         A     2,24(3) ==> .tm_wday
         A     2,=A(@@2)
         ST    2,100(13)
         L     2,16(3) ==> .tm_mon
         SLL   2,1
         A     2,16(3) ==> .tm_mon
         A     2,=A(@@3)
         ST    2,104(13)
         MVC   108(4,13),12(3) ==> .tm_mday
         MVC   112(4,13),8(3) ==> .tm_hour
         MVC   116(4,13),4(3) ==> .tm_min
         MVC   120(4,13),0(3) ==> .tm_sec
         L     2,20(3) ==> .tm_year
         A     2,=F'1900'
         ST    2,124(13)
         LA    1,88(,13)
         L     15,=V(SNPRINTF)
         BALR  14,15
@@L11    EQU   *
         LR    15,4 ==> result
@@L7     EQU   *
* Function 'asctime64_r' epilogue
         PDPEPIL
* Function 'asctime64_r' literal pool
         DS    0D
         LTORG
* Function 'asctime64_r' page table
@@PGT2   DS    0F
         DC    A(@@PG2)
@@LC0    EQU   *
         DC    C'%.3s %.3s%3d %.2d:%.2d:%.2d %d'
         DC    X'15'
         DC    X'0'
         END
