 TITLE '/home/mike/repos/crent370/clib/@@examin.c'
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
         DC    C'0123456789ABCDEF'
         DC    X'0'
@@3      EQU   *
         DC    C'0123456789abcdef'
         DC    X'0'
         DS    0F
         EJECT
* external function '__examin' prologue
* frame base=88, local stack=176, call args=24
&FUNC    SETC  '__examin'
@@EXAMIN PDPPRLG CINDEX=0,FRAME=288,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__examin' code
         SLR   2,2
         SLR   3,3
         ST    2,264(13)
         ST    3,4+264(13)
         L     6,12(11) ==> arg
         MVC   224(4,13),=F'0' ==> extraCh
         MVC   228(4,13),224(13) ==> flagMinus,extraCh
         MVC   232(4,13),224(13) ==> flagPlus,extraCh
         MVC   236(4,13),224(13) ==> flagSpace,extraCh
         MVC   240(4,13),224(13) ==> flagHash,extraCh
         MVC   244(4,13),224(13) ==> flagZero,extraCh
         MVC   248(4,13),224(13) ==> width,extraCh
         MVC   252(4,13),=F'-1' ==> precision
         MVC   256(4,13),224(13) ==> lng,extraCh
         L     3,0(11) ==> formt
         L     4,0(3) ==> format
         SLR   3,3 ==> fin
@@L21    EQU   *
         SLR   2,2
         IC    2,0(4) ==> format
         LA    5,92(0,0)
         CR    2,5
         BE    @@L11
         BH    @@L15
         LA    7,64(0,0)
         CLR   2,7
         BE    @@L8
         LA    15,78(0,0)
         CLR   2,15
         BE    @@L7
         B     @@L13
@@L15    EQU   *
         LA    5,123(0,0)
         CR    2,5
         BE    @@L9
         BH    @@L16
         LA    7,96(0,0)
         CLR   2,7
         BE    @@L6
         B     @@L13
@@L16    EQU   *
         LA    15,240(0,0)
         CLR   2,15
         BE    @@L10
         B     @@L13
@@L6     EQU   *
         MVC   228(4,13),=F'1' ==> flagMinus
         B     @@L5
@@L7     EQU   *
         MVC   232(4,13),=F'1' ==> flagPlus
         B     @@L5
@@L8     EQU   *
         MVC   236(4,13),=F'1' ==> flagSpace
         B     @@L5
@@L9     EQU   *
         MVC   240(4,13),=F'1' ==> flagHash
         B     @@L5
@@L10    EQU   *
         MVC   244(4,13),=F'1' ==> flagZero
         B     @@L5
@@L11    EQU   *
         L     2,0(6) ==> arg
         A     2,=F'4'
         ST    2,0(6) ==> arg
         A     2,=F'-4'
         MVC   248(4,13),0(2) ==> width
         L     2,248(13) ==> width
         LTR   2,2
         BNL   @@L5
         MVC   228(4,13),=F'1' ==> flagMinus
         LCR   2,2
         ST    2,248(13) ==> width
         B     @@L5
@@L13    EQU   *
         LA    3,1(0,0) ==> fin
@@L5     EQU   *
         LTR   3,3 ==> fin
         BNE   @@L17
         A     4,=F'1' ==> format
         B     @@L2
@@L17    EQU   *
         L     5,236(13) ==> flagSpace
         LTR   5,5
         BE    @@L19
         L     7,232(13) ==> flagPlus
         LTR   7,7
         BE    @@L19
         MVC   236(4,13),=F'0' ==> flagSpace
@@L19    EQU   *
         L     15,228(13) ==> flagMinus
         LTR   15,15
         BE    @@L2
         MVC   244(4,13),=F'0' ==> flagZero
@@L2     EQU   *
         LTR   3,3 ==> fin
         BE    @@L21
         SLR   2,2
         IC    2,0(4) ==> format
         LR    15,2
         L     3,=V(@@ISBUF)
         L     3,0(3) ==> __isbuf
         MH    2,=H'2'
         LH    2,0(2,3)
         N     2,=F'8'
         CH    2,=H'0'
         BE    @@L22
@@L26    EQU   *
         L     2,248(13) ==> width
         SLL   2,3
         A     2,248(13) ==> width
         A     2,248(13) ==> width
         AR    2,15
         A     2,=F'-240'
         ST    2,248(13) ==> width
         A     4,=F'1' ==> format
         SLR   15,15
         IC    15,0(4) ==> format
         LR    2,15
         MH    2,=H'2'
         LH    2,0(2,3)
         N     2,=F'8'
         CH    2,=H'0'
         BNE   @@L26
