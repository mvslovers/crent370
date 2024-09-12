 TITLE '/home/mike/repos/crent370/clib/vvscanf.c'
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
* external function 'vvscanf' prologue
* frame base=88, local stack=136, call args=16
&FUNC    SETC  'vvscanf'
VVSCANF  PDPPRLG CINDEX=0,FRAME=240,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'vvscanf' code
         SLR   2,2
         SLR   3,3
         ST    2,184(13)
         ST    3,4+184(13)
         ST    2,192(13)
         ST    3,4+192(13)
         L     5,0(11) ==> format
         L     6,8(11) ==> fp
         L     9,12(11) ==> s
         MVC   108(4,13),=F'0' ==> cnt
         MVC   104(4,13),108(13) ==> fin,cnt
         LTR   6,6 ==> fp
         BE    @@L2
         ST    6,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(FTELL)
         BALR  14,15
         ST    15,148(13) ==> startpos
         B     @@L3
@@L2     EQU   *
         ST    9,152(13) ==> s,startp
@@L3     EQU   *
         LTR   6,6 ==> fp
         BNE   @@L4
         SLR   4,4 ==> ch
         IC    4,0(9) ==> ch,s
         A     9,=F'1' ==> s
         B     @@L5
@@L4     EQU   *
         ST    6,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(FGETC)
         BALR  14,15
         LR    4,15 ==> ch
@@L5     EQU   *
         MVC   168(4,13),=F'0' ==> informatitem
         L     3,104(13) ==> fin
         LTR   3,3
         L     14,=A(@@L7)
         BNER  14
@@L245   EQU   *
         L     12,0(,10)
         IC    2,0(5) ==> format
         CLM   2,1,=XL1'00'
         BNE   @@L9
         MVC   104(4,13),=F'1' ==> fin
         L     14,=A(@@L10)
         BR    14
@@L9     EQU   *
         CLI   0(5),108 ==> format
         BE    @@L12
         L     15,168(13) ==> informatitem
         LTR   15,15
         L     14,=A(@@L11)
         BER   14
@@L12    EQU   *
         CLI   0(5),108 ==> format
         BNE   @@L13
         A     5,=F'1' ==> format
         MVC   160(4,13),=F'0' ==> modlong
         MVC   164(4,13),160(13) ==> modshort,modlong
         MVC   156(4,13),160(13) ==> skipvar,modlong
         CLI   0(5),92 ==> format
         BNE   @@L13
         MVC   156(4,13),=F'1' ==> skipvar
         A     5,=F'1' ==> format
@@L13    EQU   *
         CLI   0(5),108 ==> format
         BNE   @@L15
         L     15,108(13) ==> cnt
         LA    2,108(0,0)
         CLR   4,2 ==> ch
         L     14,=A(@@L1)
         BNER  14
         LTR   6,6 ==> fp
         BNE   @@L17
         SLR   4,4 ==> ch
         IC    4,0(9) ==> ch,s
         A     9,=F'1' ==> s
         B     @@L18
@@L17    EQU   *
         ST    6,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(FGETC)
         BALR  14,15
         LR    4,15 ==> ch
@@L18    EQU   *
         MVC   168(4,13),=F'0' ==> informatitem
         L     14,=A(@@L10)
         BR    14
@@L15    EQU   *
         CLI   0(5),147 ==> format
         BNE   @@L20
         MVC   160(4,13),=F'1' ==> modlong
         B     @@L265
@@L20    EQU   *
         CLI   0(5),136 ==> format
         BNE   @@L22
         MVC   164(4,13),=F'1' ==> modshort
@@L265   EQU   *
         MVC   168(4,13),=F'1' ==> informatitem
         L     14,=A(@@L10)
         BR    14
@@L22    EQU   *
         MVC   168(4,13),=F'0' ==> informatitem
         CLI   0(5),162 ==> format
         BNE   @@L24
         L     3,156(13) ==> skipvar
         LTR   3,3
         BNE   @@L25
         L     15,4(11) ==> arg
         A     15,=F'4'
         ST    15,4(11) ==> arg
         LR    2,15
         A     2,=F'-4'
         MVC   112(4,13),0(2) ==> cptr
@@L25    EQU   *
         LTR   4,4 ==> ch
         BL    @@L27
         L     2,=V(@@ISBUF)
         L     3,0(2) ==> __isbuf
         LR    2,4 ==> ch
         MH    2,=H'2'
         LH    2,0(2,3)
         N     2,=F'256'
         CH    2,=H'0'
         BE    @@L27
@@L32    EQU   *
         LTR   6,6 ==> fp
         BNE   @@L30
         SLR   4,4 ==> ch
         IC    4,0(9) ==> ch,s
         A     9,=F'1' ==> s
         B     @@L26
