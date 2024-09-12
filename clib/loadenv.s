 TITLE '/home/mike/repos/crent370/clib/loadenv.c'
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
* external function 'loadenv' prologue
* frame base=88, local stack=1032, call args=16
&FUNC    SETC  'loadenv'
LOADENV  PDPPRLG CINDEX=0,FRAME=1136,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'loadenv' code
         LA    2,1(0,0) ==> err
         MVC   88(4,13),0(11) ==> fn
         MVC   92(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(FOPEN)
         BALR  14,15
         LR    3,15 ==> fp
         LTR   15,15 ==> fp
         BE    @@L3
         B     @@L4
@@L18    EQU   *
         LA    2,104(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'21'
         LA    1,88(,13)
         L     15,=V(STRRCHR)
         BALR  14,15
         LTR   15,15 ==> p
         BE    @@L7
         MVI   0(15),0 ==> p
@@L7     EQU   *
         IC    2,104(13) ==> buf
         CLM   2,1,=XL1'5C'
         BE    @@L4
         CLM   2,1,=XL1'7B'
         BE    @@L4
         LA    4,104(,13)
         ST    4,88(13)
         LA    2,1128(,13)
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=A(@@2)
         BALR  14,15
         LTR   15,15 ==> fp
         BE    @@L10
         L     2,1128(13)
         AR    2,4
         A     2,=F'-8'
         MVI   0(2),0 ==> buf
         L     2,1128(13)
         A     2,=F'-8'
         ST    2,1128(13)
@@L10    EQU   *
         L     2,1128(13)
         BCTR  2,0
         ST    2,1128(13)
         LR    15,2
         LTR   2,2
         BNH   @@L12
         IC    2,104(13,2) ==> buf
         SLL   2,24
         SRA   2,24
         C     2,=F'64'
         BNE   @@L12
@@L16    EQU   *
         SLR   2,2
         STC   2,104(15,13) ==> buf
         L     2,1128(13)
         BCTR  2,0
         ST    2,1128(13)
         LR    15,2
         LTR   2,2
         BNH   @@L12
         IC    2,104(13,2) ==> buf
         CLM   2,1,=XL1'40'
         BE    @@L16
@@L12    EQU   *
         LA    2,104(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'126'
         LA    1,88(,13)
         L     15,=V(STRCHR)
         BALR  14,15
         LTR   15,15 ==> fp
         BE    @@L4
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(PUTENV)
         BALR  14,15
@@L4     EQU   *
         LA    2,104(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'1024'
         ST    3,96(13) ==> fp
         LA    1,88(,13)
         L     15,=V(FGETS)
         BALR  14,15
         LTR   15,15 ==> fp
         BNE   @@L18
         SLR   2,2 ==> err
@@L3     EQU   *
         LTR   3,3 ==> fp
         BE    @@L19
         ST    3,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(FCLOSE)
         BALR  14,15
@@L19    EQU   *
         LR    15,2 ==> err
* Function 'loadenv' epilogue
         PDPEPIL
* Function 'loadenv' literal pool
         DS    0D
         LTORG
* Function 'loadenv' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'r'
         DC    X'0'
         
&FUNC    SETC 'numbered'
         DS    0F
         EJECT
* static function 'numbered' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'numbered'
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
* Function 'numbered' code
         L     3,0(11) ==> buf
         L     2,4(11) ==> len
         SLR   4,4 ==> rc
         ST    3,88(13) ==> buf
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         ST    15,0(2) ==> rc,len
         LA    5,8(0,0)
         CR    15,5 ==> rc
         BNH   @@L23
         LR    15,3 ==> p,buf
         A     15,0(2) ==> p,len
         A     15,=F'-8' ==> p
         IC    2,0(15) ==> p
         CLM   2,1,=XL1'00'
         BE    @@L31
@@L29    EQU   *
         IC    3,0(15) ==> p
         LA    2,16(,3)
         CLM   2,1,=XL1'09'
         BH    @@L23
         A     15,=F'1' ==> p
         IC    2,0(15) ==> p
         CLM   2,1,=XL1'00'
         BNE   @@L29
@@L31    EQU   *
         LA    4,1(0,0) ==> rc
@@L23    EQU   *
         LR    15,4 ==> rc
* Function 'numbered' epilogue
         PDPEPIL
* Function 'numbered' literal pool
         DS    0D
         LTORG
* Function 'numbered' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
         END