@@L22    EQU   *
         CLI   0(4),75 ==> format
         BNE   @@L27
         A     4,=F'1' ==> format
         CLI   0(4),92 ==> format
         BNE   @@L28
         L     2,0(6) ==> arg
         A     2,=F'4'
         ST    2,0(6) ==> arg
         A     2,=F'-4'
         MVC   252(4,13),0(2) ==> precision
         A     4,=F'1' ==> format
         B     @@L27
@@L28    EQU   *
         MVC   252(4,13),=F'0' ==> precision
         SLR   2,2
         IC    2,0(4) ==> format
         LR    5,2
         L     3,=V(@@ISBUF)
         L     3,0(3) ==> __isbuf
         MH    2,=H'2'
         LH    2,0(2,3)
         N     2,=F'8'
         CH    2,=H'0'
         BE    @@L27
@@L33    EQU   *
         L     2,252(13) ==> precision
         SLL   2,3
         A     2,252(13) ==> precision
         A     2,252(13) ==> precision
         AR    2,5
         A     2,=F'-240'
         ST    2,252(13) ==> precision
         A     4,=F'1' ==> format
         SLR   5,5
         IC    5,0(4) ==> format
         LR    2,5
         MH    2,=H'2'
         LH    2,0(2,3)
         N     2,=F'8'
         CH    2,=H'0'
         BNE   @@L33
@@L27    EQU   *
         IC    2,0(4) ==> format
         CLM   2,1,=XL1'88'
         BE    @@L35
         CLM   2,1,=XL1'93'
         BNE   @@L36
         MVC   256(4,13),=F'1' ==> lng
         CLI   1(4),147
         BNE   @@L35
         B     @@L179
@@L36    EQU   *
         CLI   0(4),211 ==> format
         BNE   @@L39
         MVC   256(4,13),=F'1' ==> lng
         CLI   1(4),211
         BNE   @@L35
@@L179   EQU   *
         MVC   256(4,13),=F'2' ==> lng
         A     4,=F'1' ==> format
         B     @@L35
@@L39    EQU   *
         BCTR  4,0 ==> format
@@L35    EQU   *
         A     4,=F'1' ==> format
         SLR   7,7 ==> specifier
         IC    7,0(4) ==> specifier,format
         MVC   88(4,13),=A(@@LC0)
         ST    7,92(13) ==> specifier
         LA    1,88(,13)
         L     15,=V(STRCHR)
         BALR  14,15
         LTR   15,15 ==> rem
         L     14,=A(@@L42)
         BER   14
         LTR   7,7 ==> specifier
         L     14,=A(@@L42)
         BER   14
         L     2,252(13) ==> precision
         LTR   2,2
         BNL   @@L43
         MVC   252(4,13),=F'1' ==> precision
@@L43    EQU   *
         L     5,256(13) ==> lng
         LA    3,1(0,0)
         CLR   5,3
         BE    @@L48
         L     2,256(13) ==> lng
         LA    15,2(0,0)
         CLR   2,15
         BNE   @@L46
         L     2,0(6) ==> arg
         A     2,=F'4'
         ST    2,0(6) ==> arg
         A     2,=F'-4'
         MVC   192(4,13),0(2)
         L     2,0(6) ==> arg
         A     2,=F'4'
         ST    2,0(6) ==> arg
         A     2,=F'-4'
         L     2,0(2) ==> lvalue
         ST    2,196(13) ==> lvalue,u32
         B     @@L45
@@L46    EQU   *
         SLR   3,3
         LTR   3,3
         BE    @@L48
         L     2,0(6) ==> arg
         A     2,=F'4'
         ST    2,0(6) ==> arg
         A     2,=F'-4'
         L     3,0(2)
         SLL   3,16 ==> hvalue
         SRA   3,16 ==> hvalue
         LR    2,3 ==> hvalue
         N     2,=XL4'0000FFFF'
         LA    5,164(0,0)
         CLR   7,5 ==> specifier
         BE    @@L45
         LR    2,3 ==> lvalue,hvalue
         SLL   2,16 ==> lvalue
         SRA   2,16 ==> lvalue
         B     @@L45
@@L48    EQU   *
         L     2,0(6) ==> arg
         A     2,=F'4'
         ST    2,0(6) ==> arg
         A     2,=F'-4'
         L     2,0(2) ==> lvalue