@@L30    EQU   *
         ST    6,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(FGETC)
         BALR  14,15
         LR    4,15 ==> ch
@@L26    EQU   *
         LTR   4,4 ==> ch
         BL    @@L27
         L     2,=V(@@ISBUF)
         L     3,0(2) ==> __isbuf
         LR    2,4 ==> ch
         MH    2,=H'2'
         LH    2,0(2,3)
         N     2,=F'256'
         CH    2,=H'0'
         BNE   @@L32
@@L27    EQU   *
         LTR   6,6 ==> fp
         BE    @@L35
         L     2,=F'-1'
         CLR   4,2 ==> ch
         BE    @@L34
@@L35    EQU   *
         LTR   6,6 ==> fp
         BNE   @@L38
         LTR   4,4 ==> ch
         BNE   @@L38
@@L34    EQU   *
         L     3,156(13) ==> skipvar
         LTR   3,3
         L     14,=A(@@L6)
         BNER  14
         L     15,112(13) ==> cptr
         MVC   0(1,15),159(13) ==> skipvar
         L     14,=A(@@L6)
         BR    14
@@L38    EQU   *
         L     2,=V(@@ISBUF)
         L     3,0(2) ==> __isbuf
         LR    2,4 ==> ch
         MH    2,=H'2'
         LH    2,0(2,3)
         N     2,=F'256'
         CH    2,=H'0'
         BNE   @@L39
         LTR   6,6 ==> fp
         BE    @@L44
         L     2,=F'-1'
         CLR   4,2 ==> ch
         BE    @@L39
@@L44    EQU   *
         LTR   6,6 ==> fp
         BNE   @@L42
         LTR   4,4 ==> ch
         BE    @@L39
@@L42    EQU   *
         L     3,156(13) ==> skipvar
         LTR   3,3
         BNE   @@L45
         L     15,112(13) ==> cptr
         STC   4,0(15) ==> ch
         A     15,=F'1'
         ST    15,112(13) ==> cptr
@@L45    EQU   *
         LTR   6,6 ==> fp
         BNE   @@L46
         SLR   4,4 ==> ch
         IC    4,0(9) ==> ch,s
         A     9,=F'1' ==> s
         B     @@L38
@@L46    EQU   *
         ST    6,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(FGETC)
         BALR  14,15
         LR    4,15 ==> ch
         B     @@L38
@@L39    EQU   *
         L     2,156(13) ==> skipvar
         LTR   2,2
         BNE   @@L48
         L     3,112(13) ==> cptr
         MVC   0(1,3),159(13) ==> skipvar
@@L48    EQU   *
         L     15,108(13) ==> cnt
         A     15,=F'1'
         ST    15,108(13) ==> cnt
         L     14,=A(@@L10)
         BR    14
@@L24    EQU   *
         CLI   0(5),173 ==> format
         BNE   @@L50
         SLR   3,3 ==> mcnt
         LR    8,3 ==> reverse,mcnt
         L     2,156(13) ==> skipvar
         LTR   2,2
         BNE   @@L51
         L     15,4(11) ==> arg
         A     15,=F'4'
         ST    15,4(11) ==> arg
         LR    2,15
         A     2,=F'-4'
         MVC   112(4,13),0(2) ==> cptr
@@L51    EQU   *
         A     5,=F'1' ==> format
         CLI   0(5),95 ==> format
         BNE   @@L52
         LA    8,1(0,0) ==> reverse
         AR    5,8 ==> format
@@L52    EQU   *
         IC    2,0(5) ==> format
         CLM   2,1,=XL1'00'
         L     14,=A(@@L7)
         BER   14
         LR    7,5 ==> first,format
         A     5,=F'1' ==> format
         ST    5,88(13) ==> format
         MVC   92(4,13),=F'189'
         LA    1,88(,13)
         L     15,=V(STRCHR)
         BALR  14,15
         LR    2,15 ==> last
         L     15,108(13) ==> cnt
         LTR   2,2 ==> last
         L     14,=A(@@L1)
         BER   14
         LR    5,2 ==> size,last
         SR    5,7 ==> size,first
@@L67    EQU   *
         ST    7,88(13) ==> first
         ST    4,92(13) ==> ch
         ST    5,96(13) ==> size
         LA    1,88(,13)
         L     15,=V(MEMCHR)
         BALR  14,15
         LTR   15,15 ==> found
         BE    @@L58
         LA    15,1(0,0) ==> found
@@L58    EQU   *
         LTR   15,15 ==> found
         BE    @@L59
         LTR   8,8 ==> reverse
         BNE   @@L56
@@L59    EQU   *
         LTR   15,15 ==> found
         BNE   @@L60
         LTR   8,8 ==> reverse
         BE    @@L56
