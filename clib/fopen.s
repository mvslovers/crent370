 TITLE '/home/mike/repos/crent370/clib/fopen.c'
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
* external function 'fopen' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'fopen'
FOPEN    PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'fopen' code
         L     5,0(11) ==> fn
         L     7,4(11) ==> mode
         LA    1,88(,13)
         L     15,=V(@@GRTGET)
         BALR  14,15
         LR    8,15 ==> grt
         LA    2,1(0,0) ==> err
         SLR   6,6 ==> fp
         LTR   5,5 ==> fn
         BE    @@L3
         LTR   7,7 ==> mode
         BE    @@L3
         ST    2,88(13) ==> err
         MVC   92(4,13),=F'192'
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         LR    6,15 ==> fp
         LTR   15,15 ==> fp
         BE    @@L3
         SLR   4,4 ==> i
         L     2,=A(@@LC0)
         IC    2,0(4,2) ==> i
         CLM   2,1,=XL1'00'
         BE    @@L74
         L     3,=A(@@LC0)
@@L10    EQU   *
         IC    2,0(4,3) ==> i
         STC   2,0(4,6) ==> .eye
         A     4,=F'1' ==> i
         IC    2,0(4,3) ==> i
         CLM   2,1,=XL1'00'
         BNE   @@L10
@@L74    EQU   *
         ST    6,88(13) ==> fp
         ST    7,92(13) ==> mode
         LA    1,88(,13)
         L     15,=V(@@FPMODE)
         BALR  14,15
         LR    2,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L3
         LH    2,40(6) ==> .flags
         N     2,=F'4096'
         CH    2,=H'0'
         BE    @@L12
         MVI   42(6),64 ==> .recfm
         MVC   16(2,6),=H'136' ==> .lrecl
@@L12    EQU   *
         SLR   2,2
         IC    2,0(5) ==> fn
         L     3,=V(@@TOLOW)
         L     3,0(3) ==> __tolow
         MH    2,=H'2'
         LH    2,0(2,3)
         CLM   2,3,=H'132'
         BNE   @@L13
         SLR   2,2
         IC    2,1(5)
         MH    2,=H'2'
         LH    2,0(2,3)
         CLM   2,3,=H'132'
         BNE   @@L13
         CLI   2(5),122
         BNE   @@L13
         A     5,=F'3' ==> fn
         SLR   4,4 ==> i
         IC    2,0(5) ==> fn
         CLM   2,1,=XL1'00'
         BE    @@L15
         SLL   2,24
         SRA   2,24
         C     2,=F'77'
         BE    @@L15
         L     7,=V(@@TOUP)
@@L19    EQU   *
         SLR   2,2
         IC    2,0(5) ==> fn
         L     3,0(7) ==> __toup
         MH    2,=H'2'
         IC    3,1(2,3)
         STC   3,43(6,4) ==> .ddname
         A     4,=F'1' ==> i
         A     5,=F'1' ==> fn
         LA    2,7(0,0)
         CR    4,2 ==> i
         BH    @@L15
         IC    2,0(5) ==> fn
         CLM   2,1,=XL1'00'
         BE    @@L15
         CLM   2,1,=XL1'4D'
         BNE   @@L19
@@L15    EQU   *
         CLI   0(5),77 ==> fn
         BNE   @@L27
         SLR   4,4 ==> i
         A     5,=F'1' ==> fn
         IC    2,0(5) ==> fn
         CLM   2,1,=XL1'00'
         BE    @@L27
         SLL   2,24
         SRA   2,24
         C     2,=F'93'
         BE    @@L27
         L     7,=V(@@TOUP)
@@L26    EQU   *
         SLR   2,2
         IC    2,0(5) ==> fn
         L     3,0(7) ==> __toup
         MH    2,=H'2'
         IC    3,1(2,3)
         STC   3,52(6,4) ==> .member
         A     4,=F'1' ==> i
         A     5,=F'1' ==> fn
         LA    2,7(0,0)
         CR    4,2 ==> i
         BH    @@L27
         IC    2,0(5) ==> fn
         CLM   2,1,=XL1'00'
         BE    @@L27
         CLM   2,1,=XL1'5D'
         BNE   @@L26
         B     @@L27
@@L13    EQU   *
         CLI   0(5),92 ==> fn
         BNE   @@L28
         SLR   4,4 ==> i
         A     5,=F'1' ==> fn
         IC    2,0(5) ==> fn
         CLM   2,1,=XL1'00'
         BE    @@L30
         SLL   2,24
         SRA   2,24
         C     2,=F'77'
         BE    @@L30
         L     7,=V(@@TOUP)
@@L34    EQU   *
         SLR   2,2
         IC    2,0(5) ==> fn
         L     3,0(7) ==> __toup
         MH    2,=H'2'
         IC    3,1(2,3)
         STC   3,43(6,4) ==> .ddname
         A     4,=F'1' ==> i
         A     5,=F'1' ==> fn
         LA    2,7(0,0)
         CR    4,2 ==> i
         BH    @@L30
         IC    2,0(5) ==> fn
         CLM   2,1,=XL1'00'
         BE    @@L30
         CLM   2,1,=XL1'4D'
         BNE   @@L34
@@L30    EQU   *
         IC    2,43(6) ==> .ddname
         CLM   2,1,=XL1'00'
         BE    @@L35
         ST    6,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(@@FPOPEN)
         BALR  14,15
         LR    2,15 ==> err
         LTR   15,15 ==> err
         BE    @@L3
@@L35    EQU   *
         ST    6,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(@@FPSTAR)
         BALR  14,15
         B     @@L81
