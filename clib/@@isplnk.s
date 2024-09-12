 TITLE '/home/mike/repos/crent370/clib/@@isplnk.c'
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
* Program text area
@@6      EQU   *
         DC    C'isplink'
         DC    X'0'
         DS    0F
         EJECT
* external function 'isplink' prologue
* frame base=88, local stack=8, call args=8
&FUNC    SETC  'isplink'
@@ISPLNK PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'isplink' code
         MVC   100(4,13),=F'20'
         L     2,0(11) ==> service_name
         LTR   2,2 ==> service_name
         BNE   @@L2
         MVC   88(4,13),=A(@@LC0)
         B     @@L12
@@L2     EQU   *
         ST    11,96(13)
         SLR   15,15 ==> i
         L     3,96(13) ==> u
@@L9     EQU   *
         LR    2,15 ==> i
         MH    2,=H'4'
         L     2,0(2,3)
         N     2,=F'-2147483648'
         LTR   2,2
         BNE   @@L5
         A     15,=F'1' ==> i
         LA    2,19(0,0)
         CR    15,2 ==> i
         BNH   @@L9
@@L5     EQU   *
         LA    2,20(0,0)
         CLR   15,2 ==> i
         BNE   @@L10
         MVC   88(4,13),=A(@@LC1)
@@L12    EQU   *
         MVC   92(4,13),=A(@@6)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         B     @@L3
@@L10    EQU   *
         LR    1,11           parameter list
         L     15,=V(ISPLINK)
         BALR  14,15          call ISPLINK
         ST    15,100(13)      save return code
@@L3     EQU   *
         L     15,100(13)
* Function 'isplink' epilogue
         PDPEPIL
* Function 'isplink' literal pool
         DS    0D
         LTORG
* Function 'isplink' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'%s: Missing service name.'
         DC    X'0'
@@LC1    EQU   *
         DC    C'%s: Missing hit order bit in plist.'
         DC    X'0'
         END
