 TITLE '/home/mike/repos/crent370/clib/@@exit.c'
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
* external function '__exit' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  '__exit'
@@EXIT   PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__exit' code
         L     6,0(11) ==> status
         LA    1,88(,13)
         L     15,=V(@@GRTGET)
         BALR  14,15
         LR    5,15 ==> grt
         LTR   15,15 ==> grt
         BE    @@L3
         L     2,16(15) ==> .grtexit
         LTR   2,2
         BE    @@L4
         LR    2,15 ==> grt
         A     2,=F'16'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    4,15 ==> count
         LTR   15,15 ==> count
         BE    @@L39
@@L9     EQU   *
         BCTR  4,0 ==> count
         L     2,16(5) ==> .grtexit
         LR    15,4 ==> count
         MH    15,=H'4'
         L     3,0(15,2) ==> func
         LTR   3,3 ==> func
         BE    @@L8
         ST    6,88(13) ==> status
         L     2,20(5) ==> .grtexita
         L     2,0(15,2)
         ST    2,92(13)
         LA    1,88(,13)
         LA    15,0(3) ==> func
         BALR  14,15
@@L8     EQU   *
         L     2,16(5) ==> .grtexit
         LR    3,4 ==> count
         MH    3,=H'4'
         SLR   7,7
         ST    7,0(3,2)
         L     2,20(5) ==> .grtexita
         ST    7,0(3,2)
         LTR   4,4 ==> count
         BNE   @@L9
@@L39    EQU   *
         LR    2,5 ==> grt
         A     2,=F'16'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARFRE)
         BALR  14,15
         A     2,=F'4'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARFRE)
         BALR  14,15
@@L4     EQU   *
         L     2,24(5) ==> .grtfile
         LTR   2,2
         BE    @@L10
         LR    2,5 ==> grt
         A     2,=F'24'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    4,15 ==> count
         LTR   15,15 ==> count
         BE    @@L41
@@L18    EQU   *
         BCTR  4,0 ==> count
         L     3,24(5) ==> .grtfile
         LR    2,4 ==> count
         MH    2,=H'4'
         L     2,0(2,3) ==> fp
         LTR   2,2 ==> fp
         BE    @@L11
         ST    2,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(FCLOSE)
         BALR  14,15
         LA    1,88(,13)
         L     15,=V(@@GTIN)
         BALR  14,15
         CL    2,0(15) ==> fp,grt
         BNE   @@L15
         LA    1,88(,13)
         L     15,=V(@@GTIN)
         BALR  14,15
         B     @@L48
@@L15    EQU   *
         LA    1,88(,13)
         L     15,=V(@@GTOUT)
         BALR  14,15
         CL    2,0(15) ==> fp,grt
         BNE   @@L16
         LA    1,88(,13)
         L     15,=V(@@GTOUT)
         BALR  14,15
         B     @@L48
@@L16    EQU   *
         LA    1,88(,13)
         L     15,=V(@@GTERR)
         BALR  14,15
         CL    2,0(15) ==> fp,grt
         BNE   @@L11
         LA    1,88(,13)
         L     15,=V(@@GTERR)
         BALR  14,15
@@L48    EQU   *
         MVC   0(4,15),=F'0' ==> grt
@@L11    EQU   *
         LTR   4,4 ==> count
         BNE   @@L18
@@L41    EQU   *
         LR    2,5 ==> grt
         A     2,=F'24'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARFRE)
         BALR  14,15
@@L10    EQU   *
         L     2,32(5) ==> .grtenv
         LTR   2,2
         BE    @@L19
         LR    2,5 ==> grt
         A     2,=F'32'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    4,15 ==> count
         LTR   15,15 ==> count
         BE    @@L43
@@L24    EQU   *
         BCTR  4,0 ==> count
         L     2,32(5) ==> .grtenv
         LR    3,4 ==> count
         MH    3,=H'4'
         L     2,0(3,2)
         LTR   2,2
         BE    @@L20
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
         L     2,32(5) ==> .grtenv
         SLR   7,7
         ST    7,0(3,2)
@@L20    EQU   *
         LTR   4,4 ==> count
         BNE   @@L24
@@L43    EQU   *
         LR    2,5 ==> grt
         A     2,=F'32'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARFRE)
         BALR  14,15
@@L19    EQU   *
         L     2,68(5) ==> .grtwsa
         LTR   2,2
         BE    @@L25
         LR    2,5 ==> grt
         A     2,=F'68'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    4,15 ==> count
         LTR   15,15 ==> count
         BE    @@L45
@@L30    EQU   *
         BCTR  4,0 ==> count
         L     2,68(5) ==> .grtwsa
         LR    3,4 ==> count
         MH    3,=H'4'
         L     2,0(3,2)
         LTR   2,2
         BE    @@L26
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
         L     2,68(5) ==> .grtwsa
         SLR   7,7
         ST    7,0(3,2)
@@L26    EQU   *
         LTR   4,4 ==> count
         BNE   @@L30
@@L45    EQU   *
         LR    2,5 ==> grt
         A     2,=F'68'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARFRE)
         BALR  14,15
@@L25    EQU   *
         L     2,72(5) ==> .grtdevtb
         LTR   2,2
         BE    @@L31
         LR    2,5 ==> grt
         A     2,=F'72'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    4,15 ==> count
         LTR   15,15 ==> count
         BE    @@L47
@@L36    EQU   *
         BCTR  4,0 ==> count
         L     2,72(5) ==> .grtdevtb
         LR    3,4 ==> count
         MH    3,=H'4'
         L     2,0(3,2)
         LTR   2,2
         BE    @@L32
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
         L     2,72(5) ==> .grtdevtb
         SLR   7,7
         ST    7,0(3,2)
@@L32    EQU   *
         LTR   4,4 ==> count
         BNE   @@L36
@@L47    EQU   *
         LR    2,5 ==> grt
         A     2,=F'72'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARFRE)
         BALR  14,15
@@L31    EQU   *
         L     2,76(5) ==> .grtptrs
         LTR   2,2
         BE    @@L3
         LR    2,5 ==> grt
         A     2,=F'76'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARFRE)
         BALR  14,15
@@L3     EQU   *
         ST    6,88(13) ==> status
         LA    1,88(,13)
         L     15,=V(@@EXITA)
         BALR  14,15
* Function '__exit' epilogue
         PDPEPIL
* Function '__exit' literal pool
         DS    0D
         LTORG
* Function '__exit' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
