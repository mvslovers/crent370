 TITLE '/home/mike/repos/crent370/clib/@@linkds.c'
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
         
&FUNC    SETC 'trylink'
* Program text area
         DS    0F
         EJECT
* static function 'trylink' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  'trylink'
@@0      PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=NO
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'trylink' code
         SLR   2,2 ==> rc
         ST    2,88(13) ==> rc
         ST    2,92(13) ==> rc
         LA    1,88(,13)
         L     15,=V(@@ABRPT)
         BALR  14,15
         MVC   88(4,13),0(11) ==> pgm
         MVC   92(4,13),4(11) ==> dcb
         MVC   96(4,13),8(11) ==> r1
         MVC   100(4,13),12(11) ==> prc
         LA    1,88(,13)
         L     15,=V(@@LINK)
         BALR  14,15
         LR    2,15 ==> rc
         MVC   88(4,13),=F'2'
         MVC   92(4,13),=F'1'
         LA    1,88(,13)
         L     15,=V(@@ABRPT)
         BALR  14,15
         LR    15,2 ==> rc
* Function 'trylink' epilogue
         PDPEPIL
* Function 'trylink' literal pool
         DS    0D
         LTORG
* Function 'trylink' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         DS    0F
         EJECT
* external function '__linkds' prologue
* frame base=88, local stack=0, call args=24
&FUNC    SETC  '__linkds'
@@LINKDS PDPPRLG CINDEX=1,FRAME=112,BASER=12,ENTRY=YES
         B     @@FEN1
         LTORG
@@FEN1   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         LR    11,1
         L     10,=A(@@PGT1)
* Function '__linkds' code
         MVC   88(4,13),=A(@@0)
         MVC   92(4,13),0(11) ==> pgm
         MVC   96(4,13),4(11) ==> dcb
         MVC   100(4,13),8(11) ==> r1
         MVC   104(4,13),12(11) ==> prc
         LA    1,88(,13)
         L     15,=V(@@@TRY)
         BALR  14,15
* Function '__linkds' epilogue
         PDPEPIL
* Function '__linkds' literal pool
         DS    0D
         LTORG
* Function '__linkds' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
         END
