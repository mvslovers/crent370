 TITLE '/home/mike/repos/crent370/time64/tm64syr.c'
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
         
* safe_years_high
* Program text area
         DS    0F
@@2      EQU   *
         DC    F'2016'
         DC    F'2017'
         DC    F'2018'
         DC    F'2019'
         DC    F'2020'
         DC    F'2021'
         DC    F'2022'
         DC    F'2023'
         DC    F'2024'
         DC    F'2025'
         DC    F'2026'
         DC    F'2027'
         DC    F'2028'
         DC    F'2029'
         DC    F'2030'
         DC    F'2031'
         DC    F'2032'
         DC    F'2033'
         DC    F'2034'
         DC    F'2035'
         DC    F'2036'
         DC    F'2037'
         DC    F'2010'
         DC    F'2011'
         DC    F'2012'
         DC    F'2013'
         DC    F'2014'
         DC    F'2015'
         
* safe_years_low
         DS    0F
@@3      EQU   *
         DC    F'1996'
         DC    F'1997'
         DC    F'1998'
         DC    F'1971'
         DC    F'1972'
         DC    F'1973'
         DC    F'1974'
         DC    F'1975'
         DC    F'1976'
         DC    F'1977'
         DC    F'1978'
         DC    F'1979'
         DC    F'1980'
         DC    F'1981'
         DC    F'1982'
         DC    F'1983'
         DC    F'1984'
         DC    F'1985'
         DC    F'1986'
         DC    F'1987'
         DC    F'1988'
         DC    F'1989'
         DC    F'1990'
         DC    F'1991'
         DC    F'1992'
         DC    F'1993'
         DC    F'1994'
         DC    F'1995'
         
&FUNC    SETC 'cycle_offset'
         DS    0F
         EJECT
* static function 'cycle_offset' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'cycle_offset'
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
* Function 'cycle_offset' code
         SLR   4,4 ==> year_diff
         SLR   5,5 ==> year_diff
         LR    2,4 ==> year_diff
         LR    3,5 ==> year_diff
         L     6,0(11) ==> year
         LR    15,6 ==> year_diff,year
         A     15,=F'-2000' ==> year_diff
         LA    7,2000(0,0)
         CR    6,7 ==> year
         BNH   @@L2
         BCTR  15,0 ==> year_diff
@@L2     EQU   *
         LR    4,15 ==> year_diff
         SRDA  4,32 ==> year_diff
         LA    6,100(0,0)
         DR    4,6 ==> year_diff
         LR    2,15 ==> year_diff
         SRDA  2,32 ==> year_diff
         LA    7,400(0,0)
         DR    2,7 ==> year_diff
         LR    15,5 ==> exceptions
         SR    15,3 ==> exceptions,year_diff
         MH    15,=H'16'
* Function 'cycle_offset' epilogue
         PDPEPIL
* Function 'cycle_offset' literal pool
         DS    0D
         LTORG
* Function 'cycle_offset' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         
&FUNC    SETC 'safe_year'
         DS    0F
         EJECT
* external function 'safe_year' prologue
* frame base=88, local stack=24, call args=16
&FUNC    SETC  'safe_year'
TM64SYR  PDPPRLG CINDEX=1,FRAME=128,BASER=12,ENTRY=YES
         B     @@FEN1
         LTORG
@@FEN1   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         LR    11,1
         L     10,=A(@@PGT1)
* Function 'safe_year' code
         SLR   4,4 ==> year
         SLR   5,5 ==> year
         ST    4,112(13) ==> year
         ST    5,4+112(13) ==> year
         LR    6,4
         LR    7,5
         ST    4,120(13)
         ST    5,4+120(13)
         LR    8,4 ==> year_cycle
         LR    9,5 ==> year_cycle
         MVC   104(4,13),=F'0' ==> safe_year
         L     2,0(11) ==> year
         A     2,=F'-1970'
         L     15,0(11) ==> year
         LA    3,67(0,0)
         CLR   2,3
         BNH   @@L3
         MVC   88(4,13),0(11) ==> year
         LA    1,88(,13)
         L     15,=A(@@4)
         BALR  14,15
         L     3,0(11) ==> year_cycle,year
         AR    3,15 ==> year_cycle,year
         L     2,0(11) ==> year
         LA    15,1969(0,0)
         CR    2,15
         BH    @@L5
         A     3,=F'-8' ==> year_cycle