@@L45    EQU   *
         LR    6,2 ==> ulvalue,lvalue
         LTR   2,2 ==> ulvalue
         BNL   @@L54
         LA    15,132(0,0)
         CLR   7,15 ==> specifier
         BE    @@L55
         LA    3,137(0,0)
         CLR   7,3 ==> specifier
         BNE   @@L54
@@L55    EQU   *
         MVC   260(4,13),=F'1' ==> neg
         LCR   6,2 ==> ulvalue,lvalue
         B     @@L56
@@L54    EQU   *
         MVC   260(4,13),=F'0' ==> neg
@@L56    EQU   *
         LA    5,231(0,0)
         CLR   7,5 ==> specifier
         BE    @@L58
         LA    15,167(0,0)
         CLR   7,15 ==> specifier
         BE    @@L58
         LA    2,151(0,0)
         CLR   7,2 ==> specifier
         BNE   @@L57
@@L58    EQU   *
         MVC   280(4,13),=F'16' ==> base
         B     @@L59
@@L57    EQU   *
         MVC   280(4,13),=F'8' ==> base
         LA    3,150(0,0)
         CLR   7,3 ==> specifier
         BE    @@L59
         MVC   280(4,13),=F'10' ==> base
@@L59    EQU   *
         LA    5,151(0,0)
         CLR   7,5 ==> specifier
         BNE   @@L62
         MVC   252(4,13),=F'8' ==> precision
@@L62    EQU   *
         SLR   5,5 ==> x
         L     2,256(13) ==> lng
         LA    15,2(0,0)
         CLR   2,15
         BNE   @@L63
         LA    2,200(,13)
         ST    2,88(13)
         MVC   92(4,13),280(13) ==> base
         LA    1,88(,13)
         L     15,=V(@@64FI32)
         BALR  14,15
         ST    5,260(13) ==> x,neg
         B     @@L64
@@L70    EQU   *
         LA    2,192(,13)
         ST    2,88(13)
         LA    2,200(,13)
         ST    2,92(13)
         LA    2,208(,13)
         ST    2,96(13)
         LA    2,216(,13)
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(@@64DMOD)
         BALR  14,15
         LA    2,216(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@64TI32)
         BALR  14,15
         LA    3,231(0,0)
         CLR   7,3 ==> specifier
         BE    @@L68
         LA    2,151(0,0)
         CLR   7,2 ==> specifier
         BNE   @@L67
@@L68    EQU   *
         L     2,=A(@@2)
         B     @@L180
@@L67    EQU   *
         L     2,=A(@@3)
@@L180   EQU   *
         IC    2,0(15,2) ==> digits
         STC   2,112(13,5) ==> work
         A     5,=F'1' ==> x
         LA    2,208(,13)
         ST    2,88(13)
         LA    2,192(,13)
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(@@64COPY)
         BALR  14,15
@@L64    EQU   *
         LA    2,192(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@64IS0)
         BALR  14,15
         LTR   15,15 ==> rem
         BNE   @@L71
         B     @@L70
@@L63    EQU   *
         LTR   6,6 ==> ulvalue
         BE    @@L71
         MVC   272(4,13),280(13) ==> base
@@L84    EQU   *
         ST    6,264(13) ==> ulvalue
         L     3,280(13) ==> base
         CLR   3,6
         BH    @@L77
         LA    15,1(0,0)
         CLR   3,15
         BE    @@L75
         L     2,264(13)
         L     3,4+264(13)
         SRDL  2,32
         D     2,280(13) ==> base
         ST    2,264(13)
         ST    3,4+264(13)
         B     @@L77
@@L75    EQU   *
         MVC   264(4,13),=F'0'
@@L77    EQU   *
         L     15,264(13) ==> rem
         LA    3,231(0,0)
         CLR   7,3 ==> specifier
         BE    @@L79
         LA    2,151(0,0)
         CLR   7,2 ==> specifier
         BNE   @@L78
@@L79    EQU   *
         L     2,=A(@@2)
         B     @@L181
@@L78    EQU   *
         L     2,=A(@@3)
@@L181   EQU   *
         IC    2,0(15,2) ==> digits
         STC   2,112(13,5) ==> work
         A     5,=F'1' ==> x
         LR    8,6 ==> ulvalue
         SLR   9,9 ==> ulvalue
         L     3,280(13) ==> base
         CLR   3,6
         BH    @@L83
         LA    15,1(0,0)
         CLR   3,15
         BE    @@L81
         SRDL  8,32 ==> ulvalue
         DR    8,3 ==> ulvalue
         B     @@L83
