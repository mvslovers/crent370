 TITLE '/home/mike/repos/crent370/dyn75/@@75init.c'
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
         
&FUNC    SETC '@@75init'
* Program text area
         DS    0F
         EJECT
* external function '__75init' prologue
* frame base=88, local stack=64, call args=8
&FUNC    SETC  '__75init'
@@75INIT PDPPRLG CINDEX=0,FRAME=160,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__75init' code
         LA    1,88(,13)
         L     15,=V(@@GRTGET)
         BALR  14,15
         LR    4,15 ==> grt
         LR    3,15 ==> grt
         A     3,=F'28'
         ST    3,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         L     2,0(3) ==> .grtsock
         LTR   2,2
         BNE   @@L2
         MVC   88(4,13),=F'1024'
         LA    1,88(,13)
         L     15,=V(@@ARNEW)
         BALR  14,15
         ST    15,0(3) ==> grt,grtsock
@@L2     EQU   *
         LR    2,4 ==> grt
         A     2,=F'28'
         ST    2,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
         LA    2,96(,13)
         XC    0(64,2),0(2)     clear __75 parameter list
         MVC   124(4,13),=F'1' ==> .r7
         LA    2,96(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@75)
         BALR  14,15
         LR    2,4 ==> grt
         A     2,=F'28'
         ST    2,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         OI    10(4),128 ==> .grtflag1
         ST    2,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
         L     15,156(13) ==> .r15
* Function '__75init' epilogue
         PDPEPIL
* Function '__75init' literal pool
         DS    0D
         LTORG
* Function '__75init' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
