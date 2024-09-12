 TITLE '/home/mike/repos/crent370/clib/@@ctdel.c'
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
         
&FUNC    SETC 'cthread_delete'
* Program text area
         DS    0F
         EJECT
* external function 'cthread_delete' prologue
* frame base=88, local stack=8, call args=8
&FUNC    SETC  'cthread_delete'
@@CTDEL  PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'cthread_delete' code
         L     4,0(11) ==> task
         LA    1,88(,13)
         L     15,=V(@@GRTGET)
         BALR  14,15
         LR    5,15 ==> grt
         LTR   4,4 ==> task
         BE    @@L1
         L     2,0(4) ==> task
         LTR   2,2
         BE    @@L1
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(STRCMP)
         BALR  14,15
         LR    3,15 ==> grt
         LTR   15,15 ==> grt
         BNE   @@L1
         LR    2,5 ==> grt
         A     2,=F'64'
         ST    2,88(13)
         ST    15,92(13) ==> grt
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         MVC   96(4,13),0(2) ==> .grtcthrd
         LA    2,96(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    6,15 ==> count
         LR    15,3 ==> n,grt
         CLR   3,6 ==> n,count
         BNL   @@L7
@@L12    EQU   *
         LR    3,15 ==> n
         MH    3,=H'4'
         L     2,96(13)
         L     2,0(3,2)
         LTR   2,2
         BE    @@L8
         CL    2,0(4) ==> task
         BNE   @@L8
         LR    2,5 ==> grt
         A     2,=F'64'
         ST    2,88(13)
         LR    2,15 ==> n
         A     2,=F'1'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(@@ARDEL)
         BALR  14,15
         B     @@L7
@@L8     EQU   *
         A     15,=F'1' ==> n
         CLR   15,6 ==> n,count
         BL    @@L12
@@L7     EQU   *
         LR    2,5 ==> grt
         A     2,=F'64'
         ST    2,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
         MVC   88(4,13),0(4) ==> task
         LA    1,88(,13)
         L     15,=V(@@CTDET)
         BALR  14,15
         MVC   88(4,13),0(4) ==> task
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
         MVC   0(4,4),=F'0' ==> task
@@L3     EQU   *
@@L1     EQU   *
* Function 'cthread_delete' epilogue
         PDPEPIL
* Function 'cthread_delete' literal pool
         DS    0D
         LTORG
* Function 'cthread_delete' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'CTHDTASK'
         DC    X'0'
         END
