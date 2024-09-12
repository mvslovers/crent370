 TITLE '/home/mike/repos/crent370/clib/mtxlock.c'
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
* external function 'mtxlock' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  'mtxlock'
MTXLOCK  PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'mtxlock' code
         L     4,0(11) ==> mutex
         SLR   2,2 ==> psa
         L     3,540(2) ==> tcb
         MVC   88(4,13),=A(@@LC0)
         ST    2,92(13) ==> psa
         ST    4,96(13) ==> mutex
         LA    1,88(,13)
         L     15,=V(@@LKRNF)
         BALR  14,15
         ST    3,0(4) ==> tcb,owner
         L     2,4(4) ==> .count
         A     2,=F'1'
         ST    2,4(4) ==> .count
         LTR   15,15 ==> rc
         BNE   @@L1
         LA    1,88(,13)
         L     15,=V(@@CRTGET)
         BALR  14,15
         A     15,=F'340'
         ST    15,88(13)
         ST    4,92(13) ==> mutex
         LA    1,88(,13)
         L     15,=V(@@ARADD)
         BALR  14,15
@@L1     EQU   *
* Function 'mtxlock' epilogue
         PDPEPIL
* Function 'mtxlock' literal pool
         DS    0D
         LTORG
* Function 'mtxlock' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'MUTEX.%08X'
         DC    X'0'
         END