@@L60    EQU   *
         L     15,156(13) ==> skipvar
         LTR   15,15
         BNE   @@L61
         L     15,112(13) ==> cptr
         STC   4,0(15) ==> ch
         A     15,=F'1'
         ST    15,112(13) ==> cptr
@@L61    EQU   *
         A     3,=F'1' ==> mcnt
         LTR   6,6 ==> fp
         BNE   @@L62
         SLR   4,4 ==> ch
         IC    4,0(9) ==> ch,s
         A     9,=F'1' ==> s
         B     @@L63
@@L62    EQU   *
         ST    6,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(FGETC)
         BALR  14,15
         LR    4,15 ==> ch
@@L63    EQU   *
         LTR   6,6 ==> fp
         BE    @@L66
         L     15,=F'-1'
         CLR   4,15 ==> ch
         BE    @@L56
@@L66    EQU   *
         LTR   6,6 ==> fp
         BNE   @@L67
         LTR   4,4 ==> ch
         BNE   @@L67
@@L56    EQU   *
         LTR   3,3 ==> mcnt
         L     14,=A(@@L7)
         BER   14
         L     3,156(13) ==> skipvar
         LTR   3,3
         BNE   @@L69
         L     15,112(13) ==> cptr
         MVC   0(1,15),159(13) ==> skipvar
         A     15,=F'1'
         ST    15,112(13) ==> cptr
@@L69    EQU   *
         L     3,108(13) ==> cnt
         A     3,=F'1'
         ST    3,108(13) ==> cnt
         LR    5,2 ==> format,last
         A     5,=F'1' ==> format
         L     14,=A(@@L10)
         BR    14
@@L50    EQU   *
         CLI   0(5),131 ==> format
         BNE   @@L72
         L     15,156(13) ==> skipvar
         LTR   15,15
         BNE   @@L73
         L     2,4(11) ==> arg
         A     2,=F'4'
         ST    2,4(11) ==> arg
         A     2,=F'-4'
         MVC   112(4,13),0(2) ==> cptr
@@L73    EQU   *
         LTR   6,6 ==> fp
         BE    @@L76
         L     3,=F'-1'
         CLR   4,3 ==> ch
         L     14,=A(@@L10)
         BER   14
@@L76    EQU   *
         LTR   6,6 ==> fp
         BNE   @@L74
         LTR   4,4 ==> ch
         L     14,=A(@@L10)
         BER   14
@@L74    EQU   *
         L     15,156(13) ==> skipvar
         LTR   15,15
         BNE   @@L78
         L     2,112(13) ==> cptr
         STC   4,0(2) ==> ch
@@L78    EQU   *
         L     3,108(13) ==> cnt
         A     3,=F'1'
         ST    3,108(13) ==> cnt
         L     14,=A(@@L269)
         BR    14
@@L72    EQU   *
         CLI   0(5),149 ==> format
         BNE   @@L82
         L     15,4(11) ==> arg
         A     15,=F'4'
         ST    15,4(11) ==> arg
         LR    2,15
         A     2,=F'-4'
         MVC   120(4,13),0(2) ==> uptr
         LTR   6,6 ==> fp
         BE    @@L83
         ST    6,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(FTELL)
         BALR  14,15
         S     15,148(13) ==> startpos
         L     2,120(13) ==> uptr
         ST    15,0(2)
         L     14,=A(@@L10)
         BR    14
@@L83    EQU   *
         LR    2,9 ==> s
         S     2,152(13) ==> startp
         BCTR  2,0
         L     3,120(13) ==> uptr
         ST    2,0(3)
         L     14,=A(@@L10)
         BR    14
@@L82    EQU   *
         IC    2,0(5) ==> format
         CLM   2,1,=XL1'84'
         BE    @@L87
         CLM   2,1,=XL1'A4'
         BE    @@L87
         CLM   2,1,=XL1'A7'
         BE    @@L87
         CLM   2,1,=XL1'96'
         BE    @@L87
         CLM   2,1,=XL1'97'
         BE    @@L87
         CLM   2,1,=XL1'89'
         L     14,=A(@@L86)
         BNER  14
@@L87    EQU   *
         SLR   7,7 ==> x
         ST    7,172(13) ==> x,neg
         ST    7,176(13) ==> x,undecided
         LA    8,10(0,0) ==> base
         ST    7,180(13) ==> x,mcnt
         CLI   0(5),167 ==> format
         BE    @@L258
         CLI   0(5),151 ==> format
         BNE   @@L90
@@L258   EQU   *
         LA    8,16(0,0) ==> base
         B     @@L89
@@L90    EQU   *
         CLI   0(5),150 ==> format
         BNE   @@L92
         LA    8,8(0,0) ==> base
         B     @@L89