@@L81    EQU   *
         LR    9,6 ==> ulvalue
@@L83    EQU   *
         LR    6,9 ==> ulvalue
         LTR   9,9 ==> ulvalue
         BNE   @@L84
@@L71    EQU   *
         C     5,252(13) ==> x,precision
         BNL   @@L170
@@L88    EQU   *
         L     2,=F'-16'
         STC   2,112(13,5) ==> work
         A     5,=F'1' ==> x
         C     5,252(13) ==> x,precision
         BL    @@L88
@@L170   EQU   *
         L     3,260(13) ==> neg
         LTR   3,3
         BE    @@L89
         LA    15,96(0,0)
         STC   15,112(5,13) ==> work
         B     @@L182
@@L89    EQU   *
         L     2,232(13) ==> flagPlus
         LTR   2,2
         BE    @@L91
         LA    3,78(0,0)
         STC   3,112(5,13) ==> work
         B     @@L182
@@L91    EQU   *
         L     15,236(13) ==> flagSpace
         LTR   15,15
         BE    @@L90
         LA    2,64(0,0)
         STC   2,112(5,13) ==> work
@@L182   EQU   *
         A     5,=F'1' ==> x
@@L90    EQU   *
         LA    8,240(0,0) ==> fillCh
         L     3,244(13) ==> flagZero
         LTR   3,3
         BNE   @@L95
         LA    8,64(0,0) ==> fillCh
@@L95    EQU   *
         LR    6,5 ==> y,x
         L     15,228(13) ==> flagMinus
         LTR   15,15
         BNE   @@L96
         C     5,248(13) ==> x,width
         BNL   @@L96
@@L102   EQU   *
         L     2,4(11) ==> fq
         LTR   2,2
         BNE   @@L100
         L     3,8(11) ==> s
         STC   8,0(3) ==> fillCh
         A     3,=F'1'
         ST    3,8(11) ==> s
         B     @@L101
@@L100   EQU   *
         ST    8,88(13) ==> fillCh
         MVC   92(4,13),4(11) ==> fq
         LA    1,88(,13)
         L     15,=V(FPUTC)
         BALR  14,15
@@L101   EQU   *
         L     15,224(13) ==> extraCh
         A     15,=F'1'
         ST    15,224(13) ==> extraCh
         A     6,=F'1' ==> y
         C     6,248(13) ==> y,width
         BL    @@L102
@@L96    EQU   *
         L     2,240(13) ==> flagHash
         LTR   2,2
         BE    @@L103
         L     2,=V(@@TOUP)
         L     3,0(2) ==> __toup
         LR    2,7 ==> specifier
         SLL   2,1
         LH    2,0(2,3)
         CLM   2,3,=H'231'
         BNE   @@L103
         L     3,4(11) ==> fq
         LTR   3,3
         BNE   @@L104
         L     7,8(11) ==> s
         MVI   0(7),240
         A     7,=F'1'
         ST    7,8(11) ==> s
         B     @@L105
@@L104   EQU   *
         MVC   88(4,13),=F'240'
         MVC   92(4,13),4(11) ==> fq
         LA    1,88(,13)
         L     15,=V(FPUTC)
         BALR  14,15
@@L105   EQU   *
         L     15,4(11) ==> fq
         LTR   15,15
         BNE   @@L106
         L     2,8(11) ==> s
         MVI   0(2),167
         A     2,=F'1'
         ST    2,8(11) ==> s
         B     @@L107
@@L106   EQU   *
         MVC   88(4,13),=F'167'
         MVC   92(4,13),4(11) ==> fq
         LA    1,88(,13)
         L     15,=V(FPUTC)
         BALR  14,15
@@L107   EQU   *
         L     3,224(13) ==> extraCh
         A     3,=F'2'
         ST    3,224(13) ==> extraCh
@@L103   EQU   *
         BCTR  5,0 ==> x
         LTR   5,5 ==> x
         BL    @@L173
@@L113   EQU   *
         L     7,4(11) ==> fq
         LTR   7,7
         BNE   @@L111
         IC    2,112(13,5) ==> work
         L     15,8(11) ==> s
         STC   2,0(15)
         A     15,=F'1'
         ST    15,8(11) ==> s
         B     @@L112
