 TITLE '/home/mike/repos/crent370/clib/@@dblcvt.c'
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
* external function '__dblcvt' prologue
* frame base=88, local stack=200, call args=8
&FUNC    SETC  '__dblcvt'
@@DBLCVT PDPPRLG CINDEX=0,FRAME=296,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__dblcvt' code
         SLR   2,2
         SLR   3,3
         ST    2,232(13)
         ST    3,4+232(13)
         ST    2,240(13)
         ST    3,4+240(13)
         ST    2,248(13)
         ST    3,4+248(13)
         ST    2,256(13)
         ST    3,4+256(13)
         ST    2,264(13)
         ST    3,4+264(13)
         LR    8,2 ==> i
         LR    9,3 ==> i
         ST    2,272(13) ==> i
         ST    3,4+272(13) ==> i
         ST    2,280(13) ==> i
         ST    3,4+280(13) ==> i
         ST    2,288(13) ==> i
         ST    3,4+288(13) ==> i
         LD    0,0(11) ==> num
         MVC   224(1,13),11(11) ==> cnvtype
         LTDR  0,0 ==> num
         BNL   @@L2
         LCDR  0,0 ==> num
         STD   0,80(,13)
         LM    4,5,80(13) ==> b
         LA    15,96(0,0) ==> sign
         B     @@L4
@@L2     EQU   *
         STD   0,80(,13) ==> num
         LM    4,5,80(13) ==> b
         LA    15,64(0,0) ==> sign
@@L4     EQU   *
         SLR   7,7 ==> exp
         STM   4,5,80(13) ==> b
         LD    0,80(,13)
         CD    0,=D'1.0E0'
         BNH   @@L5
         CD    0,=D'1.0E1'
         BL    @@L13
@@L12    EQU   *
         A     7,=F'1' ==> exp
         STM   4,5,80(13) ==> b
         LD    2,80(,13)
         DD    2,=D'1.0E1'
         STD   2,80(,13)
         LM    4,5,80(13) ==> b
         CD    2,=D'1.0E1'
         BL    @@L13
         LA    2,119(0,0)
         CR    7,2 ==> exp
         BNH   @@L12
         B     @@L13
@@L5     EQU   *
         STM   4,5,80(13) ==> b
         LD    0,80(,13)
         LTDR  0,0
         BNE   @@L14
         SLR   7,7 ==> exp
         B     @@L13
@@L14    EQU   *
         CD    0,=D'1.0E0'
         BNL   @@L13
         BNL   @@L13
         L     2,=F'-120'
         CR    7,2 ==> exp
         BNH   @@L13
@@L24    EQU   *
         BCTR  7,0 ==> exp
         STM   4,5,80(13) ==> b
         LD    0,80(,13)
         MD    0,=D'1.0E1'
         STD   0,80(,13)
         LM    4,5,80(13) ==> b
         CD    0,=D'1.0E0'
         BNL   @@L13
         L     2,=F'-120'
         CR    7,2 ==> exp
         BH    @@L24
@@L13    EQU   *
         LR    2,7 ==> exp
         A     2,=F'119'
         LA    3,238(0,0)
         CLR   2,3
         BNH   @@L25
         SLR   7,7 ==> exp
         LM    4,5,=D'0.0E0' ==> b
@@L25    EQU   *
         SLR   2,2 ==> cnvtype
         IC    2,224(13) ==> cnvtype
         LA    6,134(0,0)
         CR    2,6 ==> cnvtype
         BE    @@L30
         BH    @@L41
         LA    3,133(0,0)
         CLR   2,3 ==> cnvtype
         BE    @@L131
         B     @@L33
@@L41    EQU   *
         LA    6,197(0,0)
         CLR   2,6 ==> cnvtype
         BE    @@L131
         LA    3,198(0,0)
         CR    2,3 ==> cnvtype
         BNE   @@L33
@@L30    EQU   *
         MVC   228(4,13),=F'1' ==> format
         LTR   7,7 ==> exp
         BNL   @@L26
         MVC   228(4,13),=F'-1' ==> format
         B     @@L26
