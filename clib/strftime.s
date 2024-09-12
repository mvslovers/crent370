 TITLE '/home/mike/repos/crent370/clib/strftime.c'
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
@@LC0    EQU   *
         DC    C'Sun'
         DC    X'0'
@@LC1    EQU   *
         DC    C'Mon'
         DC    X'0'
@@LC2    EQU   *
         DC    C'Tue'
         DC    X'0'
@@LC3    EQU   *
         DC    C'Wed'
         DC    X'0'
@@LC4    EQU   *
         DC    C'Thu'
         DC    X'0'
@@LC5    EQU   *
         DC    C'Fri'
         DC    X'0'
@@LC6    EQU   *
         DC    C'Sat'
         DC    X'0'
* Program data area
         DS    0F
@@0      EQU   *
         DC    A(@@LC0)
         DC    A(@@LC1)
         DC    A(@@LC2)
         DC    A(@@LC3)
         DC    A(@@LC4)
         DC    A(@@LC5)
         DC    A(@@LC6)
* Program text area
@@LC7    EQU   *
         DC    C'Sunday'
         DC    X'0'
@@LC8    EQU   *
         DC    C'Monday'
         DC    X'0'
@@LC9    EQU   *
         DC    C'Tuesday'
         DC    X'0'
@@LC10   EQU   *
         DC    C'Wednesday'
         DC    X'0'
@@LC11   EQU   *
         DC    C'Thursday'
         DC    X'0'
@@LC12   EQU   *
         DC    C'Friday'
         DC    X'0'
@@LC13   EQU   *
         DC    C'Saturday'
         DC    X'0'
* Program data area
         DS    0F
@@1      EQU   *
         DC    A(@@LC7)
         DC    A(@@LC8)
         DC    A(@@LC9)
         DC    A(@@LC10)
         DC    A(@@LC11)
         DC    A(@@LC12)
         DC    A(@@LC13)
* Program text area
@@LC14   EQU   *
         DC    C'Jan'
         DC    X'0'
@@LC15   EQU   *
         DC    C'Feb'
         DC    X'0'
@@LC16   EQU   *
         DC    C'Mar'
         DC    X'0'
@@LC17   EQU   *
         DC    C'Apr'
         DC    X'0'
@@LC18   EQU   *
         DC    C'May'
         DC    X'0'
@@LC19   EQU   *
         DC    C'Jun'
         DC    X'0'
@@LC20   EQU   *
         DC    C'Jul'
         DC    X'0'
@@LC21   EQU   *
         DC    C'Aug'
         DC    X'0'
@@LC22   EQU   *
         DC    C'Sep'
         DC    X'0'
@@LC23   EQU   *
         DC    C'Oct'
         DC    X'0'
@@LC24   EQU   *
         DC    C'Nov'
         DC    X'0'
@@LC25   EQU   *
         DC    C'Dec'
         DC    X'0'
* Program data area
         DS    0F
@@2      EQU   *
         DC    A(@@LC14)
         DC    A(@@LC15)
         DC    A(@@LC16)
         DC    A(@@LC17)
         DC    A(@@LC18)
         DC    A(@@LC19)
         DC    A(@@LC20)
         DC    A(@@LC21)
         DC    A(@@LC22)
         DC    A(@@LC23)
         DC    A(@@LC24)
         DC    A(@@LC25)
* Program text area
@@LC26   EQU   *
         DC    C'January'
         DC    X'0'
@@LC27   EQU   *
         DC    C'February'
         DC    X'0'
@@LC28   EQU   *
         DC    C'March'
         DC    X'0'
@@LC29   EQU   *
         DC    C'April'
         DC    X'0'
@@LC30   EQU   *
         DC    C'June'
         DC    X'0'
@@LC31   EQU   *
         DC    C'July'
         DC    X'0'
@@LC32   EQU   *
         DC    C'August'
         DC    X'0'
@@LC33   EQU   *
         DC    C'September'
         DC    X'0'
@@LC34   EQU   *
         DC    C'October'
         DC    X'0'
@@LC35   EQU   *
         DC    C'November'
         DC    X'0'
@@LC36   EQU   *
         DC    C'December'
         DC    X'0'
* Program data area
         DS    0F
