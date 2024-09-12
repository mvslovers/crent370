 TITLE '/home/mike/repos/crent370/clib/@@apfset.c'
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
         
&FUNC    SETC 'clib_apf_setup'
* Program text area
         DS    0F
         EJECT
* external function 'clib_apf_setup' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'clib_apf_setup'
@@APFSET PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'clib_apf_setup' code
         SLR   3,3 ==> rc
         LA    1,88(,13)
         L     15,=V(@@CRTGET)
         BALR  14,15
         IC    2,268(15) ==> .crtopts
         N     2,=F'1'
         CLM   2,1,=XL1'00'
         BNE   @@L2
         MVC   88(4,13),0(11) ==> pgm
         LA    1,88(,13)
         L     15,=A(@@6)
         BALR  14,15
         LR    3,15 ==> rc
@@L2     EQU   *
         LR    15,3 ==> rc
* Function 'clib_apf_setup' epilogue
         PDPEPIL
* Function 'clib_apf_setup' literal pool
         DS    0D
         LTORG
* Function 'clib_apf_setup' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         
&FUNC    SETC 'unauth_setup'
         DS    0F
         EJECT
* static function 'unauth_setup' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'unauth_setup'
@@6      PDPPRLG CINDEX=1,FRAME=96,BASER=12,ENTRY=NO
         B     @@FEN1
         LTORG
@@FEN1   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         LR    11,1
         L     10,=A(@@PGT1)
* Function 'unauth_setup' code
         L     4,0(11) ==> name
         LA    1,88(,13)
         L     15,=V(@@CRTGET)
         BALR  14,15
         LR    3,15 ==> crt
         LA    1,88(,13)
         L     15,=V(@@AUTASK)
         BALR  14,15
         LTR   15,15 ==> rc
         BNE   @@L4
         IC    2,269(3) ==> .crtauth
         N     2,=F'-128'
         CLM   2,1,=XL1'00'
         BE    @@L5
         LA    1,88(,13)
         L     15,=V(@@AUSTEP)
         BALR  14,15
         LTR   15,15 ==> rc
         BNE   @@L4
         IC    2,269(3) ==> .crtauth
         N     2,=F'64'
         CLM   2,1,=XL1'00'
         BE    @@L4
@@L5     EQU   *
         ST    4,88(13) ==> name
         LA    1,88(,13)
         L     15,=A(@@7)
         BALR  14,15
@@L4     EQU   *
* Function 'unauth_setup' epilogue
         PDPEPIL
* Function 'unauth_setup' literal pool
         DS    0D
         LTORG
* Function 'unauth_setup' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
         
&FUNC    SETC 'auth_pgm'
         DS    0F
         EJECT
* static function 'auth_pgm' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'auth_pgm'
@@7      PDPPRLG CINDEX=2,FRAME=96,BASER=12,ENTRY=NO
         B     @@FEN2
         LTORG
@@FEN2   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG2    EQU   *
         LR    11,1
         L     10,=A(@@PGT2)
* Function 'auth_pgm' code
         MVC   88(4,13),0(11) ==> name
         LA    1,88(,13)
         L     15,=V(@@AUTNAM)
         BALR  14,15
         LA    1,88(,13)
         L     15,=V(@@IDECTH)
         BALR  14,15
         MVC   88(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(@@AUTNAM)
         BALR  14,15
* Function 'auth_pgm' epilogue
         PDPEPIL
* Function 'auth_pgm' literal pool
         DS    0D
         LTORG
* Function 'auth_pgm' page table
@@PGT2   DS    0F
         DC    A(@@PG2)
@@LC0    EQU   *
         DC    C'CTHREAD'
         DC    X'0'
         END