@@L92    EQU   *
         CLI   0(5),137 ==> format
         BNE   @@L89
         SLR   8,8 ==> base
@@L89    EQU   *
         L     15,156(13) ==> skipvar
         LTR   15,15
         BNE   @@L95
         IC    2,0(5) ==> format
         CLM   2,1,=XL1'84'
         BE    @@L97
         CLM   2,1,=XL1'89'
         BNE   @@L96
@@L97    EQU   *
         L     2,160(13) ==> modlong
         LTR   2,2
         BE    @@L98
         L     3,4(11) ==> arg
         A     3,=F'4'
         ST    3,4(11) ==> arg
         LR    2,3
         A     2,=F'-4'
         MVC   124(4,13),0(2) ==> lptr
         B     @@L95
@@L98    EQU   *
         L     15,164(13) ==> modshort
         LTR   15,15
         BE    @@L100
         L     2,4(11) ==> arg
         A     2,=F'4'
         ST    2,4(11) ==> arg
         A     2,=F'-4'
         MVC   132(4,13),0(2) ==> hptr
         B     @@L95
@@L100   EQU   *
         L     3,4(11) ==> arg
         A     3,=F'4'
         ST    3,4(11) ==> arg
         LR    2,3
         A     2,=F'-4'
         MVC   116(4,13),0(2) ==> iptr
         B     @@L95
@@L96    EQU   *
         L     15,160(13) ==> modlong
         LTR   15,15
         BE    @@L103
         L     2,4(11) ==> arg
         A     2,=F'4'
         ST    2,4(11) ==> arg
         A     2,=F'-4'
         MVC   128(4,13),0(2) ==> luptr
         B     @@L95
@@L103   EQU   *
         L     3,164(13) ==> modshort
         LTR   3,3
         BE    @@L105
         L     15,4(11) ==> arg
         A     15,=F'4'
         ST    15,4(11) ==> arg
         LR    2,15
         A     2,=F'-4'
         MVC   136(4,13),0(2) ==> huptr
         B     @@L95
@@L105   EQU   *
         L     2,4(11) ==> arg
         A     2,=F'4'
         ST    2,4(11) ==> arg
         A     2,=F'-4'
         MVC   120(4,13),0(2) ==> uptr
@@L95    EQU   *
         LTR   4,4 ==> ch
         BL    @@L108
         L     2,=V(@@ISBUF)
         L     3,0(2) ==> __isbuf
         LR    2,4 ==> ch
         MH    2,=H'2'
         LH    2,0(2,3)
         N     2,=F'256'
         CH    2,=H'0'
         BE    @@L108
@@L113   EQU   *
         LTR   6,6 ==> fp
         BNE   @@L111
         SLR   4,4 ==> ch
         IC    4,0(9) ==> ch,s
         A     9,=F'1' ==> s
         B     @@L107
@@L111   EQU   *
         ST    6,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(FGETC)
         BALR  14,15
         LR    4,15 ==> ch
@@L107   EQU   *
         LTR   4,4 ==> ch
         BL    @@L108
         L     2,=V(@@ISBUF)
         L     3,0(2) ==> __isbuf
         LR    2,4 ==> ch
         MH    2,=H'2'
         LH    2,0(2,3)
         N     2,=F'256'
         CH    2,=H'0'
         BNE   @@L113
@@L108   EQU   *
         LA    3,96(0,0)
         CLR   4,3 ==> ch
         BNE   @@L114
         MVC   172(4,13),=F'1' ==> neg
         B     @@L266
@@L114   EQU   *
         LA    15,78(0,0)
         CLR   4,15 ==> ch
         BNE   @@L117
@@L266   EQU   *
         LTR   6,6 ==> fp
         BNE   @@L119
         SLR   4,4 ==> ch
         IC    4,0(9) ==> ch,s
         A     9,=F'1' ==> s
         B     @@L117
@@L119   EQU   *
         ST    6,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(FGETC)
         BALR  14,15
         LR    4,15 ==> ch
@@L117   EQU   *
         LTR   8,8 ==> base
         BNE   @@L122
         MVC   176(4,13),=F'1' ==> undecided
         B     @@L122
@@L152   EQU   *
         LR    2,4
         N     2,=XL4'000000FF' ==> ch
         L     3,=V(@@ISBUF)
         L     3,0(3) ==> __isbuf
         MH    2,=H'2'
         LH    2,0(2,3)
         N     2,=F'8'
         CH    2,=H'0'
         BE    @@L127
         LTR   8,8 ==> base
         BNE   @@L128
         LA    8,8(0,0) ==> base
         LA    2,240(0,0)
         CLR   4,2 ==> ch
         BE    @@L128
         LA    8,10(0,0) ==> base
         MVC   176(4,13),=F'0' ==> undecided
