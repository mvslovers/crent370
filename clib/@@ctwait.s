 TITLE '/home/mike/repos/crent370/clib/@@ctwait.c'
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
         
&FUNC    SETC 'cthread_wait'
* Program text area
         DS    0F
         EJECT
* external function 'cthread_wait' prologue
* frame base=88, local stack=8, call args=0
&FUNC    SETC  'cthread_wait'
@@CTWAIT PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'cthread_wait' code
         L     2,0(11) ==> ecb
         MVC   88(4,13),=F'0'
         LTR   2,2 ==> ecb
         BE    @@L3
         WAIT  ECB=(2) ==> ecb
         
AGAIN    DS    0H
         L     0,0(,2)    get ecb value ==> ecb
         LA    1,0         new ecb value
         CS    0,1,0(2)   save new value in ecb ==> ecb
         BNZ   AGAIN       ecb changed, try again
         N     0,=X'3FFFFFFF'
         ST    0,88(13)        return ecb value
@@L3     EQU   *
         L     15,88(13)
* Function 'cthread_wait' epilogue
         PDPEPIL
* Function 'cthread_wait' literal pool
         DS    0D
         LTORG
* Function 'cthread_wait' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
