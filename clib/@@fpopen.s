 TITLE '/home/mike/repos/crent370/clib/@@fpopen.c'
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
         
&FUNC    SETC '__fpopen'
* Program text area
         DS    0F
         EJECT
* external function '__fpopen' prologue
* frame base=88, local stack=216, call args=32
&FUNC    SETC  '__fpopen'
@@FPOPEN PDPPRLG CINDEX=0,FRAME=336,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__fpopen' code
         L     7,0(11) ==> fp
         LA    8,1(0,0) ==> err
         SLR   6,6 ==> i
         ST    6,312(13) ==> i
         ST    6,316(13) ==> i
         ST    6,320(13) ==> i
         ST    6,324(13) ==> i
         ST    6,328(13) ==> i
         LR    15,6 ==> pmember,i
         MVC   296(8,13),=F'0'
         MVC   304(8,13),=F'0'
         LA    4,120(,13)
         LA    5,176(0,0)
         LR    2,6 ==> i
         LR    3,6 ==> i
         MVCL  4,2 ==> i
         LTR   7,7 ==> fp
         BE    @@L3
         IC    2,43(7) ==> .ddname
         SLL   2,24
         SRA   2,24
         C     2,=F'0'
         BE    @@L3
         LA    3,296(,13)
@@L10    EQU   *
         IC    2,43(7,6) ==> .ddname
         STC   2,0(3,6) ==> ddname
         A     6,=F'1' ==> i
         LA    2,7(0,0)
         CR    6,2 ==> i
         BH    @@L6
         IC    2,43(7,6) ==> .ddname
         SLL   2,24
         SRA   2,24
         C     2,=F'0'
         BNE   @@L10
@@L6     EQU   *
         LA    3,7(0,0)
         CR    6,3 ==> i
         BH    @@L58
         LA    2,296(,13)
@@L15    EQU   *
         LA    3,64(0,0)
         STC   3,0(2,6) ==> ddname
         A     6,=F'1' ==> i
         LA    3,7(0,0)
         CR    6,3 ==> i
         BNH   @@L15
@@L58    EQU   *
         LH    2,40(7) ==> .flags
         N     2,=F'4096'
         CH    2,=H'0'
         BE    @@L16
         L     2,312(13)
         A     2,=F'1'
         ST    2,312(13)
@@L16    EQU   *
         LH    2,40(7) ==> .flags
         N     2,=F'256'
         CH    2,=H'0'
         BE    @@L17
         L     2,312(13)
         A     2,=F'8'
         ST    2,312(13)
@@L17    EQU   *
         IC    2,52(7) ==> .member
         CLM   2,1,=XL1'40'
         BNH   @@L18
         SLR   6,6 ==> i
         SLL   2,24
         SRA   2,24
         C     2,=F'0'
         BE    @@L20
         LA    3,304(,13)
@@L24    EQU   *
         IC    2,52(7,6) ==> .member
         STC   2,0(3,6) ==> member
         A     6,=F'1' ==> i
         LA    2,7(0,0)
         CR    6,2 ==> i
         BH    @@L20
         IC    2,52(7,6) ==> .member
         SLL   2,24
         SRA   2,24
         C     2,=F'0'
         BNE   @@L24
@@L20    EQU   *
         LA    3,7(0,0)
         CR    6,3 ==> i
         BH    @@L61
         LA    2,304(,13)
@@L29    EQU   *
         LA    3,64(0,0)
         STC   3,0(2,6) ==> member
         A     6,=F'1' ==> i
         LA    3,7(0,0)
         CR    6,3 ==> i
         BNH   @@L29
@@L61    EQU   *
         LA    15,304(,13) ==> pmember
@@L18    EQU   *
         IC    2,42(7) ==> .recfm
         N     2,=F'192'
         LA    3,128(0,0)
         CR    2,3
         BE    @@L31
         BH    @@L36
         LA    3,64(0,0)
         CLR   2,3
         BE    @@L32
         B     @@L30
@@L36    EQU   *
         LA    3,192(0,0)
         CLR   2,3
         BE    @@L33
         B     @@L30