@@3      EQU   *
         DC    A(@@LC26)
         DC    A(@@LC27)
         DC    A(@@LC28)
         DC    A(@@LC29)
         DC    A(@@LC18)
         DC    A(@@LC30)
         DC    A(@@LC31)
         DC    A(@@LC32)
         DC    A(@@LC33)
         DC    A(@@LC34)
         DC    A(@@LC35)
         DC    A(@@LC36)
* Program text area
@@LC37   EQU   *
         DC    X'0'
* Program data area
         DS    0F
@@4      EQU   *
         DC    A(@@LC37)
         DC    4X'00'
* Program text area
         DS    0F
         EJECT
* external function 'strftime' prologue
* frame base=88, local stack=96, call args=40
&FUNC    SETC  'strftime'
STRFTIME PDPPRLG CINDEX=0,FRAME=224,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'strftime' code
         SLR   2,2
         SLR   3,3
         ST    2,160(13)
         ST    3,4+160(13)
         ST    2,168(13)
         ST    3,4+168(13)
         ST    2,176(13)
         ST    3,4+176(13)
         ST    2,184(13)
         ST    3,4+184(13)
         ST    2,192(13)
         ST    3,4+192(13)
         ST    2,200(13)
         ST    3,4+200(13)
         ST    2,208(13)
         ST    3,4+208(13)
         L     9,0(11) ==> s
         L     6,8(11) ==> f
         L     8,12(11) ==> t
         LR    4,9 ==> p,s
         LR    7,9 ==> q,s
         A     7,4(11) ==> q,maxs
         BCTR  7,0 ==> q
         IC    2,0(6) ==> f
         CLM   2,1,=XL1'00'
         L     14,=A(@@L48)
         BER   14
@@L46    EQU   *
         L     12,0(,10)
         IC    2,0(6) ==> f
         A     6,=F'1' ==> f
         CLM   2,1,=XL1'6C'
         L     14,=A(@@L5)
         BNER  14
         LA    5,128(,13) ==> r
         SLR   2,2
         IC    2,0(6) ==> f
         A     2,=F'-108'
         A     6,=F'1' ==> f
         LA    3,125(0,0)
         CLR   2,3
         L     14,=A(@@L36)
         BHR   14
         LR    3,2
         MH    3,=H'4'
         L     2,=A(@@L38)
         L     14,0(3,2)
         BR    14
         DS    0F
         DS    0F
         DS    0F
         LTORG
         DS    0F
@@L38    EQU   *
         DC    A(@@L7)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L8)
         DC    A(@@L10)
         DC    A(@@L12)
         DC    A(@@L13)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L17)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L18)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L20)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L28)
         DC    A(@@L29)
         DC    A(@@L31)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L9)
         DC    A(@@L11)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L14)
         DC    A(@@L15)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L19)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L36)
         DC    A(@@L23)
         DC    A(@@L36)
         DC    A(@@L24)
         DC    A(@@L36)
         DC    A(@@L26)
         DC    A(@@L30)
         DC    A(@@L32)
         DC    A(@@L33)
@@L7     EQU   *
         L     5,=A(@@LC38) ==> r
         B     @@L6
@@L8     EQU   *
         L     3,24(8) ==> .tm_wday
         SLL   3,2
         L     2,=A(@@0)
         B     @@L52
@@L9     EQU   *
         L     3,24(8) ==> .tm_wday
         SLL   3,2
         L     2,=A(@@1)
         B     @@L52
@@L10    EQU   *
         L     3,16(8) ==> .tm_mon
         SLL   3,2
         L     2,=A(@@2)
         B     @@L52
@@L11    EQU   *
         L     3,16(8) ==> .tm_mon
         SLL   3,2
         L     2,=A(@@3)
@@L52    EQU   *
         L     5,0(3,2) ==> r,month
         B     @@L6
@@L12    EQU   *
         ST    5,88(13) ==> r
         MVC   92(4,13),=A(@@LC39)
         L     3,24(8) ==> .tm_wday
         SLL   3,2
         L     2,=A(@@0)
         L     2,0(3,2) ==> aday
         ST    2,96(13)
         L     3,16(8) ==> .tm_mon
         SLL   3,2
         L     2,=A(@@2)
         L     2,0(3,2) ==> amonth
         ST    2,100(13)
         MVC   104(4,13),12(8) ==> .tm_mday
         MVC   108(4,13),8(8) ==> .tm_hour
         MVC   112(4,13),4(8) ==> .tm_min
         MVC   116(4,13),0(8) ==> .tm_sec
         L     2,20(8) ==> .tm_year
         A     2,=F'1900'
         ST    2,120(13)
         LA    1,88(,13)
         L     15,=A(@@5)
         BALR  14,15
         B     @@L6
