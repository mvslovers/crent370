 TITLE '/home/mike/repos/crent370/clib/@@fmtloa.c'
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
* external function '__fmtloa' prologue
* frame base=88, local stack=72, call args=40
&FUNC    SETC  '__fmtloa'
@@FMTLOA PDPPRLG CINDEX=0,FRAME=200,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__fmtloa' code
         L     3,0(11) ==> pdslist
         L     15,=F'-1' ==> rc
         LR    4,3 ==> data,pdslist
         A     4,=F'12' ==> data
         LTR   3,3 ==> pdslist
         BNE   @@L3
         SLR   4,4 ==> data
@@L3     EQU   *
         L     5,4(11) ==> stat,loadstat
         SLR   6,6 ==> s02
         LR    8,6 ==> s01,s02
         LR    7,6 ==> s03,s02
         LR    9,6 ==> s04,s03
         MVC   168(4,13),=A(@@LC0) ==> ne
         MVC   172(4,13),=A(@@LC1) ==> ol
         MVC   176(4,13),=A(@@LC2) ==> pg
         MVC   180(4,13),=A(@@LC3) ==> rf
         MVC   184(4,13),=A(@@LC4) ==> rn
         MVC   188(4,13),=A(@@LC5) ==> ru
         MVC   192(4,13),=A(@@LC6) ==> ov
         MVC   196(4,13),=A(@@LC7) ==> ts
         LTR   4,4 ==> data
         BE    @@L5
         LTR   5,5 ==> stat
         BE    @@L5
         LA    2,75(0,0) ==> n
         
*** MEMSET ***
         LR    14,5           => target (s) ==> stat
         LR    15,2           => length (n) ==> n
         SLR   0,0             => source (NULL)
         LR    1,6            fill character ==> s03
         SLL   1,24            move fill to high byte
         MVCL  14,0            Set target to fill character
         LR    15,6 ==> i,s03
         CLI   0(3),64 ==> .name
         BNH   @@L9
@@L13    EQU   *
         IC    2,0(15,3) ==> .name
         STC   2,0(15,5) ==> .name
         A     15,=F'1' ==> i
         LA    2,7(0,0)
         CR    15,2 ==> i
         BH    @@L9
         IC    2,0(15,3) ==> .name
         CLM   2,1,=XL1'40'
         BH    @@L13
@@L9     EQU   *
         LR    2,5 ==> stat
         A     2,=F'9'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC8)
         L     2,8(3)
         SRL   2,8
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
         IC    15,11(3) ==> .idc
         N     15,=F'31' ==> rc
         MH    15,=H'2' ==> rc
         LTR   15,15 ==> rc
         BE    @@L5
         IC    2,8(4) ==> .loadatr1
         N     2,=F'4'
         CLM   2,1,=XL1'00'
         BE    @@L15
         LR    8,4 ==> s01,data
         A     8,=F'21' ==> s01
@@L15    EQU   *
         IC    2,11(3) ==> .idc
         N     2,=F'-128'
         CLM   2,1,=XL1'00'
         BE    @@L16
         LR    6,8 ==> s02,s01
         A     6,=F'8' ==> s02
         LTR   8,8 ==> s01
         BNE   @@L16
         LR    6,4 ==> s02,data
         A     6,=F'21' ==> s02
@@L16    EQU   *
         IC    2,18(4) ==> .loadftb1
         N     2,=F'16'
         CLM   2,1,=XL1'00'
         BE    @@L19
         LR    7,6 ==> s03,s02
         A     7,=F'11' ==> s03
         LTR   6,6 ==> s02
         BNE   @@L21
         LR    7,8 ==> s03,s01
         A     7,=F'8' ==> s03
         LTR   8,8 ==> s01
         BNE   @@L21
         LR    7,4 ==> s03,data
         A     7,=F'21' ==> s03
@@L21    EQU   *
         A     7,=F'1' ==> s03
         N     7,=F'2147483646' ==> s03
@@L19    EQU   *
         IC    2,18(4) ==> .loadftb1
         N     2,=F'8'
         CLM   2,1,=XL1'00'
         BE    @@L24
         LR    9,7 ==> s04,s03
         A     9,=F'4' ==> s04
         LTR   7,7 ==> s03
         BNE   @@L24
         LR    9,6 ==> s04,s02
         A     9,=F'11' ==> s04
         LTR   6,6 ==> s02
         BNE   @@L24
         LR    9,8 ==> s04,s01
         A     9,=F'8' ==> s04
         LTR   8,8 ==> s01
         BNE   @@L24
         LR    9,4 ==> s04,data
         A     9,=F'21' ==> s04
@@L24    EQU   *
         LR    2,5 ==> stat
         A     2,=F'16'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC9)
         SLR   2,2
         IC    2,10(4) ==> .loadstor
         ST    2,96(13)
         SLR   2,2
         IC    2,11(4) ==> .loadstor
         ST    2,100(13)
         SLR   2,2
         IC    2,12(4) ==> .loadstor
         ST    2,104(13)
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
         LTR   6,6 ==> s02
         BE    @@L31
         SLR   15,15 ==> i
         CLI   3(6),64 ==> .loadmnm
         BNH   @@L31
