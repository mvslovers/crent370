 TITLE '/home/mike/repos/crent370/dyn75/@@75bind.c'
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
         
&FUNC    SETC 'bind'
* Program text area
         DS    0F
         EJECT
* external function 'bind' prologue
* frame base=88, local stack=72, call args=16
&FUNC    SETC  'bind'
@@75BIND PDPPRLG CINDEX=0,FRAME=176,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'bind' code
         L     5,0(11) ==> ss
         L     4,4(11) ==> name
         L     6,8(11) ==> length
         LH    2,2(4) ==> .sin_port
         CH    2,=H'0'
         BNE   @@L2
         LA    2,168(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(TIME)
         BALR  14,15
         L     2,168(13)
         N     2,=F'32767'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(SRAND)
         BALR  14,15
         SLR   2,2 ==> i
@@L8     EQU   *
         LA    1,88(,13)
         L     15,=V(RAND)
         BALR  14,15
         N     15,=F'32767'
         SLL   15,16
         SRA   15,16
         AH    15,=H'10000'
         STH   15,2(4) ==> .sin_port
         ST    5,88(13) ==> ss
         ST    4,92(13) ==> name
         ST    6,96(13) ==> length
         LA    1,88(,13)
         L     15,=V(@@75BIND)
         BALR  14,15
         LR    3,15 ==> rc
         LTR   15,15 ==> rc
         BE    @@L10
         A     2,=F'1' ==> i
         LA    3,99(0,0)
         CR    2,3 ==> i
         BNH   @@L8
         MVC   2(2,4),=H'0' ==> .sin_port
@@L2     EQU   *
         LA    2,104(,13)
         XC    0(64,2),0(2)     clear __75 parameter list
         LR    2,5 ==> ss
         SLL   2,16
         O     2,=F'6'
         ST    2,132(13) ==> .r7
         MVC   136(4,13),4(4) ==> .r8,s_addr
         LH    2,0(4) ==> .sin_family
         SLL   2,16
         LH    3,2(4) ==> .sin_port
         N     3,=XL4'0000FFFF'
         OR    2,3
         N     2,=F'16777215'
         ST    2,140(13) ==> .r9
         LA    2,104(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@75)
         BALR  14,15
         L     3,120(13) ==> rc,r4
         LTR   3,3 ==> rc
         BL    @@L9
         ST    5,88(13) ==> ss
         ST    4,92(13) ==> name
         MVC   96(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@SOUPD)
         BALR  14,15
         B     @@L10
@@L9     EQU   *
         MVC   108(4,13),=F'0' ==> .r1
         ST    5,136(13) ==> ss,r8
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
@@L10    EQU   *
         LR    15,3 ==> rc
* Function 'bind' epilogue
         PDPEPIL
* Function 'bind' literal pool
         DS    0D
         LTORG
* Function 'bind' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
