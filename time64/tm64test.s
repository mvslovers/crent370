 TITLE '/home/mike/repos/crent370/time64/tm64test.c'
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
         
&FUNC    SETC 'main'
* Program text area
         DS    0F
         COPY  PDPMAIN
         EJECT
* external function 'main' prologue
* frame base=88, local stack=168, call args=40
&FUNC    SETC  'main'
MAIN     PDPPRLG CINDEX=0,FRAME=296,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'main' code
         LA    4,128(,13)
         LA    5,36(0,0)
         SLR   2,2
         LR    3,2
         MVCL  4,2
         SLR   4,4 ==> i
@@L6     EQU   *
         MVC   88(4,13),=F'0'
         LA    0,208(,13)
         LA    1,88(,13)
         L     15,=V(TM64UTIM)
         BALR  14,15
         MVC   272(8,13),208(13)
         MVC   88(4,13),=A(@@LC0)
         MVC   92(8,13),272(13)
         MVC   100(8,13),272(13)
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         LA    2,272(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'1000000'
         ST    2,96(13)
         LA    2,280(,13)
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(@@64VU32)
         BALR  14,15
         MVC   88(4,13),=A(@@LC1)
         MVC   92(8,13),272(13)
         MVC   100(8,13),272(13)
         MVC   108(8,13),280(13)
         MVC   116(8,13),280(13)
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         A     4,=F'1' ==> i
         LA    2,9(0,0)
         CR    4,2 ==> i
         BNH   @@L6
         MVC   88(4,13),=A(@@LC2)
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         MVC   88(4,13),=F'0'
         LA    0,216(,13)
         LA    1,88(,13)
         L     15,=V(TM64UTIM)
         BALR  14,15
         MVC   280(8,13),216(13)
         MVC   88(4,13),=F'0'
         LA    0,224(,13)
         LA    1,88(,13)
         L     15,=V(TM64UTIM)
         BALR  14,15
         MVC   272(8,13),224(13)
         MVC   88(8,13),272(13)
         MVC   96(8,13),280(13)
         LA    1,88(,13)
         L     15,=V(TM64DTIM)
         BALR  14,15
         MVC   88(4,13),=A(@@LC3)
         STD   0,92(13) ==> d
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         MVC   88(4,13),=A(@@LC2)
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         SLR   4,4 ==> i
@@L11    EQU   *
         MVC   88(4,13),=F'0'
         LA    0,232(,13)
         LA    1,88(,13)
         L     15,=V(TM64UTIM)
         BALR  14,15
         MVC   280(8,13),232(13)
         MVC   88(4,13),=F'0'
         LA    0,240(,13)
         LA    1,88(,13)
         L     15,=V(TM64UTIM)
         BALR  14,15
         MVC   272(8,13),240(13)
         LA    2,272(,13)
         ST    2,88(13)
         LA    2,280(,13)
         ST    2,92(13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@64SUB)
         BALR  14,15
         MVC   88(4,13),=A(@@LC4)
         MVC   92(8,13),280(13)
         MVC   100(8,13),280(13)
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         A     4,=F'1' ==> i
         LA    3,9(0,0)
         CR    4,3 ==> i
         BNH   @@L11
         MVC   88(4,13),=A(@@LC2)
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         MVC   88(4,13),=F'0'
         LA    0,248(,13)
         LA    1,88(,13)
         L     15,=V(TM64TIME)
         BALR  14,15
         MVC   280(8,13),248(13)
         MVC   88(4,13),=A(@@LC5)
         MVC   92(8,13),280(13)
         MVC   100(8,13),280(13)
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         L     2,280(13)
         L     4,=F'-1'
         CLR   2,4
         BE    @@L13
         LA    2,280(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(TM64GMT)
         BALR  14,15
         L     3,=A(@@LC7) ==> p
         LTR   15,15 ==> tmp
         BE    @@L15
         ST    15,88(13) ==> tmp
         LA    1,88(,13)
         L     15,=V(TM64ASC)
         BALR  14,15
         LR    3,15 ==> p
         LTR   15,15 ==> p
         BNE   @@L15
         L     3,=A(@@LC8) ==> p
@@L15    EQU   *
         MVC   88(4,13),=A(@@LC9)
         ST    3,92(13) ==> p
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         LA    2,280(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(TM64LTM)
         BALR  14,15
         L     3,=A(@@LC7) ==> p
         LTR   15,15 ==> tmp
         BE    @@L18
         ST    15,88(13) ==> tmp
         LA    1,88(,13)
         L     15,=V(TM64ASC)
         BALR  14,15
         LR    3,15 ==> p
         LTR   15,15 ==> p
         BNE   @@L18
         L     3,=A(@@LC8) ==> p
@@L18    EQU   *
         MVC   88(4,13),=A(@@LC10)
         ST    3,92(13) ==> p
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
@@L13    EQU   *
         MVC   88(4,13),=A(@@LC2)
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         LA    4,128(,13) ==> s
         SLR   3,3 ==> c
         LA    2,36(0,0) ==> n
         
*** MEMSET ***
         LR    14,4           => target (s) ==> s
         LR    15,2           => length (n) ==> n
         SLR   0,0             => source (NULL)
         LR    1,3            fill character ==> c
         SLL   1,24            move fill to high byte
         MVCL  14,0            Set target to fill character
         MVC   144(4,13),=F'11' ==> .tm_mon
         MVC   140(4,13),=F'1' ==> .tm_mday
         MVC   136(4,13),=F'12' ==> .tm_hour
         MVC   132(4,13),=F'34' ==> .tm_min
         MVC   128(4,13),=F'45' ==> .tm_sec
         MVC   88(4,13),=A(@@LC2)
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         MVC   88(4,13),=A(@@LC11)
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         MVC   88(4,13),=A(@@LC12)
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         MVC   88(4,13),=A(@@LC2)
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         LA    4,69(0,0) ==> i
@@L35    EQU   *
         ST    4,148(13) ==> i,tm_year
         LA    2,128(,13)
         ST    2,88(13)
         LA    0,256(,13)
         LA    1,88(,13)
         L     15,=V(TM64MKT)
         BALR  14,15
         MVC   280(8,13),256(13)
         L     3,=A(@@LC13) ==> p
         L     2,280(13)
         L     5,=F'-1'
         CLR   2,5
         BE    @@L26
         LA    2,280(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(TM64GMT)
         BALR  14,15
         L     3,=A(@@LC7) ==> p
         LTR   15,15 ==> tmp
         BE    @@L26
         ST    15,88(13) ==> tmp
         LA    1,88(,13)
         L     15,=V(TM64ASC)
         BALR  14,15
         LR    3,15 ==> p
         LTR   15,15 ==> p
         BNE   @@L26
         L     3,=A(@@LC8) ==> p
@@L26    EQU   *
         MVC   88(4,13),=A(@@LC14)
         LR    2,4 ==> i
         A     2,=F'1900'
         ST    2,92(13)
         MVC   96(8,13),280(13)
         ST    3,104(13) ==> p
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         MVC   168(36,13),128(13) ==> tmp_date,date
         LA    2,168(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(MKTIME)
         BALR  14,15
         ST    15,288(13) ==> tmp
         L     3,=A(@@LC15) ==> p
         L     5,=F'-1'
         CLR   15,5
         BE    @@L31
         LA    2,288(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(GMTIME)
         BALR  14,15
         L     3,=A(@@LC16) ==> p
         LTR   15,15 ==> tmp
         BE    @@L31
         ST    15,88(13) ==> tmp
         LA    1,88(,13)
         L     15,=V(ASCTIME)
         BALR  14,15
         LR    3,15 ==> p
         LTR   15,15 ==> p
         BNE   @@L31
         L     3,=A(@@LC17) ==> p
@@L31    EQU   *
         MVC   88(4,13),=A(@@LC18)
         LR    2,4 ==> i
         A     2,=F'1900'
         ST    2,92(13)
         MVC   96(4,13),288(13)
         ST    3,100(13) ==> p
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         MVC   88(4,13),=A(@@LC2)
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         A     4,=F'1' ==> i
         LA    2,999(0,0)
         CR    4,2 ==> i
         BNH   @@L35
         MVC   88(4,13),=F'0'
         LA    0,264(,13)
         LA    1,88(,13)
         L     15,=V(TM64TIME)
         BALR  14,15
         MVC   280(8,13),264(13)
         L     3,=A(@@LC19) ==> p
         L     2,280(13)
         L     4,=F'-1'
         CLR   2,4
         BE    @@L37
         LA    2,280(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(TM64GMT)
         BALR  14,15
         L     3,=A(@@LC7) ==> p
         LTR   15,15 ==> tmp
         BE    @@L37
         ST    15,88(13) ==> tmp
         LA    1,88(,13)
         L     15,=V(TM64ASC)
         BALR  14,15
         LR    3,15 ==> p
         LTR   15,15 ==> p
         BNE   @@L37
         L     3,=A(@@LC8) ==> p
@@L37    EQU   *
         MVC   88(4,13),=A(@@LC20)
         MVC   92(8,13),280(13)
         ST    3,100(13) ==> p
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         MVC   168(36,13),128(13) ==> tmp_date,date
         MVC   88(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(TIME)
         BALR  14,15
         ST    15,288(13) ==> tmp
         L     3,=A(@@LC15) ==> p
         L     5,=F'-1'
         CLR   15,5
         BE    @@L42
         LA    2,288(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(GMTIME)
         BALR  14,15
         L     3,=A(@@LC16) ==> p
         LTR   15,15 ==> tmp
         BE    @@L42
         ST    15,88(13) ==> tmp
         LA    1,88(,13)
         L     15,=V(ASCTIME)
         BALR  14,15
         LR    3,15 ==> p
         LTR   15,15 ==> p
         BNE   @@L42
         L     3,=A(@@LC17) ==> p
@@L42    EQU   *
         MVC   88(4,13),=A(@@LC21)
         MVC   92(4,13),288(13)
         ST    3,96(13) ==> p
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         MVC   88(4,13),=A(@@LC2)
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         MVC   280(4,13),=F'2147483647'
         LA    3,284(,13)
         MVC   0(4,3),=F'-1' ==> .u32
         MVC   88(4,13),=A(@@LC22)
         MVC   92(4,13),280(13)
         MVC   96(4,13),0(3) ==> .u32
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         MVC   280(4,13),=F'-1'
         MVC   0(4,3),=F'-1' ==> .u32
         MVC   88(4,13),=A(@@LC23)
         MVC   92(4,13),280(13)
         MVC   96(4,13),0(3) ==> .u32
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         LA    2,280(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@64INIT)
         BALR  14,15
         LA    2,280(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'1'
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@64SI32)
         BALR  14,15
         MVC   88(4,13),=A(@@LC24)
         MVC   92(4,13),280(13)
         MVC   96(4,13),0(3) ==> .u32
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         SLR   15,15
* Function 'main' epilogue
         PDPEPIL
* Function 'main' literal pool
         DS    0D
         LTORG
* Function 'main' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'utime64(NULL) = 0x%016llX (%llu)'
         DC    X'15'
         DC    X'0'
@@LC1    EQU   *
         DC    C' div 1000000  = 0x%016llX (%llu) remainder = %01'
         DC    C'6llX (%llu)'
         DC    X'15'
         DC    X'0'
@@LC2    EQU   *
         DC    C'------------------------------------------------'
         DC    C'---'
         DC    X'15'
         DC    X'0'
@@LC3    EQU   *
         DC    C'difftime64(uresult,result)==%f'
         DC    X'15'
         DC    X'0'
@@LC4    EQU   *
         DC    C'utime64() - utime64() = 0x%016llX (%llu)'
         DC    X'15'
         DC    X'0'
@@LC5    EQU   *
         DC    C'time64(NULL) = 0x%016llX (%llu)'
         DC    X'15'
         DC    X'0'
@@LC7    EQU   *
         DC    C'*** gmtime64 failure ***'
         DC    X'15'
         DC    X'0'
@@LC8    EQU   *
         DC    C'*** asctime64 failure ***'
         DC    X'15'
         DC    X'0'
@@LC9    EQU   *
         DC    C'   GMT: %s'
         DC    X'0'
@@LC10   EQU   *
         DC    C' local: %s'
         DC    X'0'
@@LC11   EQU   *
         DC    C'Validate values at: https://www.epochconverter.c'
         DC    C'om/'
         DC    X'15'
         DC    X'0'
@@LC12   EQU   *
         DC    C'Note: all values are for Jan 1 of each year.'
         DC    X'15'
         DC    X'0'
@@LC13   EQU   *
         DC    C'*** mktime64 failure ***'
         DC    X'15'
         DC    X'0'
@@LC14   EQU   *
         DC    C'mktime64: Year:%d 0x%016llX %s'
         DC    X'0'
@@LC15   EQU   *
         DC    C'*** mktime failure ***'
         DC    X'15'
         DC    X'0'
@@LC16   EQU   *
         DC    C'*** gmtime failure ***'
         DC    X'15'
         DC    X'0'
@@LC17   EQU   *
         DC    C'*** asctime failure ***'
         DC    X'15'
         DC    X'0'
@@LC18   EQU   *
         DC    C'  mktime: Year:%d         0x%08X %s'
         DC    X'0'
@@LC19   EQU   *
         DC    C'*** timegm64 failure ***'
         DC    X'15'
         DC    X'0'
@@LC20   EQU   *
         DC    C'timegm64: Time NOW  0x%016llX GMT %s'
         DC    X'0'
@@LC21   EQU   *
         DC    C'  mktime: Time NOW          0x%08X GMT %s'
         DC    X'0'
@@LC22   EQU   *
         DC    C'1/2 Max value test 0x%08X%08X'
         DC    X'15'
         DC    X'0'
@@LC23   EQU   *
         DC    C'Max value test 0x%08X%08X'
         DC    X'15'
         DC    X'0'
@@LC24   EQU   *
         DC    C'result = 0 then result - 1 0x%08X%08X'
         DC    X'15'
         DC    X'0'
         END   @@MAIN