@@L111   EQU   *
         SLR   2,2
         IC    2,112(13,5) ==> work
         ST    2,88(13)
         MVC   92(4,13),4(11) ==> fq
         LA    1,88(,13)
         L     15,=V(FPUTC)
         BALR  14,15
@@L112   EQU   *
         L     3,224(13) ==> extraCh
         A     3,=F'1'
         ST    3,224(13) ==> extraCh
         BCTR  5,0 ==> x
         LTR   5,5 ==> x
         BNL   @@L113
@@L173   EQU   *
         L     5,228(13) ==> flagMinus
         LTR   5,5
         L     14,=A(@@L121)
         BER   14
         C     6,248(13) ==> y,width
         L     14,=A(@@L121)
         BNLR  14
@@L120   EQU   *
         L     7,4(11) ==> fq
         LTR   7,7
         BNE   @@L118
         L     15,8(11) ==> s
         STC   8,0(15) ==> fillCh
         A     15,=F'1'
         ST    15,8(11) ==> s
         B     @@L119
@@L118   EQU   *
         ST    8,88(13) ==> fillCh
         MVC   92(4,13),4(11) ==> fq
         LA    1,88(,13)
         L     15,=V(FPUTC)
         BALR  14,15
@@L119   EQU   *
         L     2,224(13) ==> extraCh
         A     2,=F'1'
         ST    2,224(13) ==> extraCh
         A     6,=F'1' ==> y
         C     6,248(13) ==> y,width
         L     14,=A(@@L121)
         BNLR  14
         B     @@L120
@@L42    EQU   *
         MVC   88(4,13),=A(@@LC1)
         ST    7,92(13) ==> specifier
         LA    1,88(,13)
         L     15,=V(STRCHR)
         BALR  14,15
         LTR   15,15 ==> rem
         BE    @@L122
         LTR   7,7 ==> specifier
         BE    @@L122
         L     3,252(13) ==> precision
         LTR   3,3
         BNL   @@L123
         MVC   252(4,13),=F'6' ==> precision
@@L123   EQU   *
         L     2,0(6) ==> arg
         A     2,=F'8'
         ST    2,0(6) ==> arg
         A     2,=F'-8'
         MVC   88(8,13),0(2)
         LR    2,7
         N     2,=XL4'000000FF' ==> specifier
         ST    2,96(13) ==> specifier
         MVC   100(4,13),248(13) ==> width
         MVC   104(4,13),252(13) ==> precision
         LA    2,112(,13)
         ST    2,108(13)
         LA    1,88(,13)
         L     15,=V(@@DBLCVT)
         BALR  14,15
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         LR    3,15 ==> slen
         L     5,236(13) ==> flagSpace
         LTR   5,5
         BNE   @@L125
         L     7,232(13) ==> flagPlus
         LTR   7,7
         BE    @@L124
@@L125   EQU   *
         CLI   112(13),96 ==> work
         BE    @@L124
         A     3,=F'1' ==> slen
         LA    2,113(,13)
         ST    2,88(13)
         LA    2,112(,13)
         ST    2,92(13)
         ST    3,96(13) ==> slen
         LA    1,88(,13)
         L     15,=V(MEMMOVE)
         BALR  14,15
         L     15,236(13) ==> flagSpace
         LTR   15,15
         BE    @@L126
         MVI   112(13),64 ==> work
         B     @@L124
@@L126   EQU   *
         L     2,232(13) ==> flagPlus
         LTR   2,2
         BE    @@L124
         MVI   112(13),78 ==> work
@@L124   EQU   *
         L     5,4(11) ==> fq
         LTR   5,5
         BNE   @@L129
         MVC   88(4,13),8(11) ==> s
         LA    2,112(,13)
         ST    2,92(13)
         ST    3,96(13) ==> slen
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         B     @@L130
@@L129   EQU   *
         LA    2,112(,13)
         ST    2,88(13)
         MVC   92(4,13),4(11) ==> fq
         LA    1,88(,13)
         L     15,=V(FPUTS)
         BALR  14,15
@@L130   EQU   *
         A     3,224(13) ==> slen,extraCh
         ST    3,224(13) ==> slen,extraCh
         L     14,=A(@@L121)
         BR    14
