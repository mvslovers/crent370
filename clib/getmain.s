 TITLE '/home/mike/repos/crent370/clib/getmain.c'
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
         
&FUNC    SETC 'getmain'
* Program text area
@@6      EQU   *
         DC    C'getmain'
         DC    X'0'
         DS    0F
         EJECT
* external function 'getmain' prologue
* frame base=88, local stack=8, call args=24
&FUNC    SETC  'getmain'
GETMAIN  PDPPRLG CINDEX=0,FRAME=120,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'getmain' code
         L     6,0(11) ==> size
         L     5,4(11) ==> sp
         SLR   4,4 ==> r1
         LR    15,4 ==> r1
         LTR   6,6 ==> size
         BE    @@L1
         SLR   15,15 ==> r1
         L     2,=F'16777215'
         CLR   6,2 ==> size
         BH    @@L1
         LA    1,88(,13)
         L     15,=V(@@ISSUP)
         BALR  14,15
         LTR   15,15 ==> r1
         BE    @@L4
         LA    3,112(,13)
         IPK   0             get psw key in R2
         STC   2,0(,3)      save psw key
         B     @@L5
@@L4     EQU   *
         SLR   2,2 ==> psa
         L     2,540(2) ==> tcb
         MVC   112(1,13),28(2)
@@L5     EQU   *
         N     5,=F'255' ==> sp
         LR    3,6 ==> lv,size
         A     3,=F'71' ==> lv
         N     3,=F'16777152' ==> lv
         GETMAIN RC,LV=(3),SP=(5) ==> lv,sp
         LR    2,15              save the return code ==> rc
         LR    4,1               save the returned address ==> r1
         LTR   2,2 ==> rc
         BE    @@L6
         MVC   88(4,13),=A(@@LC0)
         MVC   92(4,13),=A(@@6)
         ST    3,96(13) ==> lv
         ST    5,100(13) ==> sp
         ST    2,104(13) ==> rc
         ST    2,108(13) ==> rc
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         SLR   4,4 ==> r1
         B     @@L9
@@L6     EQU   *
         
*** MEMCLR ***
         LR    14,4           => target (s) ==> r1
         LR    15,3           => length (n) ==> lv
         SLR   0,0             => source (NULL)
         SLR   1,1             zero fill
         MVCL  14,0            Set target to fill character
         LR    2,5 ==> sp
         SLL   2,24
         OR    2,3 ==> lv
         ST    2,0(4) ==> r1
         IC    2,112(13)
         SLL   2,24
         OR    2,6 ==> size
         ST    2,4(4)
         A     4,=F'8' ==> r1
@@L9     EQU   *
         LR    15,4 ==> r1
@@L1     EQU   *
* Function 'getmain' epilogue
         PDPEPIL
* Function 'getmain' literal pool
         DS    0D
         LTORG
* Function 'getmain' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'%s request for %u bytes from sp=%u failed, rc=0x'
         DC    C'%02X (%d)'
         DC    X'0'
         
&FUNC    SETC 'freemain'
@@7      EQU   *
         DC    C'freemain'
         DC    X'0'
         DS    0F
         EJECT
* external function 'freemain' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  'freemain'
FREEMAIN PDPPRLG CINDEX=1,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN1
         LTORG
@@FEN1   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         LR    11,1
         L     10,=A(@@PGT1)
* Function 'freemain' code
         L     3,0(11) ==> addr
         SLR   2,2 ==> rc
         LTR   3,3 ==> addr
         BE    @@L12
         A     3,=F'-8' ==> addr
         SLR   5,5 ==> sp
         IC    5,0(3) ==> sp,addr
         L     4,0(3) ==> lv,addr
         N     4,=F'16777215' ==> lv
         L     2,4(3) ==> size
         N     2,=F'16777215' ==> size
         LTR   4,4 ==> lv
         BE    @@L14
         LTR   2,2 ==> size
         BNE   @@L13
@@L14    EQU   *
         ST    3,88(13) ==> addr
         MVC   92(4,13),=F'64'
         MVC   96(4,13),=A(@@LC1)
         B     @@L16
@@L13    EQU   *
         LR    6,4 ==> lv
         SR    6,2 ==> size
         LR    2,6
         A     2,=F'-8'
         LA    6,64(0,0)
         CLR   2,6
         BNH   @@L15
         ST    3,88(13) ==> addr
         ST    6,92(13)
         MVC   96(4,13),=A(@@LC2)
@@L16    EQU   *
         MVC   100(4,13),=A(@@7)
         LA    1,88(,13)
         L     15,=V(WTODUMPF)
         BALR  14,15
         L     15,=F'-1' ==> rc
         B     @@L10
@@L15    EQU   *
         
         LR    14,3           => target (s) ==> addr
         LR    15,4           => length (n) ==> lv
         SLR   0,0             => source (NULL)
         SLR   1,1             => fill 0
         MVCL  14,0            Set target to fill character
         FREEMAIN RC,A=(3),LV=(4),SP=(5) ==> addr,lv,sp
         LR    2,15 ==> rc
@@L12    EQU   *
         LR    15,2 ==> rc
@@L10    EQU   *
* Function 'freemain' epilogue
         PDPEPIL
* Function 'freemain' literal pool
         DS    0D
         LTORG
* Function 'freemain' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
@@LC1    EQU   *
         DC    C'%s duplicate freemain'
         DC    X'0'
@@LC2    EQU   *
         DC    C'%s check storage prefix'
         DC    X'0'
         IKJTCB DSECT=YES,LIST=YES
         END
