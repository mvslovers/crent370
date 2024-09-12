 TITLE '/home/mike/repos/crent370/clib/asctime.c'
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
         DS    0F
         EJECT
* external function 'asctime' prologue
* frame base=88, local stack=0, call args=40
&FUNC    SETC  'asctime'
ASCTIME  PDPPRLG CINDEX=0,FRAME=128,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'asctime' code
         L     3,0(11) ==> timeptr
         LA    1,88(,13)
         L     15,=V(@@CRTGET)
         BALR  14,15
         LR    4,15 ==> buf,crt
         A     4,=F'24' ==> buf
         LTR   15,15 ==> crt
         BNE   @@L3
         L     4,=A(@@4) ==> buf
@@L3     EQU   *
         ST    4,88(13) ==> buf
         MVC   92(4,13),=A(@@LC0)
         L     2,24(3) ==> .tm_wday
         SLL   2,1
         A     2,24(3) ==> .tm_wday
         A     2,=A(@@2)
         ST    2,96(13)
         L     2,16(3) ==> .tm_mon
         SLL   2,1
         A     2,16(3) ==> .tm_mon
         A     2,=A(@@3)
         ST    2,100(13)
         MVC   104(4,13),12(3) ==> .tm_mday
         MVC   108(4,13),8(3) ==> .tm_hour
         MVC   112(4,13),4(3) ==> .tm_min
         MVC   116(4,13),0(3) ==> .tm_sec
         L     2,20(3) ==> .tm_year
         A     2,=F'1900'
         ST    2,120(13)
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
         LR    15,4 ==> buf
* Function 'asctime' epilogue
         PDPEPIL
* Function 'asctime' literal pool
         DS    0D
         LTORG
* Function 'asctime' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'%.3s %.3s%3d %.2d:%.2d:%.2d %d'
         DC    X'15'
         DC    X'0'
         DS    0F
@@4      EQU   *
         DC    28X'00'
         END
