 TITLE '/home/mike/repos/crent370/clib/setenv.c'
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
* external function 'setenv' prologue
* frame base=88, local stack=16, call args=16
&FUNC    SETC  'setenv'
SETENV   PDPPRLG CINDEX=0,FRAME=120,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'setenv' code
         L     4,0(11) ==> name
         L     6,4(11) ==> value
         LA    1,88(,13)
         L     15,=V(@@GRTGET)
         BALR  14,15
         LR    8,15 ==> grt
         MVC   108(4,13),=F'0' ==> err
         LR    2,15 ==> grt
         A     2,=F'32'
         ST    2,88(13)
         MVC   92(4,13),108(13) ==> err
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         CLI   0(4),64 ==> name
         BNE   @@L28
@@L5     EQU   *
         A     4,=F'1' ==> name
         CLI   0(4),64 ==> name
         BE    @@L5
@@L28    EQU   *
         LTR   4,4 ==> name
         BE    @@L6
         ST    4,88(13) ==> name
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         LR    5,15 ==> l_name
         B     @@L7
@@L6     EQU   *
         SLR   5,5 ==> l_name
@@L7     EQU   *
         LTR   5,5 ==> l_name
         BE    @@L9
         LR    2,4 ==> name
         AR    2,5 ==> l_name
         BCTR  2,0
         CLI   0(2),64
         BNE   @@L9
@@L12    EQU   *
         BCTR  5,0 ==> l_name
         LTR   5,5 ==> l_name
         BE    @@L9
         LR    2,4 ==> name
         AR    2,5 ==> l_name
         BCTR  2,0
         CLI   0(2),64
         BE    @@L12
@@L9     EQU   *
         LTR   5,5 ==> l_name
         BE    @@L32
         LTR   6,6 ==> value
         BE    @@L32
         ST    4,88(13) ==> name
         LA    2,104(,13)
         ST    2,92(13)
         MVC   96(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@FINDEN)
         BALR  14,15
         LR    9,15 ==> found
         LTR   15,15 ==> found
         BNE   @@L16
         ST    4,88(13) ==> name
         LA    2,104(,13)
         ST    2,92(13)
         MVC   96(4,13),=F'1'
         LA    1,88(,13)
         L     15,=V(@@FINDEN)
         BALR  14,15
         LR    9,15 ==> found
@@L16    EQU   *
         LTR   9,9 ==> found
         BE    @@L17
         L     2,8(11) ==> rewrite
         LTR   2,2 ==> rewrite
         BE    @@L15
@@L17    EQU   *
         CLI   0(6),64 ==> value
         BNE   @@L31
@@L21    EQU   *
         A     6,=F'1' ==> value
         CLI   0(6),64 ==> value
         BE    @@L21
@@L31    EQU   *
         ST    6,88(13) ==> value
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         ST    15,112(13) ==> l_value
         LR    2,15 ==> length
         AR    2,5 ==> length,l_name
         A     2,=F'12' ==> length
         MVC   88(4,13),=F'1'
         ST    2,92(13) ==> length
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         LR    7,15 ==> envvar
         LTR   15,15 ==> envvar
         BNE   @@L22
@@L32    EQU   *
         MVC   108(4,13),=F'1' ==> err
         B     @@L15
@@L22    EQU   *
         LR    3,15 ==> envvar
         A     3,=F'8'
         ST    3,0(15) ==> .name
         LR    2,15 ==> envvar
         AR    2,5 ==> l_name
         A     2,=F'9'
         ST    2,4(15) ==> .value
         ST    3,88(13)
         ST    4,92(13) ==> name
         ST    5,96(13) ==> l_name
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         MVC   88(4,13),4(7) ==> .value
         ST    6,92(13) ==> value
         MVC   96(4,13),112(13) ==> l_value
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         L     2,104(13)
         LTR   2,2
         BL    @@L23
         LTR   9,9 ==> found
         BE    @@L24
         L     3,32(8) ==> .grtenv
         MH    2,=H'4'
         L     3,0(2,3)
         ST    3,88(13)
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
@@L24    EQU   *
         L     3,32(8) ==> .grtenv
         L     2,104(13)
         SLL   2,2
         ST    7,0(2,3) ==> envvar
         B     @@L15
@@L23    EQU   *
         LR    2,8 ==> grt
         A     2,=F'32'
         ST    2,88(13)
         ST    7,92(13) ==> envvar
         LA    1,88(,13)
         L     15,=V(@@ARADD)
         BALR  14,15
         ST    15,108(13) ==> err
         LTR   15,15
         BE    @@L15
         ST    7,88(13) ==> envvar
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
@@L15    EQU   *
         LR    2,8 ==> grt
         A     2,=F'32'
         ST    2,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
         L     15,108(13) ==> err
* Function 'setenv' epilogue
         PDPEPIL
* Function 'setenv' literal pool
         DS    0D
         LTORG
* Function 'setenv' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