@@L128   EQU   *
         ST    8,188(13) ==> base
         L     2,184(13)
         L     3,4+184(13)
         MR    2,7 ==> x
         ST    2,184(13)
         ST    3,4+184(13)
         L     7,188(13) ==> x
         AR    7,4 ==> x,ch
         A     7,=F'-240' ==> x
         B     @@L267
@@L127   EQU   *
         LR    2,4
         N     2,=XL4'000000FF' ==> ch
         L     3,=V(@@ISBUF)
         L     3,0(3) ==> __isbuf
         MH    2,=H'2'
         LH    2,0(2,3)
         N     2,=F'2'
         CH    2,=H'0'
         BE    @@L123
         LA    3,231(0,0)
         CLR   4,3 ==> ch
         BE    @@L136
         LA    15,167(0,0)
         CLR   4,15 ==> ch
         BNE   @@L135
@@L136   EQU   *
         LTR   8,8 ==> base
         BE    @@L138
         LA    2,8(0,0)
         CLR   8,2 ==> base
         BNE   @@L137
         L     3,176(13) ==> undecided
         LTR   3,3
         BE    @@L137
@@L138   EQU   *
         LA    8,16(0,0) ==> base
         MVC   176(4,13),=F'0' ==> undecided
         B     @@L267
@@L137   EQU   *
         LA    15,16(0,0)
         CLR   8,15 ==> base
         BNE   @@L123
         B     @@L267
@@L135   EQU   *
         LA    2,10(0,0)
         CR    8,2 ==> base
         BNH   @@L123
         ST    8,196(13) ==> base
         L     2,192(13)
         L     3,4+192(13)
         MR    2,7 ==> x
         ST    2,192(13)
         ST    3,4+192(13)
         LR    2,4
         N     2,=XL4'000000FF' ==> ch
         L     3,=V(@@TOUP)
         L     3,0(3) ==> __toup
         MH    2,=H'2'
         LH    2,0(2,3)
         L     7,196(13) ==> x
         AR    7,2 ==> x
         A     7,=F'-183' ==> x
@@L267   EQU   *
         LTR   6,6 ==> fp
         BNE   @@L149
         SLR   4,4 ==> ch
         IC    4,0(9) ==> ch,s
         A     9,=F'1' ==> s
         B     @@L133
@@L149   EQU   *
         ST    6,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(FGETC)
         BALR  14,15
         LR    4,15 ==> ch
@@L133   EQU   *
         L     3,180(13) ==> mcnt
         A     3,=F'1'
         ST    3,180(13) ==> mcnt
@@L122   EQU   *
         LTR   6,6 ==> fp
         BE    @@L126
         L     15,=F'-1'
         CLR   4,15 ==> ch
         BE    @@L123
@@L126   EQU   *
         LTR   6,6 ==> fp
         BNE   @@L152
         LTR   4,4 ==> ch
         BNE   @@L152
@@L123   EQU   *
         L     2,180(13) ==> mcnt
         LTR   2,2
         L     14,=A(@@L7)
         BER   14
         L     3,156(13) ==> skipvar
         LTR   3,3
         L     14,=A(@@L229)
         BNER  14
         IC    2,0(5) ==> format
         CLM   2,1,=XL1'84'
         BE    @@L156
         CLM   2,1,=XL1'89'
         BNE   @@L155
@@L156   EQU   *
         LCR   2,7 ==> lval,x
         L     15,172(13) ==> neg
         LTR   15,15
         BNE   @@L158
         LR    2,7 ==> lval,x
@@L158   EQU   *
         L     3,160(13) ==> modlong
         LTR   3,3
         BE    @@L159
         L     15,124(13) ==> lptr
         ST    2,0(15) ==> lval
         L     14,=A(@@L229)
         BR    14
@@L159   EQU   *
         L     3,164(13) ==> modshort
         LTR   3,3
         BE    @@L161
         L     15,132(13) ==> hptr
         STH   2,0(15) ==> lval
         L     14,=A(@@L229)
         BR    14
@@L161   EQU   *
         L     3,116(13) ==> iptr
         ST    2,0(3) ==> lval
         L     14,=A(@@L229)
         BR    14
@@L155   EQU   *
         L     15,160(13) ==> modlong
         LTR   15,15
         BE    @@L164
         L     2,128(13) ==> luptr
         B     @@L261
@@L164   EQU   *
         L     3,164(13) ==> modshort
         LTR   3,3
         BE    @@L166
         L     15,136(13) ==> huptr
         STH   7,0(15) ==> x
         L     14,=A(@@L229)
         BR    14
@@L166   EQU   *
         L     2,120(13) ==> uptr
