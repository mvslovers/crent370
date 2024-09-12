 TITLE '/home/mike/repos/crent370/clib/@@ctpop.c'
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
         
&FUNC    SETC 'cthread_pop'
* Program text area
         DS    0F
         EJECT
* external function 'cthread_pop' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'cthread_pop'
@@CTPOP  PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'cthread_pop' code
         L     6,0(11) ==> type
         SLR   5,5 ==> rc
         LA    1,88(,13)
         L     15,=V(@@CRTGET)
         BALR  14,15
         LR    4,15 ==> crt
         LR    7,5 ==> func,rc
         LR    8,5 ==> arg,rc
         LR    2,15 ==> crt
         A     2,=F'332'
         ST    2,88(13)
         ST    5,92(13) ==> rc
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    3,15 ==> count
         LTR   15,15 ==> count
         BE    @@L2
         ST    2,88(13)
         ST    15,92(13) ==> count
         LA    1,88(,13)
         L     15,=V(@@ARDEL)
         BALR  14,15
         LR    7,15 ==> func
         A     2,=F'4'
         ST    2,88(13)
         ST    3,92(13) ==> count
         LA    1,88(,13)
         L     15,=V(@@ARDEL)
         BALR  14,15
         LR    8,15 ==> arg
@@L2     EQU   *
         LR    2,4 ==> crt
         A     2,=F'332'
         ST    2,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
         LTR   7,7 ==> func
         BE    @@L4
         LA    2,2(0,0)
         CLR   6,2 ==> type
         BE    @@L8
         BH    @@L11
         LA    2,1(0,0)
         CLR   6,2 ==> type
         BE    @@L7
         B     @@L4
@@L11    EQU   *
         LA    2,3(0,0)
         CLR   6,2 ==> type
         BE    @@L9
         B     @@L4
@@L7     EQU   *
         ST    8,88(13) ==> arg
         LA    1,88(,13)
         LA    15,0(7) ==> func
         BALR  14,15
         B     @@L12
@@L8     EQU   *
         ST    7,88(13) ==> func
         ST    8,92(13) ==> arg
         LA    1,88(,13)
         L     15,=V(@@@TRY)
         BALR  14,15
@@L12    EQU   *
         LR    5,15 ==> rc
         B     @@L4
@@L9     EQU   *
         MVC   88(4,13),=F'0'
         MVC   92(4,13),=F'1'
         LA    1,88(,13)
         L     15,=V(@@ABRPT)
         BALR  14,15
         ST    8,88(13) ==> arg
         LA    1,88(,13)
         LA    15,0(7) ==> func
         BALR  14,15
         LR    5,15 ==> rc
         MVC   88(4,13),=F'2'
         MVC   92(4,13),=F'1'
         LA    1,88(,13)
         L     15,=V(@@ABRPT)
         BALR  14,15
@@L4     EQU   *
         LR    15,5 ==> rc
* Function 'cthread_pop' epilogue
         PDPEPIL
* Function 'cthread_pop' literal pool
         DS    0D
         LTORG
* Function 'cthread_pop' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
