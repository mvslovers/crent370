 TITLE '/home/mike/repos/crent370/clib/@@sukydo.c'
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
         
&FUNC    SETC 'super_key_do'
* Program text area
         DS    0F
         EJECT
* external function 'super_key_do' prologue
* frame base=88, local stack=8, call args=0
&FUNC    SETC  'super_key_do'
@@SUKYDO PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'super_key_do' code
         MVC   89(1,13),3(11) ==> pswkey
         LA    6,8(,11) ==> r1
         LA    1,88(,13)
         L     15,=V(@@ISSUP)
         BALR  14,15
         LR    5,15 ==> sup
         LTR   15,15 ==> sup
         BNE   @@L2
         MODESET MODE=SUP      switch to supervisor state
         LR    4,15              save return code ==> rc
         LTR   4,4 ==> rc
         BNE   @@L4
@@L2     EQU   *
         LA    3,88(,13)
         IPK   0             get psw key in R2
         STC   2,0(,3)      save psw key
         IC    2,89(13)
         CLM   2,1,=XL1'FF'
         BE    @@L5
         CLM   2,1,=XL1'0F'
         BH    @@L6
         SLL   2,4
         STC   2,89(13)
@@L6     EQU   *
         LA    3,89(,13)
         IC    2,0(,3)           get new psw key
         SPKA  0(2)             save in psw
@@L5     EQU   *
         L     2,4(11)
         LR    15,2          => function to call 
         LR    1,6           => parameter list ==> r1
         BALR  14,15         call function
         LR    4,15          save return code ==> rc
         LA    3,88(,13)
         IC    2,0(,3)           get prev psw key
         SPKA  0(2)             save in psw
         LTR   5,5 ==> sup
         BNE   @@L4
         MODESET MODE=PROB     switch to problem state
@@L4     EQU   *
         LR    15,4 ==> rc
* Function 'super_key_do' epilogue
         PDPEPIL
* Function 'super_key_do' literal pool
         DS    0D
         LTORG
* Function 'super_key_do' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