@@L261   EQU   *
         ST    7,0(2) ==> x
         L     14,=A(@@L229)
         BR    14
@@L86    EQU   *
         IC    15,0(5) ==> format
         LA    2,123(,15)
         CLM   2,1,=XL1'02'
         BNH   @@L170
         CLM   15,1,=XL1'C5'
         BE    @@L170
         CLM   15,1,=XL1'C7'
         L     14,=A(@@L10)
         BNER  14
@@L170   EQU   *
         L     2,156(13) ==> skipvar
         LTR   2,2
         BNE   @@L171
         L     3,160(13) ==> modlong
         LTR   3,3
         BE    @@L172
         L     15,4(11) ==> arg
         A     15,=F'4'
         ST    15,4(11) ==> arg
         LR    2,15
         A     2,=F'-4'
         MVC   140(4,13),0(2) ==> dptr
         B     @@L171
@@L172   EQU   *
         L     2,4(11) ==> arg
         A     2,=F'4'
         ST    2,4(11) ==> arg
         A     2,=F'-4'
         MVC   144(4,13),0(2) ==> fptr
@@L171   EQU   *
         MVC   200(4,13),=F'0' ==> negsw1
         MVC   204(4,13),200(13) ==> negsw2,negsw1
         MVC   208(4,13),200(13) ==> dotsw,negsw1
         MVC   212(4,13),200(13) ==> expsw,negsw1
         MVC   216(4,13),200(13) ==> ndigs1,negsw1
         MVC   220(4,13),200(13) ==> ndigs2,negsw1
         MVC   224(4,13),200(13) ==> nfdigs,negsw1
         SLR   7,7 ==> ntrailzer
         SLR   8,8 ==> expnum
         ST    7,228(13) ==> expsignsw
         LD    0,=D'0.0E0'
         STD   0,232(13) ==> fpval
         LTR   4,4 ==> ch
         BL    @@L175
         L     2,=V(@@ISBUF)
         L     3,0(2) ==> __isbuf
         LR    2,4 ==> ch
         MH    2,=H'2'
         LH    2,0(2,3)
         N     2,=F'256'
         CH    2,=H'0'
         BE    @@L175
@@L180   EQU   *
         LTR   6,6 ==> fp
         BNE   @@L178
         SLR   4,4 ==> ch
         IC    4,0(9) ==> ch,s
         A     9,=F'1' ==> s
         B     @@L174
@@L178   EQU   *
         ST    6,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(FGETC)
         BALR  14,15
         LR    4,15 ==> ch
@@L174   EQU   *
         LTR   4,4 ==> ch
         BL    @@L175
         L     2,=V(@@ISBUF)
         L     3,0(2) ==> __isbuf
         LR    2,4 ==> ch
         MH    2,=H'2'
         LH    2,0(2,3)
         N     2,=F'256'
         CH    2,=H'0'
         BNE   @@L180
@@L175   EQU   *
         LA    2,96(0,0)
         CLR   4,2 ==> ch
         BNE   @@L181
         MVC   200(4,13),=F'1' ==> negsw1
         B     @@L268
@@L181   EQU   *
         LA    3,78(0,0)
         CLR   4,3 ==> ch
         BNE   @@L184
@@L268   EQU   *
         LTR   6,6 ==> fp
         BNE   @@L186
         SLR   4,4 ==> ch
         IC    4,0(9) ==> ch,s
         A     9,=F'1' ==> s
         B     @@L184
@@L186   EQU   *
         ST    6,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(FGETC)
         BALR  14,15
         LR    4,15 ==> ch
@@L184   EQU   *
         LTR   4,4 ==> ch
         L     14,=A(@@L189)
         BNHR  14
@@L214   EQU   *
         L     12,0(,10)
         LA    15,75(0,0)
         CLR   4,15 ==> ch
         BNE   @@L191
         L     2,208(13) ==> dotsw
         LTR   2,2
         BNE   @@L191
         L     3,212(13) ==> expsw
         LTR   3,3
         BNE   @@L191
         MVC   208(4,13),=F'1' ==> dotsw
         L     14,=A(@@L192)
         BR    14
@@L191   EQU   *
         L     2,=V(@@ISBUF)
         L     3,0(2) ==> __isbuf
         LR    2,4 ==> ch
         MH    2,=H'2'
         LH    2,0(2,3)
         N     2,=F'8'
         CH    2,=H'0'
         L     14,=A(@@L193)
         BER   14
         L     15,212(13) ==> expsw
         LTR   15,15
         BE    @@L194
         L     2,220(13) ==> ndigs2
         A     2,=F'1'
         ST    2,220(13) ==> ndigs2
         LR    2,8 ==> expnum
         SLL   2,3
         AR    2,8 ==> expnum
         AR    2,8 ==> expnum
         AR    2,4 ==> ch
         LR    8,2 ==> expnum
         A     8,=F'-240' ==> expnum
         L     14,=A(@@L192)
         BR    14