@@L33    EQU   *
         LTR   7,7 ==> exp
         BL    @@L34
         MVC   228(4,13),=F'1' ==> format
         L     6,16(11) ==> nprecision
         CR    6,7 ==> exp
         BH    @@L26
         B     @@L131
@@L34    EQU   *
         MVC   228(4,13),=F'-1' ==> format
         L     2,=F'-4'
         CR    7,2 ==> exp
         BNL   @@L26
@@L131   EQU   *
         MVC   228(4,13),=F'0' ==> format
@@L26    EQU   *
         L     3,228(13) ==> format
         LTR   3,3
         BE    @@L43
         BH    @@L74
         L     6,=F'-1'
         CLR   3,6
         BE    @@L61
         B     @@L42
@@L74    EQU   *
         L     3,228(13) ==> format
         LA    2,1(0,0)
         CLR   3,2
         BE    @@L52
         B     @@L42
@@L43    EQU   *
         L     3,16(11) ==> j,nprecision
         LA    6,13(0,0)
         CR    3,6 ==> j
         BNH   @@L45
         LA    3,14(0,0) ==> j
@@L45    EQU   *
         LD    0,=D'5.0E-1' ==> round
         LA    6,1(0,0) ==> i
         CR    6,3 ==> i,j
         BH    @@L119
@@L49    EQU   *
         DD    0,=D'1.0E1' ==> round
         A     6,=F'1' ==> i
         CR    6,3 ==> i,j
         BNH   @@L49
         B     @@L119
@@L52    EQU   *
         L     2,16(11) ==> j,nprecision
         AR    2,7 ==> j,exp
         LR    3,2 ==> j
         LA    6,13(0,0)
         CR    2,6 ==> j
         BNH   @@L54
         LA    3,14(0,0) ==> j
@@L54    EQU   *
         LD    0,=D'5.0E-1' ==> round
         LA    6,1(0,0) ==> i
         LTR   3,3 ==> j
         BNH   @@L119
@@L58    EQU   *
         DD    0,=D'1.0E1' ==> round
         LR    2,6 ==> i
         A     6,=F'1' ==> i
         CR    2,3 ==> i,j
         BL    @@L58
@@L119   EQU   *
         STM   4,5,80(13) ==> b
         LD    2,80(,13)
         ADR   2,0 ==> round
         STD   2,80(,13)
         LM    4,5,80(13) ==> b
         CD    2,=D'1.0E1'
         BL    @@L42
         DD    2,=D'1.0E1'
         STD   2,80(,13)
         LM    4,5,80(13) ==> b
         A     7,=F'1' ==> exp
         B     @@L42
@@L61    EQU   *
         L     3,16(11) ==> nprecision
         LA    2,13(0,0)
         CR    3,2
         BH    @@L62
         AR    3,7 ==> j,exp
         A     3,=F'1' ==> j
         B     @@L63
@@L62    EQU   *
         LA    3,14(0,0) ==> j
@@L63    EQU   *
         LD    0,=D'5.0E0' ==> round
         LA    6,1(0,0) ==> i
         LTR   3,3 ==> j
         BNH   @@L121
@@L67    EQU   *
         DD    0,=D'1.0E1' ==> round
         LR    2,6 ==> i
         A     6,=F'1' ==> i
         CR    2,3 ==> i,j
         BL    @@L67
@@L121   EQU   *
         LTR   3,3 ==> j
         BL    @@L68
         STM   4,5,80(13) ==> b
         LD    2,80(,13)
         ADR   2,0 ==> round
         STD   2,80(,13)
         LM    4,5,80(13) ==> b
@@L68    EQU   *
         STM   4,5,80(13) ==> b
         LD    0,80(,13)
         CD    0,=D'1.0E1'
         BL    @@L69
         DD    0,=D'1.0E1'
         STD   0,80(,13)
         LM    4,5,80(13) ==> b
         A     7,=F'1' ==> exp
