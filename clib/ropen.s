 TITLE '/home/mike/repos/crent370/clib/ropen.c'
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
* external function 'ropen' prologue
* frame base=88, local stack=320, call args=32
&FUNC    SETC  'ropen'
ROPEN    PDPPRLG CINDEX=0,FRAME=440,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'ropen' code
         L     6,0(11) ==> fnm
         L     9,4(11) ==> write
         LA    1,88(,13)
         L     15,=V(@@GRTGET)
         BALR  14,15
         LR    7,15 ==> grt
         SLR   15,15 ==> fp
         LPR   2,9 ==> fp,write
         LCR   2,2 ==> fp
         SRL   2,31 ==> fp
         ST    2,416(13) ==> fp
         LR    8,15 ==> dyn,fp
         ST    15,420(13) ==> fp
         ST    15,424(13) ==> fp
         ST    15,428(13) ==> fp
         ST    15,432(13) ==> fp
         LA    4,120(,13)
         LA    5,260(0,0)
         LR    2,15 ==> fp
         LR    3,15 ==> fp
         MVCL  4,2 ==> fp
         LA    4,384(,13)
         LA    5,9(0,0)
         LR    2,15 ==> fp
         LR    3,15 ==> fp
         MVCL  4,2 ==> fp
         LA    4,400(,13)
         LA    5,9(0,0)
         LR    2,15 ==> fp
         LR    3,15 ==> fp
         MVCL  4,2 ==> fp
         CLI   0(6),64 ==> fnm
         BNE   @@L83
@@L6     EQU   *
         A     6,=F'1' ==> fnm
         CLI   0(6),64 ==> fnm
         BE    @@L6
@@L83    EQU   *
         SLR   2,2
         IC    2,0(6) ==> fnm
         L     3,=V(@@TOUP)
         L     3,0(3) ==> __toup
         MH    2,=H'2'
         LH    2,0(2,3)
         CLM   2,3,=H'196'
         BNE   @@L7
         SLR   2,2
         IC    2,1(6)
         MH    2,=H'2'
         LH    2,0(2,3)
         CLM   2,3,=H'196'
         BNE   @@L7
         CLI   2(6),122
         BNE   @@L7
         LR    15,6 ==> p,fnm
         A     15,=F'3' ==> p
         SLR   4,4 ==> i
         IC    2,0(4,15) ==> i
         CLM   2,1,=XL1'00'
         BE    @@L9
         L     5,=V(@@TOUP)
@@L14    EQU   *
         IC    2,0(4,15) ==> i
         SLL   2,24
         SRA   2,24
         C     2,=F'77'
         BE    @@L9
         SLR   2,2
         IC    2,0(4,15) ==> i
         L     3,0(5) ==> __toup
         MH    2,=H'2'
         IC    3,1(2,3)
         STC   3,400(4,13) ==> tmpdd
         A     4,=F'1' ==> i
         LA    2,7(0,0)
         CR    4,2 ==> i
         BH    @@L9
         IC    2,0(4,15) ==> i
         SLL   2,24
         SRA   2,24
         C     2,=F'0'
         BNE   @@L14
@@L9     EQU   *
         AR    15,4 ==> p,i
         LA    6,7(0,0)
         CR    4,6 ==> i
         BH    @@L86
         LA    5,280(0,0)
         LA    3,120(,13)
@@L18    EQU   *
         LR    2,4 ==> i
         AR    2,3
         LA    6,64(0,0)
         STC   6,0(5,2) ==> tmpdd
         A     4,=F'1' ==> i
         LA    2,7(0,0)
         CR    4,2 ==> i
         BNH   @@L18
@@L86    EQU   *
         SLR   6,6
         STC   6,400(4,13) ==> tmpdd
         CLI   0(15),77 ==> p
         BNE   @@L27
         A     15,=F'1' ==> p
         SLR   4,4 ==> i
         IC    2,0(15) ==> p
         STC   6,80(,13)
         CLM   2,1,80(13)
         BE    @@L21
         L     5,=V(@@TOUP)
@@L26    EQU   *
         IC    2,0(4,15) ==> i
         SLL   2,24
         SRA   2,24
         C     2,=F'93'
         BE    @@L21
         SLR   2,2
         IC    2,0(4,15) ==> i
         L     3,0(5) ==> __toup
         MH    2,=H'2'
         IC    3,1(2,3)
         STC   3,384(4,13) ==> member
         A     4,=F'1' ==> i
         LA    2,7(0,0)
         CR    4,2 ==> i
         BH    @@L21
         IC    2,0(4,15) ==> i
         CLM   2,1,=XL1'00'
         BNE   @@L26
