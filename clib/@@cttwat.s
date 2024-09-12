 TITLE '/home/mike/repos/crent370/clib/@@cttwat.c'
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
         
&FUNC    SETC 'cthread_timed_wait'
* Program text area
         DS    0F
         EJECT
* external function 'cthread_timed_wait' prologue
* frame base=88, local stack=8, call args=16
&FUNC    SETC  'cthread_timed_wait'
@@CTTWAT PDPPRLG CINDEX=0,FRAME=112,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'cthread_timed_wait' code
         L     3,0(11) ==> ecb
         MVC   104(4,13),=F'0' ==> rc
         LTR   3,3 ==> ecb
         BE    @@L3
         ST    3,88(13) ==> ecb
         MVC   92(4,13),4(11) ==> bintvl
         MVC   96(4,13),8(11) ==> postcode
         LA    1,88(,13)
         L     15,=V(@@ECBTW)
         BALR  14,15
         L     2,0(3) ==> ecb
         N     2,=F'1073741823'
         ST    2,104(13) ==> rc
         MVC   0(4,3),=F'0' ==> ecb
@@L3     EQU   *
         L     15,104(13) ==> rc
* Function 'cthread_timed_wait' epilogue
         PDPEPIL
* Function 'cthread_timed_wait' literal pool
         DS    0D
         LTORG
* Function 'cthread_timed_wait' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
