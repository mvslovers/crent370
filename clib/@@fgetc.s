 TITLE '/home/mike/repos/crent370/clib/@@fgetc.c'
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
* external function '__fgetc' prologue
* frame base=88, local stack=8, call args=16
&FUNC    SETC  '__fgetc'
@@FGETC  PDPPRLG CINDEX=0,FRAME=112,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__fgetc' code
         L     4,0(11) ==> fp
         L     3,8(4) ==> dcb,dcb
         L     5,=F'-1' ==> c
         LH    2,40(4) ==> .flags
         N     2,=F'513'
         CH    2,=H'0'
         BNE   @@L3
         L     2,20(4) ==> c,ungetch
         CLR   2,5 ==> c
         BE    @@L4
         LR    5,2 ==> c
         MVC   20(4,4),=F'-1' ==> .ungetch
         B     @@L3
@@L4     EQU   *
         L     2,32(4) ==> .upto
         CL    2,36(4) ==> .endbuf
         BL    @@L6
         CLI   17(3),79 ==> .dcbdevt
         BNE   @@L7
         MVC   88(4,13),12(4) ==> .asmbuf
         LH    2,16(4) ==> .lrecl
         N     2,=XL4'0000FFFF'
         BCTR  2,0
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=A(@@2)
         BALR  14,15
         ST    15,104(13) ==> read
         ST    15,88(13)
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         LR    3,15 ==> read
         MVC   88(4,13),104(13)
         MVC   92(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(STRCMP)
         BALR  14,15
         LTR   15,15 ==> read
         BE    @@L3
         MVC   88(4,13),104(13)
         MVC   92(4,13),=A(@@LC1)
         LA    1,88(,13)
         L     15,=V(STRCMP)
         BALR  14,15
         LTR   15,15 ==> read
         BE    @@L3
         MVC   88(4,13),104(13)
         MVC   92(4,13),=A(@@LC2)
         LA    1,88(,13)
         L     15,=V(STRCMP)
         BALR  14,15
         LTR   15,15 ==> read
         BE    @@L3
         MVC   88(4,13),104(13)
         MVC   92(4,13),=A(@@LC3)
         LA    1,88(,13)
         L     15,=V(STRCMP)
         BALR  14,15
         LTR   15,15 ==> read
         BE    @@L3
         B     @@L12
@@L7     EQU   *
         MVC   88(4,13),8(4) ==> .dcb
         LA    2,104(,13)
         ST    2,92(13)
         LA    2,108(,13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@AREAD)
         BALR  14,15
         LTR   15,15 ==> read
         BNE   @@L19
         IC    2,42(4) ==> .recfm
         N     2,=F'192'
         LA    3,128(0,0)
         CR    2,3
         BE    @@L16
         BH    @@L21
         LA    6,64(0,0)
         CLR   2,6
         BE    @@L17
         B     @@L19
@@L21    EQU   *
         LA    3,192(0,0)
         CLR   2,3
         BE    @@L18
         B     @@L19
@@L16    EQU   *
         LH    3,16(4) ==> .lrecl
         N     3,=XL4'0000FFFF'
         B     @@L12
@@L17    EQU   *
         L     3,104(13)
         SLR   2,2
         IC    2,0(3)
         SLL   2,8
         SLR   5,5
         IC    5,1(3)
         LR    3,5
         OR    3,2 ==> read
         L     2,104(13)
         A     2,=F'4'
         ST    2,104(13)
         A     3,=F'-4' ==> read
         B     @@L12
@@L18    EQU   *
         L     3,108(13) ==> read
         B     @@L12
@@L19    EQU   *
         OC    40(2,4),=H'1' ==> .flags
         B     @@L3
@@L12    EQU   *
         LTR   3,3 ==> read
         BE    @@L22
         LH    2,40(4) ==> .flags
         N     2,=F'1024'
         CH    2,=H'0'
         BNE   @@L23
         MVC   88(4,13),104(13)
         MVC   92(4,13),=F'0'
         ST    3,96(13) ==> read
         LA    1,88(,13)
         L     15,=V(MEMCHR)
         BALR  14,15
         LTR   15,15 ==> p
         BE    @@L23
         LR    3,15 ==> read,p
         S     3,104(13) ==> read
@@L23    EQU   *
         MVC   88(4,13),28(4) ==> .buf
         MVC   92(4,13),104(13)
         ST    3,96(13) ==> read
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
@@L22    EQU   *
         MVC   32(4,4),28(4) ==> .upto,buf
         LR    2,3 ==> read
         A     2,28(4) ==> .buf
         ST    2,36(4) ==> .endbuf
         LH    2,40(4) ==> .flags
         N     2,=F'1024'
         CH    2,=H'0'
         BNE   @@L6
         LR    3,4 ==> fp
         A     3,=F'36'
         L     2,0(3) ==> .endbuf
         MVI   0(2),21
         A     2,=F'1'
         ST    2,0(3) ==> .endbuf
@@L6     EQU   *
         LR    2,4 ==> fp
         A     2,=F'32'
         L     3,0(2) ==> .upto
         SLR   5,5 ==> c
         IC    5,0(3) ==> c
         A     3,=F'1'
         ST    3,0(2) ==> .upto
         L     2,24(4) ==> .filepos
         A     2,=F'1'
         ST    2,24(4) ==> .filepos
@@L3     EQU   *
         LR    15,5 ==> c
* Function '__fgetc' epilogue
         PDPEPIL
* Function '__fgetc' literal pool
         DS    0D
         LTORG
* Function '__fgetc' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'/*'
         DC    X'0'
@@LC1    EQU   *
         DC    C'//'
         DC    X'0'
@@LC2    EQU   *
         DC    C'<eof>'
         DC    X'0'
@@LC3    EQU   *
         DC    C'<EOF>'
         DC    X'0'
         DS    0F
         EJECT
* static function 'tso_getline' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'tso_getline'
@@2      PDPPRLG CINDEX=1,FRAME=96,BASER=12,ENTRY=NO
         B     @@FEN1
         LTORG
@@FEN1   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         LR    11,1
         L     10,=A(@@PGT1)
* Function 'tso_getline' code
         L     4,0(11) ==> buf
         L     3,4(11) ==> len
         LTR   4,4 ==> buf
         BE    @@L28
         LTR   3,3 ==> len
         BE    @@L28
         LR    2,4 ==> r1,buf
         N     2,=F'16777215' ==> r1
         O     2,=F'-2147483648' ==> r1
         LR    0,3                buffer length ==> len
         LR    1,2                flags and buffer address ==> r1
         TGET  (1),(0),R
         LR    2,4 ==> buf
         AR    2,3 ==> len
         BCTR  2,0
         MVI   0(2),0
         SLR   3,3 ==> len
         B     @@L30
@@L34    EQU   *
         A     3,=F'1' ==> len
@@L30    EQU   *
         SLR   2,2
         IC    2,0(3,4) ==> len
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(ISSPACE)
         BALR  14,15
         LTR   15,15 ==> len
         BNE   @@L34
         ST    4,88(13) ==> buf
         LR    2,4 ==> buf
         AR    2,3 ==> len
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         ST    4,88(13) ==> buf
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         LR    3,15 ==> len
         LTR   15,15 ==> len
         BE    @@L28
@@L39    EQU   *
         BCTR  3,0 ==> len
         SLR   2,2
         IC    2,0(3,4) ==> len
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(ISSPACE)
         BALR  14,15
         LTR   15,15 ==> len
         BE    @@L28
         SLR   2,2
         STC   2,0(3,4) ==> len
         LTR   3,3 ==> len
         BNE   @@L39
@@L28    EQU   *
         LR    15,4 ==> buf
* Function 'tso_getline' epilogue
         PDPEPIL
* Function 'tso_getline' literal pool
         DS    0D
         LTORG
* Function 'tso_getline' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
         END