@@L13    EQU   *
         ST    5,88(13) ==> r
         MVC   92(4,13),=A(@@LC40)
         MVC   96(4,13),12(8) ==> .tm_mday
         B     @@L50
@@L14    EQU   *
         ST    5,88(13) ==> r
         MVC   92(4,13),=A(@@LC40)
         MVC   96(4,13),8(8) ==> .tm_hour
         B     @@L50
@@L15    EQU   *
         ST    5,88(13) ==> r
         MVC   92(4,13),=A(@@LC40)
         MVC   160(4,13),8(8) ==> .tm_hour
         L     2,160(13)
         L     3,4+160(13)
         SRDA  2,32
         LA    15,12(0,0)
         DR    2,15
         ST    2,160(13)
         ST    3,4+160(13)
         L     2,160(13)
         LTR   2,2
         BNE   @@L54
         LR    2,15
         B     @@L54
@@L17    EQU   *
         ST    5,88(13) ==> r
         MVC   92(4,13),=A(@@LC41)
         L     2,28(8) ==> .tm_yday
         B     @@L55
@@L18    EQU   *
         ST    5,88(13) ==> r
         MVC   92(4,13),=A(@@LC40)
         L     2,16(8) ==> .tm_mon
@@L55    EQU   *
         A     2,=F'1'
         B     @@L54
@@L19    EQU   *
         ST    5,88(13) ==> r
         MVC   92(4,13),=A(@@LC40)
         MVC   96(4,13),4(8) ==> .tm_min
         B     @@L50
@@L20    EQU   *
         L     2,8(8) ==> .tm_hour
         L     5,=A(@@LC42) ==> r
         LA    3,11(0,0)
         CR    2,3
         BH    @@L6
         L     5,=A(@@LC43) ==> r
         B     @@L6
@@L23    EQU   *
         ST    5,88(13) ==> r
         MVC   92(4,13),=A(@@LC40)
         MVC   96(4,13),0(8) ==> .tm_sec
         B     @@L50
@@L24    EQU   *
         MVC   168(4,13),28(8) ==> .tm_yday
         L     2,168(13)
         L     3,4+168(13)
         SRDA  2,32
         LA    15,7(0,0)
         DR    2,15
         ST    2,168(13)
         ST    3,4+168(13)
         MVC   216(4,13),172(13) ==> w
         MVC   176(4,13),28(8) ==> .tm_yday
         L     2,176(13)
         L     3,4+176(13)
         SRDA  2,32
         DR    2,15
         ST    2,176(13)
         ST    3,4+176(13)
         L     2,176(13)
         C     2,24(8) ==> .tm_wday
         BNH   @@L27
         B     @@L56
@@L26    EQU   *
         MVC   184(4,13),28(8) ==> .tm_yday
         L     2,184(13)
         L     3,4+184(13)
         SRDA  2,32
         LA    15,7(0,0)
         DR    2,15
         ST    2,184(13)
         ST    3,4+184(13)
         MVC   216(4,13),188(13) ==> w
         MVC   192(4,13),28(8) ==> .tm_yday
         L     2,192(13)
         L     3,4+192(13)
         SRDA  2,32
         DR    2,15
         ST    2,192(13)
         ST    3,4+192(13)
         L     2,24(8) ==> .tm_wday
         A     2,=F'6'
         ST    2,200(13)
         L     2,200(13)
         L     3,4+200(13)
         SRDA  2,32
         DR    2,15
         ST    2,200(13)
         ST    3,4+200(13)
         C     2,192(13)
         BNL   @@L27
@@L56    EQU   *
         L     2,216(13) ==> w
         A     2,=F'1'
         ST    2,216(13) ==> w
@@L27    EQU   *
         ST    5,88(13) ==> r
         MVC   92(4,13),=A(@@LC40)
         MVC   96(4,13),216(13) ==> w
         B     @@L50
