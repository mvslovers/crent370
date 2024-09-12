 TITLE '/home/mike/repos/crent370/clib/@@listpd.c'
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
* external function '__listpd' prologue
* frame base=88, local stack=280, call args=16
&FUNC    SETC  '__listpd'
@@LISTPD PDPPRLG CINDEX=0,FRAME=384,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__listpd' code
         MVC   376(4,13),=F'0'
         MVC   88(4,13),0(11) ==> dataset
         MVC   92(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(FOPEN)
         BALR  14,15
         LR    8,15 ==> fp
         LTR   15,15 ==> fp
         BE    @@L3
@@L4     EQU   *
         LA    2,104(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'1'
         MVC   96(4,13),=F'256'
         ST    8,100(13) ==> fp
         LA    1,88(,13)
         L     15,=V(FREAD)
         BALR  14,15
         LTR   15,15 ==> len
         BNH   @@L3
         LH    6,104(13)
         N     6,=XL4'0000FFFF'
         LA    5,2(0,0) ==> pos
         CLR   5,6 ==> pos,len
         BNL   @@L21
         LA    9,104(,13)
         LA    7,360(,13)
@@L17    EQU   *
         LR    3,9
         AR    3,5 ==> pos
         ST    3,88(13)
         MVC   92(4,13),=A(@@LC1)
         MVC   96(4,13),=F'8'
         LA    1,88(,13)
         L     15,=V(MEMCMP)
         BALR  14,15
         LTR   15,15 ==> fp
         BE    @@L3
         IC    2,11(9,5) ==> buf
         N     2,=F'31'
         MH    2,=H'2'
         LR    4,2 ==> size
         A     4,=F'12' ==> size
         L     2,4(11) ==> filter
         LTR   2,2
         BE    @@L13
         ST    7,88(13)
         ST    3,92(13)
         MVC   96(4,13),=F'8'
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         MVI   368(13),0 ==> member
         ST    7,88(13)
         MVC   92(4,13),=A(@@LC2)
         LA    1,88(,13)
         L     15,=V(STRTOK)
         BALR  14,15
         ST    7,88(13)
         MVC   92(4,13),4(11) ==> filter
         LA    1,88(,13)
         L     15,=V(@@PATMAT)
         BALR  14,15
         LTR   15,15 ==> fp
         BE    @@L10
@@L13    EQU   *
         MVC   88(4,13),=F'1'
         ST    4,92(13) ==> size
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         MVC   88(4,13),=F'1'
         ST    4,92(13) ==> size
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         LR    3,15 ==> fp
         LTR   15,15 ==> fp
         BE    @@L3
         ST    15,88(13) ==> fp
         LA    2,104(,13)
         AR    2,5 ==> pos
         ST    2,92(13)
         ST    4,96(13) ==> size
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         LA    2,376(,13)
         ST    2,88(13)
         ST    3,92(13) ==> fp
         LA    1,88(,13)
         L     15,=V(@@ARADD)
         BALR  14,15
         LTR   15,15 ==> rc
         BE    @@L10
         ST    3,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
         B     @@L3
@@L10    EQU   *
         AR    5,4 ==> pos,size
         CLR   5,6 ==> pos,len
         BL    @@L17
@@L21    EQU   *
         LH    2,40(8) ==> .flags
         N     2,=F'1'
         CH    2,=H'0'
         BE    @@L4
@@L3     EQU   *
         LTR   8,8 ==> fp
         BE    @@L19
         ST    8,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(FCLOSE)
         BALR  14,15
@@L19    EQU   *
         L     15,376(13)
* Function '__listpd' epilogue
         PDPEPIL
* Function '__listpd' literal pool
         DS    0D
         LTORG
* Function '__listpd' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'r,record'
         DC    X'0'
@@LC1    EQU   *
         DC    X'FF'
         DC    X'FF'
         DC    X'FF'
         DC    X'FF'
         DC    X'FF'
         DC    X'FF'
         DC    X'FF'
         DC    X'FF'
         DC    X'0'
@@LC2    EQU   *
         DC    C' '
         DC    X'0'
         END