@@L69    EQU   *
         LTR   7,7 ==> exp
         BL    @@L42
         MVC   228(4,13),=F'1' ==> format
@@L42    EQU   *
         L     3,228(13) ==> format
         L     2,=F'-1'
         CLR   3,2
         BNE   @@L75
         L     6,20(11) ==> result
         STC   15,0(6) ==> sign
         MVI   1(6),240
         MVI   2(6),75
         MVI   3(6),0
         A     7,=F'1' ==> exp
         BE    @@L123
@@L79    EQU   *
         L     8,16(11) ==> nprecision
         BCTR  8,0
         ST    8,16(11) ==> nprecision
         MVC   88(4,13),20(11) ==> result
         MVC   92(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(STRCAT)
         BALR  14,15
         A     7,=F'1' ==> exp
         BNE   @@L79
@@L123   EQU   *
         STM   4,5,80(13) ==> b
         LD    2,80(,13)
         LDR   0,2
         AD    0,=XL8'4F08000000000000'
         STD   0,80(,13)
         L     6,84(,13) ==> i
         L     2,16(11) ==> nprecision
         BCTR  2,0
         ST    2,16(11) ==> nprecision
         ST    6,232(13) ==> i
         L     8,232(13)
         L     9,4+232(13)
         SRDA  8,32
         LA    15,10(0,0)
         DR    8,15
         LA    2,240(,8)
         STC   2,96(13) ==> work
         MVI   97(13),0 ==> work
         MVC   88(4,13),20(11) ==> result
         LA    2,96(,13)
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(STRCAT)
         BALR  14,15
         L     3,16(11) ==> pdigits,nprecision
         BCTR  3,0 ==> pdigits
         L     2,16(11) ==> nprecision
         LTR   2,2
         BNH   @@L84
@@L83    EQU   *
         MVC   80(4,13),=XL8'4E00000080000000'
         ST    6,84(,13) ==> i
         XI    84(13),128
         LD    0,80(,13)
         SD    0,=XL8'4E00000080000000'
         STM   4,5,80(13) ==> b
         LD    2,80(,13)
         SDR   2,0
         MD    2,=D'1.0E1'
         STD   2,80(,13)
         LM    4,5,80(13) ==> b
         LDR   0,2
         AD    0,=XL8'4F08000000000000'
         STD   0,80(,13)
         L     6,84(,13) ==> i
         ST    6,240(13) ==> i
         L     8,240(13)
         L     9,4+240(13)
         SRDA  8,32
         LA    15,10(0,0)
         DR    8,15
         ST    8,240(13)
         ST    9,4+240(13)
         LA    2,240(,8)
         STC   2,96(13) ==> work
         MVI   97(13),0 ==> work
         MVC   88(4,13),20(11) ==> result
         LA    2,96(,13)
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(STRCAT)
         BALR  14,15
         LR    2,3 ==> pdigits
         BCTR  3,0 ==> pdigits
         LTR   2,2 ==> pdigits
         BNH   @@L84
         B     @@L83
@@L75    EQU   *
         L     3,228(13) ==> format
         LA    2,1(0,0)
         CLR   3,2
         BNE   @@L85
         STM   4,5,80(13) ==> b
         LD    2,80(,13)
         LDR   0,2
         AD    0,=XL8'4F08000000000000'
         STD   0,80(,13)
         L     6,84(,13) ==> i
         L     2,20(11) ==> result
         STC   15,0(2) ==> sign
         MVI   1(2),0
         ST    6,248(13) ==> i
         L     8,248(13)
         L     9,4+248(13)
         SRDA  8,32
         LA    15,10(0,0)
         DR    8,15
         LA    2,240(,8)
         STC   2,96(13) ==> work
         MVI   97(13),0 ==> work
         MVC   88(4,13),20(11) ==> result
         LA    2,96(,13)
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(STRCAT)
         BALR  14,15
         L     3,16(11) ==> pdigits,nprecision
         AR    3,7 ==> pdigits,exp
         ST    3,16(11) ==> pdigits,nprecision
         BCTR  3,0 ==> pdigits
         L     2,16(11) ==> nprecision
         LTR   2,2
         BNH   @@L84
@@L90    EQU   *
         L     2,16(11) ==> nprecision
         SR    2,3 ==> pdigits
         BCTR  2,0
         CLR   2,7 ==> exp
         BNE   @@L89
         MVC   88(4,13),20(11) ==> result
         MVC   92(4,13),=A(@@LC1)
         LA    1,88(,13)
         L     15,=V(STRCAT)
         BALR  14,15
@@L89    EQU   *
         MVC   80(4,13),=XL8'4E00000080000000'
         ST    6,84(,13) ==> i
         XI    84(13),128
         LD    0,80(,13)
         SD    0,=XL8'4E00000080000000'
         STM   4,5,80(13) ==> b
         LD    2,80(,13)
         SDR   2,0
         MD    2,=D'1.0E1'
         STD   2,80(,13)
         LM    4,5,80(13) ==> b
         LDR   0,2
         AD    0,=XL8'4F08000000000000'
         STD   0,80(,13)
         L     6,84(,13) ==> i
         ST    6,256(13) ==> i
         L     8,256(13)
         L     9,4+256(13)
         SRDA  8,32
         LA    15,10(0,0)
         DR    8,15
         ST    8,256(13)
         ST    9,4+256(13)
         LA    2,240(,8)
         STC   2,96(13) ==> work
         MVI   97(13),0 ==> work
         MVC   88(4,13),20(11) ==> result
         LA    2,96(,13)
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(STRCAT)
         BALR  14,15
         LR    2,3 ==> pdigits
         BCTR  3,0 ==> pdigits
         LTR   2,2 ==> pdigits
         BNH   @@L84
         B     @@L90
@@L85    EQU   *
         STM   4,5,80(13) ==> b
         LD    2,80(,13)
         LDR   0,2
         AD    0,=XL8'4F08000000000000'
         STD   0,80(,13)
         L     6,84(,13) ==> i
         L     2,20(11) ==> result
         STC   15,0(2) ==> sign
         MVI   1(2),0
         ST    6,264(13) ==> i
         L     2,264(13)
         L     3,4+264(13)
         SRDA  2,32
         LA    15,10(0,0)
         DR    2,15
         ST    2,264(13)
         ST    3,4+264(13)
         IC    3,267(13)
         LA    2,240(,3)
         STC   2,96(13) ==> work
         MVI   97(13),0 ==> work
         MVC   88(4,13),20(11) ==> result
         LA    2,96(,13)
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(STRCAT)
         BALR  14,15
         MVC   88(4,13),20(11) ==> result
         MVC   92(4,13),=A(@@LC1)
         LA    1,88(,13)
         L     15,=V(STRCAT)
         BALR  14,15
         L     3,16(11) ==> pdigits,nprecision
         BCTR  3,0 ==> pdigits
         L     15,16(11) ==> nprecision
         LTR   15,15
         BNH   @@L84
@@L95    EQU   *
         MVC   80(4,13),=XL8'4E00000080000000'
         ST    6,84(,13) ==> i
         XI    84(13),128
         LD    0,80(,13)
         SD    0,=XL8'4E00000080000000'
         STM   4,5,80(13) ==> b
         LD    2,80(,13)
         SDR   2,0
         MD    2,=D'1.0E1'
         STD   2,80(,13)
         LM    4,5,80(13) ==> b
         LDR   0,2
         AD    0,=XL8'4F08000000000000'
         STD   0,80(,13)
         L     6,84(,13) ==> i
         LR    8,6 ==> i
         SRDA  8,32 ==> i
         LA    2,10(0,0)
         DR    8,2 ==> i
         LA    2,240(,8)
         STC   2,96(13) ==> work
         MVI   97(13),0 ==> work
         MVC   88(4,13),20(11) ==> result
         LA    2,96(,13)
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(STRCAT)
         BALR  14,15
         LR    2,3 ==> pdigits
         BCTR  3,0 ==> pdigits
         LTR   2,2 ==> pdigits
         BH    @@L95
@@L84    EQU   *
         L     3,228(13) ==> format
         LTR   3,3
         BNE   @@L96
         MVI   96(13),197 ==> work
         LTR   7,7 ==> exp
         BNL   @@L97
         LCR   7,7 ==> exp
         MVI   97(13),96 ==> work
         B     @@L98
@@L97    EQU   *
         MVI   97(13),78 ==> work
@@L98    EQU   *
         ST    7,272(13) ==> exp
         L     4,272(13)
         L     5,4+272(13)
         SRDA  4,32
         LA    6,10(0,0)
         DR    4,6
         ST    4,272(13)
         ST    5,4+272(13)
         MVC   280(4,13),276(13)
         L     8,280(13)
         L     9,4+280(13)
         SRDA  8,32
         DR    8,6
         L     2,=F'-16'
         LA    3,0(2,8)
         STC   3,98(13) ==> work
         ST    7,288(13) ==> exp
         L     4,288(13)
         L     5,4+288(13)
         SRDA  4,32
         DR    4,6
         LA    2,0(2,4)
         STC   2,99(13) ==> work
         MVI   100(13),0 ==> work
         MVC   88(4,13),20(11) ==> result
         LA    2,96(,13)
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(STRCAT)
         BALR  14,15
         B     @@L99
@@L96    EQU   *
         IC    8,224(13) ==> cnvtype
         CLM   8,1,=XL1'C7'
         BE    @@L101
         CLM   8,1,=XL1'87'
         BNE   @@L99
@@L101   EQU   *
         MVC   88(4,13),20(11) ==> result
         MVC   92(4,13),=F'75'
         LA    1,88(,13)
         L     15,=V(STRCHR)
         BALR  14,15
         LR    2,15 ==> p
         LTR   15,15 ==> p
         BE    @@L99
         A     2,=F'1' ==> p
         ST    2,88(13) ==> p
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         AR    2,15 ==> p
         BCTR  2,0 ==> p
         CLI   0(2),240 ==> p
         BNE   @@L128
@@L106   EQU   *
         MVI   0(2),0 ==> p
         BCTR  2,0 ==> p
         CLI   0(2),240 ==> p
         BE    @@L106
@@L128   EQU   *
         CLI   0(2),75 ==> p
         BNE   @@L99
         MVI   0(2),0 ==> p
@@L99    EQU   *
         L     9,20(11) ==> result
         CLI   0(9),64
         BNE   @@L108
         LA    2,96(,13)
         ST    2,88(13)
         LR    2,9
         A     2,=F'1'
         ST    2,92(13)
         B     @@L133
@@L108   EQU   *
         LA    2,96(,13)
         ST    2,88(13)
         MVC   92(4,13),20(11) ==> result
@@L133   EQU   *
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         LA    2,96(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         L     3,12(11) ==> pdigits,nwidth
         SR    3,15 ==> pdigits,p
         L     15,20(11) ==> result
         MVI   0(15),0
         BNH   @@L130
@@L113   EQU   *
         MVC   88(4,13),20(11) ==> result
         MVC   92(4,13),=A(@@LC2)
         LA    1,88(,13)
         L     15,=V(STRCAT)
         BALR  14,15
         BCTR  3,0 ==> pdigits
         LTR   3,3 ==> pdigits
         BH    @@L113
@@L130   EQU   *
         MVC   88(4,13),20(11) ==> result
         LA    2,96(,13)
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(STRCAT)
         BALR  14,15
* Function '__dblcvt' epilogue
         PDPEPIL
* Function '__dblcvt' literal pool
         DS    0D
         LTORG
* Function '__dblcvt' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'0'
         DC    X'0'
@@LC1    EQU   *
         DC    C'.'
         DC    X'0'
@@LC2    EQU   *
         DC    C' '
         DC    X'0'
         END
