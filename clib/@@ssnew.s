 TITLE '/home/mike/repos/crent370/clib/@@ssnew.c'
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
         
&FUNC    SETC 'ssct_new'
* Program text area
         DS    0F
         EJECT
* external function 'ssct_new' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  'ssct_new'
@@SSNEW  PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'ssct_new' code
         L     6,0(11) ==> name
         SLR   5,5 ==> restore
         IPK   0             get psw key in R2
         LR    4,2           save psw key in register ==> prevkey
         CLM   4,1,=XL1'00' ==> prevkey
         BE    @@L2
         LA    5,1(0,0) ==> restore
         SLR   2,2               PSW key 0 value
         SPKA  0(2)             save in psw
@@L2     EQU   *
         MVC   88(4,13),=F'24'
         MVC   92(4,13),=F'241'
         LA    1,88(,13)
         L     15,=V(GETMAIN)
         BALR  14,15
         LR    3,15 ==> ssct
         LTR   15,15 ==> ssct
         BE    @@L3
         ST    15,88(13) ==> ssct
         MVC   92(4,13),=A(@@LC0)
         MVC   96(4,13),=F'4'
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         LTR   6,6 ==> name
         BE    @@L4
         LR    2,3 ==> ssct
         A     2,=F'8'
         ST    2,88(13)
         MVC   92(4,13),=F'4'
         ST    6,96(13) ==> name
         MVC   100(4,13),=F'64'
         LA    1,88(,13)
         L     15,=V(STRCPYP)
         BALR  14,15
@@L4     EQU   *
         MVC   16(4,3),4(11) ==> .ssctssvt,ssvt
         MVC   20(4,3),8(11) ==> .ssctsuse,suse
@@L3     EQU   *
         LTR   5,5 ==> restore
         BE    @@L5
         LR    2,4               get prev psw key ==> prevkey
         SPKA  0(2)             save in psw
@@L5     EQU   *
         LR    15,3 ==> ssct
* Function 'ssct_new' epilogue
         PDPEPIL
* Function 'ssct_new' literal pool
         DS    0D
         LTORG
* Function 'ssct_new' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'SSCT'
         DC    X'0'
         END
