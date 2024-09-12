 TITLE '/home/mike/repos/crent370/time64/tm64ltmr.c'
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
         DC    C'localtime64_r'
         DC    X'0'
         DS    0F
         EJECT
* external function 'localtime64_r' prologue
* frame base=88, local stack=104, call args=24
&FUNC    SETC  'localtime64_r'
TM64LTMR PDPPRLG CINDEX=0,FRAME=216,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'localtime64_r' code
         SLR   4,4
         SLR   5,5
         LR    8,4
         LR    9,5
         L     3,0(11) ==> time
         L     6,4(11) ==> local_tm
         LTR   3,3 ==> time
         BNE   @@L2
         MVC   88(4,13),=A(@@LC0)
         MVC   92(4,13),=A(@@2)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         LR    15,3 ==> local_tm,time
         B     @@L1
@@L2     EQU   *
         LTR   6,6 ==> local_tm
         BNE   @@L3
         MVC   88(4,13),=A(@@LC1)
         MVC   92(4,13),=A(@@2)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         B     @@L9
@@L3     EQU   *
         ST    3,88(13) ==> time
         LA    2,152(,13)
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(TM64GMTR)
         BALR  14,15
         LR    2,15 ==> local_tm
         LTR   15,15 ==> local_tm
         BNE   @@L4
         MVC   88(4,13),=A(@@LC2)
         MVC   92(4,13),=A(@@2)
         MVC   96(8,13),0(3) ==> time
         MVC   104(8,13),0(3) ==> time
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         B     @@L11
@@L4     EQU   *
         L     3,172(13) ==> orig_year,tm_year
         LR    2,3 ==> orig_year
         A     2,=F'-70'
         LA    7,67(0,0)
         CLR   2,7
         BNH   @@L5
         A     2,=F'1970'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(TM64SYR)
         BALR  14,15
         A     15,=F'-1900'
         ST    15,172(13) ==> .tm_year
@@L5     EQU   *
         LA    2,152(,13)
         ST    2,88(13)
         LA    0,192(,13)
         LA    1,88(,13)
         L     15,=V(TM64TGM)
         BALR  14,15
         MVC   200(8,13),192(13)
         LA    2,200(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@64TU32)
         BALR  14,15
         ST    15,208(13) ==> local_tm
         LA    2,208(,13)
         ST    2,88(13)
         LA    2,112(,13)
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(LOCALTMR)
         BALR  14,15
         LR    2,15 ==> local_tm
         LTR   15,15 ==> local_tm
         BNE   @@L6
         MVC   88(4,13),=A(@@LC3)
         MVC   92(4,13),=A(@@2)
         MVC   96(4,13),208(13)
         MVC   100(4,13),208(13)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
@@L11    EQU   *
         LR    15,2 ==> local_tm
         B     @@L1
@@L6     EQU   *
         MVC   0(36,6),112(13) ==> local_tm,safe_date
         ST    3,20(6) ==> orig_year,tm_year
         L     15,16(6) ==> month_diff,tm_mon
         S     15,168(13) ==> month_diff,tm_mon
         LA    2,11(0,0)
         CLR   15,2 ==> month_diff
         BNE   @@L7
         LR    2,3 ==> orig_year
         BCTR  2,0
         ST    2,20(6) ==> .tm_year
@@L7     EQU   *
         L     3,=F'-11'
         CLR   15,3 ==> month_diff
         BNE   @@L8
         L     2,20(6) ==> .tm_year
         A     2,=F'1'
         ST    2,20(6) ==> .tm_year
@@L8     EQU   *
         L     15,20(6) ==> .tm_year
         A     15,=F'1900'
         LR    4,15
         SRDA  4,32
         LA    7,400(0,0)
         DR    4,7
         LTR   4,4
         BE    @@L9
         LR    2,15
         N     2,=F'3'
         LTR   2,2
         BNE   @@L10
         LR    8,15
         SRDA  8,32
         LA    2,100(0,0)
         DR    8,2
         LTR   8,8
         BNE   @@L9
@@L10    EQU   *
         L     2,28(6) ==> .tm_yday
         LA    3,365(0,0)
         CLR   2,3
         BNE   @@L9
         MVC   28(4,6),=F'364' ==> .tm_yday
@@L9     EQU   *
         LR    15,6 ==> local_tm
@@L1     EQU   *
* Function 'localtime64_r' epilogue
         PDPEPIL
* Function 'localtime64_r' literal pool
         DS    0D
         LTORG
* Function 'localtime64_r' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'%s: NULL time pointer parameter 1'
         DC    X'0'
@@LC1    EQU   *
         DC    C'%s: NULL local_tm pointer parameter 2'
         DC    X'0'
@@LC2    EQU   *
         DC    C'%s: gmtime64_r failure for time value 0x%016LLX '
         DC    C'(%llu)'
         DC    X'0'
@@LC3    EQU   *
         DC    C'%s: localtime_r failure for time value 0x%08X (%'
         DC    C'u)'
         DC    X'0'
         END