@@L37    EQU   *
         IC    2,3(15,6) ==> .loadmnm
         STC   2,23(15,5) ==> .aliasof
         A     15,=F'1' ==> i
         LA    2,7(0,0)
         CR    15,2 ==> i
         BH    @@L31
         IC    2,3(15,6) ==> .loadmnm
         CLM   2,1,=XL1'40'
         BH    @@L37
@@L31    EQU   *
         LTR   9,9 ==> s04
         BE    @@L38
         LR    2,5 ==> stat
         A     2,=F'32'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC10)
         SLR   2,2
         IC    2,1(9) ==> .loadapfac
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
         B     @@L39
@@L38    EQU   *
         LR    2,5 ==> stat
         A     2,=F'32'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC11)
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
@@L39    EQU   *
         LR    2,5 ==> stat
         A     2,=F'35'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC9)
         SLR   2,2
         IC    2,15(4) ==> .loadepa
         ST    2,96(13)
         SLR   2,2
         IC    2,16(4) ==> .loadepa
         ST    2,100(13)
         SLR   2,2
         IC    2,17(4) ==> .loadepa
         ST    2,104(13)
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
         IC    2,8(4) ==> .loadatr1
         N     2,=F'2'
         CLM   2,1,=XL1'00'
         BE    @@L40
         MVC   168(4,13),=A(@@LC12) ==> ne
@@L40    EQU   *
         IC    2,8(4) ==> .loadatr1
         N     2,=F'8'
         CLM   2,1,=XL1'00'
         BNE   @@L41
         MVC   172(4,13),=A(@@LC12) ==> ol
@@L41    EQU   *
         IC    2,18(4) ==> .loadftb1
         N     2,=F'32'
         CLM   2,1,=XL1'00'
         BNE   @@L42
         MVC   176(4,13),=A(@@LC12) ==> pg
@@L42    EQU   *
         IC    2,9(4) ==> .loadatr2
         N     2,=F'1'
         CLM   2,1,=XL1'00'
         BNE   @@L43
         MVC   180(4,13),=A(@@LC12) ==> rf
@@L43    EQU   *
         IC    2,8(4) ==> .loadatr1
         N     2,=F'-128'
         CLM   2,1,=XL1'00'
         BNE   @@L44
         MVC   184(4,13),=A(@@LC12) ==> rn
@@L44    EQU   *
         IC    2,8(4) ==> .loadatr1
         N     2,=F'64'
         CLM   2,1,=XL1'00'
         BNE   @@L45
         MVC   188(4,13),=A(@@LC12) ==> ru
@@L45    EQU   *
         IC    2,8(4) ==> .loadatr1
         N     2,=F'32'
         CLM   2,1,=XL1'00'
         BNE   @@L46
         MVC   192(4,13),=A(@@LC12) ==> ov
@@L46    EQU   *
         IC    2,8(4) ==> .loadatr1
         N     2,=F'16'
         CLM   2,1,=XL1'00'
         BNE   @@L47
         MVC   196(4,13),=A(@@LC12) ==> ts
@@L47    EQU   *
         LR    2,5 ==> stat
         A     2,=F'42'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC13)
         MVC   96(4,13),168(13) ==> ne
         MVC   100(4,13),172(13) ==> ol
         MVC   104(4,13),176(13) ==> pg
         MVC   108(4,13),180(13) ==> rf
         MVC   112(4,13),184(13) ==> rn
         MVC   116(4,13),188(13) ==> ru
         MVC   120(4,13),192(13) ==> ov
         MVC   124(4,13),196(13) ==> ts
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
         LTR   7,7 ==> s03
         BE    @@L48
         A     2,=F'24'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC14)
         SLR   2,2
         IC    2,0(7) ==> .loadchlvl
         ST    2,96(13)
         SLR   2,2
         IC    2,1(7) ==> .loadssifb
         ST    2,100(13)
         SLR   2,2
         IC    2,2(7) ==> .loadmbrsn
         ST    2,104(13)
         SLR   2,2
         IC    2,3(7) ==> .loadmbrsn
         ST    2,108(13)
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
@@L48    EQU   *
         SLR   15,15 ==> rc
@@L5     EQU   *
* Function '__fmtloa' epilogue
         PDPEPIL
* Function '__fmtloa' literal pool
         DS    0D
         LTORG
* Function '__fmtloa' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'NE'
         DC    X'0'
@@LC1    EQU   *
         DC    C'OL'
         DC    X'0'
@@LC2    EQU   *
         DC    C'PG'
         DC    X'0'
@@LC3    EQU   *
         DC    C'RF'
         DC    X'0'
@@LC4    EQU   *
         DC    C'RN'
         DC    X'0'
@@LC5    EQU   *
         DC    C'RU'
         DC    X'0'
@@LC6    EQU   *
         DC    C'OV'
         DC    X'0'
@@LC7    EQU   *
         DC    C'TS'
         DC    X'0'
@@LC8    EQU   *
         DC    C'%06X'
         DC    X'0'
@@LC9    EQU   *
         DC    C'%02X%02X%02X'
         DC    X'0'
@@LC10   EQU   *
         DC    C'%02X'
         DC    X'0'
@@LC11   EQU   *
         DC    C'00'
         DC    X'0'
@@LC12   EQU   *
         DC    C'  '
         DC    X'0'
@@LC13   EQU   *
         DC    C'%s %s %s %s %s %s %s %s'
         DC    X'0'
@@LC14   EQU   *
         DC    C'%02X%02X%02X%02X'
         DC    X'0'
         END
