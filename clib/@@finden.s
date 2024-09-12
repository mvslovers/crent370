 TITLE '/home/mike/repos/crent370/clib/@@finden.c'
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
* external function '__findenv' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  '__findenv'
@@FINDEN PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__findenv' code
         L     6,0(11) ==> name
         L     8,4(11) ==> index
         LA    1,88(,13)
         L     15,=V(@@GRTGET)
         BALR  14,15
         LR    5,15 ==> grt
         L     9,=F'-1' ==> empty
         LTR   6,6 ==> name
         BE    @@L2
         L     2,32(15) ==> .grtenv
         LTR   2,2
         BE    @@L2
         LR    2,15 ==> grt
         A     2,=F'32'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    7,15 ==> count
         SLR   4,4 ==> i
         CLR   4,15 ==> i,count
         BNL   @@L2
@@L16    EQU   *
         L     3,32(5) ==> .grtenv
         LR    2,4 ==> i
         MH    2,=H'4'
         L     3,0(2,3) ==> envvar
         LTR   3,3 ==> envvar
         BNE   @@L7
         LTR   9,9 ==> empty
         BNL   @@L5
         LR    9,4 ==> empty,i
         B     @@L5
@@L7     EQU   *
         L     2,0(3) ==> .name
         LTR   2,2
         BE    @@L5
         L     15,8(11) ==> nocase
         LTR   15,15
         BE    @@L10
         ST    2,88(13)
         ST    6,92(13) ==> name
         LA    1,88(,13)
         L     15,=V(STRICMP)
         BALR  14,15
         B     @@L21
@@L10    EQU   *
         MVC   88(4,13),0(3) ==> .name
         ST    6,92(13) ==> name
         LA    1,88(,13)
         L     15,=V(STRCMP)
         BALR  14,15
@@L21    EQU   *
         LTR   15,15 ==> grt
         BNE   @@L5
         LTR   8,8 ==> index
         BE    @@L15
         ST    4,0(8) ==> i,index
@@L15    EQU   *
         L     15,4(3) ==> grt,value
         B     @@L1
@@L5     EQU   *
         A     4,=F'1' ==> i
         CLR   4,7 ==> i,count
         BL    @@L16
@@L2     EQU   *
         LTR   8,8 ==> index
         BE    @@L17
         ST    9,0(8) ==> empty,index
@@L17    EQU   *
         SLR   15,15 ==> grt
@@L1     EQU   *
* Function '__findenv' epilogue
         PDPEPIL
* Function '__findenv' literal pool
         DS    0D
         LTORG
* Function '__findenv' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
