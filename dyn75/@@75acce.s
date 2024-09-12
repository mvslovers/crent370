 TITLE '/home/mike/repos/crent370/dyn75/@@75acce.c'
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
         
&FUNC    SETC 'accept'
* Program text area
         DS    0F
         EJECT
* external function 'accept' prologue
* frame base=88, local stack=104, call args=16
&FUNC    SETC  'accept'
@@75ACCE PDPPRLG CINDEX=0,FRAME=208,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'accept' code
         L     3,0(11) ==> ss
         L     9,4(11) ==> name
         LTR   9,9 ==> name
         BNE   @@L2
         LA    9,168(,13) ==> name
         XC    0(16,9),0(9)     clear temp sockaddr_in ==> name
@@L2     EQU   *
         LA    2,104(,13)
         XC    0(64,2),0(2)     clear __75 parameter list
         LA    2,104(,13)
@@L3     EQU   *
         MVC   108(4,13),=F'0' ==> .r1
         ST    9,128(13) ==> name,r6
         MVC   132(4,13),=F'9' ==> .r7
         ST    3,136(13) ==> ss,r8
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@75)
         BALR  14,15
         L     8,120(13) ==> rc,r4
         L     4,=F'-2'
         CLR   8,4 ==> rc
         BNE   @@L4
         STIMER WAIT,BINTVL==F'8'   0.08 seconds
         B     @@L3
@@L4     EQU   *
         LTR   8,8 ==> rc
         BL    @@L7
         LA    3,184(,13)
         LR    6,3
         LA    7,16(0,0)
         SLR   4,4
         LR    5,4
         MVCL  6,4
         MVC   200(4,13),=F'16'
         ST    8,88(13) ==> rc
         ST    3,92(13)
         LA    2,200(,13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@75SNAM)
         BALR  14,15
         ST    8,88(13) ==> rc
         ST    3,92(13)
         ST    9,96(13) ==> name
         LA    1,88(,13)
         L     15,=V(@@SOADD)
         BALR  14,15
@@L7     EQU   *
         L     2,=F'-1'
         CLR   8,2 ==> rc
         BNE   @@L8
         MVC   108(4,13),=F'0' ==> .r1
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
         LR    15,8 ==> rc
* Function 'accept' epilogue
         PDPEPIL
* Function 'accept' literal pool
         DS    0D
         LTORG
* Function 'accept' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
