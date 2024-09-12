 TITLE '/home/mike/repos/crent370/dyn75/@@75conn.c'
         COPY  PDPTOP
         CSECT
* GNU C version 3.2.3 - c2asm370 version 1.0 (mvs)
*        compiled by GNU C version 13.2.0.
*
* options passed:  -lang-c -I. -I/home/mike/repos/crent370/dyn75
* -I/home/mike/repos/crent370/include -iprefix -D__GNUC__=3
* -D__GNUC_MINOR__=2 -D__GNUC_PATCHLEVEL__=3 -D__GXX_ABI_VERSION=102
* -D__GCC__ -D__MVS__ -D__GCC__ -D__MVS__ -Asystem=mvs -Acpu=i370
* -Amachine=i370 -D__OPTIMIZE__ -D__STDC_HOSTED__=1 -trigraphs -O1
* -fverbose-asm
* 
* options enabled:  -fdefer-pop -fthread-jumps -fpeephole
* -ffunction-cse -fkeep-static-consts -fpcc-struct-return -fgcse-lm
* -fgcse-sm -fsched-interblock -fsched-spec -fbranch-count-reg
* -fcprop-registers -fcommon -fverbose-asm -fgnu-linker
* -fargument-alias -fmerge-constants -fident
* -fguess-branch-probability -fmath-errno -ftrapping-math
* -mchar-instructions -mno-pickax -mno-constants-first
*
         
&FUNC    SETC 'connect'
* Program text area
         DS    0F
         EJECT
* external function 'connect' prologue
* frame base=88, local stack=88, call args=16
&FUNC    SETC  'connect'
@@75CONN PDPPRLG CINDEX=0,FRAME=192,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'connect' code
         L     8,4(11) ==> name
         LA    2,104(,13)
         XC    0(64,2),0(2)     clear __75 parameter list
         MVC   132(4,13),=F'1' ==> .r7
         SLR   4,4 ==> i
@@L9     EQU   *
         MVC   108(4,13),=F'0' ==> .r1
         L     2,132(13) ==> .r7
         SLL   2,24
         ST    2,132(13) ==> .r7
         SRL   2,16
         ST    2,132(13) ==> .r7
         A     2,=F'7'
         ST    2,132(13) ==> .r7
         L     2,0(11) ==> ss
         SLL   2,16
         A     2,132(13) ==> .r7
         ST    2,132(13) ==> .r7
         MVC   136(4,13),4(8) ==> .r8,s_addr
         LH    2,0(8) ==> .sin_family
         SLL   2,16
         LH    3,2(8) ==> .sin_port
         N     3,=XL4'0000FFFF'
         OR    2,3
         N     2,=F'16777215'
         ST    2,140(13) ==> .r9
         LA    2,104(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@75)
         BALR  14,15
         L     2,120(13) ==> .r4
         L     3,=F'-2'
         CLR   2,3
         BNE   @@L3
         L     2,132(13) ==> .r7
         SLL   2,16
         ST    2,132(13) ==> .r7
         SRL   2,24
         ST    2,132(13) ==> .r7
         LTR   2,2
         BE    @@L12
         BCTR  2,0
         ST    2,132(13) ==> .r7
         STIMER WAIT,BINTVL==F'100'     1.00 seconds
         A     4,=F'1' ==> i
         LA    2,1(0,0)
         CR    4,2 ==> i
         BNH   @@L9
@@L3     EQU   *
         L     9,120(13) ==> rc,r4
         LTR   9,9 ==> rc
         BL    @@L10
         LA    3,168(,13)
         LR    6,3
         LA    7,16(0,0)
         SLR   4,4
         LR    5,4
         MVCL  6,4
         MVC   184(4,13),=F'16'
         MVC   88(4,13),0(11) ==> ss
         ST    3,92(13)
         LA    2,184(,13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@75SNAM)
         BALR  14,15
         MVC   88(4,13),0(11) ==> ss
         ST    3,92(13)
         ST    8,96(13) ==> name
         LA    1,88(,13)
         L     15,=V(@@SOUPD)
         BALR  14,15
         B     @@L8
@@L12    EQU   *
         L     9,=F'-1' ==> rc
         LA    1,88(,13)
         L     15,=V(@@ERRNO)
         BALR  14,15
         MVC   0(4,15),=F'61' ==> rc
         B     @@L8
@@L10    EQU   *
         MVC   108(4,13),=F'0' ==> .r1
         MVC   136(4,13),0(11) ==> .r8,ss
         MVC   132(4,13),=F'2' ==> .r7
         LA    2,104(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@75)
         BALR  14,15
         LA    1,88(,13)
         L     15,=V(@@ERRNO)
         BALR  14,15
         MVC   0(4,15),120(13) ==> rc,r4
@@L8     EQU   *
         LR    15,9 ==> rc
* Function 'connect' epilogue
         PDPEPIL
* Function 'connect' literal pool
         DS    0D
         LTORG
* Function 'connect' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
