 TITLE '/home/mike/repos/crent370/dyn75/@@75ioct.c'
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
         
&FUNC    SETC 'ioctlsocket'
* Program text area
         DS    0F
         EJECT
* external function 'ioctlsocket' prologue
* frame base=88, local stack=64, call args=8
&FUNC    SETC  'ioctlsocket'
@@75IOCT PDPPRLG CINDEX=0,FRAME=160,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'ioctlsocket' code
         L     5,0(11) ==> ss
         L     2,4(11) ==> cmd
         L     4,8(11) ==> argp
         LA    3,96(,13)
         XC    0(64,3),0(3)     clear __75 parameter list
         MVC   124(4,13),=F'15' ==> .r7
         LR    3,5 ==> ss
         SLL   3,16
         O     3,=F'15'
         ST    3,124(13) ==> .r7
         ST    2,128(13) ==> cmd,r8
         ST    4,132(13) ==> argp,r9
         LA    3,96(,13)
         ST    3,88(13)
         LA    1,88(,13)
         L     15,=V(@@75)
         BALR  14,15
         LA    6,1(0,0)
         CLR   2,6 ==> cmd
         BE    @@L3
         L     2,112(13) ==> rc,r4
         L     6,=F'-1'
         CLR   2,6 ==> rc
         BNE   @@L3
         MVC   100(4,13),=F'0' ==> .r1
         MVC   124(4,13),=F'2' ==> .r7
         ST    5,128(13) ==> ss,r8
         ST    3,88(13)
         LA    1,88(,13)
         L     15,=V(@@75)
         BALR  14,15
         LA    1,88(,13)
         L     15,=V(@@ERRNO)
         BALR  14,15
         MVC   0(4,15),112(13) ==> rc,r4
         B     @@L5
@@L3     EQU   *
         LTR   4,4 ==> argp
         BE    @@L6
         MVC   0(4,4),112(13) ==> argp,r4
@@L6     EQU   *
         SLR   2,2 ==> rc
@@L5     EQU   *
         LR    15,2 ==> rc
* Function 'ioctlsocket' epilogue
         PDPEPIL
* Function 'ioctlsocket' literal pool
         DS    0D
         LTORG
* Function 'ioctlsocket' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
