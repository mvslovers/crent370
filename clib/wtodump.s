 TITLE '/home/mike/repos/crent370/clib/wtodump.c'
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
* external function 'wtodump' prologue
* frame base=88, local stack=168, call args=48
&FUNC    SETC  'wtodump'
WTODUMP  PDPPRLG CINDEX=0,FRAME=304,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'wtodump' code
         L     6,8(11) ==> size
         SLR   7,7 ==> iHex
         ST    7,300(13) ==> ie
         L     9,12(11) ==> x,chunk
         MH    9,=H'2' ==> x
         L     2,12(11) ==> chunk
         LTR   2,2 ==> chunk
         BNL   @@L2
         A     2,=F'3' ==> chunk
@@L2     EQU   *
         SRA   2,2
         AR    9,2 ==> x
         BCTR  9,0 ==> x
         L     5,4(11) ==> area,varea
         MVC   88(4,13),=A(@@LC0)
         MVC   92(4,13),=F'0'
         MVC   96(4,13),=F'0'
         MVC   100(4,13),=A(@@LC1)
         ST    5,104(13) ==> area
         MVC   108(4,13),0(11) ==> title
         ST    6,112(13) ==> size
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         MVC   296(4,13),=F'0' ==> j
         SLR   8,8 ==> i
         LTR   6,6 ==> size
         BNH   @@L17
@@L13    EQU   *
         CL    8,12(11) ==> i,chunk
         BNE   @@L7
         MVC   88(4,13),=A(@@LC2)
         MVC   92(4,13),=F'0'
         MVC   96(4,13),=F'0'
         MVC   100(4,13),=A(@@LC1)
         MVC   104(4,13),296(13) ==> j
         ST    9,108(13) ==> x
         ST    9,112(13) ==> x
         LA    2,136(,13)
         ST    2,116(13)
         MVC   120(4,13),12(11) ==> chunk
         MVC   124(4,13),12(11) ==> chunk
         LA    2,216(,13)
         ST    2,128(13)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         L     2,296(13) ==> j
         A     2,12(11) ==> chunk
         ST    2,296(13) ==> j
         SLR   7,7 ==> iHex
         LR    8,7 ==> i,iHex
         ST    7,300(13) ==> iHex,ie
@@L7     EQU   *
         LA    3,136(,13)
         LR    2,3
         AR    2,7 ==> iHex
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC3)
         SLR   2,2
         IC    2,0(5) ==> area
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
         AR    7,15 ==> iHex
         LR    2,8 ==> i
         N     2,=F'3'
         LA    4,3(0,0)
         CLR   2,4
         BNE   @@L8
         LR    2,3
         AR    2,7 ==> iHex
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC4)
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
         AR    7,15 ==> iHex
@@L8     EQU   *
         IC    15,0(5) ==> e,area
         LA    2,216(,13)
         A     2,300(13) ==> ie
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC5)
         LR    4,15 ==> e
         N     4,=XL4'000000FF' ==> e
         L     2,=V(@@ISBUF)
         L     3,0(2) ==> __isbuf
         LR    2,4 ==> e
         MH    2,=H'2'
         LH    2,0(2,3)
         N     2,=F'16'
         CH    2,=H'0'
         BNE   @@L10
         LA    4,64(0,0) ==> e
         CLM   15,1,=XL1'40' ==> e
         BE    @@L10
         LA    4,75(0,0) ==> e
@@L10    EQU   *
         ST    4,96(13) ==> e
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
         A     15,300(13) ==> ie
         ST    15,300(13) ==> ie
         A     5,=F'1' ==> area
         BCTR  6,0 ==> size
         A     8,=F'1' ==> i
         LTR   6,6 ==> size
         BH    @@L13
@@L17    EQU   *
         LTR   7,7 ==> iHex
         BE    @@L1
         MVC   88(4,13),=A(@@LC2)
         MVC   92(4,13),=F'0'
         MVC   96(4,13),=F'0'
         MVC   100(4,13),=A(@@LC1)
         MVC   104(4,13),296(13) ==> j
         ST    9,108(13) ==> x
         ST    9,112(13) ==> x
         LA    2,136(,13)
         ST    2,116(13)
         MVC   120(4,13),12(11) ==> chunk
         MVC   124(4,13),12(11) ==> chunk
         LA    2,216(,13)
         ST    2,128(13)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
@@L15    EQU   *
@@L1     EQU   *
* Function 'wtodump' epilogue
         PDPEPIL
* Function 'wtodump' literal pool
         DS    0D
         LTORG
* Function 'wtodump' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'%*.*sDump of %08X "%s" (%d bytes)'
         DC    X'15'
         DC    X'0'
@@LC1    EQU   *
         DC    X'0'
@@LC2    EQU   *
         DC    C'%*.*s+%05X %-*.*s :%-*.*s:'
         DC    X'15'
         DC    X'0'
@@LC3    EQU   *
         DC    C'%02X'
         DC    X'0'
@@LC4    EQU   *
         DC    C' '
         DC    X'0'
@@LC5    EQU   *
         DC    C'%c'
         DC    X'0'
         END