@@L122   EQU   *
         LA    15,162(0,0)
         CR    7,15 ==> specifier
         L     14,=A(@@L121)
         BNER  14
         L     2,0(6) ==> arg
         A     2,=F'4'
         ST    2,0(6) ==> arg
         A     2,=F'-4'
         L     6,0(2) ==> svalue
         LA    8,64(0,0) ==> fillCh
         L     2,252(13) ==> precision
         LTR   2,2
         BNH   @@L133
         ST    6,88(13) ==> svalue
         MVC   92(4,13),=F'0'
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(MEMCHR)
         BALR  14,15
         LR    3,15 ==> length,p
         SR    3,6 ==> length,svalue
         LTR   15,15 ==> p
         BNE   @@L136
         L     3,252(13) ==> length,precision
         B     @@L136
@@L133   EQU   *
         L     3,252(13) ==> precision
         LTR   3,3
         BNL   @@L137
         ST    6,88(13) ==> svalue
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         LR    3,15 ==> length
         B     @@L136
@@L137   EQU   *
         SLR   3,3 ==> length
@@L136   EQU   *
         L     5,228(13) ==> flagMinus
         LTR   5,5
         BNE   @@L139
         C     3,248(13) ==> length,width
         BNL   @@L139
         L     2,248(13) ==> width
         SR    2,3 ==> length
         L     7,224(13) ==> extraCh
         AR    7,2
         ST    7,224(13) ==> extraCh
         CR    5,2 ==> x
         BNL   @@L139
         L     2,248(13) ==> width
         SR    2,3 ==> length
@@L147   EQU   *
         L     15,4(11) ==> fq
         LTR   15,15
         BNE   @@L145
         L     7,8(11) ==> s
         STC   8,0(7) ==> fillCh
         A     7,=F'1'
         ST    7,8(11) ==> s
         B     @@L143
@@L145   EQU   *
         ST    8,88(13) ==> fillCh
         MVC   92(4,13),4(11) ==> fq
         LA    1,88(,13)
         L     15,=V(FPUTC)
         BALR  14,15
@@L143   EQU   *
         A     5,=F'1' ==> x
         CR    5,2 ==> x
         BL    @@L147
@@L139   EQU   *
         SLR   5,5 ==> x
         CR    5,3 ==> x,length
         BNL   @@L177
@@L154   EQU   *
         L     15,4(11) ==> fq
         LTR   15,15
         BNE   @@L152
         IC    7,0(5,6) ==> x
         L     2,8(11) ==> s
         STC   7,0(2)
         A     2,=F'1'
         ST    2,8(11) ==> s
         B     @@L150
@@L152   EQU   *
         SLR   2,2
         IC    2,0(5,6) ==> x
         ST    2,88(13)
         MVC   92(4,13),4(11) ==> fq
         LA    1,88(,13)
         L     15,=V(FPUTC)
         BALR  14,15
@@L150   EQU   *
         A     5,=F'1' ==> x
         CR    5,3 ==> x,length
         BL    @@L154
@@L177   EQU   *
         L     15,224(13) ==> extraCh
         AR    15,3 ==> length
         ST    15,224(13) ==> extraCh
         L     2,228(13) ==> flagMinus
         LTR   2,2
         BE    @@L121
         C     3,248(13) ==> length,width
         BNL   @@L121
         L     2,248(13) ==> width
         SR    2,3 ==> length
         AR    15,2
         ST    15,224(13) ==> extraCh
         SLR   5,5 ==> x
         CR    5,2 ==> x
         BNL   @@L121
         L     2,248(13) ==> width
         SR    2,3 ==> length
@@L163   EQU   *
         L     3,4(11) ==> fq
         LTR   3,3
         BNE   @@L161
         L     7,8(11) ==> s
         STC   8,0(7) ==> fillCh
         A     7,=F'1'
         ST    7,8(11) ==> s
         B     @@L159
@@L161   EQU   *
         ST    8,88(13) ==> fillCh
         MVC   92(4,13),4(11) ==> fq
         LA    1,88(,13)
         L     15,=V(FPUTC)
         BALR  14,15
@@L159   EQU   *
         A     5,=F'1' ==> x
         CR    5,2 ==> x
         BL    @@L163
@@L121   EQU   *
         L     15,0(11) ==> formt
         ST    4,0(15) ==> format
         L     15,224(13) ==> extraCh
* Function '__examin' epilogue
         PDPEPIL
* Function '__examin' literal pool
         DS    0D
         LTORG
* Function '__examin' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'dxXuiop'
         DC    X'0'
@@LC1    EQU   *
         DC    C'eEgGfF'
         DC    X'0'
         END