@@L21    EQU   *
         SLR   6,6
         STC   6,384(4,13) ==> member
         B     @@L27
@@L7     EQU   *
         LA    8,1(0,0) ==> dyn
         SLR   4,4 ==> i
         CLI   0(6),125 ==> fnm
         BNE   @@L28
         AR    6,8 ==> fnm
         B     @@L29
@@L28    EQU   *
         IC    2,10(7) ==> .grtflag1
         N     2,=F'64'
         CLM   2,1,=XL1'00'
         BE    @@L29
         LA    1,88(,13)
         L     15,=V(@@GETPFX)
         BALR  14,15
         LTR   15,15 ==> p
         BE    @@L29
         SLR   4,4 ==> i
         IC    2,0(15) ==> p
         CLM   2,1,=XL1'40'
         BE    @@L33
         SLL   2,24
         SRA   2,24
         C     2,=F'0'
         BE    @@L33
@@L37    EQU   *
         IC    2,0(4,15) ==> i
         STC   2,120(13,4) ==> newfnm
         A     4,=F'1' ==> i
         LA    2,7(0,0)
         CR    4,2 ==> i
         BH    @@L33
         IC    2,0(4,15) ==> i
         CLM   2,1,=XL1'40'
         BE    @@L33
         CLM   2,1,=XL1'00'
         BNE   @@L37
@@L33    EQU   *
         LA    2,75(0,0)
         STC   2,120(4,13) ==> newfnm
         A     4,=F'1' ==> i
@@L29    EQU   *
         LA    2,120(,13)
         LR    15,2 ==> p
         AR    15,4 ==> p,i
         SLR   4,4 ==> i
         IC    2,0(6) ==> fnm
         CLM   2,1,=XL1'00'
         BE    @@L39
         CLM   2,1,=XL1'4D'
         BE    @@L39
         L     5,=V(@@TOUP)
@@L43    EQU   *
         SLR   2,2
         IC    2,0(4,6) ==> i
         L     3,0(5) ==> __toup
         MH    2,=H'2'
         IC    3,1(2,3)
         STC   3,0(4,15) ==> i
         A     4,=F'1' ==> i
         IC    2,0(4,6) ==> i
         CLM   2,1,=XL1'00'
         BE    @@L39
         CLM   2,1,=XL1'4D'
         BNE   @@L43
@@L39    EQU   *
         SLR   2,2
         STC   2,0(4,15) ==> i
         IC    2,0(4,6) ==> i
         CLM   2,1,=XL1'4D'
         BNE   @@L44
         LR    15,6 ==> p,fnm
         AR    15,4 ==> p,i
         A     15,=F'1' ==> p
         CLI   0(15),64 ==> p
         BNE   @@L91
@@L48    EQU   *
         A     15,=F'1' ==> p
         CLI   0(15),64 ==> p
         BE    @@L48
@@L91    EQU   *
         SLR   4,4 ==> i
         IC    2,0(15) ==> p
         CLM   2,1,=XL1'40'
         BE    @@L50
         CLM   2,1,=XL1'00'
         BE    @@L50
         L     5,=V(@@TOUP)
@@L55    EQU   *
         IC    2,0(4,15) ==> i
         SLL   2,24
         SRA   2,24
         C     2,=F'93'
         BE    @@L50
         SLR   2,2
         IC    2,0(4,15) ==> i
         L     3,0(5) ==> __toup
         MH    2,=H'2'
         IC    3,1(2,3)
         STC   3,384(4,13) ==> member
         A     4,=F'1' ==> i
         LA    6,7(0,0)
         CR    4,6 ==> i
         BH    @@L50
         IC    2,0(4,15) ==> i
         CLM   2,1,=XL1'40'
         BE    @@L50
         SLL   2,24
         SRA   2,24
         C     2,=F'0'
         BNE   @@L55
@@L50    EQU   *
         LA    2,7(0,0)
         CR    4,2 ==> i
         BH    @@L94
         LA    5,264(0,0)
         LA    3,120(,13)
@@L59    EQU   *
         LR    2,4 ==> i
         AR    2,3
         LA    6,64(0,0)
         STC   6,0(5,2) ==> member
         A     4,=F'1' ==> i
         LA    2,7(0,0)
         CR    4,2 ==> i
         BNH   @@L59
