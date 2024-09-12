 TITLE '/home/mike/repos/crent370/clib/@@tminit.c'
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
         
&FUNC    SETC 'tmr_init'
* Program text area
         DS    0F
         EJECT
* external function 'tmr_init' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'tmr_init'
@@TMINIT PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'tmr_init' code
         LA    1,88(,13)
         L     15,=V(@@TMRGET)
         BALR  14,15
         LR    3,15 ==> tmr
         ST    15,88(13) ==> tmr
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         LR    4,15 ==> lockrc
         IC    2,8(3) ==> .flags
         N     2,=F'-128'
         CLM   2,1,=XL1'00'
         BNE   @@L2
         ST    3,88(13) ==> tmr
         MVC   92(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         LA    1,88(,13)
         L     15,=V(RAND)
         BALR  14,15
         SLL   15,8
         N     15,=F'16776960'
         ST    15,28(3) ==> .id
         MVI   8(3),128 ==> .flags
@@L2     EQU   *
         LTR   4,4 ==> lockrc
         BNE   @@L3
         ST    3,88(13) ==> tmr
         ST    4,92(13) ==> lockrc
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
@@L3     EQU   *
         SLR   15,15
* Function 'tmr_init' epilogue
         PDPEPIL
* Function 'tmr_init' literal pool
         DS    0D
         LTORG
* Function 'tmr_init' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'**TMR**'
         DC    X'0'
         END