@@L5     EQU   *
         L     4,0(11) ==> year
         SRDA  4,32 ==> year
         LA    15,100(0,0)
         DR    4,15 ==> year
         LTR   4,4
         BNE   @@L6
         MVC   112(4,13),0(11) ==> year
         L     4,112(13)
         L     5,4+112(13)
         SRDA  4,32
         LA    15,400(0,0)
         DR    4,15
         LTR   4,4
         BE    @@L6
         A     3,=F'11' ==> year_cycle
@@L6     EQU   *
         L     2,0(11) ==> year
         BCTR  2,0
         LR    6,2
         SRDA  6,32
         LA    4,100(0,0)
         DR    6,4
         LTR   6,6
         BNE   @@L7
         ST    2,120(13)
         L     4,120(13)
         L     5,4+120(13)
         SRDA  4,32
         LA    15,400(0,0)
         DR    4,15
         LTR   4,4
         BE    @@L7
         A     3,=F'17' ==> year_cycle
@@L7     EQU   *
         LR    8,3 ==> year_cycle
         SRDA  8,32 ==> year_cycle
         LA    2,28(0,0)
         DR    8,2 ==> year_cycle
         LR    3,8 ==> year_cycle
         LTR   8,8 ==> year_cycle
         BNL   @@L8
         AR    3,2 ==> year_cycle
@@L8     EQU   *
         LTR   3,3 ==> year_cycle
         BNL   @@L10
         MVC   88(4,13),=A(@@LC0)
         MVC   92(4,13),=A(@@LC1)
         MVC   96(4,13),=F'128'
         LA    1,88(,13)
         L     15,=V(@@ASSERT)
         BALR  14,15
@@L10    EQU   *
         LA    4,27(0,0)
         CR    3,4 ==> year_cycle
         BNH   @@L12
         MVC   88(4,13),=A(@@LC2)
         MVC   92(4,13),=A(@@LC1)
         MVC   96(4,13),=F'129'
         LA    1,88(,13)
         L     15,=V(@@ASSERT)
         BALR  14,15
@@L12    EQU   *
         L     15,0(11) ==> year
         LA    5,1969(0,0)
         CR    15,5
         BH    @@L13
         MH    3,=H'4'
         L     2,=A(@@3)
         B     @@L19
@@L13    EQU   *
         L     4,0(11) ==> year
         LA    2,2037(0,0)
         CR    4,2
         BNH   @@L15
         MH    3,=H'4'
         L     2,=A(@@2)
@@L19    EQU   *
         L     2,0(3,2) ==> safe_years_high
         ST    2,104(13) ==> safe_year
         B     @@L14
@@L15    EQU   *
         MVC   88(4,13),=A(@@LC3)
         MVC   92(4,13),=A(@@LC1)
         MVC   96(4,13),=F'133'
         LA    1,88(,13)
         L     15,=V(@@ASSERT)
         BALR  14,15
@@L14    EQU   *
         L     2,104(13) ==> safe_year
         A     2,=F'-1970'
         LA    5,67(0,0)
         CLR   2,5
         BNH   @@L18
         MVC   88(4,13),=A(@@LC4)
         MVC   92(4,13),=A(@@LC1)
         MVC   96(4,13),=F'135'
         LA    1,88(,13)
         L     15,=V(@@ASSERT)
         BALR  14,15
@@L18    EQU   *
         L     15,104(13) ==> year,safe_year
@@L3     EQU   *
* Function 'safe_year' epilogue
         PDPEPIL
* Function 'safe_year' literal pool
         DS    0D
         LTORG
* Function 'safe_year' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
@@LC0    EQU   *
         DC    C'year_cycle >= 0'
         DC    X'0'
@@LC1    EQU   *
         DC    C'<stdin>'
         DC    X'0'
@@LC2    EQU   *
         DC    C'year_cycle < SOLAR_CYCLE_LENGTH'
         DC    X'0'
@@LC3    EQU   *
         DC    C'0'
         DC    X'0'
@@LC4    EQU   *
         DC    C'safe_year <= MAX_SAFE_YEAR '
         DC    X'50'
         DC    X'50'
         DC    C' safe_year >= MIN_SAFE_YEAR'
         DC    X'0'
         END