@@L194   EQU   *
         L     3,216(13) ==> ndigs1
         A     3,=F'1'
         ST    3,216(13) ==> ndigs1
         L     15,208(13) ==> dotsw
         LTR   15,15
         BE    @@L196
         L     2,224(13) ==> nfdigs
         A     2,=F'1'
         ST    2,224(13) ==> nfdigs
@@L196   EQU   *
         LA    3,240(0,0)
         CLR   4,3 ==> ch
         BNE   @@L197
         LD    0,232(13) ==> fpval
         LTDR  0,0
         BE    @@L197
         A     7,=F'1' ==> ntrailzer
         L     14,=A(@@L192)
         BR    14
@@L197   EQU   *
         LTR   7,7 ==> ntrailzer
         BNH   @@L253
@@L203   EQU   *
         LD    2,232(13) ==> fpval
         MD    2,=D'1.0E1'
         STD   2,232(13) ==> fpval
         BCTR  7,0 ==> ntrailzer
         LTR   7,7 ==> ntrailzer
         BH    @@L203
@@L253   EQU   *
         LD    0,232(13) ==> fpval
         MD    0,=D'1.0E1'
         STD   0,232(13) ==> fpval
         LR    2,4 ==> ch
         A     2,=F'-240'
         MVC   80(4,13),=XL8'4E00000080000000'
         ST    2,84(,13)
         XI    84(13),128
         LD    0,80(,13)
         SD    0,=XL8'4E00000080000000'
         AD    0,232(13) ==> fpval
         STD   0,232(13) ==> fpval
         L     14,=A(@@L192)
         BR    14
@@L193   EQU   *
         LA    2,133(0,0)
         CLR   4,2 ==> ch
         BE    @@L206
         LA    3,197(0,0)
         CLR   4,3 ==> ch
         BNE   @@L205
@@L206   EQU   *
         L     15,212(13) ==> expsw
         LTR   15,15
         BNE   @@L205
         MVC   212(4,13),=F'1' ==> expsw
         B     @@L192
@@L205   EQU   *
         LA    2,78(0,0)
         CLR   4,2 ==> ch
         BE    @@L209
         LA    3,96(0,0)
         CLR   4,3 ==> ch
         L     14,=A(@@L189)
         BNER  14
@@L209   EQU   *
         L     2,212(13) ==> expsw
         LA    15,1(0,0)
         CLR   2,15
         L     14,=A(@@L189)
         BNER  14
         L     3,220(13) ==> ndigs2
         LTR   3,3
         L     14,=A(@@L189)
         BNER  14
         L     15,228(13) ==> expsignsw
         LTR   15,15
         BNE   @@L189
         ST    2,228(13) ==> expsignsw
         LA    2,96(0,0)
         CLR   4,2 ==> ch
         BNE   @@L192
         MVC   204(4,13),212(13) ==> negsw2,expsw
@@L192   EQU   *
         LTR   6,6 ==> fp
         BNE   @@L212
         SLR   4,4 ==> ch
         IC    4,0(9) ==> ch,s
         A     9,=F'1' ==> s
         B     @@L188
@@L212   EQU   *
         ST    6,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(FGETC)
         BALR  14,15
         LR    4,15 ==> ch
@@L188   EQU   *
         LTR   4,4 ==> ch
         BH    @@L214
@@L189   EQU   *
         L     3,216(13) ==> ndigs1
         LTR   3,3
         L     14,=A(@@L246)
         BER   14
         L     15,212(13) ==> expsw
         LTR   15,15
         BE    @@L215
         L     2,220(13) ==> ndigs2
         LTR   2,2
         L     14,=A(@@L246)
         BER   14
@@L215   EQU   *
         L     3,204(13) ==> negsw2
         LTR   3,3
         BE    @@L217
         LCR   8,8 ==> expnum
@@L217   EQU   *
         LR    2,7 ==> ntrailzer
         S     2,224(13) ==> nfdigs
         AR    8,2 ==> expnum
         L     14,=A(@@L218)
         BER   14
         LD    0,232(13) ==> fpval
         LTDR  0,0
         L     14,=A(@@L218)
         BER   14
         MVC   204(4,13),=F'0' ==> negsw2
         LTR   8,8 ==> expnum
         BNL   @@L220
         LCR   8,8 ==> expnum
         MVC   204(4,13),=F'1' ==> negsw2
@@L220   EQU   *
         LD    0,=D'1.0E1' ==> pow10
