 TITLE '/home/mike/repos/crent370/clib/@@ctfind.c'
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
         
&FUNC    SETC 'cthread_find'
* Program text area
         DS    0F
         EJECT
* external function 'cthread_find' prologue
* frame base=88, local stack=8, call args=8
&FUNC    SETC  'cthread_find'
@@CTFIND PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'cthread_find' code
         L     9,0(11) ==> tcb
         LA    1,88(,13)
         L     15,=V(@@GRTGET)
         BALR  14,15
         LR    8,15 ==> grt
         SLR   6,6 ==> task
         LR    2,15 ==> grt
         A     2,=F'64'
         ST    2,88(13)
         ST    6,92(13) ==> task
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         LR    7,15 ==> locked
         MVC   96(4,13),0(2) ==> .grtcthrd
         LA    2,96(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    4,6 ==> n,task
         CLR   6,15 ==> task,count
         BNL   @@L3
         L     5,96(13)
@@L8     EQU   *
         LR    2,4 ==> n
         MH    2,=H'4'
         L     3,0(2,5) ==> task
         LTR   3,3 ==> task
         BE    @@L4
         L     2,8(3) ==> .tcb
         CLR   2,9 ==> tcb
         BNE   @@L4
         LR    6,3 ==> task
         B     @@L3
@@L4     EQU   *
         A     4,=F'1' ==> n
         CLR   4,15 ==> n,count
         BL    @@L8
@@L3     EQU   *
         LTR   7,7 ==> locked
         BNE   @@L10
         LR    2,8 ==> grt
         A     2,=F'64'
         ST    2,88(13)
         ST    7,92(13) ==> locked
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
@@L10    EQU   *
         LR    15,6 ==> task
* Function 'cthread_find' epilogue
         PDPEPIL
* Function 'cthread_find' literal pool
         DS    0D
         LTORG
* Function 'cthread_find' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