@@L31    EQU   *
         MVC   316(4,13),=F'0'
         B     @@L30
@@L32    EQU   *
         MVC   316(4,13),=F'1'
         B     @@L30
@@L33    EQU   *
         MVC   316(4,13),=F'2'
@@L30    EQU   *
         LH    2,16(7) ==> .lrecl
         N     2,=XL4'0000FFFF'
         ST    2,320(13)
         LH    2,18(7) ==> .blksize
         N     2,=XL4'0000FFFF'
         ST    2,324(13)
         LA    2,296(,13)
         ST    2,88(13)
         LA    2,312(,13)
         ST    2,92(13)
         LA    2,316(,13)
         ST    2,96(13)
         LA    2,320(,13)
         ST    2,100(13)
         LA    2,324(,13)
         ST    2,104(13)
         LA    2,328(,13)
         ST    2,108(13)
         ST    15,112(13) ==> pmember
         LA    1,88(,13)
         L     15,=V(@@AOPEN)
         BALR  14,15
         ST    15,8(7) ==> err,dcb
         LTR   15,15 ==> err
         BL    @@L3
         LH    3,40(7) ==> .flags
         O     3,=F'16384'
         STH   3,40(7) ==> .flags
         MVC   12(4,7),328(13) ==> .asmbuf
         MVC   20(4,7),=F'-1' ==> .ungetch
         MVC   42(1,7),36(15) ==> .recfm,dcbrecfm
         MVC   16(2,7),82(15) ==> .lrecl,dcblrecl
         MVC   18(2,7),62(15) ==> .blksize,dcbblksi
         N     3,=F'512'
         CH    3,=H'0'
         BNE   @@L38
         IC    2,42(7) ==> .recfm
         N     2,=F'192'
         LA    3,128(0,0)
         CR    2,3
         BE    @@L40
         BH    @@L45
         LA    3,64(0,0)
         CLR   2,3
         BE    @@L41
         B     @@L39
@@L45    EQU   *
         LA    3,192(0,0)
         CLR   2,3
         BE    @@L42
         B     @@L39
@@L40    EQU   *
         LH    6,16(7) ==> .lrecl
         B     @@L63
@@L41    EQU   *
         LH    6,16(7) ==> .lrecl
         N     6,=XL4'0000FFFF'
         A     6,=F'-4' ==> i
         B     @@L39
@@L42    EQU   *
         LH    6,18(7) ==> .blksize
@@L63    EQU   *
         N     6,=XL4'0000FFFF'
@@L39    EQU   *
         MVC   88(4,13),=F'1'
         LR    2,6 ==> i
         A     2,=F'8'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         ST    15,28(7) ==> err,buf
         LTR   15,15 ==> err
         BE    @@L3
         LH    2,40(7) ==> .flags
         N     2,=F'4096'
         CH    2,=H'0'
         BE    @@L38
         ST    15,32(7) ==> err,upto
         LR    2,6 ==> i
         AR    2,15
         ST    2,36(7) ==> .endbuf
@@L38    EQU   *
         MVC   88(4,13),8(7) ==> .dcb
         LA    2,120(,13)
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(@@RDJFCB)
         BALR  14,15
         LR    8,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L3
         CLI   120(13),64 ==> .jfcbdsnm
         BNH   @@L3
         LR    6,15 ==> i,err
         CLI   0(2),64 ==> .jfcbdsnm
         BNH   @@L51
@@L55    EQU   *
         IC    2,120(13,6) ==> .jfcbdsnm
         STC   2,61(7,6) ==> .dataset
         A     6,=F'1' ==> i
         LA    3,43(0,0)
         CR    6,3 ==> i
         BH    @@L51
         IC    2,120(13,6) ==> .jfcbdsnm
         CLM   2,1,=XL1'40'
         BH    @@L55
@@L51    EQU   *
         SLR   2,2
         STC   2,61(7,6) ==> .dataset
@@L3     EQU   *
         LR    15,8 ==> err
* Function '__fpopen' epilogue
         PDPEPIL
* Function '__fpopen' literal pool
         DS    0D
         LTORG
* Function '__fpopen' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
