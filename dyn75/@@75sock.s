 TITLE '/home/mike/repos/crent370/dyn75/@@75sock.c'
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
         
&FUNC    SETC 'socket'
* Program text area
         DS    0F
         EJECT
* external function 'socket' prologue
* frame base=88, local stack=64, call args=16
&FUNC    SETC  'socket'
@@75SOCK PDPPRLG CINDEX=0,FRAME=168,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'socket' code
         LA    1,88(,13)
         L     15,=V(@@GRTGET)
         BALR  14,15
         LA    2,104(,13)
         XC    0(64,2),0(2)     clear __75 parameter list
         IC    2,10(15) ==> .grtflag1
         N     2,=F'-128'
         CLM   2,1,=XL1'00'
         BNE   @@L2
         LA    1,88(,13)
         L     15,=V(@@75INIT)
         BALR  14,15
@@L2     EQU   *
         L     2,0(11) ==> af
         SLL   2,16
         ST    2,136(13) ==> .r8
         MVC   140(4,13),4(11) ==> .r9,type
         OC    136(4,13),140(13) ==> .r8,r9
         MVC   140(4,13),8(11) ==> .r9,protocol
         MVC   132(4,13),=F'5' ==> .r7
         LA    2,104(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@75)
         BALR  14,15
         L     3,120(13) ==> socket,r4
         LTR   3,3 ==> socket
         BL    @@L3
         ST    3,88(13) ==> socket
         MVC   92(4,13),=F'0'
         MVC   96(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@SOADD)
         BALR  14,15
         B     @@L4
@@L3     EQU   *
         MVC   108(4,13),=F'0' ==> .r1
         MVC   132(4,13),=F'3' ==> .r7
         LA    2,104(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@75)
         BALR  14,15
         LA    1,88(,13)
         L     15,=V(@@ERRNO)
         BALR  14,15
         MVC   0(4,15),120(13) ==> grt,r4
@@L4     EQU   *
         LR    15,3 ==> socket
* Function 'socket' epilogue
         PDPEPIL
* Function 'socket' literal pool
         DS    0D
         LTORG
* Function 'socket' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
