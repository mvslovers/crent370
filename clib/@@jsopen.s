 TITLE '/home/mike/repos/crent370/clib/@@jsopen.c'
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
         
HASPACE  DCB   DDNAME=HASPACE1,DSORG=DA,MACRF=(RIC),OPTCD=A,           X
               RECFM=F
DCBLEN   EQU   *-HASPACE
         DCBD  DSORG=DA
         CSECT ,
* Program text area
         DS    0F
         EJECT
* external function '__jsopen' prologue
* frame base=88, local stack=4128, call args=16
&FUNC    SETC  '__jsopen'
@@JSOPEN PDPPRLG CINDEX=0,FRAME=4232,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__jsopen' code
         L     7,0(11) ==> dataset
         SLR   6,6 ==> js
         L     2,=F'4224'
         AR    2,13
         MVC   0(4,2),=F'-2147483648'
         LA    4,104(,13)
         LA    5,20(0,0)
         LR    2,6 ==> js
         LR    3,6 ==> js
         MVCL  4,2 ==> js
         MVC   88(4,13),=F'1'
         MVC   92(4,13),=F'128'
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         LR    6,15 ==> js
         LTR   15,15 ==> js
         BE    @@L3
         ST    15,88(13) ==> js
         MVC   92(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         LR    4,6 ==> dcb,js
         A     4,=F'24' ==> dcb
         ST    4,16(6) ==> dcb,dcb
         L     1,=A(HASPACE)        model DCB for HASPACE
         MVC   0(DCBLEN,4),0(1)   copy model to our dcb area ==> dcb
         SLR   2,2
         IC    2,0(7) ==> dataset
         L     3,=V(@@TOUP)
         L     3,0(3) ==> __toup
         MH    2,=H'2'
         LH    2,0(2,3)
         CLM   2,3,=H'196'
         BNE   @@L4
         SLR   2,2
         IC    2,1(7)
         MH    2,=H'2'
         LH    2,0(2,3)
         CLM   2,3,=H'196'
         BNE   @@L4
         CLI   2(7),122
         BNE   @@L4
         A     7,=F'3' ==> p
         SLR   5,5 ==> i
         IC    2,0(7) ==> p
         SLL   2,24
         SRA   2,24
         C     2,=F'0'
         BE    @@L6
         L     15,=V(@@TOUP)
@@L10    EQU   *
         SLR   2,2
         IC    2,0(5,7) ==> i
         L     3,0(15) ==> __toup
         MH    2,=H'2'
         IC    3,1(2,3)
         STC   3,8(6,5) ==> .ddname
         A     5,=F'1' ==> i
         LA    2,7(0,0)
         CR    5,2 ==> i
         BH    @@L6
         IC    2,0(7) ==> p
         SLL   2,24
         SRA   2,24
         C     2,=F'0'
         BNE   @@L10
@@L6     EQU   *
         LA    7,7(0,0)
         CR    5,7 ==> i
         BH    @@L20
         LA    3,8(0,0)
@@L14    EQU   *
         LR    2,5 ==> i
         AR    2,6 ==> js
         LA    7,64(0,0)
         STC   7,0(3,2) ==> .ddname
         A     5,=F'1' ==> i
         LA    2,7(0,0)
         CR    5,2 ==> i
         BNH   @@L14
@@L20    EQU   *
         LR    2,4 ==> dcb
         A     2,=F'40'
         ST    2,88(13)
         LR    2,6 ==> js
         A     2,=F'8'
         ST    2,92(13)
         MVC   96(4,13),=F'8'
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         B     @@L15
@@L4     EQU   *
         ST    6,88(13) ==> js
         ST    7,92(13) ==> dataset
         LA    1,88(,13)
         L     15,=A(@@6)
         BALR  14,15
         LTR   15,15 ==> rc
         BE    @@L15
         ST    6,88(13) ==> js
         LA    1,88(,13)
         L     15,=V(@@JSCLOS)
         BALR  14,15
         SLR   6,6 ==> js
         B     @@L3
@@L15    EQU   *
         L     2,=F'4224'
         AR    2,13
         OPEN  ((4)),MF=(E,(2)) ==> dcb
         IC    2,48(4) ==> .dcboflgs
         N     2,=F'16'
         CLM   2,1,=XL1'00'
         BNE   @@L17
         ST    6,88(13) ==> js
         LA    1,88(,13)
         L     15,=V(@@JSCLOS)
         BALR  14,15
         SLR   6,6 ==> js
@@L17    EQU   *
         LR    2,6 ==> js
         A     2,=F'8'
         LA    3,104(,13)
         DEVTYPE (2),((3),20),DEVTAB
         LH    2,114(13)
         N     2,=XL4'0000FFFF'
         ST    2,20(6) ==> .trkcyl
@@L3     EQU   *
         LR    15,6 ==> js
* Function '__jsopen' epilogue
         PDPEPIL
* Function '__jsopen' literal pool
         DS    0D
         LTORG
* Function '__jsopen' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'HASPJS'
         DC    X'0'
         
&FUNC    SETC 'allocate_spool'
         DS    0F
         EJECT
* static function 'allocate_spool' prologue
* frame base=88, local stack=32, call args=16
&FUNC    SETC  'allocate_spool'
@@6      PDPPRLG CINDEX=1,FRAME=136,BASER=12,ENTRY=NO
         B     @@FEN1
         LTORG
@@FEN1   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         LR    11,1
         L     10,=A(@@PGT1)
* Function 'allocate_spool' code
         L     6,0(11) ==> fp
         SLR   15,15 ==> count
         L     7,16(6) ==> dcb,dcb
         ST    15,128(13) ==> count
         LA    4,104(,13)
         LA    5,20(0,0)
         LR    2,15 ==> count
         LR    3,15 ==> count
         MVCL  4,2 ==> count
         LA    2,128(,13)
         ST    2,88(13)
         ST    15,92(13) ==> count
         LA    1,88(,13)
         L     15,=V(@@TXRDDN)
         BALR  14,15
         LR    3,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L23
         LA    2,128(,13)
         ST    2,88(13)
         MVC   92(4,13),4(11) ==> dataset
         LA    1,88(,13)
         L     15,=V(@@TXDSN)
         BALR  14,15
         LR    3,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L23
         LA    2,128(,13)
         ST    2,88(13)
         ST    15,92(13) ==> err
         LA    1,88(,13)
         L     15,=V(@@TXSHR)
         BALR  14,15
         LR    3,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L23
         LA    2,128(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LTR   15,15 ==> count
         BE    @@L23
         BCTR  15,0 ==> count
         L     4,128(13)
         LR    3,15 ==> count
         MH    3,=H'4'
         L     2,0(3,4)
         O     2,=F'-2147483648'
         ST    2,0(3,4)
         MVI   104(13),20 ==> .len
         MVI   105(13),1 ==> .request
         MVI   106(13),64 ==> .flag1
         MVC   112(4,13),128(13) ==> .txtptr
         LA    2,104(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@SVC99)
         BALR  14,15
         LR    3,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L23
         LR    2,6 ==> fp
         A     2,=F'8'
         ST    2,88(13)
         L     2,128(13)
         L     2,0(2)
         A     2,=F'6'
         ST    2,92(13)
         MVC   96(4,13),=F'8'
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         LR    2,7 ==> dcb
         A     2,=F'40'
         ST    2,88(13)
         L     2,128(13)
         L     2,0(2)
         A     2,=F'6'
         ST    2,92(13)
         MVC   96(4,13),=F'8'
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
@@L23    EQU   *
         L     2,128(13)
         LTR   2,2
         BE    @@L28
         LA    2,128(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@FRTX9A)
         BALR  14,15
@@L28    EQU   *
         LR    15,3 ==> err
* Function 'allocate_spool' epilogue
         PDPEPIL
* Function 'allocate_spool' literal pool
         DS    0D
         LTORG
* Function 'allocate_spool' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
         END
