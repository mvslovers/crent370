 TITLE '/home/mike/repos/crent370/clib/tzset.c'
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
         DC    C'tzset'
         DC    X'0'
         DS    0F
         EJECT
* external function 'tzset' prologue
* frame base=88, local stack=8, call args=16
&FUNC    SETC  'tzset'
TZSET    PDPPRLG CINDEX=0,FRAME=112,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'tzset' code
         SLR   8,8 ==> rem
         SLR   9,9 ==> rem
         LR    6,8 ==> tzoffset
         LR    7,9 ==> tzoffset
         MVC   88(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(GETENV)
         BALR  14,15
         LR    4,15 ==> tz
         LTR   15,15 ==> tz
         BNE   @@L2
         MVC   88(4,13),=A(@@LC1)
         LA    1,88(,13)
         L     15,=V(GETENV)
         BALR  14,15
         LR    4,15 ==> tz
@@L2     EQU   *
         LTR   4,4 ==> tz
         BE    @@L3
         LR    3,4 ==> p,tz
         SLR   5,5 ==> tzoffset
         ST    5,104(13) ==> tzoffset,neg
         CLI   0(4),96 ==> tz
         BNE   @@L19
         MVC   104(4,13),=F'1' ==> neg
@@L7     EQU   *
         A     3,=F'1' ==> p
         CLI   0(3),96 ==> p
         BE    @@L7
@@L19    EQU   *
         SLR   2,2
         IC    2,0(3) ==> p
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(ISDIGIT)
         BALR  14,15
         LTR   15,15 ==> tz
         BE    @@L8
         ST    3,88(13) ==> p
         LA    1,88(,13)
         L     15,=V(ATOI)
         BALR  14,15
         LR    2,15 ==> tmp
         MH    2,=H'3600'
         AR    5,2 ==> tzoffset
         ST    3,88(13) ==> p
         MVC   92(4,13),=F'122'
         LA    1,88(,13)
         L     15,=V(STRCHR)
         BALR  14,15
         LR    3,15 ==> p
         LTR   15,15 ==> p
         BE    @@L9
         A     3,=F'1' ==> p
         ST    3,88(13) ==> p
         LA    1,88(,13)
         L     15,=V(ATOI)
         BALR  14,15
         LR    2,15 ==> tmp
         SLL   2,4
         SR    2,15 ==> tmp
         SLL   2,2
         AR    5,2 ==> tzoffset
         ST    3,88(13) ==> p
         MVC   92(4,13),=F'122'
         LA    1,88(,13)
         L     15,=V(STRCHR)
         BALR  14,15
         LR    3,15 ==> p
@@L9     EQU   *
         LTR   3,3 ==> p
         BE    @@L10
         A     3,=F'1' ==> p
         ST    3,88(13) ==> p
         LA    1,88(,13)
         L     15,=V(ATOI)
         BALR  14,15
         AR    5,15 ==> tzoffset,tmp
@@L10    EQU   *
         L     2,104(13) ==> neg
         LTR   2,2
         BE    @@L12
         LCR   5,5 ==> tzoffset
         B     @@L12
@@L8     EQU   *
         MVC   88(4,13),=A(@@LC2)
         MVC   92(4,13),=A(@@2)
         ST    4,96(13) ==> tz
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         MVC   88(4,13),=A(@@LC3)
         MVC   92(4,13),=A(@@2)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         MVC   88(4,13),=A(@@LC4)
         MVC   92(4,13),=A(@@2)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
@@L3     EQU   *
         LA    2,16(0,0)
         L     2,0(2) ==> cvt
         L     2,304(2)
         MVC   80(4,13),=XL8'4E00000080000000'
         ST    2,84(,13)
         XI    84(13),128
         LD    2,80(,13)
         SD    2,=XL8'4E00000080000000'
         MD    2,=D'1.04857649999999980039E0'
         LDR   0,2
         AD    0,=XL8'4F08000000000000'
         STD   0,80(,13)
         L     5,84(,13) ==> tzoffset
         LTR   5,5 ==> tzoffset
         BNL   @@L13
         LCR   8,5 ==> tzoffset
         SRDA  8,32 ==> rem
         LA    2,10(0,0)
         DR    8,2 ==> rem
         LTR   8,8 ==> rem
         BE    @@L12
         AR    5,8 ==> tzoffset,rem
         A     5,=F'-10' ==> tzoffset
         B     @@L12
@@L13    EQU   *
         LTR   5,5 ==> tzoffset
         BNH   @@L12
         LR    6,5 ==> tzoffset
         SRDA  6,32 ==> tzoffset
         LA    2,10(0,0)
         DR    6,2 ==> tzoffset
         LTR   6,6 ==> rem
         BE    @@L12
         SR    5,6 ==> tzoffset,rem
         A     5,=F'10' ==> tzoffset
@@L12    EQU   *
         ST    5,88(13) ==> tzoffset
         LA    1,88(,13)
         L     15,=V(@@TZSET)
         BALR  14,15
* Function 'tzset' epilogue
         PDPEPIL
* Function 'tzset' literal pool
         DS    0D
         LTORG
* Function 'tzset' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'tz'
         DC    X'0'
@@LC1    EQU   *
         DC    C'TZ'
         DC    X'0'
@@LC2    EQU   *
         DC    C'%s: Invalid time zone format in TZ variable "%s"'
         DC    X'0'
@@LC3    EQU   *
         DC    C'%s: Expected format is TZ=[-]HH[:MM][:SS]'
         DC    X'0'
@@LC4    EQU   *
         DC    C'%s: Defaulting to time zone offset calculated fr'
         DC    C'om CVTTZ'
         DC    X'0'
         END
