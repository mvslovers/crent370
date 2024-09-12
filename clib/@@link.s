 TITLE '/home/mike/repos/crent370/clib/@@link.c'
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
* external function '__link' prologue
* frame base=88, local stack=32, call args=0
&FUNC    SETC  '__link'
@@LINK   PDPPRLG CINDEX=0,FRAME=120,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__link' code
         L     3,0(11) ==> pgm
         L     6,8(11) ==> r1
         L     5,12(11) ==> prc
         L     15,=F'-1' ==> rc
         LTR   3,3 ==> pgm
         BE    @@L3
         IC    2,0(3) ==> pgm
         SLL   2,24
         SRA   2,24
         C     2,=F'0'
         BE    @@L3
         SLR   15,15 ==> i
         L     2,=V(@@TOUP)
         L     4,0(2) ==> __toup
@@L10    EQU   *
         SLR   2,2
         IC    2,0(15,3) ==> i
         MH    2,=H'2'
         IC    2,1(2,4)
         STC   2,88(13,15) ==> program
         A     15,=F'1' ==> i
         LA    2,7(0,0)
         CR    15,2 ==> i
         BH    @@L6
         IC    2,0(15,3) ==> i
         SLL   2,24
         SRA   2,24
         C     2,=F'0'
         BNE   @@L10
@@L6     EQU   *
         LA    3,7(0,0)
         CR    15,3 ==> i
         BH    @@L18
         LA    2,88(,13)
@@L14    EQU   *
         LA    3,64(0,0)
         STC   3,0(2,15) ==> program
         A     15,=F'1' ==> i
         LA    3,7(0,0)
         CR    15,3 ==> i
         BNH   @@L14
@@L18    EQU   *
         MVI   96(13),0 ==> program
         LA    2,88(,13)
         ST    2,104(13) ==> plist
         MVC   108(4,13),4(11) ==> plist,dcb
         LA    2,104(,13)
         OI    4(2),X'80'     extended plist for error ret address
         LA    0,ERRET         => error return address
         ST    0,8(0,2)       save in LINK SVC parameter list
         LR    1,6            => linked program parameter list ==> r1
         LR    15,2           => LINK SVC parameter list
         SVC   6              LINK SVC
         B     DONE             normal return, return to caller
ERRET    DS    0H
         L     15,=F'-1'        indicate failure
DONE     DS    0H
         LR    15,15           save return code ==> rc
@@L3     EQU   *
         LTR   5,5 ==> prc
         BE    @@L15
         ST    15,0(5) ==> rc,prc
@@L15    EQU   *
* Function '__link' epilogue
         PDPEPIL
* Function '__link' literal pool
         DS    0D
         LTORG
* Function '__link' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
