 TITLE '/home/mike/repos/crent370/clib/tmpnam.c'
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
         DS    0F
         EJECT
* external function 'tmpnam' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  'tmpnam'
TMPNAM   PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'tmpnam' code
         L     4,0(11) ==> s
         LA    1,88(,13)
         L     15,=V(@@CRTGET)
         BALR  14,15
         SLR   2,2 ==> grt
         LTR   15,15 ==> crt
         BE    @@L3
         L     2,280(15) ==> grt,crtgrt
@@L3     EQU   *
         LR    3,2 ==> s,grt
         LTR   2,2 ==> grt
         BE    @@L1
         LR    3,2 ==> cnt,grt
         A     3,=F'12' ==> cnt
         A     15,=F'284' ==> buf
         LTR   4,4 ==> s
         BNE   @@L5
         LR    4,15 ==> s,buf
@@L5     EQU   *
         ST    3,88(13) ==> cnt
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         L     2,0(3) ==> cnt
         L     5,=F'99998'
         CLR   2,5
         BNH   @@L6
         MVC   0(4,3),=F'0' ==> cnt
@@L6     EQU   *
         L     2,0(3) ==> cnt
         A     2,=F'1'
         ST    2,0(3) ==> cnt
         ST    4,88(13) ==> s
         MVC   92(4,13),=A(@@LC0)
         MVC   96(4,13),0(3) ==> cnt
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
         ST    3,88(13) ==> cnt
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
         LR    3,4 ==> s
@@L1     EQU   *
         LR    15,3 ==> s
* Function 'tmpnam' epilogue
         PDPEPIL
* Function 'tmpnam' literal pool
         DS    0D
         LTORG
* Function 'tmpnam' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    X'50'
         DC    X'50'
         DC    C'TMP%05u'
         DC    X'0'
         END