@@L28    EQU   *
         ST    5,88(13) ==> r
         MVC   92(4,13),=A(@@LC44)
         MVC   96(4,13),24(8) ==> .tm_wday
         B     @@L50
@@L29    EQU   *
         ST    5,88(13) ==> r
         MVC   92(4,13),=A(@@LC45)
         L     3,24(8) ==> .tm_wday
         SLL   3,2
         L     2,=A(@@0)
         L     2,0(3,2) ==> aday
         ST    2,96(13)
         L     3,16(8) ==> .tm_mon
         SLL   3,2
         L     2,=A(@@2)
         L     2,0(3,2) ==> amonth
         ST    2,100(13)
         MVC   104(4,13),12(8) ==> .tm_mday
         L     2,20(8) ==> .tm_year
         A     2,=F'1900'
         ST    2,108(13)
         B     @@L51
@@L30    EQU   *
         ST    5,88(13) ==> r
         MVC   92(4,13),=A(@@LC46)
         MVC   96(4,13),8(8) ==> .tm_hour
         MVC   100(4,13),4(8) ==> .tm_min
         MVC   104(4,13),0(8) ==> .tm_sec
@@L51    EQU   *
         LA    1,88(,13)
         L     15,=A(@@5)
         BALR  14,15
         B     @@L6
@@L31    EQU   *
         ST    5,88(13) ==> r
         MVC   92(4,13),=A(@@LC40)
         MVC   208(4,13),20(8) ==> .tm_year
         L     2,208(13)
         L     3,4+208(13)
         SRDA  2,32
         LA    15,100(0,0)
         DR    2,15
         ST    2,208(13)
         ST    3,4+208(13)
         MVC   96(4,13),208(13)
         B     @@L50
@@L32    EQU   *
         ST    5,88(13) ==> r
         MVC   92(4,13),=A(@@LC47)
         L     2,20(8) ==> .tm_year
         A     2,=F'1900'
@@L54    EQU   *
         ST    2,96(13)
@@L50    EQU   *
         LA    1,88(,13)
         L     15,=A(@@5)
         BALR  14,15
         B     @@L6
@@L33    EQU   *
         L     2,32(8) ==> .tm_isdst
         LTR   2,2
         BE    @@L34
         L     2,=A(@@4)
         L     5,4(2) ==> r,__tzname
         B     @@L6
@@L34    EQU   *
         L     2,=A(@@4)
         L     5,0(2) ==> r,__tzname
         B     @@L6
@@L36    EQU   *
         MVI   128(13),108 ==> buf
         L     2,=F'-1'
         IC    3,0(2,6)
         STC   3,129(13) ==> buf
         MVI   130(13),0 ==> buf
         IC    2,0(2,6)
         CLM   2,1,=XL1'00'
         BNE   @@L6
         BCTR  6,0 ==> f
@@L6     EQU   *
         IC    2,0(5) ==> r
         CLM   2,1,=XL1'00'
         BE    @@L2
@@L43    EQU   *
         CLR   4,7 ==> p,q
         BE    @@L53
         MVC   0(1,4),0(5) ==> p,r
         A     5,=F'1' ==> r
         A     4,=F'1' ==> p
         IC    2,0(5) ==> r
         CLM   2,1,=XL1'00'
         BE    @@L2
         B     @@L43
@@L5     EQU   *
         CLR   4,7 ==> p,q
         BNE   @@L45
@@L53    EQU   *
         MVI   0(4),0 ==> p
         SLR   15,15
         B     @@L1
@@L45    EQU   *
         L     2,=F'-1'
         IC    2,0(2,6)
         STC   2,0(4) ==> p
         A     4,=F'1' ==> p
@@L2     EQU   *
         IC    2,0(6) ==> f
         CLM   2,1,=XL1'00'
         BNE   @@L46
@@L48    EQU   *
         MVI   0(4),0 ==> p
         LR    15,4 ==> p
         SR    15,9 ==> s
@@L1     EQU   *
* Function 'strftime' epilogue
         PDPEPIL
* Function 'strftime' literal pool
         DS    0D
         LTORG
* Function 'strftime' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC38   EQU   *
         DC    C'%'
         DC    X'0'
@@LC39   EQU   *
         DC    C'%0 %0 %2 %2:%2:%2 %4'
         DC    X'0'