@@L221   EQU   *
         L     12,0(,10)
         LR    2,8 ==> expnum
         N     2,=F'1'
         LTR   2,2
         L     14,=A(@@L224)
         BER   14
         L     2,204(13) ==> negsw2
         LTR   2,2
         B     @@PGE0
         DS    0F
         LTORG
         DS    0F
@@PGE0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         BE    @@L225
         LD    2,232(13) ==> fpval
         DDR   2,0 ==> pow10
         B     @@L263
@@L225   EQU   *
         L     12,4(,10)
         LD    2,232(13) ==> fpval
         MDR   2,0 ==> pow10
@@L263   EQU   *
         L     12,4(,10)
         STD   2,232(13) ==> fpval
@@L224   EQU   *
         L     12,4(,10)
         SRA   8,1 ==> expnum
         BE    @@L218
         MDR   0,0 ==> pow10
         L     14,=A(@@L221)
         BR    14
@@L218   EQU   *
         L     12,4(,10)
         L     2,200(13) ==> negsw1
         LTR   2,2
         BE    @@L228
         LD    0,232(13) ==> fpval
         LCDR  0,0
         STD   0,232(13) ==> fpval
@@L228   EQU   *
         L     12,4(,10)
         L     2,156(13) ==> skipvar
         LTR   2,2
         BNE   @@L229
         L     3,160(13) ==> modlong
         LTR   3,3
         BE    @@L230
         LD    0,232(13) ==> fpval
         L     15,140(13) ==> dptr
         STD   0,0(15)
         B     @@L229
@@L230   EQU   *
         L     12,4(,10)
         LD    2,232(13) ==> fpval
         LRER  0,2
         L     2,144(13) ==> fptr
         STE   0,0(2)
@@L229   EQU   *
         L     12,4(,10)
         L     3,108(13) ==> cnt
         A     3,=F'1'
         ST    3,108(13) ==> cnt
         B     @@L10
@@L11    EQU   *
         L     12,4(,10)
         SLR   2,2
         IC    2,0(5) ==> format
         L     3,=V(@@ISBUF)
         L     3,0(3) ==> __isbuf
         MH    2,=H'2'
         LH    2,0(2,3)
         N     2,=F'256'
         CH    2,=H'0'
         BE    @@L233
         LTR   4,4 ==> ch
         BL    @@L10
         LR    2,4 ==> ch
         MH    2,=H'2'
         LH    2,0(2,3)
         N     2,=F'256'
         CH    2,=H'0'
         BE    @@L10
@@L240   EQU   *
         L     12,4(,10)
         LTR   6,6 ==> fp
         BNE   @@L238
         SLR   4,4 ==> ch
         IC    4,0(9) ==> ch,s
         A     9,=F'1' ==> s
         B     @@L234
@@L238   EQU   *
         L     12,4(,10)
         ST    6,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(FGETC)
         BALR  14,15
         LR    4,15 ==> ch
@@L234   EQU   *
         L     12,4(,10)
         LTR   4,4 ==> ch
         BL    @@L10
         L     2,=V(@@ISBUF)
         L     3,0(2) ==> __isbuf
         LR    2,4 ==> ch
         MH    2,=H'2'
         LH    2,0(2,3)
         N     2,=F'256'
         CH    2,=H'0'
         BNE   @@L240
         B     @@L10
@@L233   EQU   *
         L     12,4(,10)
         SLR   2,2
         IC    2,0(5) ==> format
         L     15,108(13) ==> cnt
         CLR   4,2 ==> ch
         BNE   @@L1
@@L269   EQU   *
         L     12,4(,10)
         LTR   6,6 ==> fp
         BNE   @@L243
         SLR   4,4 ==> ch
         IC    4,0(9) ==> ch,s
         A     9,=F'1' ==> s
         B     @@L10
@@L243   EQU   *
         L     12,4(,10)
         ST    6,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(FGETC)
         BALR  14,15
         LR    4,15 ==> ch
@@L10    EQU   *
         L     12,4(,10)
         A     5,=F'1' ==> format
@@L6     EQU   *
         L     12,4(,10)
         L     15,104(13) ==> fin
         LTR   15,15
         L     14,=A(@@L245)
         BER   14
@@L7     EQU   *
         L     12,4(,10)
         LTR   6,6 ==> fp
         BE    @@L246
         ST    4,88(13) ==> ch
         ST    6,92(13) ==> fp
         LA    1,88(,13)
         L     15,=V(UNGETC)
         BALR  14,15
@@L246   EQU   *
         L     12,4(,10)
         L     15,108(13) ==> cnt
@@L1     EQU   *
         L     12,4(,10)
* Function 'vvscanf' epilogue
         PDPEPIL
* Function 'vvscanf' literal pool
         DS    0D
         LTORG
* Function 'vvscanf' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         DC    A(@@PG1)
         END
