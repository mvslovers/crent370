 TITLE '/home/mike/repos/crent370/clib/@@ctgtcb.c'
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
         
&FUNC    SETC 'cthread_get_tcb'
* Program text area
         DS    0F
         EJECT
* external function 'cthread_get_tcb' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'cthread_get_tcb'
@@CTGTCB PDPPRLG CINDEX=0,FRAME=88,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'cthread_get_tcb' code
         L     15,0(11) ==> task
         LTR   15,15 ==> task
         BE    @@L2
         L     15,8(15) ==> tcb,tcb
         B     @@L4
@@L2     EQU   *
         SLR   2,2 ==> psa
         L     15,540(2) ==> tcb
@@L4     EQU   *
* Function 'cthread_get_tcb' epilogue
         PDPEPIL
* Function 'cthread_get_tcb' literal pool
         DS    0D
         LTORG
* Function 'cthread_get_tcb' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