@@LC40   EQU   *
         DC    C'%2'
         DC    X'0'
@@LC41   EQU   *
         DC    C'%3'
         DC    X'0'
@@LC42   EQU   *
         DC    C'PM'
         DC    X'0'
@@LC43   EQU   *
         DC    C'AM'
         DC    X'0'
@@LC44   EQU   *
         DC    C'%1'
         DC    X'0'
@@LC45   EQU   *
         DC    C'%3s %3s %2 %4'
         DC    X'0'
@@LC46   EQU   *
         DC    C'%2:%2:%2'
         DC    X'0'
@@LC47   EQU   *
         DC    C'%4'
         DC    X'0'
* Program data area
         DS    0F
@@6      EQU   *
         DC    F'1'
         DC    F'10'
         DC    F'100'
         DC    F'1000'
         DC    F'10000'
* Program text area
         DS    0F
         EJECT
* static function 'strfmt' prologue
* frame base=88, local stack=8, call args=0
&FUNC    SETC  'strfmt'
@@5      PDPPRLG CINDEX=1,FRAME=96,BASER=12,ENTRY=NO
         B     @@FEN1
         LTORG
@@FEN1   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         LR    11,1
         L     10,=A(@@PGT1)
* Function 'strfmt' code
         SLR   8,8 ==> ival
         SLR   9,9 ==> ival
         LR    6,8 ==> ival
         LR    7,9 ==> ival
         L     4,0(11) ==> str
         LA    2,8(,11)
         ST    2,88(13) ==> vp
         L     2,4(11)
         IC    2,0(2)
         CLM   2,1,=XL1'00'
         BE    @@L75
@@L73    EQU   *
         L     3,4(11) ==> fmt
         IC    2,0(3)
         A     3,=F'1'
         ST    3,4(11) ==> fmt
         CLM   2,1,=XL1'6C'
         BNE   @@L61
         SLR   2,2
         IC    2,0(3)
         LR    15,2 ==> ilen
         A     15,=F'-240' ==> ilen
         LR    2,3
         A     2,=F'1'
         ST    2,4(11) ==> fmt
         LTR   15,15 ==> ilen
         BNE   @@L62
         L     2,88(13) ==> vp
         A     2,=F'4'
         ST    2,88(13) ==> vp
         A     2,=F'-4'
         L     3,0(2) ==> sval
         IC    2,0(3) ==> sval
         CLM   2,1,=XL1'00'
         BE    @@L58
@@L66    EQU   *
         MVC   0(1,4),0(3) ==> str,sval
         A     3,=F'1' ==> sval
         A     4,=F'1' ==> str
         IC    2,0(3) ==> sval
         CLM   2,1,=XL1'00'
         BE    @@L58
         B     @@L66
@@L62    EQU   *
         L     2,88(13) ==> vp
         A     2,=F'4'
         ST    2,88(13) ==> vp
         A     2,=F'-4'
         L     3,0(2) ==> ival
         LTR   15,15 ==> ilen
         BE    @@L58
         L     5,=A(@@6)
@@L71    EQU   *
         LR    2,15 ==> ilen
         MH    2,=H'4'
         LR    8,3 ==> ival
         SRDA  8,32 ==> ival
         D     8,0(2,5) ==> ival,pow
         LR    3,8 ==> ival
         BCTR  15,0 ==> ilen
         LR    2,15 ==> ilen
         MH    2,=H'4'
         LR    6,8 ==> ival
         SRDA  6,32 ==> ival
         D     6,0(2,5) ==> ival,pow
         LA    2,240(,7) ==> ival
         STC   2,0(4) ==> str
         A     4,=F'1' ==> str
         LTR   15,15 ==> ilen
         BE    @@L58
         B     @@L71
@@L61    EQU   *
         L     3,4(11)
         L     2,=F'-1'
         IC    3,0(2,3)
         STC   3,0(4) ==> str
         A     4,=F'1' ==> str
@@L58    EQU   *
         L     2,4(11)
         IC    2,0(2)
         CLM   2,1,=XL1'00'
         BNE   @@L73
@@L75    EQU   *
         MVI   0(4),0 ==> str
* Function 'strfmt' epilogue
         PDPEPIL
* Function 'strfmt' literal pool
         DS    0D
         LTORG
* Function 'strfmt' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
         END
