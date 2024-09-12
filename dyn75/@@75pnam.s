 TITLE '/home/mike/repos/crent370/dyn75/@@75pnam.c'
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
         
&FUNC    SETC 'getpeername'
* Program text area
         DS    0F
         EJECT
* external function 'getpeername' prologue
* frame base=88, local stack=72, call args=16
&FUNC    SETC  'getpeername'
@@75PNAM PDPPRLG CINDEX=0,FRAME=176,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'getpeername' code
         L     6,0(11) ==> ss
         L     3,4(11) ==> addr
         L     5,8(11) ==> addrlen
         MVC   168(4,13),=F'0'
         SLR   4,4 ==> rc
         LTR   3,3 ==> addr
         BE    @@L2
         ST    6,88(13) ==> ss
         LA    2,168(,13)
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(@@SOFIND)
         BALR  14,15
         LTR   15,15 ==> rc
         BE    @@L2
         L     2,168(13)
         LTR   2,2
         BE    @@L2
         A     2,=F'16'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC0)
         MVC   96(4,13),=F'4'
         LA    1,88(,13)
         L     15,=V(MEMCMP)
         BALR  14,15
         LTR   15,15 ==> rc
         BE    @@L2
         LA    6,16(0,0) ==> len
         LTR   5,5 ==> addrlen
         BE    @@L6
         L     6,0(5) ==> len,addrlen
@@L6     EQU   *
         LA    2,16(0,0)
         CLR   6,2 ==> len
         BNH   @@L7
         LR    6,2 ==> len
@@L7     EQU   *
         ST    3,88(13) ==> addr
         L     2,168(13)
         A     2,=F'16'
         ST    2,92(13)
         ST    6,96(13) ==> len
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         B     @@L8
@@L2     EQU   *
         LA    2,104(,13)
         XC    0(64,2),0(2)     clear __75 parameter list
         ST    3,128(13) ==> addr,r6
         MVC   132(4,13),=F'19' ==> .r7
         ST    6,136(13) ==> ss,r8
         LA    2,104(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@75)
         BALR  14,15
         L     4,120(13) ==> rc,r4
         L     3,=F'-1'
         CLR   4,3 ==> rc
         BNE   @@L8
         MVC   108(4,13),=F'0' ==> .r1
         MVC   132(4,13),=F'2' ==> .r7
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@75)
         BALR  14,15
         LA    1,88(,13)
         L     15,=V(@@ERRNO)
         BALR  14,15
         MVC   0(4,15),120(13) ==> rc,r4
@@L8     EQU   *
         LTR   5,5 ==> addrlen
         BE    @@L10
         MVC   0(4,5),=F'16' ==> addrlen
@@L10    EQU   *
         LR    15,4 ==> rc
* Function 'getpeername' epilogue
         PDPEPIL
* Function 'getpeername' literal pool
         DS    0D
         LTORG
* Function 'getpeername' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    X'0'
         DC    X'0'
         DC    X'0'
         DC    X'0'
         DC    X'0'
         END