@@L28    EQU   *
         SLR   4,4 ==> i
         CLI   0(5),125 ==> fn
         BNE   @@L38
         A     5,=F'1' ==> fn
         B     @@L39
@@L38    EQU   *
         CLI   0(5),80 ==> fn
         BE    @@L39
         IC    2,10(8) ==> .grtflag1
         N     2,=F'64'
         CLM   2,1,=XL1'00'
         BE    @@L39
         LA    1,88(,13)
         L     15,=V(@@GETPFX)
         BALR  14,15
         LTR   15,15 ==> gp
         BE    @@L39
         LA    2,7(0,0)
         CR    4,2 ==> i
         BH    @@L44
         IC    2,0(15) ==> gp
         SLL   2,24
         SRA   2,24
         C     2,=F'0'
         BE    @@L44
         L     7,=V(@@TOUP)
@@L48    EQU   *
         SLR   2,2
         IC    2,0(15) ==> gp
         L     3,0(7) ==> __toup
         MH    2,=H'2'
         IC    3,1(2,3)
         STC   3,61(6,4) ==> .dataset
         A     4,=F'1' ==> i
         A     15,=F'1' ==> gp
         LA    2,7(0,0)
         CR    4,2 ==> i
         BH    @@L44
         IC    2,0(15) ==> gp
         SLL   2,24
         SRA   2,24
         C     2,=F'0'
         BNE   @@L48
@@L44    EQU   *
         LA    2,75(0,0)
         STC   2,61(6,4) ==> .dataset
         A     4,=F'1' ==> i
@@L39    EQU   *
         LA    2,43(0,0)
         CR    4,2 ==> i
         BH    @@L50
         IC    2,0(5) ==> fn
         CLM   2,1,=XL1'00'
         BE    @@L50
         CLM   2,1,=XL1'4D'
         BE    @@L50
         SLL   2,24
         SRA   2,24
         C     2,=F'125'
         BE    @@L50
         L     7,=V(@@TOUP)
@@L54    EQU   *
         SLR   2,2
         IC    2,0(5) ==> fn
         L     3,0(7) ==> __toup
         MH    2,=H'2'
         IC    3,1(2,3)
         STC   3,61(6,4) ==> .dataset
         A     4,=F'1' ==> i
         A     5,=F'1' ==> fn
         LA    2,43(0,0)
         CR    4,2 ==> i
         BH    @@L50
         IC    2,0(5) ==> fn
         CLM   2,1,=XL1'00'
         BE    @@L50
         CLM   2,1,=XL1'4D'
         BE    @@L50
         CLM   2,1,=XL1'7D'
         BNE   @@L54
@@L50    EQU   *
         CLI   0(5),77 ==> fn
         BNE   @@L55
         A     5,=F'1' ==> fn
         SLR   4,4 ==> i
         IC    2,0(5) ==> fn
         CLM   2,1,=XL1'00'
         BE    @@L55
         SLL   2,24
         SRA   2,24
         C     2,=F'93'
         BE    @@L55
         L     7,=V(@@TOUP)
@@L61    EQU   *
         SLR   2,2
         IC    2,0(5) ==> fn
         L     3,0(7) ==> __toup
         MH    2,=H'2'
         IC    3,1(2,3)
         STC   3,52(6,4) ==> .member
         A     4,=F'1' ==> i
         A     5,=F'1' ==> fn
         LA    2,7(0,0)
         CR    4,2 ==> i
         BH    @@L55
         IC    2,0(5) ==> fn
         CLM   2,1,=XL1'00'
         BE    @@L55
         CLM   2,1,=XL1'5D'
         BNE   @@L61
@@L55    EQU   *
         LH    2,40(6) ==> .flags
         N     2,=F'8192'
         CH    2,=H'0'
         BE    @@L62
         ST    6,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(@@FPSHR)
         BALR  14,15
         B     @@L81
@@L62    EQU   *
         CLI   61(6),80 ==> .dataset
         BNE   @@L64
         ST    6,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(@@FPTMP)
         BALR  14,15
         LTR   15,15 ==> err
         BE    @@L27
@@L64    EQU   *
         IC    2,52(6) ==> .member
         CLM   2,1,=XL1'00'
         BE    @@L66
         ST    6,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(@@FPSHR)
         BALR  14,15
         LTR   15,15 ==> err
         BE    @@L27
@@L66    EQU   *
         ST    6,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(@@FPOLD)
         BALR  14,15
         LTR   15,15 ==> err
         BE    @@L27
         ST    6,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(@@FPNEW)
         BALR  14,15
@@L81    EQU   *
         LR    2,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L3
@@L27    EQU   *
         ST    6,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(@@FPOPEN)
         BALR  14,15
         LR    2,15 ==> err
@@L3     EQU   *
         LTR   2,2 ==> err
         BE    @@L70
         LTR   6,6 ==> fp
         BE    @@L70
         ST    6,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(FCLOSE)
         BALR  14,15
         SLR   6,6 ==> fp
@@L70    EQU   *
         LTR   6,6 ==> fp
         BE    @@L72
         LR    2,8 ==> grt
         A     2,=F'24'
         ST    2,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         ST    2,88(13)
         ST    6,92(13) ==> fp
         LA    1,88(,13)
         L     15,=V(@@ARADD)
         BALR  14,15
         ST    2,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
@@L72    EQU   *
         LR    15,6 ==> fp
* Function 'fopen' epilogue
         PDPEPIL
* Function 'fopen' literal pool
         DS    0D
         LTORG
* Function 'fopen' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'F I L E'
         DC    X'0'
         END