@@L94    EQU   *
         SLR   6,6
         STC   6,384(4,13) ==> member
@@L44    EQU   *
         LA    2,400(,13)
         ST    2,88(13)
         LA    2,120(,13)
         ST    2,92(13)
         MVC   96(4,13),416(13)
         MVC   100(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@FILDEF)
         BALR  14,15
         LR    3,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L61
@@L27    EQU   *
         MVC   420(4,13),=F'1'
         MVC   424(4,13),=F'255'
         MVC   428(4,13),=F'6233'
         LA    2,400(,13)
         ST    2,88(13)
         LA    2,416(,13)
         ST    2,92(13)
         LA    2,420(,13)
         ST    2,96(13)
         LA    2,424(,13)
         ST    2,100(13)
         LA    2,428(,13)
         ST    2,104(13)
         LA    2,432(,13)
         ST    2,108(13)
         LA    2,384(,13)
         ST    2,112(13)
         LA    1,88(,13)
         L     15,=V(@@AOPEN)
         BALR  14,15
         LR    5,15 ==> hfile
         LTR   15,15 ==> hfile
         BH    @@L62
         LA    3,1(0,0) ==> err
         LA    1,88(,13)
         L     15,=V(@@ERRNO)
         BALR  14,15
         LCR   2,5 ==> hfile
         ST    2,0(15) ==> grt
         B     @@L61
@@L62    EQU   *
         MVC   88(4,13),=F'1'
         MVC   92(4,13),=F'52'
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         LTR   15,15 ==> fp
         BNE   @@L63
         ST    5,88(13) ==> hfile
         LA    1,88(,13)
         L     15,=V(@@ACLOSE)
         BALR  14,15
         LTR   8,8 ==> dyn
         BE    @@L64
         LA    2,400(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@FDCLR)
         BALR  14,15
@@L64    EQU   *
         LA    3,1(0,0) ==> err
         B     @@L61
@@L63    EQU   *
         SLR   4,4 ==> i
         L     2,=A(@@LC0)
         IC    2,0(4,2) ==> i
         CLM   2,1,=XL1'00'
         BE    @@L96
         L     3,=A(@@LC0)
@@L69    EQU   *
         IC    2,0(4,3) ==> i
         STC   2,0(4,15) ==> .eye
         A     4,=F'1' ==> i
         IC    2,0(4,3) ==> i
         CLM   2,1,=XL1'00'
         BNE   @@L69
@@L96    EQU   *
         ST    8,8(15) ==> dyn,dyn
         MVC   12(4,15),420(13) ==> .recfm
         MVC   16(4,15),424(13) ==> .lrecl
         ST    9,20(15) ==> write,write
         ST    5,24(15) ==> hfile,hfile
         MVC   28(4,15),432(13) ==> .asmbuf
         SLR   4,4 ==> i
         IC    2,400(13) ==> tmpdd
         SLL   2,24
         SRA   2,24
         C     2,=F'0'
         BE    @@L71
@@L75    EQU   *
         IC    6,400(4,13) ==> tmpdd
         STC   6,32(15,4) ==> .ddname
         A     4,=F'1' ==> i
         LA    2,7(0,0)
         CR    4,2 ==> i
         BH    @@L71
         IC    2,400(4,13) ==> tmpdd
         CLM   2,1,=XL1'00'
         BNE   @@L75
@@L71    EQU   *
         SLR   4,4 ==> i
         IC    2,384(13) ==> member
         SLL   2,24
         SRA   2,24
         C     2,=F'0'
         BE    @@L77
@@L81    EQU   *
         IC    6,384(4,13) ==> member
         STC   6,41(15,4) ==> .member
         A     4,=F'1' ==> i
         LA    2,7(0,0)
         CR    4,2 ==> i
         BH    @@L77
         IC    2,384(4,13) ==> member
         CLM   2,1,=XL1'00'
         BNE   @@L81
@@L77    EQU   *
         L     2,8(11) ==> rfile
         ST    15,0(2) ==> fp,rfile
         SLR   3,3 ==> err
@@L61    EQU   *
         LR    15,3 ==> err
* Function 'ropen' epilogue
         PDPEPIL
* Function 'ropen' literal pool
         DS    0D
         LTORG
* Function 'ropen' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'*RFILE*'
         DC    X'0'
         END
